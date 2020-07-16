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
        int idx = 0;
        int start = 0;
        int end = nums.size()-1;
#if 0
        LOGD("K: %2d\n", k);
        LOGD("I: %2d, ", idx);
        for(int i=0; i<nums.size(); ++i)
        {
            if(i%10==0) printf(" | ");
            printf("%d ", nums[i]);
        }
        printf("\n");
#endif
        while(1) {
            LOGD("Start: %d, End: %d\n", start, end);
            idx = getIdxAndSort(nums, start, end);
#if 0
            LOGD("O: %2d, ", idx);
            for(int i=0; i<nums.size(); ++i)
            {
                printf("%d ", nums[i]);
            }
            printf("\n");
#endif
            if(idx == k-1) {
                break;
            }
            
            if(idx<k-1) {
                start = idx+1;
            }
            else if(idx>k-1) {
                end = idx-1;
            }
        }

        return nums[idx];
    }
    
    int getIdxAndSort(vector<int>& nums, int start, int end)
    {
        int i = start;
        int j = end-1;
        int p = end;
        int tmp;
        LOGD("P[%d]: %d\n", p, nums[p]);

        while(i<j )
        {
            while(nums[i]>nums[p] && i<j)++i;
            while(nums[j]<nums[p] && j>i)--j;
            LOGD("(%d, %d)\n", i, j);
            if(i!=j) {
                LOGD("Swap i: %d, j: %d\n", i, j);
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                ++i;
                --j;
//                for(int x=0;x<nums.size(); ++x) { printf("%d ", nums[x]); } printf("(%d, %d)\n", i, j);
            }
        }
        
        if(nums[i]>nums[p]) ++i;
        LOGD("Swap i: %d, p: %d\n", i, p);
        tmp = nums[i];
        nums[i] = nums[p];
        nums[p] = tmp;
//        for(int x=0;x<nums.size(); ++x) { printf("%d ", nums[x]); } printf("\n");
        return i;
    }

    //
    // A solution by using Queue
    //
    int findKthLargest0(vector<int>& nums, int k) {
           return getKthByQueue(nums, k);
    }
    int getKthByQueue(vector<int>& nums, int k) {
        if(nums.empty()) return 0;

        int retVal;
        int *pArray = new int[k];

        for(int i=0; i<k; ++i) {
            pArray[i] = nums[i];
        }
        
        int idx = findMinIdx(pArray, k);
        for(int i=k; i<nums.size(); ++i)
        {
            if(nums[i] >= pArray[idx]) {
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
    // int k = 2;
    // int arr1[] = {3,2,3,1,2,4,5,5,6};
    // int k = 4;
    int arr1[] = {-1,2,0};
    int k = 2;
    // int arr1[] = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    // int k = 20;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> numbs(arr1, arr1+n);
    vector<int> numbs0(arr1, arr1+n);
    
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    int ans;
    ans = solution->findKthLargest0(numbs0, k);
    LOGE("Ans0: %d\n", ans);
    ans = solution->findKthLargest(numbs, k);
    LOGE("Ans: %d\n", ans);
    delete solution;
}