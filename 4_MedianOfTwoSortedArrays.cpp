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
https://leetcode.com/problems/median-of-two-sorted-arrays/
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/


#ifdef _CVERSION_
//C
/*

*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    return 0;
}

void Test_AM_findMedianSortedArrays()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 36 ms, faster than 95.26% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 89.9 MB, less than 25.58% of C++ online submissions for Median of Two Sorted Arrays.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int mid = (m+n)/2;
        bool odd = (m+n)%2 == 0 ? false : true;               
        vector<int> merged;
        
        int i=0, j=0;        
        while(i<m && j<n) {
            if(merged.size()-1 == mid) {
//                LOGD("Ret \n");
                return odd ? merged[mid] : (double)(merged[mid-1]+merged[mid])/2;
            }
            if(nums1[i]<nums2[j]) {
//                LOGD("Push: %d\n", nums1[i]);
                merged.push_back(nums1[i]);
                ++i;
            }
            else {
//                LOGD("Push: %d\n", nums2[j]);
                merged.push_back(nums2[j]);
                ++j;
            }
        }
        
        while(i<m) {
            if(merged.size()-1 == mid) {
//                LOGD("Ret \n");
                return odd ? merged[mid] : (double)(merged[mid-1]+merged[mid])/2;
            }
//            LOGD("Push: %d\n", nums1[i]);
            merged.push_back(nums1[i]);
            ++i;
        }
        while(j<n) {
            if(merged.size()-1 == mid) {
                LOGD("Ret %d\n", odd);
                return odd ? merged[mid] : (double)(merged[mid-1]+merged[mid])/2;
            }
            LOGD("Push: %d\n", nums2[j]);
            merged.push_back(nums2[j]);
            ++j;
        }        
        return odd ? merged[mid] : (double)(merged[mid-1]+merged[mid])/2;        
    }
};

void Test_AM_findMedianSortedArrays()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    int nums1[] = {1,3};
    int nums2[] = {2};
    int n1 = sizeof(nums1)/sizeof(nums1[0]);
    int n2 = sizeof(nums2)/sizeof(nums2[0]);
//    vector<int> input1(nums1, nums1+n1);
    vector<int> input1;
    vector<int> input2(nums2, nums2+n2);    
    
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    double ans = solution->findMedianSortedArrays(input1, input2);
    delete solution;
        
    LOGD("Ans: %f\n", ans);
}

#endif// _CPPVERSION_