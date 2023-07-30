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

#ifdef _2138_
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
https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
2138. Divide a String Into Groups of Size k

A string s can be partitioned into groups of size k using the following procedure:

The first group consists of the first k characters of the string, the second group consists of 
the next k characters of the string, and so on. Each character can be a part of exactly one group.
For the last group, if the string does not have k characters remaining, a character fill is used to 
complete the group.

Note that the partition is done so that after removing the fill character from the last group 
(if it exists) and concatenating all the groups in order, the resultant string should be s.

Given the string s, the size of each group k and the character fill, return a string array denoting 
the composition of every group s has been divided into, using the above procedure.

Example 1:

Input: s = "abcdefghi", k = 3, fill = "x"
Output: ["abc","def","ghi"]

Explanation:
The first 3 characters "abc" form the first group.
The next 3 characters "def" form the second group.
The last 3 characters "ghi" form the third group.

Since all groups can be completely filled by characters from the string, we do not need to use fill.
Thus, the groups formed are "abc", "def", and "ghi".

Example 2:

Input: s = "abcdefghij", k = 3, fill = "x"
Output: ["abc","def","ghi","jxx"]
Explanation:
Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
For the last group, we can only use the character 'j' from the string. 
To complete this group, we add 'x' twice.
Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters only.
1 <= k <= 100
fill is a lowercase English letter.

*/


#ifdef _CVERSION_
//C
/*

*/

void Test_divideString()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 4 ms Beats 31.84%
Memory: 7.1 MB Beats 5.79%
*/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int length = s.length();
        int m = k - length%k;
        vector<string>ans;
        
        for(int i=0; i<m && m!=k; ++i) {
            s += fill;
        }
        
        string str;
        for(int i=0; i<length+m; i+=k) {
            str = s.substr(i, k);
            LOGD("i: %d, str: %s (%d)\n", i, str.c_str(), str.length());
            if(str.length() == k) {
               ans.push_back(str);
            }
        }
        return ans;
    }
};class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int length = s.length();
        int m = k - length%k;
        vector<string>ans;
        
        for(int i=0; i<m && m!=k; ++i) {
            s += fill;
        }
        
        string str;
        for(int i=0; i<length+m; i+=k) {
            str = s.substr(i, k);
            LOGD("i: %d, str: %s (%d)\n", i, str.c_str(), str.length());
            if(str.length() == k) {
               ans.push_back(str);
            }
        }
        return ans;
    }
};

void Test_divideString()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    string s = "abcdefghij";
//    string s = "abcdefghi";
    int k = 3;
    char fill = 'x';
    vector<string> ans;
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    ans = solution->divideString(s, k, fill);
    delete solution;
    for(string s : ans) {
        LOGD("Str: %s\n", s.c_str());
    }
}

#endif// _CPPVERSION_
#endif//_2138_