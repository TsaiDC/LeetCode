//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
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

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//

/*
https://leetcode.com/problems/minimum-window-substring/
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/

class Solution {
public:
    string minWindow(string s, string t) {        
        int *flagT = new int[t.size()];
        int start_s = 0;
       
/*
        //1. �ˬdS�Ĥ@�Ӧr���s�b t
        if S[0] �s�bt, t count-1, �w�q left �� idx
           S[1] �s�bt, S[1] != S[0], t count-1
        �@���ˬd��t count = 0, �w�qright ��idx, stop
        �@���ˬd��s ����,
        
        //2. �ˬdS�ĤG�Ӧr���s�b t
        //3. ���ƤW�z
*/

        while(start_s < s.size()) {
            int tCount = t.size();
            int idx_left=-1, idx_right=-1;        
            for(int i=0; i<tCount; ++i) {
                flagT[i] = true;
            }
            for(int i = start_s; i<s.size(); ++i) {
                for(int j = 0; j<t.size(); ++j) {
                    if(s.at(i) == t.at(j)) {                    
                        if(flagT[j]) {
                            if(idx_left < 0) idx_left = i;
                            flagT[j] = false;
                            --tCount;
                            if(tCount == 0)  idx_right = i;
                        }
                    }
                }
            }                
            LOGD("Start: %d, Count: %d, L(%d) R(%d)\n", start_s, tCount, idx_left, idx_right);
            ++start_s;
        }
        delete [] flagT;
        return "";
    }
};

void Test_minWindow()
{
    LOGD("%s\n", __TIME__);
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution *solution = new Solution();
    string ans = solution->minWindow(s, t);   
    delete solution;
    LOGD("Ans: %s\n", ans.c_str());
}