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
https://leetcode.com/problems/asteroid-collision/
370. Range Addition

Assume you have an array of length n initialized with all 0's and are given k update operations.
Each operation is represented as a triplet:[startIndex, endIndex, inc] which increments eah element
of subarray A[startIndex ... endIndex](startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Input: length = 5, updates = [[1, 3, 2], [2, 4, 3], [0, 2. -2]]
Output: [-2, 0, 3, 5, 3]

0 | 1 | 2 | 3 | 4 | 
--+---+---+---+---+
0 | 0 | 0 | 0 | 0 |
--+---+---+---+---+
  |+2 |+2 |+2 |   |
--+---+---+---+---+
  |   |+3 |+3 |+3 |
--+---+---+---+---+
-2|-2 |-2 |   |   |
--+---+---+---+---+
-2| 0 | 3 | 5 | 3 |  <-- ans
*/


#ifdef _CVERSION_
//C
/*

*/

void Test_AM_TEST()
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
    vector<int> getModifiedArray(int length, vector< vector<int>> updates) {
        
    }
};

void Test_AM_getModifiedArray()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;
}

#endif// _CPPVERSION_