//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>

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
https://leetcode.com/problems/shortest-path-in-binary-matrix/
1091. Shortest Path in Binary Matrix

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.
*/

int shortestPathBinaryMatrix(vector< vector<int> >& grid) {
    int N = grid.size();
    LOGD("N: %d\n", N);
    int **ary = new int*[N];
    for(int i = 0; i < N; ++i) {
        ary[i] = new int[N];
    }
    
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            ary[i][j] = grid[i][j] == 1 ? -1 : 0;
        }
    }
    
    //Display
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            printf("%2d ",ary[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(ary[i][j] <0) {
                continue;
            }
            for(int ii=i-1; ii<3; ++ii)
            {
                if(ii<0)
                    continue;

                for(int jj=j-1; jj<3; ++jj)
                {
                    if(jj<0)
                        continue;
                    if( ary[ii][jj] >=0) {
                        ary[ii][jj] = ary[i][j] + 1;
                    }
                }
            }
        }
    }
    
#if 0
    int a[4]; //left, up, upleft,upriht
    int min;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            a[0] = -1; a[1] = -1; a[2] = -1; a[3] = -1;
            min = -1;
            if(j-1 >=0) {
                a[0] = ary[i][j-1];
            }
            if(i-1 >=0) {
                a[1] = ary[i-1][j];
            }
            if((i-1 >=0) && (j-1>=0)) {
                a[2] = ary[i-1][j-1];
            }
            if((i-1 >= 0) && (j+1 < N)) {
                a[3] = ary[i-1][j+1];
            }            
            //Find min
            for(int x =0; x<4; ++x)
            {
                if(a[x] >=0) {
                    if(min < 0) {
                        min = a[x];
                    }
                    else {
                        if(a[x]<min) {
                            min = a[x];
                        }
                    }
                }
            }
            LOGD("i: %d, j: %d, MIN: %d, (%d, %d, %d, %d)\n", i, j, min, a[0], a[1], a[2], a[3]);
            if(min>=0 && ary[i][j] >=0) {
                ary[i][j] = min+1;
            }
        }
    }
#endif
    //Display
    LOGD("\n");
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            printf("%2d ",ary[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < N; ++i) {
        delete [] ary[i];
    }
    delete [] ary;

    return 0;
}

void Test_shortestPathBinaryMatrix()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {0,0,0,0,0,0,0};
    int arr2[] = {1,1,1,1,1,1,0};
    int arr3[] = {1,0,0,0,1,1,0};
    int arr4[] = {1,0,1,0,1,1,0};
    int arr5[] = {1,0,1,0,0,0,0};
    int arr6[] = {1,0,1,1,1,1,1};
    int arr7[] = {1,0,0,0,0,0,0};

    
    int n = sizeof(arr1)/sizeof(arr1[0]);

    printf("\n");
    vector<int> input1(arr1, arr1+n);
    vector<int> input2(arr2, arr2+n);
    vector<int> input3(arr3, arr3+n);
    vector<int> input4(arr4, arr4+n);
    vector<int> input5(arr5, arr5+n);
    vector<int> input6(arr6, arr6+n);
    vector<int> input7(arr7, arr7+n);
    vector< vector<int> > grid;
    grid.push_back(input1);
    grid.push_back(input2);
    grid.push_back(input3);
    grid.push_back(input4);
    grid.push_back(input5);
    grid.push_back(input6);
    grid.push_back(input7);
    shortestPathBinaryMatrix(grid);
    
    LOGD("Done \n");
}