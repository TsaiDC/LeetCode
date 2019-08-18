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
https://leetcode.com/problems/4sum/
18. 4Sum

Given an array nums of n integers and an integer target, 
are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

vector< vector<int> > fourSum(vector<int>& nums, int target) {
    if(nums.size()<4) {
        return {};
    }
    vector< vector<int> > retVector;
    vector<int>row;
    map<int, int> mMap;
    map<int, int>::iterator iter;
    map<int, int>::iterator iter2;
    map<int, int>::iterator iter3;
    map<int, int>::iterator iter4;
    
    //1. Create Ref Map
    for(int i=0; i<nums.size(); ++i)
    {
//        mMap[nums[i]-target] = mMap[nums[i]-target] == 0 ? 1 : mMap[nums[i]-target] + 1;
        mMap[nums[i]] = mMap[nums[i]] == 0 ? 1 : mMap[nums[i]] + 1;        
    }
#if 1
    for(iter = mMap.begin(); iter != mMap.end(); iter++)
    {
        LOGD("%d, %d\n", iter->first, iter->second);
    }
#endif

    //2.
    int first, second, third, forth, sum, secSum;
    for(iter = mMap.begin(); iter != mMap.end(); iter++)
    {   
//        LOGD("-------------\n");
        first = iter->first;
        sum = target-first;
//        LOGD("first: %d(%d), sum: %d\n", iter->first, iter->second, sum);
        iter->second -= 1;
        

        for(iter2 = mMap.begin(); iter2 != mMap.end(); iter2++)
        {            
            if(iter2->second == 0)
                continue;

            second =iter2->first;
            secSum = sum - second;
//            LOGD("  second: %d(%d), secSum: %d\n", iter2->first, iter2->second, secSum);
            iter2->second -= 1;                      

            for(iter3 = mMap.begin(); iter3 != mMap.end(); iter3++)
            {
                if(iter3->second == 0) {
                    continue;
                }
                third = iter3->first;
                iter3->second -= 1;
                
                forth = secSum - third;
                iter4 = mMap.find(forth);
                
                if(iter4 != mMap.end() && iter4->second != 0) {                
                    if(second < first || third < first || third < second || forth < first || forth < second || forth < third) {
                        iter3->second += 1;
                        continue;
                    }                
//                    LOGD("%d %d %d %d\n\n", first + target, second + target, third + target, forth + target);
                    LOGD("%d %d %d %d\n\n", first, second, third, forth);
                    row.clear();
                    row.push_back(first);
                    row.push_back(second);
                    row.push_back(third);
                    row.push_back(forth);
                    retVector.push_back(row);
                }
                iter3->second += 1;
            }
            iter2->second += 1;
        }
        
        iter->second += 1;
    }

    if(retVector.size() == 0) {
        return {};
    }

    return retVector;
}

void Test_fourSum()
{
    LOGD("%s\n", __TIME__);
#if 1
//    int arr[] = {-1, 0, 1, 2, -1, -4};
//    int arr[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//    int arr[] = {1, 0, 0, 2, 1, 1, 1};
//    int arr[] = {-1, 0, 1};
//    int arr[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
//    int arr[] = {1, 0, -1, 0, -2, 2};
    int arr[] = {1,-2,-5,-4,-3,3,3,5};
    int target = -11;    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Input: ");
    for(int i=0; i<n; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    vector<int> input(arr, arr+n);
    fourSum(input, target);

#endif
    LOGD("Done \n");
}