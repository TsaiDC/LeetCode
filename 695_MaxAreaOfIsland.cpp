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
https://leetcode.com/problems/max-area-of-island/
695. Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are 
surrounded by water.

The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0. 

Example:
Input: grid = [
[0,0,1,0,0,0,0,1,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,1,1,0,1,0,0,0,0,0,0,0,0],
[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0]]

Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
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

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int areaCount = 0;
        int maxArea = 0;
        pair<int, int> node;
        queue< pair<int, int> > path;
#if 0
        for(int i=0; i<grid.size(); ++i)
        {
            for(int j=0; j<grid[0].size(); ++j)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        LOGD("\n");
#endif
        for(int i=0; i<grid.size(); ++i)
        {
            for(int j=0; j<grid[0].size(); ++j)
            {
                if(grid[i][j] == 1){
                    areaCount = 1;
                    node = make_pair(i, j);
                    grid[i][j] = 2;
                    path.push(node);
                    while(!path.empty()){
                        node = path.front();
                        path.pop();
                        
                        for(int x=0; x<4; ++x)
                        {
                            int node_x = node.first + direction[x];
                            int node_y = node.second + direction[x+1];

                            if(node_x >= 0 && node_y >= 0 && 
                               node_x < grid.size() && node_y < grid[0].size() && 
                               grid[node_x][node_y] == 1) {
                                pair<int, int> new_node = make_pair(node_x, node_y);
                                grid[node_x][node_y] = 2;
                                path.push(new_node);                                
                                ++areaCount;
                            }
                        }
                    }
                    maxArea = areaCount > maxArea ? areaCount:maxArea;
                }
            }
        }
#if 0
        for(int i=0; i<grid.size(); ++i)
        {
            for(int j=0; j<grid[0].size(); ++j)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
#endif
        return maxArea;
    }
};

void Test_maxAreaOfIsland()
{
    LOGD("%s\n", __TIME__);
#if 0
    int arr0[] = {0,0,1,0,0,0,0,1,0,0,0,0,0};
    int arr1[] = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    int arr2[] = {0,1,1,0,1,0,0,0,0,0,0,0,0};
    int arr3[] = {0,1,0,0,1,1,0,0,1,0,1,0,0};
    int arr4[] = {0,1,0,0,1,1,0,0,1,1,1,0,0};
    int arr5[] = {0,0,0,0,0,0,0,0,0,0,1,0,0};
    int arr6[] = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    int arr7[] = {0,0,0,0,0,0,0,1,1,0,0,0,0};
    int n = sizeof(arr0)/sizeof(arr0[0]);
    vector<int> input0(arr0, arr0+n);
    vector<int> input1(arr1, arr1+n);
    vector<int> input2(arr2, arr2+n);
    vector<int> input3(arr3, arr3+n);
    vector<int> input4(arr4, arr4+n);
    vector<int> input5(arr5, arr5+n);
    vector<int> input6(arr6, arr6+n);
    vector<int> input7(arr7, arr7+n);
    
    vector< vector<int> > grid;
    grid.push_back(input0);
    grid.push_back(input1);
    grid.push_back(input2);
    grid.push_back(input3);
    grid.push_back(input4);
    grid.push_back(input5);
    grid.push_back(input6);
    grid.push_back(input7);
#endif

#if 1
    int arr0[] = {1,1};
    int arr1[] = {1,0};

    int n = sizeof(arr0)/sizeof(arr0[0]);
    vector<int> input0(arr0, arr0+n);
    vector<int> input1(arr1, arr1+n);
    
    vector< vector<int> > grid;
    grid.push_back(input0);
    grid.push_back(input1);

#endif
    Solution *solution = new Solution();
    int ans = solution->maxAreaOfIsland(grid);
    LOGD("Ans %d\n", ans);
    delete solution;
}