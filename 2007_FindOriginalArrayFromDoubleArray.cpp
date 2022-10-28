//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
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
// Set Ref:
// https://shengyu7697.github.io/std-unordered_set/
//

/*
https://leetcode.com/problems/find-original-array-from-doubled-array/
2007. Find Original Array From Doubled Array

An integer array original is transformed into a doubled array changed by appending twice 
the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is not 
a doubled array, return an empty array. The elements in original may be returned in any 
order.

Example 1:

Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].

Example 2:

Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.

Example 3:

Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.
 

Constraints:

1 <= changed.length <= 10^5
0 <= changed[i] <= 10^5
*/
#ifdef _CVERSION_
//C
/*

*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOriginalArray(int* changed, int changedSize, int* returnSize){

}

void Test_GG_findOriginalArray()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime
948 ms
Beats
32.14%
*/

//1 3 5 7, 2 6 10 14
//1 2 3 5 6 7 10 14
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        if(changed.empty()) {
            return ans;
        }
        if(changed.size()%2 != 0) {
            return ans;
        }
        unordered_map<int, int>map;
        for(int i : changed) {
            map[i] += 1;
        }
        std::sort(changed.begin(), changed.end(), std::less<int>());
        for(int i : changed) {
            if(i == 0) {                
                if(map[i] >= 2) {
                    map[i] -= 2;
                    ans.push_back(i);
                }
                continue;                
            }
                            
            if(map[i] > 0 && map[i*2] > 0) {
                ans.push_back(i);
                map[i*2] -= 1;
                map[i] -= 1;
            }
        }
        
        if(ans.size() != changed.size()/2) {
            ans.clear();
        }
        
        return ans;
    }
};

void Test_GG_findOriginalArray()
{
    LOGD("[CPP] %s\n", __TIME__);    
    Solution *solution = new Solution();
//    int input1[] = {1,3,4,2,6,8 };
//    vector<int> v1(input1, input1+6);
//    int input1[] = {6,3,0,1};
    int input1[] = {0,0,2,4};
    vector<int> v1(input1, input1+4);
    vector<int> ans = solution->findOriginalArray(v1);
    delete solution;
    
    for(int i : ans) {
        LOGD("Ans: %d\n", i);
    }
}

#endif //_CPPVERSION_
