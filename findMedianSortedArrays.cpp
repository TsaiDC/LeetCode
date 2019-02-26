//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "apiheader.h"

using namespace std;

/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int idx;
    vector<int>combine;

    for (int i=0, j=0, k=0;j<nums1.size() || k<nums2.size(); ++i)
    {
        if(j<nums1.size() && k<nums2.size()) {
            if(nums1[j] < nums2[k]) {
                combine.push_back(nums1[j]);
                j++;
            } else {
                combine.push_back(nums2[k]);
                k++;
            }
        }
        else if(j<nums1.size() && k>=nums2.size()) {
            combine.push_back(nums1[j]);
            j++;
        }
        else if(j>=nums1.size() && k<nums2.size()) {
            combine.push_back(nums2[k]);
            k++;        
        }
        else {
            break;
        }
    }

    for(int i=0; i<combine.size(); ++i)
    {
        printf("%d ", combine[i]);
    }
    printf("\n");

    if(combine.size() == 1) {        
        printf("[DBG] %s(%d) %s, idx: %d, tmp: %f\n", __FUNCTION__, __LINE__, __TIME__, idx, (double)combine[0]);
        return (double)combine[0];
    }
    else if(combine.size() %2 == 0) {
        idx = combine.size()/2;
        printf("[DBG] %s(%d) %s, idx: %d, tmp: %f\n", __FUNCTION__, __LINE__, __TIME__, idx, (double)(combine[idx] + combine[idx-1])/2);
        return (double)(combine[idx] + combine[idx-1])/2;
    }
    else {
        idx = combine.size()/2;
        printf("[DBG] %s(%d) %s, idx: %d, tmp: %f\n", __FUNCTION__, __LINE__, __TIME__, idx, (double)combine.at(idx));
        return (double)combine[idx];
    }
    return 0.0;
}

void Test_findMedianSortedArrays()
{
    printf("[DBG] %s(%d) %s\n", __FUNCTION__, __LINE__, __TIME__);
    vector<int> nums1;	
    vector<int> nums2;
	
	nums1.push_back(1);
	nums1.push_back(3);
	nums2.push_back(2);
	
    printf("[DBG] %s(%d) %s, Middle: %f\n", __FUNCTION__, __LINE__, __TIME__, findMedianSortedArrays(nums1, nums2));
    
}