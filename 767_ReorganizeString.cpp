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
#include <algorithm>

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
https://leetcode.com/problems/reorganize-string/
767. Reorganize String

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/


#ifdef _CVERSION_
//C
/*

*/

char * reorganizeString(char * s){

}

void Test_AM_reorganizeString()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
#if 1
/*
Ref
Priority Queue
Take 2 top freq char
*/
class Solution {
public:
    string reorganizeString(string s) {
#if 0
        unordered_map<char, int>count;
        for(auto ch : s)
            count[ch]++;
        priority_queue<pair<int, char>>pq;
        for(auto x:count)
            pq.push({x.second, x.first});
        
        string ret;
        while(!pq.empty()) {
            int k = min(2, (int)pq.size());
            vector<pair<int, char>> tmp;
            for(int i=0; i<k; i++) {
                auto[freq, ch] = pq.top();
                pq.pop();
                ret.push_back(ch);
                freq--;
                if(freq>0)
                    tmp.push_back({freq, ch});
            }
            if(k==1 && tmp.size() > 0) {
                return "";
            }
            for(auto s:tmp)
                pq.push(s);
        }
        return ret;
#endif
    }
};

#endif
#if 0
/*
Ref.
Greedy.
a_a_a_...
fill even position then fill odd posistioin
*/
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>count;
        for(auto ch : s)
            count[ch]++;
            
        vector<pair<int, char>> arr;
        for(auto ch:s)
            arr.push_back({count[ch], ch});
            
        sort(arr.rbegin(), arr.rend());

        string ret(s.size(), ' ');
        int i=0;
        for(auto [cnt, ch] : arr) {
            ret[i] = ch;
            if(i>=1 && ret[i] == ret[i-1]) {
                return "";
            }
            i+=2;
            if(i>=s.size()) {
                i = 1;
            }
        }
        return ret;
    }
};

#endif
void Test_AM_reorganizeString()
{    
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    string input = "aab";
    string ans = solution->reorganizeString(input);
    
    LOGD("Ans: %s -> %s\n", input.c_str(), ans.c_str());
    delete solution;
}

#endif// _CPPVERSION_