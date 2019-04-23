//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "apiheader.h"

using namespace std;

/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/
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
*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> result;
	for(int i=0; i<nums1.size(); ++i)
	{
	    for(int j=0; j<nums2.size() && result.size() < nums2.size(); ++j)
		{
		    if(nums1.at(i) == nums2.at(j)) {
			    result.push_back(nums1.at(i));
//				printf("i: %d val: %d\n", i, nums1.at(i) );
				break;
			}
		}
	}
#if 1
	for(int i=0; i<result.size(); ++i)
	{
	    printf("%d ", result.at(i));
	}
	printf("\n");
#endif
	return result;
}

void Test_intersect()
{
    printf("[DBG] %s(%d) %s\n", __FUNCTION__, __LINE__, __TIME__);
	
	const int arr[] = {4,9,5};
    vector<int> nums1 (arr, arr + sizeof(arr) / sizeof(arr[0]) );

	const int brr[] = {9,4,9,8,4};
    vector<int> nums2 (brr, brr + sizeof(brr) / sizeof(brr[0]) );
	
	intersect(nums1, nums2);
}