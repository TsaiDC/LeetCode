//g++ main.cpp twosum.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    int a, b;
    for(int i=0; i<nums.size(); ++i)
    {
        a = nums[i];
        b = target - a;
        for (int j = i+1; j<nums.size(); ++j) 
        {
            if(nums[j] == b) {
                result.push_back(i);
                result.push_back(j);
                printf("[DBG] %s(%d) %s\n", __FUNCTION__, __LINE__, __TIME__);
                return result;
            }
        }
    }
    return result;
}

void Test_addTwoSum()
{
    vector<int> input;
    vector<int> output;
	input.push_back(2);
	input.push_back(7);
	input.push_back(11);
	input.push_back(15);
    output = twoSum (input, 22);
    printf("[DBG] %s(%d) %s : size: %d\n", __FUNCTION__, __LINE__, __TIME__, output.size());
    for (int i=0; i<output.size(); ++i)
    {
        printf("[DBG] %s(%d) %s : idx: %d\n", __FUNCTION__, __LINE__, __TIME__, output[i]);
    }
}