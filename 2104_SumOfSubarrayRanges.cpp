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
https://leetcode.com/problems/sum-of-subarray-ranges/
2104. Sum of Subarray Ranges

You are given an integer array nums. The range of a subarray of nums is the difference
 between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

Example 2:
Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.

Constraints:

1 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9

*/


#ifdef _CVERSION_
//C
/*

*/

long long subArrayRanges(int* nums, int numsSize){

}

void Test_AM_subArrayRanges()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Ref Solution.
Runtime: 48 ms, faster than 57.40% of C++ online submissions for Sum of Subarray Ranges.
Memory Usage: 11.4 MB, less than 24.40% of C++ online submissions for Sum of Subarray Ranges.
*/
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ret = 0;
        stack<int>Stack;
  
        vector<int>nextSmaller(n,n);
        for(int i=0; i<n; ++i) {
            while(!Stack.empty() && nums[Stack.top()] >= nums[i])
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        
        while(!Stack.empty()) Stack.pop();
        vector<int>preSmaller(n, -1);
        for(int i=n-1; i>=0; --i) {
            while(!Stack.empty() && nums[Stack.top()] > nums[i])
            {
                preSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        
        while(!Stack.empty()) Stack.pop();
        vector<int>nextGreater(n, n);
        for(int i=0; i<n; ++i) {
            while(!Stack.empty() && nums[Stack.top()] <= nums[i])
            {
                nextGreater[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }

        while(!Stack.empty()) Stack.pop();
        vector<int>preGreater(n, -1);
        for(int i=n-1; i>=0; --i) {
            while(!Stack.empty() && nums[Stack.top()] < nums[i])
            {
                preGreater[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }        
#if 0
        printf("NextSmaller: ");
        for(int i: nextSmaller) {
            printf(" %d,", i);
        }
        printf("\n");
        
        printf("PreSmaller: ");
        for(int i: preSmaller) {
            printf(" %d,", i);
        }
        printf("\n");

        printf("nextGreater: ");
        for(int i: nextGreater) {
            printf(" %d,", i);
        }
        printf("\n");
        
        printf("preGreater: ");
        for(int i: preGreater) {
            printf(" %d,", i);
        }
        printf("\n");      
#endif
        for(int i=0; i<n; ++i) {
            int l = preGreater[i];
            int r = nextGreater[i];
            ret += (long long)nums[i]*(i-l)*(r-i);
        }
        for(int i=0; i<n; ++i) {
            int l = preSmaller[i];
            int r = nextSmaller[i];
            ret -= (long long)nums[i]*(i-l)*(r-i);
        }

        return ret;
    }
};

void Test_AM_subArrayRanges()
{
    LOGD("[CPP] %s\n", __TIME__);
//    int arr1[] = {1,2,3};
    int arr1[] = {1,3,3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n1);
    Solution *solution = new Solution();
    long long ans = solution->subArrayRanges(input1);
    delete solution;
    LOGD("And: %lld\n", ans);
}

#endif// _CPPVERSION_