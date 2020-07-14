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

/*
https://leetcode.com/problems/longest-increasing-subsequence/
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stack;
        for(int i=0; i<nums.size(); ++i)
        {
            if(stack.empty()) {
                stack.push_back(nums[i]);
            }
            else {
                while(!stack.empty() && nums[i]<=stack.back()) {
                    stack.pop_back();
                }
                stack.push_back(nums[i]);
            }
        }
        return stack.size();
    }
};

void Test_lengthOfLIS()
{
    LOGD("%s\n", __TIME__);

//    int arr1[] = {10,9,2,5,3,7,101,18};
    int arr1[] = {1,3,6,7,9,4,10,5,6};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> numbs(arr1, arr1+n);
    Solution *solution = new Solution();
    int ans = solution->lengthOfLIS(numbs);
    LOGD("Ans: %d\n", ans);
    delete solution;
}