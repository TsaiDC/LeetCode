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
https://leetcode.com/problems/search-insert-position/
35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
             
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target == nums.front() ||
           target < nums.front())return 0;
        if(target == nums.back())return nums.size()-1;
        if(target > nums.back())return nums.size();
           
        int start = 0;
        int end = nums.size()-1;        
        int mid = 0;
        
        while(1)
        {
            mid = (start+end)/2;
            if(start == mid) { ++mid; break;}
            if(nums[mid] == target) break;
            if(nums[mid] > target) end = mid;
            else start = mid;
        }
        
        return mid;
    }
};

void Test_searchInsert()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {1,3,5,6};
    int k = 6;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> num1(arr1, arr1+n);
    
    Solution *solution = new Solution();
    int ans = solution->searchInsert(num1, k);
    LOGD("n: %d\n", ans);
    delete solution;
}