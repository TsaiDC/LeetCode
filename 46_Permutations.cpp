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

#if 0
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

void pp(int idx, vector<int>& nums, vector< vector<int> >& result)
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
            result.push_back(nums);
        }
        pp(idx+1, nums, result);
        swap(i, idx, nums);
    }
    
}

vector< vector<int> > permute(vector<int>& nums) {
    vector< vector<int> > result;
    result.push_back(nums);
    pp(0, nums, result);
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
    permute(input);    
    LOGD("Done \n");
}
#endif

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > ans;
        Solution::getDive(nums, 0, ans);
        return ans;
    }
    static void getDive(vector<int> &nums, int level, vector< vector<int> > &ans)
    {
        if(level == nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=level; i<nums.size(); ++i)
        {            
            swap(nums, i, level);
            getDive(nums, level+1, ans);
            swap(nums, i, level);        
        }
    }
    
    static void swap(vector<int> &nums, int x, int y)
    {        
        int tmp = nums[x];
        nums[x] = nums[y];
        nums[y] = tmp;
    }
};

void Test_permute()
{
    LOGD("%s\n", __TIME__);
    vector< vector<int> > ans;
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> input(arr, arr+n);
    
    Solution *solution = new Solution();
    ans = solution->permute(input);

    delete solution;
}