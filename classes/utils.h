#ifndef UTILS_H
#define UTILS_H


bool file2buffer(char *pszFileName, char *buffer, int pos, int size);
unsigned int fileSize(char *pszFileName);
int fileExist(const char *path);

bool cmmn_isValidURL(char *szURL);
char* ext2mimetype(char *ext);

char* tm2Str(time_t t,int idx);

bool getNextNDaysDateTime(int year,int month,int day, int *py, int *pm, int *pd);
bool getNextDateTime(int year,int month,int day, int *py, int *pm, int *pd);
bool getPrevDateTime(int y,int m,int d, int *py, int *pm, int *pd);


#endif