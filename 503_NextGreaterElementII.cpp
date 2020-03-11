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
https://leetcode.com/problems/next-greater-element-ii/
503. Next Greater Element II

Given a circular array 
(the next element of the last element is the first element of the array), 
print the Next Greater Number for every element. 
The Next Greater Number of a number x is the first greater number to 
its traversing-order next in the array, 
which means you could search circularly to find its next greater number. 
If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result;
    
    int j=0;
    for(int i=0; i<nums.size(); ++i)
    {
        j=(i+1)%nums.size();

        do{
            if(nums[i]<nums[j]) {
                result.push_back(nums[j]);
                break;
            }
            j=(j+1)%nums.size();            
            if(i==j) {
                result.push_back(-1);
                break;                
            }
        }while(1);
    }
    return result;
}

void Test_NextGreaterElmentII()
{
    LOGD("%s\n", __TIME__);
    vector<int> input;
    vector<int> output;
//    input.push_back(4);
//    input.push_back(3);
//    input.push_back(2);
    input.push_back(1);
    output = nextGreaterElements(input);
    
    for(int i=0; i<output.size(); ++i)
    {
        LOGD("%d\n", output[i]);
    }
}