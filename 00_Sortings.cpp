//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#define LOGE(...)
#endif


/*
Sortings:
http://notepad.yehyeh.net/Content/Algorithm/Sort/Sort.php
*/

void doInsertionSort(int* pData, int leng)
{
    for(int i=0; i<leng; ++i)
	{
	    for(int j=i+1; j<leng; ++j)
        {
        }		
	}
}

void Test_sorting()
{
    LOGD("%s\n", __TIME__);

	int iData [] = {72,63,42,27,79,3,32,71,88,73};
	int Num = sizeof(iData)/sizeof(iData[0]);	
	LOGD("Input Data Num: %d\n", Num);
	
	doInsertionSort(iData, Num);	
	
    LOGD("Done \n");
}