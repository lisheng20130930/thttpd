#ifndef UTILS_H
#define UTILS_H


bool file2buffer(char *pszFileName, char *buffer, int pos, int size);
unsigned int fileSize(char *pszFileName);


bool cmmn_isValidURL(char *szURL);


#endif