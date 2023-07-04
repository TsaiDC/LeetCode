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

#ifdef _0329_
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
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
329. Longest Increasing Path in a Matrix

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 
Example 1:

[9,9,4],
[6,6,8],
[2,1,1]

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:

[3,4,5],
[3,2,6],
[2,2,1]
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:

Input: matrix = [[1]]
Output: 1

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 2^31 - 1
*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_longestIncreasingPath()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Self, 20230704
Runtime: 111 ms Beats 18.52%
Memory: 22.2 MB Beats 19.28%
*/

typedef struct node {
    int val;
    int x;
    int y;    
}node_t;

bool compare(node_t a, node_t b) {
    return a.val < b.val;
}
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        vector<node_t> nodeVec;
        vector<vector<int>> matrixCount;
        
        for(int i=0; i<matrix.size(); ++i) {
            for(int j=0; j<matrix[0].size(); ++j) {
                node_t n;
                n.val = matrix[i][j];
                n.x =j;
                n.y =i;
                nodeVec.push_back(n);
            }
            
            //Init count map
            vector<int> v(matrix[i].size(), 0);
            matrixCount.push_back(v);
        }
        
        std::sort(nodeVec.begin(), nodeVec.end(), compare);
        
        for(auto n : nodeVec) {
//            LOGD("Sorted V: %d\n", n.val);
            int count = getTheSmallest(n, matrix, matrixCount);
            if(count > ret) ret = count;
        }
        
        return ret;
    }
    
    int getTheSmallest(node_t& n, vector<vector<int>>& matrix, vector<vector<int>>& matrixCount) {
        int offset_count = 4;
        int offset[][2] = {         {0, -1},
                           {-1, 0},          {1,  0},
                                    {0,  1},
                           };

        int x, y, maxCount= 0;
        for(int i=0; i<offset_count; ++i) {
            x = offset[i][0] + n.x;
            y = offset[i][1] + n.y;
//            LOGD("Node: (%d, %d) -> (%d, %d)\n", n.y, n.x, y, x);

            if(x<0 || x>=matrix[0].size()) continue;
            if(y<0 || y>=matrix.size()) continue;
            if(matrix[y][x] >= n.val) continue;
            if (matrixCount[y][x] > maxCount) {
                maxCount = matrixCount[y][x];
            }

        }
        matrixCount[n.y][n.x] = maxCount + 1;        
/*
        LOGD("(%d, %d)\n", n.y, n.x);
        for(auto r : matrixCount) {
            for(auto a : r) {
                printf("%d ", a);
            }
            printf("\n");
        }
*/
        return maxCount + 1;
    }
};

void Test_GG_longestIncreasingPath()
{
    //[[9,9,4],[6,6,8],[2,1,1]]
    vector<int> L1{9,9,4};
    vector<int> L2{6,6,8};
    vector<int> L3{2,1,1};
    vector<vector<int>> input{L1, L2, L3};

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    int ret = solution->longestIncreasingPath(input);
    LOGD("Ret: %d\n", ret);
    delete solution;
}

#endif// _CPPVERSION_
#endif//_0329_