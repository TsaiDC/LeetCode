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
        return singleNumber2(nums);
    }

    //Ref:
    //
    //Runtime: 32 ms, faster than 5.77% of C++ online submissions for Single Number II.
    //Memory Usage: 9.7 MB, less than 57.94% of C++ online submissions for Single Number II.
    int singleNumber1(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int sum = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(((nums[j] >> i) & 1) == 1) {
                    sum++;
                    sum %= 3;
                    LOGE("nums[%d]=(%d) >> %d Sum: %d\n", j, nums[j], i, sum);
                }
                else {
                    LOGD("nums[%d]=(%d) >> %d Sum: %d\n", j, nums[j], i, sum);
                }
            }

            if(sum != 0) {
                ans |= 0x1 << i;
                LOGD("Sum: 0x%x, ANS: 0x%x\n", sum, ans);
            }
        }
        return ans;
    }

    //Ref:
    //Runtime: 20 ms, faster than 47.59% of C++ online submissions for Single Number II.
    //Memory Usage: 9.5 MB, less than 84.13% of C++ online submissions for Single Number II.
    int singleNumber2(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask = 0;

        for (int i : nums) {
            x2 ^= x1 & i;
            LOGD("1. x1: 0x%x(%d) x2: 0x%x(%d), i: 0x%x(%d)\n", x1, x1, x2, x2, i, i);
            x1 ^= i;
            LOGD("2. x1: 0x%x(%d) x2: 0x%x(%d), i: 0x%x(%d)\n", x1, x1, x2, x2, i, i);
            mask = ~(x1 & x2);
            LOGD("3. x1: 0x%x(%d) x2: 0x%x(%d), i: 0x%x(%d), mask: 0x%x\n", x1, x1, x2, x2, i, i, mask);
            x2 &= mask;
            x1 &= mask;
            LOGD("4. x1: 0x%x(%d) x2: 0x%x(%d), i: 0x%x(%d), mask: 0x%x\n", x1, x1, x2, x2, i, i, mask);
            LOGE("\n");
        }

        return x1;  // Since p = 1, in binary form p = '01', then p1 = 1, so we should return x1.
                    // If p = 2, in binary form p = '10', then p2 = 1, and we should return x2.
                    // Or alternatively we can simply return (x1 | x2).
    }
};

void Test_singleNumber()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {0,1,0,1,0,1,99};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> num1(arr1, arr1+n);

    Solution *solution = new Solution();
    int ans = solution->singleNumber(num1);
    LOGD("Ans: %d\n", ans);
    delete solution;
}
