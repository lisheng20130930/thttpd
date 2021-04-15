#include "libos.h"
#include "evfunclib.h"
#include "httpd.h"
#include "thttpd.h"
#include "utils.h"
#include "iptables.h"
#include "config.h"


#define PORT		(60000)
#define TIMEOUT		(15)


#define BUFFLEN		(102400)
#define FSLEN		(128)


static char g_buffer[BUFFLEN] = {0};
static void* httpd = NULL;


static void node_error(node_t *node);

static void node_continue(node_t *node)
{
	int iLen = __min(BUFFLEN,node->u.d.total+node->u.d.headsize-node->sendsize);
	if(!file2buffer(node->u.d.pszPathName,g_buffer,node->sendsize-node->u.d.headsize,iLen)){
		DBGPRINT(EERROR,("[Trace@ThttpD] readError\r\n"));
		return;
	}
	node->pfnSend(node,g_buffer,iLen,((node->sendsize+iLen)==(node->u.d.total+node->u.d.headsize))?true:false);
}

static void _node_sendFile(node_t *node, char *pszPathName)
{
	node->u.d.total = fileSize(pszPathName);
	if(node->u.d.total==0){
		DBGPRINT(EERROR,("[Trace@ThttpD] fileSize error\r\n"));
		node_error(node);
		return;
	}
	
	strcpy(node->u.d.pszPathName,pszPathName);
	
	sprintf(g_buffer,"HTTP/1.0 200 OK\r\nContent-Type: %s\r\nContent-Length: %u\r\n\r\n",ext2mimetype(strrchr(pszPathName,'.')),node->u.d.total);
	DBGPRINT(EDEBUG,("[Trace@ThttpD] Info: Response-Header=[%s]\r\n",g_buffer));
	
	node->u.d.headsize = strlen(g_buffer);
	node->pfnSend(node,g_buffer,node->u.d.headsize,false);
	
	/* send file continue */
	node_continue(node);
}

static char* node_path2Name(char *root, char *path)
{
    char _path[FSLEN] = {0};
    
    if(!path||strlen(path)<=2){
        DBGPRINT(EERROR,("[Trace@HTTPD] Info: too less path\r\n"));
        return NULL;
    }
    // skip query part/fragment
    char *end = strchr(path,'?');
    if(!end){
        end = strchr(path,'#');
        if(!end){
            end = path+strlen(path);
        }
    }
    if(end-path>=FSLEN){
        DBGPRINT(EERROR,("[Trace@HTTPD] Info: path 2max\r\n"));
        return NULL;
    }
    memcpy(_path,path,end-path);
	memset(g_buffer,0x00,256);
	#ifdef WIN32
	g_buffer[0] = '.';
	#endif
    sprintf(g_buffer+strlen(g_buffer),"%s/%s",root,_path+1);	
    return g_buffer;
}


static void node_sendFile(node_t *node, char *root, char *path)
{	
	if(!can_access(getRemoteAddr(node))){
		DBGPRINT(EERROR,("[Trace@ThttpD] Info: IP prevented\r\n"));
		node_error(node);
		return;
	}
	
	char *pszFileName = node_path2Name(root,path);	
	if(!pszFileName){
		node_error(node);
		return;
	}	
	DBGPRINT(EDEBUG,("[Trace@ThttpD] Info: sendFile(name=%s)\r\n",pszFileName));
	_node_sendFile(node,pszFileName);
}

static void node_error(node_t *node)
{
	DBGPRINT(EDEBUG,("[Trace@ThttpD] node_error Enter\r\n"));
	sprintf(g_buffer,"%s","HTTP/1.0 404 Not Found\r\nContent-Length: 0\r\n\r\n");
	node->pfnSend(node,g_buffer,strlen(g_buffer), true);
	DBGPRINT(EDEBUG,("[Trace@ThttpD] node_error Leave\r\n"));
}

static void node_handle(node_t *node)
{
	DBGPRINT(EDEBUG,("[Trace@ThttpD] node_handle Enter.\r\n"));
    if(node->IsFileUpload){        
        sprintf(g_buffer,"HTTP/1.0 200 OK\r\nContent-Length: 9\r\nConnection: close\r\n\r\n%s",node->req.upload.isComplete?"{success}":"{failure}");
        node->pfnSend(node,g_buffer,strlen(g_buffer), true);
        return;
    }
	char *path = we_url_path(node->URL);
	struct mapper_t *refer = query_by_path(path);
	if(!refer){
		node_error(node);
		return;
	}
	node_sendFile(node,refer->root,path+strlen(refer->prefix));
}

static void node_clear(node_t *node)
{
	http_parser_init(&node->parser,HTTP_REQUEST);
	buffer_deinit(&node->req.buffer);
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
	DBGPRINT(EERROR,("[Trace@ThttpD] ThttpD_start.....\r\n"));	
	httpd = httpd_start(node_handler,sizeof(node_t),PORT,TIMEOUT,0,NULL);
}

void thttpd_stop()
{
	DBGPRINT(EERROR,("[Trace@ThttpD] ThttpD_stop\r\n"));
	httpd_stop(httpd);	
}

void thttpd_loop(int loops)
{	
}
