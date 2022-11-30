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
#include <algorithm>
#include <math.h>

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
https://leetcode.com/problems/the-kth-factor-of-n/
1492. The kth Factor of n

You are given two positive integers n and k. A factor of an integer n is defined as an integer i 
where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list 
or return -1 if n has less than k factors.

Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.

Example 2:

Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.

Example 3:

Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.

Constraints:

1 <= k <= n <= 1000

*/


#ifdef _CVERSION_
//C
/*

*/

int kthFactor(int n, int k){

}

void Test_AM_kthFactor()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Self,
Runtime
7 ms
Beats
7.58%

calculate all factors.
*/

class Solution {
public:
    int kthFactor(int n, int k) {
        int sq = (int)sqrt((float)n);
//        LOGD("N: %d, SQ: %d\n", n, sq);
        vector<int>factor;
        stack<int>sfactor;
        
        for(int i=1; i<=sq; ++i) {
            if(n%i==0) {
                factor.push_back(i);
                if(i != n/i )
                    sfactor.push(n/i);
            }
        }
        while(!sfactor.empty()) {
            factor.push_back(sfactor.top());
            sfactor.pop();
        }
        
//        for(int i:factor) {
//            LOGD("%d\n", i);
//        }
        return k<=factor.size() ? factor[k-1] : -1;
    }
};

void Test_AM_kthFactor()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
    int n = 12, k = 3;
    Solution *solution = new Solution();
    int ans = solution->kthFactor(n, k);
    delete solution;
    LOGD("Ans: %d\n", ans);
}

#endif// _CPPVERSION_