//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <climits>

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
https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
302. Smallest Rectangle Enclosing Black Pixels

You are given an m x n binary matrix image where 0 represents a white pixel and 1 represents a black pixel.

The black pixels are connected (i.e., there is only one black region). 
Pixels are connected horizontally and vertically.

Given two integers x and y that represents the location of one of the black pixels, 
return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

You must write an algorithm with less than O(mn) runtime complexity

Example 1:
["0","0","1","0"]
["0","1","1","0"]
["0","1","0","0"]


Input: image = [["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]], x = 0, y = 2
Output: 6

Example 2:

Input: image = [["1"]], x = 0, y = 0
Output: 1


Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 100
image[i][j] is either '0' or '1'.
1 <= x < m
1 <= y < n
image[x][y] == '1'.
The black pixels in the image only form one component.
*/
#ifdef _CVERSION_
//C
/*

*/
int minArea(char** image, int imageSize, int* imageColSize, int x, int y){

}

void Test_GG_minArea()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        
    }
};

void Test_GG_minArea()
{
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;    
}

#endif //_CPPVERSION_