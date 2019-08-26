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
https://leetcode.com/problems/permutations/
46. Permutations

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

void display(vector<int>& nums)
{
    printf("-> ");
    for (int i=0; i<nums.size();++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
void swap(int i, int j, vector<int>& nums)
{
//    LOGD("Swap i: %d, j: %d\n", i, j);
    if(i==j)
        return;
    
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void pp(int idx, vector<int>& nums)
{    
    if (idx == nums.size()-1) {
        return;
    }

    for(int i=idx; i<nums.size(); ++i)
    {        
        LOGD("i: %d, Idx: %d \n", i, idx);
        swap(i, idx, nums);
        display(nums);
        pp(i+1, nums);
        swap(i, idx, nums);
    }
}

vector< vector<int> > permute(vector<int>& nums) {
    vector<vector<int>> result;
    return result;
}

void Test_permute()
{
    LOGD("%s\n", __TIME__);
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
        
    for(int i=0; i<n; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    vector<int> input(arr, arr+n);
//    permute(input);
    pp(0, input);
    LOGD("Done \n");
}