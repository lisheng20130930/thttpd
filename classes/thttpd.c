#include "libos.h"
#include "evfunclib.h"
#include "httpd.h"
#include "thttpd.h"
#include "utils.h"
#include "cconf.h"


#define PORT		(50005)
#define TIMEOUT		(8)



#define BUFFLEN		(1024*1024)
#define PATHLEN		(1024)


static char g_buffer[BUFFLEN] = {0};
static void* httpd = NULL;


static void node_error(node_t *node);


static void node_continue(node_t *node)
{
	DBGPRINT(EDEBUG,("[ThttpD] node_send_continue Enter\r\n"));
	int iLen = __min(BUFFLEN,node->u.d.total+node->u.d.headsize-node->sendsize);
	if(!file2buffer(node->u.d.pszPathName,g_buffer,node->sendsize-node->u.d.headsize,iLen)){
		DBGPRINT(EERROR,("[ThttpD] readError\r\n"));
		return;
	}
	node->pfnSend(node,g_buffer,iLen,((node->sendsize+iLen)==(node->u.d.total+node->u.d.headsize))?true:false);
}

static void node_sendFile(node_t *node, char *pszPathName)
{
	node->u.d.total = fileSize(pszPathName);
	if(node->u.d.total==0){
		node_error(node);
		return;
	}

	strcpy(node->u.d.pszPathName,pszPathName);

	sprintf(g_buffer,"HTTP/1.0 200 OK\r\nContent-Length: %u\r\n\r\n",node->u.d.total);	
	DBGPRINT(EDEBUG,("[ThttpD] Info: Response-Header=[%s]\r\n",g_buffer));

	node->u.d.headsize = strlen(g_buffer);
	node->pfnSend(node,g_buffer,node->u.d.headsize,false);

	/* send file continue */
	node_continue(node);
}

static void node_error(node_t *node)
{
	DBGPRINT(EDEBUG,("[ThttpD] node_error Enter\r\n"));
	sprintf(g_buffer,"%s","HTTP/1.0 404 Not Found\r\nContent-Length: 0\r\n\r\n");
	node->pfnSend(node,g_buffer,strlen(g_buffer), true);
	DBGPRINT(EDEBUG,("[ThttpD] node_error Leave\r\n"));
}


static char* node_path2Name(char *pszURLPath)
{
	if(strlen(pszURLPath)>=PATHLEN){
		return NULL;
	}
	sprintf(g_buffer,"./%s", pszURLPath+1);
	if(strlen(g_buffer)<=2){
		return NULL;
	}
	return g_buffer;
}

void node_handle(node_t *node)
{
	DBGPRINT(EDEBUG,("[ThttpD] node_handle Enter.\r\n"));
	char *path = we_url_path(node->URL);
	DBGPRINT(EDEBUG,("[ThttpD] Info: path=%s\r\n",path));
	if(!path||!strchr(path,'.')){
		node_error(node);
		return;
	}
	
	char *pszFileName = node_path2Name(path);
	DBGPRINT(EDEBUG,("[ThttpD] Info: fileName=%s\r\n",pszFileName));
	if(!pszFileName){
		node_error(node);
		return;
	}
	
	DBGPRINT(EDEBUG,("[ThttpD] Info: sendFile\r\n"));
	node_sendFile(node,pszFileName);
	DBGPRINT(EDEBUG,("[ThttpD] node_handle Leave\r\n"));
}

void node_clear(node_t *node)
{
	http_parser_init(&node->parser,HTTP_REQUEST);
	buffer_deinit(&node->buffer);
}

static void node_handler(node_t *node, int evt, int p1, int p2)
{
	switch(evt)
	{
	case ENODEHANDLE:
		node_handle(node);
		break;
	case ENODECONTINUE:
		node_continue(node);
		break;
	case ENODECLEAR:
		node_clear(node);
		break;
	default:
		break;
	}
}

void thttpd_start()
{
	DBGPRINT(EERROR,("[ThttpD] ThttpD_start.....\r\n"));	
	httpd = httpd_start(node_handler,PORT,MAXCNN,TIMEOUT,1,"server.pem");
}

void thttpd_stop()
{
	DBGPRINT(EERROR,("[ThttpD] ThttpD_stop\r\n"));
	httpd_stop(httpd);
}