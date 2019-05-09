#ifndef THTTPD_H
#define THTTPD_H


struct node_t{
	http_parser parser;	
	char *URL;
	unsigned char method;
	int status;
	void *usr;
	buffer_t buffer;
	pfn_node_send pfnSend;
	unsigned int sendsize;
	unsigned int sentsize;
	list_head headers;
	union{
		struct {
			char pszPathName[1024];
			unsigned int headsize;
			unsigned int total;			
		}d;
	}u;
};


void thttpd_loop(int loops);
void thttpd_start();
void thttpd_stop();



#endif