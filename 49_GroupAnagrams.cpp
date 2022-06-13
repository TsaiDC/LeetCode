//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
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
https://leetcode.com/problems/group-anagrams/
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/


#ifdef _CVERSION_
//C
/*

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){

}

void Test_AM_groupAnagrams()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 205 ms, faster than 5.85% of C++ online submissions for Group Anagrams.
Memory Usage: 25.4 MB, less than 12.28% of C++ online submissions for Group Anagrams.
*/

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > ans;
        unordered_map<string, vector<string> > umap;
        unordered_map<string, vector<string> >::iterator it;
        for(string s: strs) {
//            LOGD("Show: %s\n", s.c_str());
            int letterCount[26] = {0};
            for(int i=0; i<s.length(); ++i) {
                letterCount[s.at(i) - 'a']++;
            }
            
            string key;
            string dig;
//            LOGD("+++ %s: \n", s.c_str());
            for(int i: letterCount) {
//                 printf("%d", i);
                 dig = std::to_string(i);
                 key += dig;
                 key += "#";
            }
//            printf("\n");
//            LOGD("--- %s: key: %s\n", s.c_str(), key.c_str());
            
            if((it = umap.find(key)) != umap.end()) {
                it->second.push_back(s);
//                LOGD("Hit: %s\n", s.c_str());
            }
            else {
                vector<string> row;
                row.push_back(s);
                umap.insert(std::make_pair(key, row));
//                LOGD("Miss: %s\n", s.c_str());
            }          
        }

        for(it = umap.begin(); it != umap.end(); ++it) {
//            LOGD("Row Size: %d\n", it->second.size());
            ans.push_back(it->second);
        }
        return ans;
    }
};

void Test_AM_groupAnagrams()
{
    LOGD("[CPP] %s\n", __TIME__);
    vector< vector<string> > ans;
    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<string> input1(arr1, arr1+n1);
    
    Solution *solution = new Solution();
    ans = solution->groupAnagrams(input1);
    delete solution;
    
    for( vector<string> vs : ans) {
        for(string str: vs) {
            printf("%s ", str.c_str());
        }
        printf("\n");
    }    
}

#endif// _CPPVERSION_