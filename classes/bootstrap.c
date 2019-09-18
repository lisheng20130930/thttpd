#include "libos.h"
#include "evfunclib.h"
#include "signal.h"
#include "httpd.h"
#include "thttpd.h"


#define MAXCNN		(8000)


static int g_loop = 0;
static int g_SIG = (-1);


static void sig_handler_cb(int sig)
{
    switch(sig)
    {
    case SIGINT:
    case SIGTERM:
		DBGPRINT(EDEBUG,("[Trace@BOOTSTRAP] SIGINT(SIGTERM) Catched\r\n"));
        g_SIG = SIGINT;
        break;
    case SIGHUP:
		DBGPRINT(EDEBUG,("[Trace@BOOTSTRAP] SIGHUP Catched\r\n"));
		signal(SIGHUP, sig_handler_cb);
        g_SIG = SIGHUP;
        break;
    default:
        break;
    }
}


int main(int argv, char **argc)
{
	DBGPRINT(EERROR,("[Trace@BOOTSTRAP] loading..........\r\n"));	
	signal(SIGINT, sig_handler_cb);
    signal(SIGTERM, sig_handler_cb);
    signal(SIGHUP, sig_handler_cb);
	
    evnet_init(MAXCNN);
    thttpd_start();
	while(1){
		if(g_SIG == SIGINT){
            g_SIG = (-1);
            break;
        }
        evnet_loop(g_loop);
		thttpd_loop(g_loop);
		g_loop++;
    }
	thttpd_stop();
    evnet_uint();
	
	return 0;
}