//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>
#include <algorithm>

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
https://leetcode.com/problems/merge-sorted-array/
88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
*/

class Solution {
public:
/*
*   Runtime: 4 ms, faster than 49.93% of C++ online submissions for Merge Sorted Array.
*   Memory Usage: 9.1 MB, less than 27.88% of C++ online submissions for Merge Sorted Array.
*/
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++) {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }

/*
*   Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
*   Memory Usage: 9.1 MB, less than 27.88% of C++ online submissions for Merge Sorted Array.
*/
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1_end = m-1;
        int n2_end = n-1;
        int idx_end = (m+n)-1;
        
        while(n2_end >= 0) {
            if(n1_end >=0) {
                if(nums2[n2_end] > nums1[n1_end]) {
                    nums1[idx_end] = nums2[n2_end];
                    idx_end--;
                    n2_end--;
                }
                else {
                    nums1[idx_end] = nums1[n1_end];
                    idx_end--;
                    n1_end--;
                }
            }
            else {
                nums1[idx_end] = nums2[n2_end];
                idx_end--;
                n2_end--;
            }
        }
        
        for(int i=0; i<m+n; i++) {
            LOGD("%d\n", nums1[i]);
        }
        
    }    
};

void Test_merge88()
{
    LOGD("%s\n", __TIME__);
    
    vector<int> nums1 = vector<int> {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = vector<int> {2, 5, 6};
    int m = 3, n = 3;
    Solution *solution = new Solution();    
    solution->merge1(nums1, m, nums2, n);
    delete solution;
}