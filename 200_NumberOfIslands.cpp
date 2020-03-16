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

/*
https://leetcode.com/problems/number-of-islands/
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), 
count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

#define GETX(idx,w) (idx%w)
#define GETY(idx,h) (idx/h)
#define GETIDX(xx, yy, width) ((yy)*width+(xx))

int numIslands(vector<vector<char>>& grid) {
    
    int h = grid.size();
    int w = grid[0].size();
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    
    LOGD("h: %d, w: %d\n",h, w);

    vector<int>rol(h*w, -1);
    vector<vector<int>> adjacent(h*w, rol);

    for(int j=0; j<h; j++)
    {
        for(int i=0; i<w; i++)
        {
            if(grid[j][i]=='1') {
                int idx_p = GETIDX(i, j, w);
                int idx_q = GETIDX(i, j, w);
                adjacent[idx_p][idx_q] = 0;
                LOGD("[o]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);

                //UP
                if(j-1>=0 && grid[j-1][i]=='1'){
                    idx_q = GETIDX(i, j-1, w);                    
                    LOGE("[u]Check (%d, %d) -> (%d, %d)\n", j, i, j-1, i);
                    adjacent[idx_p][idx_q] = 0;
                    LOGD("[u]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);
                }
                //DOWN
                if(j+1<h && grid[j+1][i]=='1'){
                    idx_q = GETIDX(i, j+1, w);
                    adjacent[idx_p][idx_q] = 0;
                    LOGD("[d]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);
                }
                //LEFT
                if(i-1 >= 0 && grid[j][i-1]=='1'){
                    idx_q = GETIDX(i-1, j, w);
                    adjacent[idx_p][idx_q] = 0;
                    LOGD("[L]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);
                }
                //RIGHT
                if(i+1 < w && grid[j][i+1]=='1'){
                    idx_q = GETIDX(i+1, j, w);
                    adjacent[idx_p][idx_q] = 0;
                    LOGD("[R]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);
                }
            }
        }        
    }

    int mark =0;
    for(int j=0; j<h*w;++j)
    {
        for(int i=0; i<h*w; ++i)
        {
            if(adjacent[j][i]>=0) {
                if(mark==0) {
                    mark++;
                }
                adjacent[j][i]=mark;
            }
            if(adjacent[j][i]<0) {
                printf("_");
            } else {
                printf("%d", mark);
            }            
        }
        printf("\n");
    }

    return 0;    
}

void Test_NumIslands()
{
    LOGD("%s\n", __TIME__);
#if 0
    char arr1[] = {'1','1','1','1','0'};
    char arr2[] = {'1','1','0','1','0'};
    char arr3[] = {'1','1','0','0','0'};
    char arr4[] = {'0','0','0','0','0'};
#endif
    char arr1[] = {'1','1','1','0'};
    char arr2[] = {'0','1','0','0'};
    char arr3[] = {'0','0','1','1'};
    char arr4[] = {'0','0','0','1'};
    char n = sizeof(arr1)/sizeof(arr1[0]);
    vector<char> input1(arr1, arr1+n);
    vector<char> input2(arr2, arr2+n);
    vector<char> input3(arr3, arr3+n);
    vector<char> input4(arr4, arr4+n);
    vector<vector<char>> input;
    input.push_back(input1);
    input.push_back(input2);
    input.push_back(input3);
    input.push_back(input4);
    
    int result = numIslands(input);
    LOGD("Ans: %d\n", result);
}