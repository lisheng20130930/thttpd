#ifndef LOG_H
#define LOG_H


/* You should modify your file name here */
#define LOGFILENAME "thttpd.dat"

/* logger level */
enum{
    EDEBUG = 0x01,
	EMSG   = 0x02,
	EERROR = 0x04,
	ELEVEL = EDEBUG|EMSG|EERROR
};

#define DBGPRINT(t,x)   {do{if(ELEVEL&(t)){_log x;}}while(0);}
#define DASSERT(x)  {do{if(!(x)){DBGPRINT(EERROR,("Assert...\r\n"));}}while(0);}


void _log(char* pszFormat, ...);


#endif