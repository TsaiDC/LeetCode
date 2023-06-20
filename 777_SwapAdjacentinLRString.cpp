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

#ifdef _0777_
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
https://leetcode.com/problems/swap-adjacent-in-lr-string/
777. Swap Adjacent in LR String

In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either 
replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". 
Given the starting string start and the ending string end, return True if and only if there exists 
a sequence of moves to transform one string to the other.

Example 1:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
Explanation: We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Example 2:

Input: start = "X", end = "L"
Output: false

Constraints:

1 <= start.length <= 10^4
start.length == end.length
Both start and end will only consist of characters in 'L', 'R', and 'X'.

*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_canTransform()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Referred.
Runtime: 0 ms Beats 100%
Memory: 7.5 MB Beats 37.7%
*/

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size(), i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if (start[i] != end[j]) return false;
            if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
            ++i; ++j;
        }
        while (i < n) {
            if (start[i] != 'X') return false;
            ++i;
        }
        while (j < n) {
            if (end[j] != 'X') return false;
            ++j;
        }
        return true;
    }
};

void Test_GG_canTransform()
{
//    string start = "RXXLRXRXL";
//      string end = "XRLXXRRLX";

    string start = "XXXXXLXXXX";
      string end = "LXXXXXXXXX";
    LOGD("[CPP] %s\n", __TIME__);    
    Solution *solution = new Solution();
    bool ans = solution->canTransform(start, end);
    delete solution;
    LOGD("Ans %d\n", ans);
}

#endif// _CPPVERSION_
#endif//_0777_