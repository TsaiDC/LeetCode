//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <queue>

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

int BfsTree(vector< vector<int> >& grid, int x, int y, int level, int* result)
{
//A B C
//D X E
//F G H
    int N = grid.size();
    int ax = x-1, ay = y-1;
    int bx = x,   by = y-1;
    int cx = x+1, cy = y-1;
    int dx = x-1, dy = y;
    int ex = x+1, ey = y;
    int fx = x-1, fy = y+1;
    int gx = x,   gy = y+1;
    int hx = x+1, hy = y+1;
    
    if(level > *result && *result > 0){
        return *result;
    }
    if(level > N*N) {
        return *result;
    }
    
    bool isA = false, isB = false, isC = false, isD = false, isE = false, isF = false, isG = false, isH = false;
    
    grid[y][x] = -1; //Passed

    if(ax >= 0 && ay >= 0 && grid[ay][ax] != 1 && grid[ay][ax] != -1) {
        isA = true;
    }
    if(by >= 0 && grid[by][bx] != 1 && grid[by][bx] != -1) {
        isB = true;
    }
    if(cx < N && cy >= 0 && grid[cy][cx] != 1 && grid[cy][cx] != -1) {
        isC = true;
    }
    if(dx >= 0 && grid[dy][dx] != 1 && grid[dy][dx] != -1) {
        isD = true;
    }
    if(ex < N && grid[ey][ex] != 1 && grid[ey][ex] != -1) {
        isE = true;
    }
    if(fx >= 0 && fy < N && grid[fy][fx] != 1 && grid[fy][fx] != -1) {
        isF = true;
    }
    if(gy < N && grid[gy][gx] != 1 && grid[gy][gx] != -1) {
        isG = true;
    }
    if(hx < N && hy < N && grid[hy][hx] != 1 && grid[hy][hx] != -1) {
        isH = true;
    }
    if(x == N-1 && y == N-1) {
        LOGE("Hit: %d\n", level);
        if(*result < 0) {
            *result = level;
        } 
        else {
            if(*result > level) {
                *result = level;
            }
        }
        grid[y][x] = 0; //Recover
        return level;
    }
    if (!isA && !isB && !isC && !isD && !isE && !isF && !isG && !isH) {
        LOGE("Dead Y: %d, X: %d\n", y, x);
        grid[y][x] = 0; //Recover
        return -1;
    }
    
    //Search Direction
 
    if(isG) {
        LOGD("Node: (y: %d, x :%d) -G-> (y: %d, x :%d)\n", y, x, gy, gx);
        BfsTree(grid, gx, gy, level+1, result);
    }
    if(isH) {
        LOGD("Node: (y: %d, x :%d) -H-> (y: %d, x :%d)\n", y, x, hy, hx);
        BfsTree(grid, hx, hy, level+1, result);
    }
    if(isE) {
        LOGD("Node: (y: %d, x :%d) -E-> (y: %d, x :%d)\n", y, x, ey, ex);
        BfsTree(grid, ex, ey, level+1, result);
    }
    if(isC) {
        LOGD("Node: (y: %d, x :%d) -C-> (y: %d, x :%d)\n", y, x, cy, cx);
        BfsTree(grid, cx, cy, level+1, result);
    }    
    if(isB) {
        LOGD("Node: (y: %d, x :%d) -B-> (y: %d, x :%d)\n", y, x, by, bx);
        BfsTree(grid, bx, by, level+1, result);
    }    
    if(isA) {
        LOGD("Node: (y: %d, x :%d) -A-> (y: %d, x :%d)\n", y, x, ay, ax);
        BfsTree(grid, ax, ay, level+1, result);
    }
    if(isD) {
        LOGD("Node: (y: %d, x :%d) -D-> (y: %d, x :%d)\n", y, x, dy, dx);
        BfsTree(grid, dx, dy, level+1, result);
    }  
    if(isF) {
        LOGD("Node: (y: %d, x :%d) -F-> (y: %d, x :%d)\n", y, x, fy, fx);
        BfsTree(grid, fx, fy, level+1, result);
    }    
    grid[y][x] = 0; //Recover
    return level;
}

int getPathByQueue(vector< vector<int> >& grid) 
{
    int N = grid.size();
    int result = 0;
    int x, y, size;
    queue<int> xPos;
    queue<int> yPos;
    xPos.push(0);
    yPos.push(0);
    while (!xPos.empty())
    {
        size = xPos.size();
        ++result;
        for(int i=0; i<size; ++i)
        {
            x = xPos.front();
            y = yPos.front();
            xPos.pop();
            yPos.pop();                  
            LOGD("%d size: %d,(%d,%d): %d\n", result, size, x, y, grid[y][x]);
            if(x==N-1 && y==N-1) {
                return result;
            }
            
            for(int yy=y-1; yy<y+2; ++yy)
            {
                for(int xx=x-1; xx<x+2; ++xx)
                {
                    if(yy>=0 && yy<N && xx>=0 && xx<N && grid[yy][xx] == 0) {
                        LOGD(" Push(%d,%d) = %d\n", xx, yy, result);
                        xPos.push(xx);
                        yPos.push(yy);
                        grid[yy][xx] = -1; //Counted                    
                    }
                }        
            }            
        }


    }
    
    return -1;
}

