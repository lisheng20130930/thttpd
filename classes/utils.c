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