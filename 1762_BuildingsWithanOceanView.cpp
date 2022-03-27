//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <algorithm>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define _CPPVERSION_

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
https://leetcode.com/problems/buildings-with-an-ocean-view/
1762. Buildings With an Ocean View

There are n buildings in a line. You are given an integer array heights of size n that represents 
the heights of the buildings in the line.

The ocean is to the right of the buildings. 
A building has an ocean view if the building can see the ocean without obstructions. Formally, 
a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.


Example 1:

Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.

Example 2:

Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.

Example 3:

Input: heights = [1,3,2,4]
Output: [3]
Explanation: Only building 3 has an ocean view.

Constraints:

1 <= heights.length <= 105
1 <= heights[i] <= 109
*/
#ifdef _CVERSION_
//C
/*

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findBuildings(int* heights, int heightsSize, int* returnSize){

}

void Test_FB_lowestCommonAncestor()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 136 ms, faster than 89.99% of C++ online submissions for Buildings With an Ocean View.
Memory Usage: 68.8 MB, less than 70.57% of C++ online submissions for Buildings With an Ocean View.
*/

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int idx;
        vector<int> ans;
        idx = heights.size()-1;
        ans.push_back(idx);
        for(int i=heights.size()-2; i>=0; --i) {
            if(heights[i] > heights[idx]) {
                idx = i;
                ans.push_back(idx);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

void Test_FB_findBuildings()
{
    LOGD("[CPP] %s\n", __TIME__);
    int intInput[] = {4,2,3,1};
    int len = sizeof(intInput)/sizeof(intInput[0]);
    vector<int>ans;
    vector<int> vecInput(intInput, intInput+len);
    Solution *solution = new Solution();
    ans = solution->findBuildings(vecInput);
    delete solution;
    
    for(int i: ans) {
        LOGD("Ans: %d\n", i);
    }
}

#endif //_CPPVERSION_