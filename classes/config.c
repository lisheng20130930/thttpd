#include "libos.h"
#include "config.h"


#define URL_PREIFX  "/front"


#ifndef WIN32
#define ROOT        "./web"
#else
#define ROOT       "../web"
#endif


#define LN_SIZE (2)
struct mapper_t g_config[LN_SIZE] = {
	{"/web","./web"},
	{"/api","./example"},
};


struct mapper_t *query_by_path(char *path)
{
	int i;
	for(i=0; i<LN_SIZE; i++){
		if(strstr(path,g_config[i].prefix)){
			return &g_config[i];
		}
	}
	return NULL;
}
