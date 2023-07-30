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

#ifdef _1592_
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
https://leetcode.com/problems/rearrange-spaces-between-words/
1592. Rearrange Spaces Between Words

You are given a string text of words that are placed among some number of spaces. 
Each word consists of one or more lowercase English letters and are separated by at 
least one space. It's guaranteed that text contains at least one word.

Rearrange the spaces so that there is an equal number of spaces between every pair of 
adjacent words and that number is maximized. If you cannot redistribute all the spaces 
equally, place the extra spaces at the end, meaning the returned string should be the 
same length as text.

Return the string after rearranging the spaces.

Example 1:

Input: text = "  this   is  a sentence "
Output: "this   is   a   sentence"
Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 
spaces between the words: 9 / (4-1) = 3 spaces.

Example 2:

Input: text = " practice   makes   perfect"
Output: "practice   makes   perfect "
Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 
extra space. We place this extra space at the end of the string.


Constraints:

1 <= text.length <= 100
text consists of lowercase English letters and ' '.
text contains at least one word.
*/


#ifdef _CVERSION_
//C
/*

*/

void Test_reorderSpaces()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 0 ms Beats 100%
Memory: 6.2 MB Beats 39.2%
*/

class Solution {
public:
    string reorderSpaces(string text) {
        int length = text.size();
        int spaceNum = 0;
        queue<string> strQ;
        int charIdx=-1, spaceIdx=-1;
        
        for(int i=0;i<length; ++i) {
            if(text.at(i) == ' ') {
                spaceNum++;
                if(charIdx<0) {
                    continue;
                }
                else {
                    string str = text.substr(charIdx, i - charIdx);
                    strQ.push(str);
                    charIdx=-1;
                }
            }
            else {
                if(charIdx<0) {
                    charIdx = i;
                }
            }
        }

        if(charIdx >= 0) {
            string str = text.substr(charIdx);
            strQ.push(str);
        }

        int spaceIntval = 0;
        if(strQ.size()-1 > 0) {
            spaceIntval = spaceNum/(strQ.size()-1);
        }
        
        string ans = "";
        string space = " ";        
        while(strQ.size()>1) {            
            ans += strQ.front();
            strQ.pop();
            for(int i=0; i<spaceIntval; ++i)
                ans += space;
            spaceNum -= spaceIntval;            
        }
        while(!strQ.empty()) {
            ans += strQ.front();
            strQ.pop();
        }        
        for(int i=0; i<spaceNum; ++i)
            ans += space;;

        return ans;
    }
};

void Test_reorderSpaces()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

//    string text = "  this   is  a sentence ";
//    string text = " practice   makes   perfect";
    string text = "a";
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    string ans = solution->reorderSpaces(text);
    delete solution;
    LOGD("Ans: %s\n", ans.c_str());
}

#endif// _CPPVERSION_
#endif//_1592_