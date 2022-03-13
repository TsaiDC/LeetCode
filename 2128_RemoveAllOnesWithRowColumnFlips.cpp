//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define _CPPVERSION_

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
https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/
2128. Remove All Ones With Row and Column Flips

You are given an m x n binary matrix grid.

In one operation, you can choose any row or column and flip each value in that row or column 
(i.e., changing all 0's to 1's, and all 1's to 0's).

Return true if it is possible to remove all 1's from grid using any number of operations or false otherwise.

Example 1:

010    010    000
101 -> 010 -> 000
010    010    000

Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
Output: true
Explanation: One possible way to remove all 1's from grid is to:
- Flip the middle row
- Flip the middle column

Example 2:

Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
Output: false
Explanation: It is impossible to remove all 1's from grid.

Example 3:

Input: grid = [[0]]
Output: true
Explanation: There are no 1's in grid.

*/
#ifdef _CVERSION_
//C
/*

*/
bool removeOnes(int** grid, int gridSize, int* gridColSize){
    return true;
}

void Test_GG_removeOnes()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
//Ref Solution
class Solution {    
public:
    bool removeOnes(vector<vector<int>>& matrix) {
        int rSize = matrix.size();
        int cSize = matrix[0].size();

        for (int r = 1; r < rSize; r++) {
            bool isFlip = matrix[r][0] != matrix[0][0];
            for (int c = 1; c < cSize; c++) {
                if ((isFlip && matrix[r][c] == matrix[0][c]) || (!isFlip && matrix[r][c] != matrix[0][c])) {
                    return false;
                }
            }
        }
        return true;

    }
};

void Test_GG_removeOnes()
{
    LOGD("[CPP] %s\n", __TIME__);    
    Solution *solution = new Solution();
    delete solution;
}

#endif //_CPPVERSION_