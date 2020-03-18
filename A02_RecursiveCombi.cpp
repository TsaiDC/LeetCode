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
Reference:
https://helloacm.com/cc-coding-exercise-recursive-combination-algorithm-implementation/
*/

void comb(int n, int r, int *arr, int sz) {
    LOGE("N: %d, %d\n", n, r);
    for(int i=n; i>=r; i--)
    {
        arr[r-1] = i;
        LOGD("%d: %d: %d\n", n, r-1, i);
        if(r>1) {
            comb(i-1, r-1, arr, sz);
        }
        else {
            for(int i=0; i<sz; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
}

void Test_RecursiveCombi()
{
    LOGI("%s\n", __TIME__);
    int N=5;
    int M=3;
    int *arr = new int[M];
    comb(N, M, arr, M);
    delete []arr;    
}