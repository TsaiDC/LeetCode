//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
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
https://leetcode.com/problems/sqrtx/
69. Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
             
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return x;
        int start = 0;
        int end = x;
        int mid;        
        
        while(1)
        {
            mid = (start+end)/2;
            if(mid == start) break;
            if(mid == (x/mid)) break;
            else if(mid > x/mid) end = mid;
            else start = mid;
        }        
        return mid;
    }
};

void Test_mySqrt()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    int n = solution->mySqrt(4);
    LOGD("n: %d\n", n);
    delete solution;
}