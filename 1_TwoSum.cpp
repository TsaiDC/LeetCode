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
https://leetcode.com/problems/two-sum/
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that 
they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element
twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

*/


#ifdef _CVERSION_
//C
/*

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

}

void Test_AM_twoSum()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

/*
Runtime: 14 ms, faster than 83.33% of C++ online submissions for Two Sum.
Memory Usage: 10.8 MB, less than 53.75% of C++ online submissions for Two Sum.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector< pair<int, int> > nums_pair;
        //1. sorting
        for(int i=0; i<nums.size(); ++i)
        {
            nums_pair.push_back(make_pair(nums[i], i));
        }

        sort(nums_pair.begin(), nums_pair.end(), comp);
        
        for(pair<int, int> i: nums_pair) {
            LOGD("Sort: %d\n", i.first);
        }

        //2. B-search
        int idx, newtarget;
        for(int i=0; i<nums_pair.size(); ++i) {        
            result.push_back(nums_pair[i].second);
            newtarget = target-nums_pair[i].first;
            idx = getIndex(nums_pair, i+1, nums_pair.size()-1, newtarget);
            LOGD("Check %d, %d\n", nums_pair[i].second, idx);
            if(idx != -1) {
                result.push_back(idx);
                return result;            
            }
            result.clear();
        }

        return result;
    }
    
    int getIndex(vector< pair<int, int> >& nums_pair, int left, int right, int target) {
        int middle = (right+left)/2;

        if(nums_pair[right].first == target ) {            
            return nums_pair[right].second;
        }
        if(nums_pair[left].first == target ) {
            return nums_pair[left].second;
        }
        if(nums_pair[middle].first == target) {
            return nums_pair[middle].second;
        }
        if((middle == right || middle == left) && nums_pair[middle].first != target ) {
            LOGD("Exit, Target: %d , Middle: %d, %d\n", target, middle, nums_pair[middle].first);
            return -1;
        }

        if(nums_pair[middle].first > target) {
            return getIndex(nums_pair, left, middle, target);
        }
        else if(nums_pair[middle].first < target) {
            return getIndex(nums_pair, middle, right, target);
        }
        LOGD("Exit\n");
        return -1;
    }
};

void Test_AM_twoSum()
{
//    int nums[] = {3,2,4};
    int nums[] = {3,2,3};
//    int nums[] = {3,2,4, 9, 10, 1, 1, 1};
    int n1 = sizeof(nums)/sizeof(nums[0]);
    int target = 6;
    vector<int> input(nums, nums+n1);

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    vector<int> ans = solution->twoSum(input, target);
    delete solution;
    
    for(int i : ans)
    {
        LOGD("Ans: %d\n", i);
    }
}

#endif// _CPPVERSION_