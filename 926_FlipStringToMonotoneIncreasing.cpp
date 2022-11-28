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
https://leetcode.com/problems/flip-string-to-monotone-increasing/
926. Flip String to Monotone Increasing

A binary string is monotone increasing if it consists of some number of 0's 
(possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

Example 1:

Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Example 2:

Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

Example 3:

Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
 

Constraints:

1 <= s.length <= 10^5
s[i] is either '0' or '1'.

*/


#ifdef _CVERSION_
//C
/*

*/
int minFlipsMonoIncr(char * s){

}

void Test_AM_minFlipsMonoIncr()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int OneCount = 0;
        int ZeroCount = 0;
        
        for(char c : s) {
            if(c == '1') {
                OneCount++;
            }
            else {
                if(OneCount > 0) {
                    ZeroCount++;
                }
            }
        }
        return min(OneCount, ZeroCount);
    }
};

void Test_AM_minFlipsMonoIncr()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
//    string input = "010110";
//    string input = "00011000";
//    string input = "00110";
    string input = "0101100011"; //Ans: 3
  
    Solution *solution = new Solution();
    int ans = solution->minFlipsMonoIncr(input);
    delete solution;
    LOGD("Ans: %d\n", ans);
}

#endif// _CPPVERSION_