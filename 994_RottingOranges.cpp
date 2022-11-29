//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <algorithm>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#define _CPPVERSION_

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
// Unorder Map:
// https://shengyu7697.github.io/std-unordered_map/
// https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/
//

/*
https://leetcode.com/problems/rotting-oranges/
994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because 
rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/


#ifdef _CVERSION_
//C
/*

*/
int orangesRotting(int** grid, int gridSize, int* gridColSize){

}

void Test_AM_orangesRotting()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Self,
Runtime
25 ms
Beats
10.41%

BFS
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>record;
        for(int i=0; i<m ; ++i) {
            record.push_back(vector<int>(n, 0));
        }
        queue<pair<int,int>>Q1;
        queue<pair<int,int>>Q2;
        int min = 0;
        int OneCount = 0;
        int OneGet = 0;
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 2) {
                    Q1.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    OneCount++;
                }
            }
        }
        
        do {
            while(!Q1.empty()) {
                int i = Q1.front().first;
                int j = Q1.front().second;
                LOGD("%d, %d\n", i, j);
                Q1.pop();
                //Up
                if(i-1 >= 0 && grid[i-1][j] == 1 && record[i-1][j] != 1) {
                    Q2.push(std::make_pair(i-1, j));
                    OneGet++;
                    record[i-1][j] = 1;
                }

                //Down
                if(i+1 < m && grid[i+1][j] == 1 && record[i+1][j] != 1) {
                    Q2.push(std::make_pair(i+1, j));
                    OneGet++;
                    record[i+1][j] = 1;
                }

                //Left
                if(j-1 >= 0 && grid[i][j-1] == 1 && record[i][j-1] != 1) {
                    Q2.push(std::make_pair(i, j-1));
                    OneGet++;
                    record[i][j-1] = 1;
                }
                //Right
                if(j+1 < n && grid[i][j+1] == 1 && record[i][j+1] != 1) {
                    Q2.push(std::make_pair(i, j+1));
                    OneGet++;
                    record[i][j+1] = 1;
                }
            }
            LOGD("------ Q2: %d\n", Q2.size());
            if(!Q2.empty()) min++;
            while(!Q2.empty()) {
                Q1.push(Q2.front());
                Q2.pop();
            }
        }while(!Q1.empty());
        
        return OneGet == OneCount ? min : -1;
    }
};

void Test_AM_orangesRotting()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);
    int length = 3;
    int arr1[] = {2, 1, 1};
    int arr2[] = {1, 1, 0};
    int arr3[] = {0, 1, 1};

    vector<vector<int>> input;
    input.push_back(vector<int>(arr1, arr1+length));
    input.push_back(vector<int>(arr2, arr2+length));
    input.push_back(vector<int>(arr3, arr3+length));    

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    int ans = solution->orangesRotting(input);
    delete solution;
    LOGD("Ans: %d\n", ans);
}

#endif// _CPPVERSION_