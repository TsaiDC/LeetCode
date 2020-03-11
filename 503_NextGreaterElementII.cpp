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
#if 0
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
#endif

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> next_greater(n);
    if(n==0) return next_greater;
    
    int maxi=0;
    for(int i=0; i<n; i++){
        maxi = nums[i] > nums[maxi]? i:maxi;
    }
    LOGD("maxi: %d\n", maxi);
    next_greater[maxi] = - 1;
    
    int p;
    for(int i=(maxi-1+n)%n; i!=maxi; i=(i-1+n)%n){
        p = (i+1)%n;
        LOGD("+++P: %d, i: %d\n", p, i);
        while(p != -1 && nums[i] >= nums[p]) 
        {
            LOGD("  p:%d, next_greater[p]: %d\n", p, next_greater[p]);
            p = next_greater[p];
        }
        LOGD("---P: %d, i: %d\n", p, i);
        next_greater[i] = p;
    }
    
    for(int i=0; i<n ;i++) {
        LOGD("%d\n", next_greater[i]);
    }
    for(int i=0; i<n; i++){
        if (next_greater[i] != -1) {
            LOGE("Change, i: %d, %d\n", i, next_greater[i]);
            next_greater[i] = nums[next_greater[i]];
        }
    }
    
    return next_greater;
}

void Test_NextGreaterElmentII()
{
    LOGD("%s\n", __TIME__);
    vector<int> input;
    vector<int> output;
    input.push_back(5);
    input.push_back(6);
    input.push_back(9);
    input.push_back(7);
    input.push_back(8);
    output = nextGreaterElements(input);
    
    for(int i=0; i<output.size(); ++i)
    {
        LOGD("%d\n", output[i]);
    }
}