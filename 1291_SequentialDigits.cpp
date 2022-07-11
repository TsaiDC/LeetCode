//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <cstdlib> 
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
https://leetcode.com/problems/sequential-digits/
1291. Sequential Digits

An integer has sequential digits if and only if each digit in the number is one more than 
the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive 
that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9

*/


#ifdef _CVERSION_
//C
/*

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize){

}

void Test_AM_sequentialDigits()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Ref. Self-Solution
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sequential Digits.
Memory Usage: 6.2 MB, less than 72.96% of C++ online submissions for Sequential Digits.
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ret;
        int prefix = 12;
        int data = prefix;
        int add = 11;
        
        while(data <= high) {
            if(data%10 == 9) {
                LOGD("%d\n", data);
                if(data>= low && data<=high) {
                    ret.push_back(data);
                }
                prefix = prefix%10 + 1 + prefix*10;
                data = prefix;
                add = add*10 + 1;
                continue;
            }
            LOGD("%d\n", data);
            if(data>= low && data<=high) {
                ret.push_back(data);
             }            
            data +=add;
        }
        
        return ret;
    }
};

void Test_AM_sequentialDigits()
{
    vector<int> ans;
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    ans = solution->sequentialDigits(89, 234);
    delete solution;
    
    for(auto &a: ans) {
        LOGD("ANS: %d\n", a);
    }
}

#endif// _CPPVERSION_