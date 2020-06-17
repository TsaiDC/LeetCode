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
https://leetcode.com/problems/house-robber/
198. House Robber

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that 
adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.
 

Example 1:

Input: nums = [1,2,3,1]

Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 400
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        int idxa = 0, idxb = 0;
        int retval = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            idxa = i-2;
            idxb = i-3;
            LOGD("----->  i: %d, a: %d, b: %d\n", i, idxa, idxb);
            if(idxa < 0 && idxb < 0) {
                dp.push_back(nums[i]);
                LOGD("I: %d, %d\n", i, nums[i]);
                continue;
            }
            else if(idxa >= 0 && idxb < 0) {
                dp.push_back(nums[i] + dp[idxa]);
                LOGD("I: %d, %d\n", i, nums[i] + dp[idxa]);
            }
            else if(idxa < 0 && idxb >= 0) {
                dp.push_back(nums[i] + dp[idxb]);
                LOGD("I: %d, %d\n", i, nums[i] + dp[idxb]);
            }
            else if(idxa >= 0 && idxb >= 0) {
                dp.push_back(nums[i] + (dp[idxa] > dp[idxb] ? dp[idxa] : dp[idxb]));
                LOGD("I: %d, %d\n", i, (nums[i] + (dp[idxa] > dp[idxb] ? dp[idxa] : dp[idxb])));
            }
        }
#if 0
        for(int i=0; i<dp.size(); ++i)
        {
            LOGD("%d\n", dp[i]);
        }
#endif
        int i = dp.size();
        if(i>1){
            retval = dp[i-1] > dp[i-2] ? dp[i-1] : dp[i-2];
        }
        else if (i==1) {
            retval = dp[i-1];
        }
        
        return retval;
    }
};

void Test_rob()
{
    LOGD("%s\n", __TIME__);
//    int arr1[] = {2, 7, 9, 3, 1};
    int arr1[] = {1, 1};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n);
    Solution *solution = new Solution();    
    int ret = solution->rob(input1);
    LOGD("Ans: %d\n", ret);
    delete solution;
}