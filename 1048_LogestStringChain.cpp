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

#include "apiheader.h"

#ifdef _1048_
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
https://leetcode.com/problems/longest-string-chain/
1048. Longest String Chain

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere 
in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 
is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is 
trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given 
list of words.


Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.

*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_longestStrChain()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Ref
Runtime: 57 ms Beats 94.46%
Memory: 23.3 MB Beats 35.86%
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int, vector<string>>lengthMap;
        int maxlength = 0;
        
        for(auto str : words) {
            int length = str.length();
            maxlength = std::max(maxlength, length);
            if( lengthMap.find(length) == lengthMap.end() ) {
                vector<string> vec;
                vec.push_back(str);
                lengthMap[length] = vec;
            }
            else {
                lengthMap[length].push_back(str);
            }
        }
        
        unordered_map<string, int> uMap;
        int res = 1;
        for(int i=1; i<=maxlength; i++) {
            if(lengthMap.find(i) == lengthMap.end()) {
                continue;
            }
            vector<string>vec = lengthMap[i];
            
            for(string s : vec) {
                if(lengthMap.find(i-1) == lengthMap.end()) {
                    uMap[s] = 1;
                }
                else {
                    int count = 1;
                    for(int j=0; j<i; j++) {
                        string pre = s.substr(0, j) + s.substr(j+1);
                        if(uMap.find(pre) != uMap.end()) {
                            count = std::max(count, uMap[pre] + 1);
                        }
                    }
                    uMap[s] = count;
                    res = std::max(count, res);
                }
            }
        }
        return res;
    }
};

void Test_GG_longestStrChain()
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
#endif//_1048_