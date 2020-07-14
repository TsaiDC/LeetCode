//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <queue>

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
https://leetcode.com/problems/find-the-duplicate-number/
287. Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

#ifndef INT_MAX
#define INT_MAX (2^31-1)
#endif
class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        if (nums.size() > 1)
        {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];
            }
            LOGD("F: %d, S: %d\n", fast, slow);
            return slow;
        }
        return -1;
    }

    int findDuplicate2(vector<int>& nums) 
    {
        int n=nums.size()-1;
        int low=1;
        int high=n;
        int mid;
        while(low<high){
            mid=(low+high)/2;
            int count=0;
            for(int i=0; i<nums.size(); ++i)
            {            
                if(nums[i]<=mid) count++;
            }
            if(count>mid) high=mid;
            else low=mid+1; 
        }
        return low;
    }
    
    int findDuplicate3(vector<int>& nums) 
    {
        int low = 1, high = nums.size() - 1;
        while (low <= high) {
            int mid = (int) (low + (high - low) * 0.5);
            int cnt = 0;            
            for(int i=0; i<nums.size(); ++i){
                if (nums[i] <= mid) ++cnt;
            }
            if (cnt <= mid) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    
    int findDuplicate0(vector<int>& nums)
    {
        int slow = 0;
        int fast = 0;
        if(!nums.empty()) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            while(slow != fast)
            {
                LOGD("S: %d, F: %d\n", slow, fast);
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            LOGD("S: %d, F: %d\n", slow, fast);
            
            fast = 0;
            while (fast != slow)
            {
                LOGD("-S: %d, F: %d\n", slow, fast);
                fast = nums[fast];
                slow = nums[slow];
            }
            LOGD("-S: %d, F: %d\n", slow, fast);
            return slow;
        }
        return -1;
    }
};

void Test_findDuplicate()
{
    LOGD("%s\n", __TIME__);
    int ans;
//    int arr1[] = {1,3,4,2,2};
//    int arr1[] = {3,1,3,4,2};
//    int arr1[] = {1,2,2,3,4};
//    int arr1[] = {1,1,3,4};
    int arr1[] = {2,5,9,6,9,3,8,9,7,1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> numbs(arr1, arr1+n);
    Solution *solution = new Solution();
    ans = solution->findDuplicate(numbs);
    LOGD("Ans: %d\n",ans);
/*
    ans = solution->findDuplicate2(numbs);
    LOGD("Ans2: %d\n",ans);
    ans = solution->findDuplicate3(numbs);
    LOGD("Ans3: %d\n",ans);
*/
    ans = solution->findDuplicate0(numbs);
    LOGD("Ans0: %d\n",ans);    
    delete solution;
}