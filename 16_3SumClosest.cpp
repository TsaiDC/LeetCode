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
https://leetcode.com/problems/3sum-closest/
16. 3Sum Closest

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

int threeSumClosest(vector<int>& nums, int target) {
    
    if(nums.size()<3) {
        LOGE("Error\n");
        return 0;
    }
    
    if(nums.size() == 3) {        
        return (nums[0] + nums[1] + nums[2]);
    }
    
    int s = (nums[0] + nums[1] + nums[2]);
    int d = std::abs((nums[0] + nums[1] + nums[2]) - target);
    int xd;
    
    for(int i=0; i<nums.size(); ++i)
    {
        for(int j=i+1; j<nums.size(); ++j)
        {
            for(int k=j+1; k<nums.size(); ++k)
            {                
                xd = std::abs((nums[i] + nums[j] + nums[k]) - target); 
                LOGD("%d, %d, %d (%d, %d)\n", nums[i], nums[j], nums[k], d, xd);
                
                if(xd < d) {
                    d = xd;
                    s = (nums[i] + nums[j] + nums[k]);
                }
            }
        }
    }
    LOGD("Ans: %d\n", s);
    return s;
}
void Test_threeSumClosest()
{
    LOGD("%s\n", __TIME__);
    int arr[] = {-1, 2, 1, -4};
//    int arr[] = {0,0,0};    
    int n = sizeof(arr)/sizeof(arr[0]);
   
    vector<int> input(arr, arr+n);
    
    int ans = threeSumClosest(input, 1);
    LOGD("And: %d\n", ans);
    LOGD("Done \n");
}