int shortestPathBinaryMatrix(vector< vector<int> >& grid) {
    
    int N = grid.size();
    int Result = -1;
    if(N==0){
        return -1;
    }
    if(grid[0][0] != 0 || grid[N-1][N-1] != 0) {
        return -1;
    }
    
    //Display
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            printf("%2d ",grid[i][j]);
        }
        printf("\n");
    }    
//    BfsTree(grid, 0, 0, 1,&Result);
    Result = getPathByQueue(grid);
    LOGD("Result: %d\n", Result); 
    //Display
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            printf("%2d ",grid[i][j]);
        }
        printf("\n");
    }        
    return Result;
}

#if 0
//Ref Solution
public int shortestPathBinaryMatrix(int[][] grid) {
    int N = grid.length;
    if (grid[0][0] != 0 || grid[N-1][N-1] != 0) {
        return -1;
    }
    int len = 0;
    Queue<int[]> q = new LinkedList<>();
    q.add(new int[] {0, 0});
    while (!q.isEmpty()) {
        int size = q.size();
        len++;
        for (int i = 0; i < size; i++) {
            int[] n = q.poll();
            int r = n[0], c = n[1];
            if (r == N-1 && c == N - 1) {
                return len;
            }
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int nr = r + x;
                    int nc = c + y;
                    if (nr >= 0 && nc >= 0 && nr < N && nc < N && grid[nr][nc] == 0) {
                        grid[nr][nc] = 2;
                        q.add(new int[] {nr, nc});
                    }
                }
            }
        }
    }
    return -1;
}
#endif

void Test_shortestPathBinaryMatrix()
{
    LOGD("%s\n", __TIME__);
    int Result;
    vector< vector<int> > grid;
    
#if 0
    int arr1[] = {0,0,0};
    int arr2[] = {0,1,0};
    int arr3[] = {0,1,0};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    vector<int> input1(arr1, arr1+n);
    vector<int> input2(arr2, arr2+n);
    vector<int> input3(arr3, arr3+n);
    
    grid.push_back(input1);
    grid.push_back(input2);
    grid.push_back(input3);
#endif

#if 1
    int arr1[] = {0,1,0,0,1,1,0};
    int arr2[] = {1,0,0,0,0,0,0};
    int arr3[] = {1,0,0,1,1,1,1};
    int arr4[] = {0,1,0,0,0,0,0};
    int arr5[] = {1,0,0,0,0,0,1};
    int arr6[] = {1,0,0,1,0,0,0};
    int arr7[] = {1,0,1,0,0,1,0};    
    int n = sizeof(arr1)/sizeof(arr1[0]);

    vector<int> input1(arr1, arr1+n);
    vector<int> input2(arr2, arr2+n);
    vector<int> input3(arr3, arr3+n);
    vector<int> input4(arr4, arr4+n);
    vector<int> input5(arr5, arr5+n);
    vector<int> input6(arr6, arr6+n);
    vector<int> input7(arr7, arr7+n);
    
    grid.push_back(input1);
    grid.push_back(input2);
    grid.push_back(input3);
    grid.push_back(input4);
    grid.push_back(input5);
    grid.push_back(input6);
    grid.push_back(input7);
#endif

#if 0
    int arr1[] = {0,0,0,0,0,0,0};
    int arr2[] = {1,0,1,1,1,1,0};
    int arr3[] = {1,0,0,0,1,1,0};
    int arr4[] = {1,0,1,0,1,1,0};
    int arr5[] = {1,0,1,0,0,0,0};
    int arr6[] = {1,0,1,1,1,1,0};
    int arr7[] = {1,0,0,0,0,0,0};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    vector<int> input1(arr1, arr1+n);
    vector<int> input2(arr2, arr2+n);
    vector<int> input3(arr3, arr3+n);
    vector<int> input4(arr4, arr4+n);
    vector<int> input5(arr5, arr5+n);
    vector<int> input6(arr6, arr6+n);
    vector<int> input7(arr7, arr7+n);
    
    grid.push_back(input1);
    grid.push_back(input2);
    grid.push_back(input3);
    grid.push_back(input4);
    grid.push_back(input5);
    grid.push_back(input6);
    grid.push_back(input7);
#endif
    Result = shortestPathBinaryMatrix(grid);
    LOGD("Result: %d\n", Result);
    
    LOGD("Done \n");
}