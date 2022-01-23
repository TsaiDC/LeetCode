//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
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
https://leetcode.com/problems/shortest-bridge/
934. Shortest Bridge
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. 
There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.
Return the smallest number of 0's you must flip to connect the two islands.


Example 1:
Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 
Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.
*/

/*
Runtime: 36 ms, faster than 23.60% of C++ online submissions for Max Area of Island.
Memory Usage: 24 MB, less than 32.58% of C++ online submissions for Max Area of Island.
*/
class Solution {
private:
    vector<int> direction;
public:
    Solution()
    {        
        direction.push_back(-1);
        direction.push_back(0);
        direction.push_back(1);
        direction.push_back(0);
        direction.push_back(-1);    
    }

    int shortestBridge(vector< vector<int> >& grid) {
        queue< pair<int, int> > Island;
        queue< pair<int, int> > Sea;
        bool isQuit = false;
        pair<int, int> node;
        
        for(int i=0; i<grid.size() && !isQuit; ++i)
        {
            for(int j=0;j<grid[0].size() && !isQuit; ++j)
            {
                if(grid[i][j] == 1) {
                    node = make_pair(i, j);
                    Island.push(node);
                    isQuit = true;
                    break;
                }
            }
        }
        
        while(!Island.empty()) {
            node = Island.front();
            Island.pop();
            int i = node.first;
            int j = node.second;
            grid[i][j] = 2;
            
            for(int x=0; x<direction.size()-1; ++x)
            {
                i = node.first+direction[x];
                j = node.second+direction[x+1];
                if(i>=0 && i<grid.size() &&
                   j>=0 && j<grid[0].size()) {
                   if(grid[i][j] == 1) {
                       pair<int, int> newNode(i, j);
                       Island.push(newNode);
                       grid[i][j] = 2;
                   }
                   else if(grid[i][j] == 0) {
                       pair<int, int> newNode(i, j);
                       Sea.push(newNode);
                   }
                }                   
            }
        }
        

        LOGD("---- Grid\n");
        for(int i=0; i<grid.size(); ++i)
        {
            for(int j=0;j<grid[0].size(); ++j)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        return 0;
    }
};

void Test_shortestBridge()
{
    LOGD("%s\n", __TIME__);

    int arr0[] = {1,1,1,1,1};
    int arr1[] = {1,0,0,0,1};
    int arr2[] = {1,0,1,0,1};
    int arr3[] = {1,0,0,0,1};
    int arr4[] = {1,1,1,1,1};

    int n = sizeof(arr0)/sizeof(arr0[0]);
    vector<int> input0(arr0, arr0+n);
    vector<int> input1(arr1, arr1+n);
    vector<int> input2(arr2, arr2+n);
    vector<int> input3(arr3, arr3+n);
    vector<int> input4(arr4, arr4+n);
    
    vector< vector<int> > grid;
    grid.push_back(input0);
    grid.push_back(input1);
    grid.push_back(input2);
    grid.push_back(input3);
    grid.push_back(input4);

    Solution *solution = new Solution();
    int ans = solution->shortestBridge(grid);
    LOGD("Ans: %d\n", ans);
    delete solution;
    
    LOGD("======================\n");
    for(const int & i : input4)
    {
        LOGD("%d\n", i);
    }
}