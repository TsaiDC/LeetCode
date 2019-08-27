//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>

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
https://leetcode.com/problems/permutations-ii/
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

static void display(int idx, int i, vector<int>& nums)
{
    printf("idx: %d, i: %d -> ", idx, i);
    for (int i=0; i<nums.size();++i)
    {
        printf("%d ", nums[i]);
    }
    if(idx == i) {
        printf(" ** \n");
    }
    else {
        printf("\n");
    }
    
}

static void swap(int i, int j, vector<int>& nums)
{
//    LOGD("Swap i: %d, j: %d\n", i, j);
    if(i==j)
        return;
    
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

static int getInt(vector<int>& nums)
{
    int result = 0;
    int m = 1;

    for(int i=0; i<nums.size(); ++i)
    {
        m *=10;
        result += (nums[i]*m);
    }
//    LOGD("Result: %d\n", result);
    return result;
}

static bool isExist(map<int, int>& mMap, int key)
{    
    map<int,int>::iterator iter;
    iter = mMap.find(key);
    if(iter == mMap.end()) {
        mMap[key] = 1;
        return false;
    }
    return true;
}

void pp(int idx, vector<int>& nums, vector< vector<int> >& result, map<int, int>& record)
{    
    if (idx == nums.size()-1) {
//        LOGD("*Idx: %d \n", idx);
        return;
    }
    
    for(int i=idx; i<nums.size(); ++i)
    {
        swap(i, idx, nums);
        if (i!= idx) {
#if 0
            for(int j=0; j<idx; j++)
            {
                printf("  ");
            }
            display(idx, i, nums);
#endif
            if(!isExist(record, getInt(nums))) {
                result.push_back(nums);
            }
        }
        pp(idx+1, nums, result, record);
        swap(i, idx, nums);
    }
    
}

vector< vector<int> > permuteUnique(vector<int>& nums) {
    vector< vector<int> > result;
    map<int, int> record;
//    int idx = getInt(nums);
    if(!isExist(record, getInt(nums))) {
        result.push_back(nums);
    }
    pp(0, nums, result, record);
#if 0
    LOGE("-----------------------------\n");
    for(int i=0; i<result.size(); ++i)
    {
        for(int j=0; j<result[i].size(); ++j)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
#endif    
    return result;
}

void Test_permuteUnique()
{
    LOGD("%s\n", __TIME__);
    int arr[] = {1,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
        
    for(int i=0; i<n; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    vector<int> input(arr, arr+n);
    permuteUnique(input);    
    LOGD("Done \n");
}