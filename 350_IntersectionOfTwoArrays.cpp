//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>

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
https://leetcode.com/problems/intersection-of-two-arrays-ii/
350. Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int> tmp1, tmp2;
        map<int, int> mapRecord;
        map<int, int>::iterator iter;
        
        if(nums1.size() > nums2.size()){
            tmp1 = nums1;
            tmp2 = nums2;
        }
        else {
            tmp1 = nums2;
            tmp2 = nums1;            
        }
        
        for(int i=0; i<tmp1.size(); ++i)
        {
            iter = mapRecord.find(tmp1[i]);
            if(iter != mapRecord.end()) {
                iter->second += 1;                
            }
            else {
                mapRecord[tmp1[i]] = 1;
            }
        }
        
        for(int i=0; i<tmp2.size(); ++i)
        {
            iter = mapRecord.find(tmp2[i]);
            if(iter != mapRecord.end() && iter->second != 0){
                result.push_back(tmp2[i]);
                iter->second -= 1;
            }
        }
        return result;
    }
};

void Test_IntersectionOfTwoArrays()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {4, 9, 5};
    int arr2[] = {9, 4, 9, 8, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> input1(arr1, arr1+n1);
    vector<int> input2(arr2, arr2+n2);
    
    Solution *instance = new Solution();
    vector<int> result = instance->intersect(input1, input2);
    
    for(int i=0; i<result.size(); ++i)
    {
        LOGD("Ans: %d\n", result[i]);
    }
    
    delete instance;
}