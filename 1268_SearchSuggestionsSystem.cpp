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
https://leetcode.com/problems/search-suggestions-system/
1268. Search Suggestions System

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of 
searchWord is typed. Suggested products should have common prefix with searchWord. 
If there are more than three products with a common prefix return the three lexicographically 
minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 10^4
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
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
char *** suggestedProducts(char ** products, int productsSize, char * searchWord, int* returnSize, int** returnColumnSizes){

}

void Test_AM_suggestedProducts()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Ref Solution, Trie
Runtime: 1375 ms, faster than 7.82% of C++ online submissions for Search Suggestions System.
Memory Usage: 590.2 MB, less than 5.45% of C++ online submissions for Search Suggestions System.
*/

class TrieNode {
public:
    TrieNode* letter[26];
    bool isEnd;
    TrieNode(): isEnd(false) {        
        for(int i=0; i<26; ++i) {
            letter[i] = NULL;
        }
    }
};

class Solution {
public:
    TrieNode* pRoot = NULL;
    vector< vector<string> > suggestedProducts(vector<string>& products, string searchWord) {
        vector< vector<string> > rets;
        vector<string> empty;
        pRoot = new TrieNode();
        createTire(products, searchWord);
        
        TrieNode* pPtr = pRoot;
        string pre;
        for(int i=0; i<searchWord.size(); ++i) {
            char ch = searchWord[i];
            if(pPtr->letter[ch - 'a'] == NULL) {
                for(int j=i; j<searchWord.size(); ++j) {
                    rets.push_back(empty);
                }
                break;
            }
            
            string str;
            vector< string > ret;
            pPtr = pPtr->letter[ch - 'a'];
            pre.push_back(ch);
            dfs(pPtr, str, ret);

            for(int j=0; j<ret.size(); ++j) {
                ret[j] = pre + ret[j];
            }
            rets.push_back(ret);
        }

        return rets;
    }

    void createTire(vector<string>& products, string searchWord) {        
        for(string str : products) {
            TrieNode* pPtr = pRoot;
            for(char ch : str) {                 
                 if(pPtr->letter[ch - 'a'] == NULL) {
                      pPtr->letter[ch - 'a'] = new TrieNode();
                 }
                 pPtr = pPtr->letter[ch - 'a'];
            }
            pPtr->isEnd = true;
        }
    }

    void dfs(TrieNode* pRoot, string str, vector<string>& ret) {
        if(ret.size() == 3) return; 
        if(pRoot->isEnd) ret.push_back(str);
        
        for(int i=0; i<26; ++i) {
            if(pRoot->letter[i] == NULL) continue;
            str.push_back('a'+i);
            dfs(pRoot->letter[i], str, ret);
            str.pop_back();
        }
    }
};

void Test_AM_suggestedProducts()
{
    LOGD("[CPP] %s\n", __TIME__);
    string searchWord = "mouse";
    string arr1[] = {"mobile","mouse","moneypot","monitor","mousepad"};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<string> input1(arr1, arr1+n1);    
    
    vector< vector<string> > ans;
    Solution *solution = new Solution();
    ans = solution->suggestedProducts(input1, searchWord);
    delete solution;
    
    for(int i=0;i<ans.size(); ++i) {
        for(int j=0; j<ans[i].size(); ++j) {
            LOGD("(%d, %d) Ans: %s\n", i, j, ans[i][j].c_str());
        }
    }
}

#endif// _CPPVERSION_