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
#define GREEN "\033[0;32;32m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#if DEBUG
#define LOGI(...) {printf(GREEN "[I] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGI(...)
#define LOGD(...)
#define LOGE(...)
#endif


/*
Sortings:
http://notepad.yehyeh.net/Content/Algorithm/Sort/Sort.php
*/

void showList(int* pData, int leng)
{
    printf("<-- ");
    for(int i=0; i<leng; ++i)
    {
        printf("%d ", pData[i]);
    }
    printf("-->\n");
}

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

void doQuickSort(int* pData, int i, int j)
{
//    LOGD("Range: %d -> %d\n", i, j);
#if 0
    LOGD("+++Input\n");
    printf("->");
    for(int xx=i; xx<=j; ++xx)
    {
        printf("%d ", pData[xx]);
    }
    printf("\n");
    LOGD("---Input\n");
#endif

    int p = j;
    int x = i, y = j-1;
    int tmp = 0;
    
    if(x>y) {
//        LOGE("Stop\n");
        return;
    }
    
    while(x<y)
    {
        while (x<=y && (pData[x] < pData[p])){++x;}
        while (y>=x && (pData[y] > pData[p])){--y;}    
        
//        LOGD("P(%d):%d, x(%d):%d, y(%d):%d\n", p, pData[p], x, pData[x], y, pData[y]);
        
        if(x<y) {
            tmp = pData[x];
            pData[x] = pData[y];
            pData[y] = tmp;
        }
#if 0   
        printf("--");
        for(int xx = i; xx<j; ++xx)
        {
            printf("%d ",pData[xx]);
        }
        printf("\n");
#endif
    }

//    LOGE("Final Swap P(%d):%d, x(%d):%d, y(%d):%d\n", p, pData[p], x, pData[x], y, pData[y]);
    if (pData[x] > pData[p]) {
        tmp = pData[x];
        pData[x] = pData[p];
        pData[p] = tmp;
    }
#if 0
    printf("<-");
    for(int xx = i; xx<=j; ++xx)
    {
        printf("%d ",pData[xx]);
    }
    printf("\n");
#endif
//    LOGD("p: %d,  0~%d <=> %d~%d \n", x, x-1, x+1, j);
    doQuickSort(pData, 0, x-1);
    doQuickSort(pData, x+1, j);
}

void doMergeSort(int* pData, int i, int j, int* oData)
{
    LOGD("Range: %d -> %d, (%d <-> %d), (%d <->%d)\n", i, j, i, i+(j-i)/2, i+(j-i)/2 + 1, j);

    int tmp = 0;
    if(j-i == 0 || j-i == 1) {
//        LOGD("Single Item i: %d, j: %d\n", i, j);
        if(pData[i] > pData[j]) {
            tmp = pData[i];
            pData[i] = pData[j];
            pData[j] = tmp;            
        }
//        showList(pData, 10);
        return;
    }

    doMergeSort(pData, i, i+(j-i)/2, oData);
    doMergeSort(pData, i+(j-i)/2 + 1, j, oData);
	int i1 = i, j1 = i+(j-i)/2;
	int i2 = i+(j-i)/2 + 1, j2 = j;
//    LOGE("Start Merge i: %d, j: %d, (%d->%d), (%d->%d)\n", i, j, i1, j1, i2, j2);
	
	int io = i;
	while (i1<=j1 && i2<=j2)
	{
	    if(pData[i1]<pData[i2]) {
		    oData[io] = pData[i1];
			++i1;
		}
		else {
			oData[io] = pData[i2];
			++i2;
		}
		++io;
	}
	while(i1<=j1)
	{
	    oData[io] = pData[i1];
		++i1;
		++io;
	}
	while(i2<=j2)
	{
		oData[io] = pData[i2];
		++i2;
		++io;
	}
	//Copy back
	while(i<=j)
	{
	    pData[i] = oData[i];
		++i;
	}
//    showList(oData, 10);
//    showList(pData, 10);
}

void Test_sorting()
{
    LOGI("%s\n", __TIME__);

	int iData [] = {72,63,42,27,79,3,32,71,88,73};
//    int iData [] = {75,98,97,12,82,78,91,21,72,70};
	int oData [10] = { 0 };
	int Num = sizeof(iData)/sizeof(iData[0]);	
	LOGI("Input Data Num: %d\n", Num);
	showList(iData, Num);

//    doInsertionSort(iData, Num);
//    doSelectionSort(iData, Num);
//    doBubbleSort(iData, Num);
//    doQuickSort(iData, 0, Num-1);
    doMergeSort(iData, 0, Num-1, oData);
	
    LOGI("+++Result\n");
	showList(iData, Num);
    LOGI("---Result\n");
    LOGI("Done \n");
}