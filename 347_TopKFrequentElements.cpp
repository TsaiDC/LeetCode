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

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//

/*
https://leetcode.com/problems/top-k-frequent-elements/
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 <= k <= number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#define LOGE(...)
#endif

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mapCount;
        map<int, int>::iterator iter;

        for(int i=0; i<nums.size(); ++i) {
            ++mapCount[nums[i]];
            LOGD("Insert [%d = %d]\n", nums[i], mapCount[nums[i]]);
        }
        
        vector< vector<int> > buckets(nums.size() + 1); 
        for(iter = mapCount.begin(); iter != mapCount.end(); iter++) {            
            buckets[iter->second].push_back(iter->first);
            LOGD("Bucket[%d] add: %d]\n", iter->second, iter->first);
        }
        
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for(int j=0; j<buckets[i].size(); ++j) {
                ans.push_back(buckets[i][j]);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};

void Test_topKFrequent()
{
    LOGD("%s\n", __TIME__);

    int arr1[] = {1,1,1,2,2,3};
    int k = 2;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> num1(arr1, arr1+n);
    
    Solution *solution = new Solution();
    vector<int> ans = solution->topKFrequent(num1, k);
    
    for(int i=0;i<ans.size(); ++i)
    {
        LOGD("Ans: %d\n", ans[i]);
    }
    
    delete solution;
}