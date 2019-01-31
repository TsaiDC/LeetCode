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