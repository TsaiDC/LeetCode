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
#include <algorithm>

#include "apiheader.h"

#ifdef _1218_
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
https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
1218. Longest Arithmetic Subsequence of Given Difference

Given an integer array arr and an integer difference, return the length of the longest subsequence 
in arr which is an arithmetic sequence such that the difference between adjacent elements in the 
subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without 
changing the order of the remaining elements.

Example 1:

Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:

Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:

Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].

Constraints:

1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4

*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_TEST()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Time Limit Exceeded
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int>idx(arr.size());
        int target = 0;
        int i,j;
        bool isFound;
        for(i=0; i<arr.size(); ++i){            
            target = arr[i] + difference;
            isFound = false;
            
            for(j=i+1; j<arr.size(); ++j) {
                if(arr[j] == target) {
                    isFound = true;
                    break;
                }
            }
            
            if(isFound) {
                idx[i] = j;
            }
            else {
                idx[i] = -1;
            }            
        }

        int maxCount = 1;
        int count = 0;
        for(i=0;i<idx.size(); ++i) {            
            if(idx[i]==-1) continue;
            count = 1;            
            for(j=idx[i]; j<idx.size();) {
                count++;
                if(idx[j] == -1) {                    
                    break;
                }
                j=idx[j];
            }

            maxCount = maxCount < count ? count : maxCount;
        }
        return maxCount;
    }
};

void Test_GG_longestSubsequence()
{
//    int arr1[] = {1, 2, 3, 4};
//    int diff = 1;

//    int arr1[] = {1, 3, 5, 7};
//    int diff = 1;
    
    int arr1[] = {1,5,7,8,5,3,4,2,1};
    int diff = -2;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    int ans = solution->longestSubsequence(input1, diff);
    LOGD("Ans: %d\n", ans);
    delete solution;
}

#endif// _CPPVERSION_
#endif//_1218_