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
https://leetcode.com/problems/container-with-most-water/
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

int maxArea(vector<int>& height) 
{
    int largest = 0;

    // have two indices, one starting from the very left, and another from the very right
    // move index from the side that has larger number than itself (scan through, inwards basically)
    
    int left = 0;
    int right = height.size() - 1;
    
    while(left < right){
        
        largest = std::max(largest, std::abs(left - right) * std::min(height[left], height[right]));
        
        if(height[left] <= height[right]){
            ++left;
        }
        else{
            --right;
        }                        
    }

    return largest;
}

void Test_maxArea()
{
    LOGD("%s\n", __TIME__);

    vector<int> input = {1,8,6,2,5,4,8,3,7};    
    int result = maxArea(input);
    LOGD("Result: %d\n", result);
    
    LOGD("Done \n");
}