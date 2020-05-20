//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>

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
https://leetcode.com/problems/create-maximum-number/
321. Create Maximum Number

Given two arrays of length m and n with digits 0-9 representing two numbers. 
Create the maximum number of length k <= m + n from digits of the two. 
The relative order of the digits from the same array must be preserved. 
Return an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        int arr[10] = {0};
        int count = k;
        for(int i=0; i<nums1.size(); ++i)
        {
            arr[nums1[i]]+=1;
        }
        for(int i=0; i<nums2.size(); ++i)
        {
            arr[nums2[i]]+=1;
        }

        for(int i=9; i>=0; i--)
        {
            while(arr[i] !=0 && count > 0)
            {
                ret.push_back(i);
                arr[i]-=1;
                count--;
            }
        }
        return ret;
    }
};

void Test_maxNumber()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {3, 4, 6, 5};
    int arr2[] = {9, 1, 2, 5, 8, 3};
    int k = 5;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> input1(arr1, arr1+n1);
    vector<int> input2(arr2, arr2+n2);
    vector<int> result;
    
    Solution *instance = new Solution();
    result = instance->maxNumber(input1, input2, k);
    
    for(int i=0;i<result.size(); i++)
    {
        LOGD("%d \n", result[i]);
    }
    delete instance;
}