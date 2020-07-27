//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <queue>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

/*
https://leetcode.com/problems/single-number-ii/
137. Single Number II

Given a non-empty array of integers, every element appears three times except for one, 
which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

*/

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#define LOGE(...)
#endif

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return 0;
    }
};

void Test_singleNumber()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {0,1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> num1(arr1, arr1+n);

    Solution *solution = new Solution();
    int ans = solution->singleNumber(num1);
    LOGD("Ans: %d\n", ans);   
    delete solution;
}