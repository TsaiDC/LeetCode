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
https://leetcode.com/problems/minimum-path-sum/
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes 
the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]

Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return 0;
    }
};

void Test_minPathSum()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {1, 3, 1};
    int arr2[] = {1, 5, 1};
    int arr3[] = {4, 2, 1};
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> input1(arr1, arr1+n1);
    vector<int> input2(arr2, arr2+n2);
    vector<int> input3(arr3, arr3+n3);

    vector<vector<int>> map;
    map.push_back(intput1);
    map.push_back(intput2);
    map.push_back(intput3);

    Solution *solution = new Solution();
    int n = solution->minPathSum(map);
    LOGD("n: %d\n", n);
    delete solution;
}