//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <climits>

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
https://leetcode.com/problems/search-in-rotated-sorted-array/
33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

int search(vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return -1;
    }

    int minIdx = 0;
    int min = nums[0];

    //1 Find the min idx
    for(int i=1; i<nums.size(); ++i)
    {
        if(nums[i]<min) {
            min = nums[i];
            minIdx = i;
        }
    }
    LOGD("Idx: %d, Min: %d\n", minIdx, nums[minIdx]);
    
    //2. Hit
    if (min == target) {
        return minIdx;
    }

    //3. Found
    int middle, i, j, idx;
    i = minIdx;
    j = nums.size() - 1 + minIdx;
    middle = (j-i)/2 + minIdx;

    while (middle != i && middle !=j)
    {
        idx = middle > (nums.size() - 1) ? (middle - nums.size()) : middle + minIdx;
        LOGD("i: %d, j: %d, middle: %d, idx: %d\n", i, j, middle, idx);
        if(nums[idx] == target) {
            LOGD("Found, idx: %d\n", idx);
            return idx;
        }
        else if(nums[idx] > target) {
            //Update Middle to left
            j = middle;
            middle = (middle - i) / 2;
        }
        else {
            //Update Middle to right
            i = middle;
            middle = ((j- middle) / 2 ) + i;
        }        
        LOGD("i: %d, j: %d, middle: %d\n", i, j, middle);
    }
    
    idx = i > (nums.size() - 1) ? (i - nums.size()) : i + minIdx;
    LOGD("i: %d, j: %d, middle: %d, idx: %d\n", i, j, middle, idx);
    if(nums[idx] == target) {
        LOGD("Found, idx: %d\n", idx);
        return idx;
    }
    
    idx = j > (nums.size() - 1) ? (j - nums.size()) : j + minIdx;
    LOGD("i: %d, j: %d, middle: %d, idx: %d\n", i, j, middle, idx);
    if(nums[idx] == target) {
        LOGD("Found, idx: %d\n", idx);
        return idx;
    }
    
    LOGE ("Can't be found\n");
    return -1;
}

int search2(vector<int>& nums, int target) {
    if(nums.size() == 0){
        return -1;
    }
    
    int low = 0;
    int high = nums.size()-1;
    
    
    while(low+1 < high){ 
        int mid = low + (high-low)/2; // avoid overflow 
        LOGD("%d, %d, Mid: %d\n", low, high, mid);
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > nums[low]){ // left side of pivot
            if(target >= nums[low] && target <= nums[mid]){ // go to left
                high = mid;
            }else{ // go to right
                low = mid;
            }
        }else{// right side of the pivot
            if(target >= nums[mid] &&  target <= nums[high]){ // go to right
                low = mid;
            }else{// go to left
                high = mid;
            }
        }
    }
    
    if(nums[low] == target){
        return low;
    }else if(nums[high] == target){
        return high;
    }
   
    return -1;
    
}

int search3(vector<int>& nums, int target) {
    int start, end , mid;
    start = 0;
    end = nums.size()-1;
    
    while(start < end) 
    {        
        mid = start + (end-start)/2;
/*
        //增加部分
        int tmp = (nums[mid] < nums[0]) == (target < nums[0])
               ? nums[mid]   如果在同一部，?用原值 
               : target < nums[0] ? INT_MIN : INT_MAX; 否?根据情?引入-inf或inf
*/
        int tmp;
        if((nums[mid] < nums[0]) == (target < nums[0])){
            tmp = nums[mid];
        }
        else {
            if(target < nums[0]) {
                tmp = INT_MIN;
            }
            else {
                tmp = INT_MAX;
            }
        }

        LOGD("%d <-> %d <-> %d\n", start, mid, end);

        if(tmp<target) {
            start = mid+1;
        }
        else if(tmp>target) {
            end = mid;
        }
        else {
            return mid;
        }
    }
    return nums[start] == target ? start : -1;
}

void Test_SearchInRotatedSortedArray()
{
    LOGD("%s\n", __TIME__);
//    int arr[] = {4,5,6,7,0,1,2};
//    int arr[] = {6,7,0,1,2, 4, 5};
//    int arr[] = {0, 1, 2, 4, 5, 6, 7};
    int arr[] = {1};
    int target = 1;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Target: %d, Input: ", target);
    for(int i=0; i<n; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    vector<int> input(arr, arr+n);
//    search(input, target);
//    int idx = search2(input, target);
    int idx = search3(input, target);
    LOGD("Ans: %d\n", idx);

    
    LOGD("Done \n");
}