//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

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

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> retVector;
    //1. Create Ref Map
    int min = nums[0], max = nums[0], length;
    int *plist, *plist2;
    for(int i=0; i<nums.size(); ++i)
    {
        if(nums[i]<min) min = nums[i];
        if(nums[i]>max) max = nums[i];
    }
    length = max - min + 1;
    LOGD("%d -> %d, Leng: %d\n", max, min, length);
    plist = new int[length];
    plist2 = new int[length];

    memset(plist, 0, sizeof(int)*length);    
    for(int i=0; i<nums.size(); ++i)
    {
        plist[nums[i] - min] += 1;     
    }
#if 1
    printf("Vector: ");
    for(int i=0; i<nums.size(); ++i)
    {        
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    printf("Array: ");
    for(int i=0; i<length; ++i)
    {    
        printf("%d ", plist[i]);
    }
    printf("\n");
#endif
    
    memcpy(plist2,plist, sizeof(int)*length);
    printf("Array2: ");
    for(int i=0; i<length; ++i)
    {    
        printf("%d ", plist2[i]);
    }
    printf("\n");
    
    //2.
    for(int i=0; i<nums.size(); ++i)
    {       
        int target;
        if(plist2[nums[i]-min]==0) {
            continue;
        }
        
        memcpy(plist2,plist, sizeof(int)*length);
        target = 0 - nums[i];
        plist2[nums[i]-min] -= 1;
        
        LOGD("Check %d + %d \n", nums[i], target);
        
    }
    
    delete [] plist;
    delete [] plist2;
    
    return retVector;
}

void Test_threeSum()
{
    LOGD("%s\n", __TIME__);
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    threeSum(input);
    LOGD("Done \n");
}