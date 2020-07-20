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

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#define LOGE(...)
#endif

/*
https://leetcode.com/problems/find-peak-element/
162. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ¡Ú nums[i+1], 
find a peak element and return its index.

The array may contain multiple peaks, 
in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -¡Û.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Follow up: Your solution should be in logarithmic complexity.
*/

#include<climits>

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }

    int helper(vector<int>& num,int start,int end){
        if(start == end){
            return start;
        }else if(start+1 == end){
            if(num[start] > num[end]) return start;
            return end;
        }else{
            
            int m = (start+end)/2;
            
            if(num[m] > num[m-1] && num[m] > num[m+1]){

                return m;

            }else if(num[m-1] > num[m] && num[m] > num[m+1]){

                return helper(num,start,m-1);

            }else{

                return helper(num,m+1,end);

            }            
        }
    }
    
    int findPeakElement1(vector<int>& nums) {
        
        if(nums.size() == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }
        
        int left;
        int right;
        for(int i=1; i<nums.size()-1; i++)
        {
            if(nums[i] - nums[i-1] > 0){ left = 1;}
            if(nums[i] - nums[i-1] == 0){ left = 0;}
            if(nums[i] - nums[i-1] < 0){ left = -1;}
            
            if(nums[i+1] - nums[i] > 0){ right = 1;}
            if(nums[i+1] - nums[i] == 0){ right = 0;}
            if(nums[i+1] - nums[i] < 0){ right = -1;}
            
            if(left == 1 && right == -1){
                return i;
            }
        }
        
        int idx = -1;
        int val = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] >= val) {
                val = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};

void Test_findPeakElement()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {-31,-59,-94,13,-44,54,83,-68,40,72,0,29,-16,88,27,-23,59,11,15,37,-11,-2,-37,-21,-81,-32,-46,93,-98,75,24,1,70,-49,-15,-57,-79,-41,64,-52,97,-92,63,3,-42,-10,-6,18,-71,21};
    int n = sizeof(arr1)/sizeof(arr1[0]);       
    vector<int> numbs(arr1, arr1+n);
    
    Solution *solution = new Solution();
    int ans = solution->findPeakElement(numbs);
    LOGD("Ans: %d\n", ans);    
    delete solution;
}