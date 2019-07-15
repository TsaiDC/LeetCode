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
    LOGD("\n");
    int tmp = 0;
    int i, j;
    bool isSwap = false;
    for(i=1; i<leng; ++i)
	{    
        tmp = pData[i];
        LOGE("PTR: %d, data: %d\n", i, tmp);
	    for(j=i; j>0 && tmp < pData[j-1]; --j)
        {                        
            LOGE("SHIFT   pData[%d]=%d <-> pData[%d]=%d\n", j, pData[j], j-1, pData[j-1]);
            pData[j] = pData[j-1];
        }        

        LOGE("SWAP    i: %d j: %d, pData: %d\n", i, j, pData[j]);
        pData[j] = tmp;               
	}
}

void doSelectionSort(int* pData, int leng)
{
    LOGD("\n");
    int ptr, tmp;
    for(int i=0; i<leng; ++i)
    {
        ptr=i;
        LOGE("-- i: %d PTR %d, D: %d\n",i, ptr, pData[ptr]);
        for(int j=i; j<leng; ++j)
        {
            if(pData[j] < pData[ptr]) {
                ptr = j;
            }
        }
        printf("ptr: %d, Min: %d\n", ptr, pData[ptr]);
        
        LOGE("Swap pData[%d] <-> pDat[%d]\n", i, ptr);
        tmp = pData[i];
        pData[i] = pData[ptr];
        pData[ptr] = tmp;

        for(int x=0;x<leng; ++x)
        {
            printf("%d ", pData[x]);
        }
        printf("\n");
    }    
    
}

void doBubbleSort(int* pData, int leng)
{
    LOGD("\n");
	int i, j, tmp;
	bool isSwap = true;
	for(i=0; i<leng-1 && isSwap == true; i++)
	{
	    isSwap = false;
	    for(j=0; j<leng-1; ++j)
		{
		    if(pData[j+1]<pData[j]) {
//			    LOGD("Swap pData[%d]=%d, pData[%d]=%d\n", j+1, pData[j+1], j, pData[j]);
			    tmp = pData[j+1];
				pData[j+1] = pData[j];
				pData[j] = tmp;
				isSwap = true;
			}
		}
	}
}

void doQuickSort(int* pData, int i, int j, int p)
{
    LOGD("\n");
}

void Test_sorting()
{
    LOGD("%s\n", __TIME__);

	int iData [] = {72,63,42,27,79,3,32,71,88,73};
//    int iData [] = {75,98,97,12,82,78,91,21,72,70};
	int Num = sizeof(iData)/sizeof(iData[0]);	
	LOGD("Input Data Num: %d\n", Num);
	
//    doInsertionSort(iData, Num);
//    doSelectionSort(iData, Num);
    doBubbleSort(iData, Num);
	    
    LOGD("+++Result\n");
    for(int i=0; i<Num; ++i)
    {
        printf("%d ", iData[i]);
    }
    printf("\n");
    LOGD("---Result\n");
    LOGD("Done \n");
}