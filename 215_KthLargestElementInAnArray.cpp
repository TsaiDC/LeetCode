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
https://leetcode.com/problems/kth-largest-element-in-an-array/
215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 <= k <= array's length.

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return 0;

        int retVal;
        int *pArray = new int[k];

        for(int i=0; i<k; ++i) {
            pArray[i] = nums[i];
        }

#if 0
        LOGD("I: ");
        for(int i=0; i<nums.size(); ++i) {
            printf("%2d ", nums[i]);
        }
        printf("\n");
        
        LOGD("A: ");
        for(int i=0; i<k; ++i) {
            printf("%2d ", pArray[i]);
        }
        printf("\n");
#endif
        
        int idx = findMinIdx(pArray, k);
        // LOGD("idx: %d\n", idx);
        for(int i=k; i<nums.size(); ++i)
        {
            if(nums[i] >= pArray[idx]) {
                // LOGD("[%d] %d >= [%d] %d\n", i, nums[i], idx, pArray[idx]);                
                pArray[idx] = nums[i];
                idx = findMinIdx(pArray, k);
            }
        }
        
        retVal = pArray[idx];
        delete[] pArray;
        return retVal;
    }

    int findMinIdx(int *pArray, int length)
    {
        int idx = 0;
        for(int i=1; i<length; ++i)
        {
            if(pArray[idx]>=pArray[i]) {
                idx = i;
            }
        }
        return idx;
    }
};

void Test_findKthLargest()
{
    // int arr1[] = {3,2,1,5,6,4};
    // int k = 6;
    int arr1[] = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    // int arr1[] = {-1,2,0};
    // int k = 2;
    // int arr1[] = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    // int k = 20;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> numbs(arr1, arr1+n);
    
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    int ans = solution->findKthLargest(numbs, k);
    LOGD("Ans: %d\n", ans);
    delete solution;
}