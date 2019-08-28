#include "libos.h"


bool file2buffer(char *pszFileName, char *buffer, int pos, int size)
{
    FILE *pFile = NULL; 
    
    pFile = fopen(pszFileName, "rb");    
    if(0 == pFile){
        return false;
    }
    
	memset(buffer, 0x00, size);
    fseek(pFile, pos, SEEK_SET);    
    fread(buffer,1,size,pFile);   
    fclose(pFile);
    
    return true;
}

#ifdef WIN32
unsigned int fileSize(char *filename)
{
	FILE *fp = fopen(filename,"rb");
	if(!fp){
		return 0;
	}
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
	fclose(fp);
    return (size<0)?0:((unsigned int)size);
}
#else
unsigned int fileSize(const char *path)  
{
	unsigned int filesize = 0;
	struct stat statbuff;
	if(stat(path, &statbuff) < 0){
		return filesize;
	}else{
		filesize = (unsigned int)statbuff.st_size;
	}
	return filesize;
}
#endif


#ifndef WIN32
int fileExist(const char *path)  
{  
    struct stat statbuff;  
	
    if(stat(path, &statbuff) < 0) {  
        return 0; 
    }
    return 1;
}
#else
int fileExist(const char *path)  
{
    int filesize = -1;
    FILE *fp = NULL;  
    fp = fopen(path, "rb");
    if(fp == NULL) { 
        return 0;
    }    
    fclose(fp);
    return 1;
}
#endif

bool cmmn_isValidURL(char *szURL)
{
	//(https://)  (http://) PERFIX
	if(strlen(szURL)>5
		&&strstr(szURL,"http")
		&&(strchr(szURL,'.')||strstr(szURL,"localhost"))
		&&strstr(szURL,"://")){
		return true;
	}
	return false;
}


char *ext2mimetype(char *ext)
{
	if(ext&&strstr(ext,"htm")){
		return "text/html";
	}
	if(ext&&strstr(ext,"js")){
		return "text/javascript";
	}
	if(ext&&strstr(ext,"css")){
		return "text/css";
	}
	if(ext&&strstr(ext,"mp4")){
		return "video/mp4";
	}
	return "application/octet-stream";
}


char* tm2Str(time_t t,int idx)
{
	static char g_str[128] = {0};
    struct tm *ptm = localtime(&t);    
    sprintf(g_str+idx,"%04d-%02d-%02d %02d:%02d:%02d",ptm->tm_year+1900, ptm->tm_mon+1,ptm->tm_mday,ptm->tm_hour,ptm->tm_min,ptm->tm_sec);    
    return (g_str+idx);
}


bool getNextNDaysDateTime(int year,int month,int day, int *py, int *pm, int *pd)
{
	int s[2][13]={0,31,28,31,30,31,30,31,31,30,31,30,31,0,31,29,31,30,31,30,31,31,30,31,30,31};
	int n,i,daytemp;
	int flag=0;
	int nyear=0,nmonth=0,nday=0;
	
	n=1;
	if(year<0||month<0||month>12||day<1||n<0){		
		return false;
	}
	daytemp=day+n;
	
	if((year%4==0&&year%100!=0)||year%400==0){
		flag=1;
	}
	if(day>s[flag][month]){		
		return false;
	}
	if(daytemp<=s[flag][month]){
		nyear=year;
		nmonth=month;
		nday=daytemp;
	}else{
		i=month;
		nyear=year;
		while(daytemp>s[flag][i]){
			daytemp=daytemp-s[flag][i];
			i++;
			if(i>12){
				nyear++;
				if((nyear%4==0&&nyear%100!=0)||nyear%400==0){
					flag=1;
				}else{
					flag=0;
				}
				i=i-12;
			}			
		}		
		nmonth=i;
		nday=daytemp;
	}
	
	*py = nyear;
	*pm = nmonth;
	*pd = nday;
	return true;
}


bool getNextDateTime(int y,int m,int d, int *py, int *pm, int *pd)
{
	int y2,m2,d2,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(y%4==0&&y%100||y%400==0){ a[2]=29;}
	y2=y;m2=m;d2=d+1;
	if(d==a[m]){
		if(m==12) {y2+=1;m2=d2=1;}
		else {m2+=1;d2=1;}
	}
	*py = y2;
	*pm = m2;
	*pd = d2;
	return true;
}


bool getPrevDateTime(int y,int m,int d, int *py, int *pm, int *pd)
{
	int y1,m1,d1,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(y%4==0&&y%100||y%400==0){ a[2]=29;}
	y1=y;m1=m;d1=d-1;
	if(d==1){
		if(m==1) {y1-=1;m1=12;d1=31;}
		else {m1-=1;d1=a[m1];}
	}	
	*py = y1;
	*pm = m1;
	*pd = d1;
	return true;
}