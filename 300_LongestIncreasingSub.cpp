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
        return LIS(nums);
        //return longestIncreasingSubsequence(nums);
    }

    // Time: O(n^n)
    // Space: O(nO
    // Myself solution
    int LIS(vector<int>& nums)
    {
        if(nums.empty())
            return 0;

        vector<int> stack(nums.size(), 0);
        int max = 0;

        for(int i=1; i<nums.size(); ++i)
        {
            max = 0;
            for(int j=i-1; j>=0; --j)
            {
                if(nums[i]>nums[j] && stack[j]>=max) {
                    max = stack[j];
                    stack[i] = max+1;
                }
            }
        }

        max = 0;
        for(int i=0; i<stack.size(); ++i)
        {
            if(stack[i]>=max) {
                max = stack[i];
            }
        }

        return max+1;
    }

    //
    // Time: O(nlongn)
    // Space: O(n)
    // Ref:
    // https://segmentfault.com/a/1190000003819886
    //
    //Runtime: 4 ms, faster than 98.43% of C++ online submissions for Longest Increasing Subsequence.
    //Memory Usage: 7.8 MB, less than 74.17% of C++ online submissions for Longest Increasing Subsequence.
    //
    int longestIncreasingSubsequence(vector<int>& nums)
    {
        if(nums.empty()) return 0;

        int len = 0;
        vector<int> tails(nums.size(), 0);        
        tails[0] = nums[0];
        
        for(int i=1; i<nums.size(); ++i)
        {
            printf("%2d+ ", i); for(int j=0; j<tails.size(); j++){printf("%2d ", tails[j]);} printf("\n");
            if(nums[i] < tails[0]){
                tails[0] = nums[i];
                LOGD("Replace 0: %d\n", nums[i]);
            }
            else if(nums[i] > tails[len]){
                tails[++len] = nums[i];
                LOGD("Replace %d: %d\n", len, nums[i]);
            }
            else {
                int idx = binarySearch(tails, 0, len, nums[i]);
                tails[idx] = nums[i];
                LOGD("Replace %d: %d\n", idx, nums[i]);
            }
            printf("%2d- ", i); for(int j=0; j<tails.size(); j++){printf("%2d ", tails[j]);} printf("\n\n");
        }
        return len+1;
    }
    
    int binarySearch(vector<int>& tails, int min, int max, int target)
    {
        while(min<=max) {
            int mid = min + (max-min)/2;
            if(tails[mid] == target) {
                return mid;
            }
            else if(tails[mid]<target) {
                min = mid+1;
            }
            else if(tails[mid]>target) {
                max = mid-1;
            }
        }
        return min;
    }
};

void Test_lengthOfLIS()
{
    LOGD("%s\n", __TIME__);

//    int arr1[] = {10,9,2,5,3,7,101,18};
//    int arr1[] = {1,3,6,7,9,4,10,5,6};
//    int arr1[] = {2,2};
    int arr1[] = {10,9,2,5,3,4};
    int n = sizeof(arr1)/sizeof(arr1[0]);       
    vector<int> numbs(arr1, arr1+n);
    LOGD("Input: ");
    for(int i=0; i<n; i++)
    {
        printf("%2d ",numbs[i]);
    }
    printf("\n");
    
    Solution *solution = new Solution();
    int ans = solution->lengthOfLIS(numbs);
//    LOGD("Ans: %d\n", ans);
    ans = solution->LIS(numbs);
    LOGD("Ans: %d\n", ans);
    ans = solution->longestIncreasingSubsequence(numbs);
    LOGD("Ans: %d\n", ans);    
    delete solution;
}