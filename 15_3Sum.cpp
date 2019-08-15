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

vector< vector<int> > threeSum(vector<int>& nums) {
    if(nums.size()<3) {
        return {};
    }
    map<long,int> mMap;
    vector< vector<int> > retVector;
    vector<int>row;
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
    long first, second, third, sum;
    long pSum;
    for(int i=0; i<length; ++i)
    {
        if(plist2[i] == 0)
            continue;

        first = i + min;       
        sum = 0-first;

        if(first-min < 0) {
            LOGE("Error, first: %d, sum: %d\n", first, min);
            return retVector;
        }
        plist2[first-min] -=1;
        
        for(int j=0; j<length; ++j)
        {
            if(plist2[j] == 0)
                continue;

            second = j + min;
            third = sum - second;
            if(second != third) {
                if(third - min < 0)
                    continue;

                if(third - min > length-1)
                    continue;

                if(plist2[second-min] > 0 && plist2[third-min] > 0) {
//                    LOGD("%d(%d) + %d(%d) + %d(%d) = 0\n", first, (first-min), second, (second - min), third, (third - min));                    
                    pSum = first*first + second*second + third*third;
                    LOGD("%d + %d + %d = 0, mMap[%d]: %d\n", first, second, third, pSum, mMap[pSum]);
                    if(mMap[pSum] != 0)
                        break;
                    mMap[pSum] = 1;
                    row.clear();
                    row.push_back(first);
                    row.push_back(second);
                    row.push_back(third);
                    retVector.push_back(row);
                    
                    break;
                }
            }
            else {
                if(plist2[second-min] >= 2) {
//                    LOGD("%d(%d) + %d(%d) + %d(%d) = 0\n", first, (first-min), second, (second - min), third, (third - min));
                    pSum = first*first + second*second + third*third;
                    LOGD("%d + %d + %d = 0, mMap[%d]: %d\n", first, second, third, pSum, mMap[pSum]);
                    if(mMap[pSum] != 0)
                        break;
                    mMap[pSum] = 1;
                    row.clear();
                    row.push_back(first);
                    row.push_back(second);
                    row.push_back(third);
                    retVector.push_back(row);
                    break;
                }
            }            
        }
        plist2[first-min] +=1;
    }

    delete [] plist;
    delete [] plist2;
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
    int arr[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//    int arr[] = {1, 0, 0, 2, 1, 1, 1};
//    int arr[] = {-1, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
//    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<int> input(arr, arr+n);
    threeSum(input);
#endif
    LOGD("Done \n");
}