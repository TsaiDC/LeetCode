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
https://leetcode.com/problems/3sum/
15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

vector< vector<int> > threeSum2(vector<int>& nums) {
    if(nums.size()<3) {
        return {};
    }
    vector< vector<int> > retVector;
    vector<int>row;
    map<int, int> mMap;
    map<int, int>::iterator iter;
    map<int, int>::iterator iter2;
    map<int, int>::iterator iter3;
    
    //1. Create Ref Map
    for(int i=0; i<nums.size(); ++i)
    {
        mMap[nums[i]] = mMap[nums[i]] == 0 ? 1 : mMap[nums[i]] + 1;
    }

    //2.
    int first, second, third, sum;
    for(iter = mMap.begin(); iter != mMap.end(); iter++)
    {
        LOGD("Map: %d -> %d\n", iter->first, iter->second);
        first = iter->first;
        if(first > 0)
            break;
        
        iter->second -= 1;
        sum = 0-first;
        
        for(iter2 = mMap.begin(); iter2 != mMap.end(); iter2++)
        {
            if(iter2->second == 0) {
                continue;
            }
            second = iter2->first;
            iter2->second -= 1;
            
            third = sum - second;
            iter3 = mMap.find(third);
            
            if(iter3 != mMap.end() && iter3->second != 0) {                
                if(second < first || third < first || third < second) {
                    iter2->second += 1;
                    continue;
                }                
                LOGD("%d %d %d\n", first, second, third);
                row.clear();
                row.push_back(first);
                row.push_back(second);
                row.push_back(third);
                retVector.push_back(row);
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

void Test_threeSum()
{
    LOGD("%s\n", __TIME__);
#if 1
//    int arr[] = {-1, 0, 1, 2, -1, -4};
//    int arr[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//    int arr[] = {1, 0, 0, 2, 1, 1, 1};
//    int arr[] = {-1, 0, 1};
    int arr[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Input: ");
    for(int i=0; i<n; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    vector<int> input(arr, arr+n);
    threeSum2(input);
#endif
    LOGD("Done \n");
}