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
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
int getIdx(vector<int>& nums, int start, int end, int target)
{
    int left, right, mid;
    left = start;
    right = end;
    mid = (right + left)/2;
    
    while ((right - left) > 1)
    {
        if(nums[mid] == target) {
            //First idx
            LOGD("Hit, IDX: %d\n", mid);
            return mid;            
        }
        else if (nums[mid]<target) {
            left = mid;
            mid = (right+left)/2;
        }
        else {
            right = mid;
            mid = (right+left)/2;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {

    vector<int> result;
    result.push_back(-1);
    result.push_back(-1);

    int idx, idx2;
    idx = getIdx(nums, 0, nums.size()-1, target);
    idx2 = idx;
    LOGD("left: %d\n", idx);
    
    //Get Left
    while(idx != -1)
    {
        result[0] = idx;
        idx = getIdx(nums, 0, idx-1, target);
    }
    
    idx = idx2;
    //Get Right
    while(idx != -1)
    {
        result[1] = idx;
        idx = getIdx(nums, idx+1, nums.size()-1, target);
    }

    return result;
}
void Test_searchRange()
{
    LOGD("%s\n", __TIME__);
    int arr[] = {5,7,7,8,8,10};
    int target = 8;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Target: %d, Input: ", target);
    for(int i=0; i<n; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    vector<int> input(arr, arr+n);
    searchRange(input, target);
    LOGD("Done \n");
}