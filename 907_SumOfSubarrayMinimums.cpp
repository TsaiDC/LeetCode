//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#define _CPPVERSION_

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
// Unorder Map:
// https://shengyu7697.github.io/std-unordered_map/
// https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/
//

/*
https://leetcode.com/problems/sum-of-subarray-minimums/
907. Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every 
(contiguous) subarray of arr. Since the answer may be large, return the answer 
modulo 10^9 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 3 * 10^4

*/


#ifdef _CVERSION_
//C
/*

*/

int sumSubarrayMins(int* arr, int arrSize){
    return 0;
}

void Test_AM_sumSubarrayMins()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Ref. Monotonic Stack
Runtime
117 ms
Beats
80.59%
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // [3, 1, 2, 4]
        // [3]          --> ans += 3， 找出比自己小的左右兩邊的邊界
        // [3, 1], [1], [1, 2], [1, 2, 4], [3, 1, 2], [3, 1, 2, 4] --> ans += 1
        // [2], [2, 4] --> ans += 2
        // [4] --> ans += 4

        int sz = arr.size();
        vector<int> ple(sz), nle(sz);
        
        // PLE
        stack<int> st;
        for(int i = 0; i < sz; ++i) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        // clear the stack
        while(!st.empty()) st.pop();
        
        // NLE
        // 為什麼是大於等於?
        // 因為等於的最小值也是和arr[i]一樣。
        // 但是如果，兩邊都使用>= 會有重複問題，所以只要一邊就可以。
        // ex : [71, 55, 82, 55], 如果ple和nle都使用>=
        // idx1 [71, 55], [55],
        //                     [82], [82, 55]
        // idx3 [71, 55, 82, 55] -->重複計算
        for(int i = sz - 1; i >= 0; --i) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nle[i] = st.empty() ? sz : st.top();
            st.push(i);
        }

        // count the result
        //   [3, 1, 2, 4]
        // -1,  ,1        ,4
        //   i - ple[i] : 前面有幾個element : 2 --> [1], [3, 1]
        //   nle[i] - i : 後面有幾個element : 3 --> [], [2], [2, 4]
        long rtn{0};
        long mod = 1e9 + 7;
        for(int i = 0; i < sz; ++i) {
            long count = (i - ple[i]) * (nle[i] - i) % mod;
            rtn = (rtn + arr[i] * count) % mod;
        }

        return rtn;
    }
};

void Test_AM_sumSubarrayMins()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;
}

#endif// _CPPVERSION_