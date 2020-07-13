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

#if 1
    void visit(int i, int j, vector< vector<char> >& grid, bool isFirstCall, int& cnt, int m, int n) {
        if(grid[i][j] == '1') {
            if(isFirstCall) cnt++;
            grid[i][j]='2';
            if(i>0) visit(i-1,j, grid, false, cnt, m, n); 
            if(j>0) visit(i, j-1, grid, false, cnt, m, n); 
            if(i+1<m) visit(i+1,j, grid, false, cnt, m, n); 
            if(j+1<n) visit(i,j+1, grid, false, cnt, m, n);
        }
    }
    int numIslands(vector< vector<char> >& grid) {
        int i = 0, j = 0, m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        int ti, tj;
        int cnt = 0;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(grid[i][j]=='1') 
                    visit(i, j, grid, true, cnt, m, n);
        return cnt;
    }
#endif
#if 0 //Ref solution
void visit(int i, int j, vector< vector<char> >& grid, bool isFirst, int &cnt)
{
    int h = grid.size();
    int w = grid[0].size();
    if(grid[j][i] == '1'){
        if(isFirst) cnt++;
        grid[j][i] == '2';

        //up
        if(j>0) visit(i, j-1, grid, false, cnt);
        //left
        if(i>0) visit(i-1, j, grid, false, cnt);
        //down
        if(j+1 < h) visit(i, j+1, grid, false, cnt);
        //right
        if(i+1 < w)visit(i+1, j, grid, false, cnt);

    }
}

int numIslands(vector< vector<char> >& grid) {
    int count = 0;
    int h = grid.size();
    int w = grid[0].size();
    
    for(int j=0; j<h; ++j)
    {
        for(int i=0; i<w; ++i)
        {
            if(grid[j][i] == '1') {
                visit(i, j, grid, true, count);
            }
        }
    }
    return count;
}
#endif


#if 0
#define GETX(idx,w) (idx%w)
#define GETY(idx,h) (idx/h)
#define GETIDX(xx, yy, width) ((yy)*width+(xx))

int numIslands(vector< vector<char> >& grid) {
    
    int h = grid.size();
    int w = grid[0].size();
    vector<int>ans_rol(w, -1);
    vector< vector<int> > ansMap(h, ans_rol);
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            printf("%c ", grid[i][j]);
            if(grid[i][j]=='1') {
                ansMap[i][j] = 0;
            }
        }
        printf("\n");
    }
    
    LOGD("h: %d, w: %d\n",h, w);

    vector<int>rol(h*w, -1);
    vector< vector<int> > adjacent(h*w, rol);

    for(int j=0; j<h; j++)
    {
        for(int i=0; i<w; i++)
        {
            if(grid[j][i]=='1') {
                int idx_p = GETIDX(i, j, w);
                int idx_q = GETIDX(i, j, w);
                adjacent[idx_p][idx_q] = 1;
                LOGD("[o]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);

                //UP
                if(j-1>=0 && grid[j-1][i]=='1'){
                    idx_q = GETIDX(i, j-1, w);                    
                    LOGE("[u]Check (%d, %d) -> (%d, %d)\n", j, i, j-1, i);
                    adjacent[idx_p][idx_q] = 1;
                    LOGD("[u]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);
                }
                //DOWN
                if(j+1<h && grid[j+1][i]=='1'){
                    idx_q = GETIDX(i, j+1, w);
                    adjacent[idx_p][idx_q] = 1;
                    LOGD("[d]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);
                }
                //LEFT
                if(i-1 >= 0 && grid[j][i-1]=='1'){
                    idx_q = GETIDX(i-1, j, w);
                    adjacent[idx_p][idx_q] = 1;
                    LOGD("[L]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);
                }
                //RIGHT
                if(i+1 < w && grid[j][i+1]=='1'){
                    idx_q = GETIDX(i+1, j, w);
                    adjacent[idx_p][idx_q] = 1;
                    LOGD("[R]Check (%d, %d) -> (%d, %d)\n", j, i, idx_p, idx_q);
                }
            }
        }        
    }

    for(int j=0; j<h*w;++j)
    {
        for(int i=0; i<h*w; ++i)
        {
            if(adjacent[j][i]<0) {
                printf("_");
            } else {
                printf("x");
            }            
        }
        printf("\n");
    }
    
    int blockNum = 0;
    for(int j=0;j<h; ++j) 
    {
        for(int i=0; i<w; ++i)
        {
            
            if(grid[j][i] == '1') {
                int idx_y = GETIDX(i, j, w);
                //find the smallest
                int smallest = blockNum;
                for(int x=0; x<adjacent[0].size(); ++x)
                {
                    if(adjacent[idx_y][x]==1) {
                        int x1 = GETX(x,w);
                        int y1 = GETY(x,h);
                        LOGD("(%d)%d, %d -> (%d)%d, %d, smallest: %d\n", idx_y, i, j, x, x1, y1, smallest);
                        if(ansMap[y1][x1] !=0 && ansMap[y1][x1]<smallest) {
                            smallest =ansMap[y1][x1];
                        }
                        if(smallest == 0) smallest++;                        
                    }
                }
                blockNum = smallest;
                LOGD("Check (%d, %d) S: %d\n", i, j, smallest);
                //update blockNum
                for(int x=0; x<adjacent[0].size(); ++x)
                {
                    if(adjacent[idx_y][x]==1) {
                        int x1 = GETX(x,w);
                        int y1 = GETY(x,h);
                        ansMap[y1][x1] = blockNum;
                    }
                }
            }
        }
    }
    
    LOGE("----------------------------\n");
    for(int j=0;j<h; ++j) 
    {
        for(int i=0; i<w; ++i)
        {
            if(ansMap[j][i]>0){
                printf("%d", ansMap[j][i]);
            }
            else {
                printf("_");
            }
        }
        printf("\n");
    }
    return 0;    
}
#endif

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
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<char> input1(arr1, arr1+n);
    vector<char> input2(arr2, arr2+n);
    vector<char> input3(arr3, arr3+n);
    vector<char> input4(arr4, arr4+n);
    vector< vector<char> > input;
    input.push_back(input1);
    input.push_back(input2);
    input.push_back(input3);
    input.push_back(input4);
    
    int result = numIslands(input);
    LOGD("Ans: %d\n", result);
}