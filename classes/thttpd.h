#ifndef THTTPD_H
#define THTTPD_H


struct node_t{
    http_parser parser;	
    char *URL;
    unsigned char method;
    int status;
    void *usr;	
    pfn_node_send pfnSend;
    unsigned int sendsize;
    unsigned int sentsize;
    struct list_head headers;
    int IsFileUpload;
    union{
        buffer_t buffer;
        struct{
            multipart_parser *mp;
            struct list_head mhdr;
            FILE *pFile;
            bool isComplete; //upload success
            char filename[256];
        }upload;
    }req;
    
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