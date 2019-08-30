//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

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

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//

/*
https://leetcode.com/problems/unique-paths/
62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

int uniquePaths(int m, int n) {
    if(m == 1|| n == 1) {
        return 1;
    }
    if(m>100 || n>100) {
        return -1;
    }
    vector<int>VS;
    
    int T = (m+n-2) > 0 ? (m+n-2) : 1;
    int B, S;
    int up, down, result;

    if(m>n){
        B = m-1 > 0 ? m-1 : 1;
        S = n-1 > 0 ? n-1 : 1;
        
    } else {
        B = n-1 > 0 ? n-1 : 1;
        S = m-1 > 0 ? m-1 : 1;
    }
    LOGD("%d!/(%d!*%d!)\n", T, B, S);
    int i;
    for(i = S; i > 0 ; --i)
    {
        VS.push_back(i);
        printf("%d ", i);
    }
    printf("\n");
    
    for(i=0; i<VS.size(); ++i)
    {
        printf("%d ", VS[i]);
    }
    printf("\n");
    
    up = T;    
    for(i = T-1; i > B; --i)
    {
        LOGD("Count, UP: %d, i: %d, New: %d\n", up, i, i*up);
        up = i * up;
        for(int j =0; j<VS.size(); ++j)
        {
            if(VS[j] == 0) {
                continue;
            }
            if(up%VS[j] == 0) {
                LOGD("Update: Up: %d, VS[%d]: %d\n", up, j, VS[j]);
                up /= VS[j];
                VS[j] = 0;
            }
        }
    }
    LOGD("Result: %d\n", up);
    return up;
}

void Test_uniquePaths()
{
    LOGD("%s\n", __TIME__); 
//    int result = uniquePaths(10, 1764322560);
    int result = uniquePaths(4, 6);
    LOGD("Result: %d\n", result);
    LOGD("Done \n");
}