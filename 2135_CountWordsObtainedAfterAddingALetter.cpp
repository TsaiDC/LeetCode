//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>


#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define _CPPVERSION_

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
// Set Ref:
// https://shengyu7697.github.io/std-unordered_set/
//
// Priority Queue:
// https://yuihuang.com/cpp-stl-priority-queue/
//

/*
https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/
2135. Count Words Obtained After Adding a Letter

You are given two 0-indexed arrays of strings startWords and targetWords. Each string 
consists of lowercase English letters only.

For each string in targetWords, check if it is possible to choose a string from startWords 
and perform a conversion operation on it to be equal to that from targetWords.

The conversion operation is described in the following two steps:

Append any lowercase letter that is not present in the string to its end.
For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added to it, but 
not 'a'. If 'd' is added, the resulting string will be "abcd".
Rearrange the letters of the new string in any arbitrary order.
For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on. Note that it 
can also be rearranged to "abcd" itself.
Return the number of strings in targetWords that can be obtained by performing the 
operations on any string of startWords.

Note that you will only be verifying if the string in targetWords can be obtained from a 
string in startWords by performing the operations. The strings in startWords do not 
actually change during this process.

 

Example 1:

Input: startWords = ["ant","act","tack"], targetWords = ["tack","act","acti"]
Output: 2
Explanation:
- In order to form targetWords[0] = "tack", we use startWords[1] = "act", append 'k' to 
  it, and rearrange "actk" to "tack".
- There is no string in startWords that can be used to obtain targetWords[1] = "act".
  Note that "act" does exist in startWords, but we must append one letter to the string 
  before rearranging it.
- In order to form targetWords[2] = "acti", we use startWords[1] = "act", append 'i' to 
  it, and rearrange "acti" to "acti" itself.

Example 2:

Input: startWords = ["ab","a"], targetWords = ["abc","abcd"]
Output: 1
Explanation:
- In order to form targetWords[0] = "abc", we use startWords[0] = "ab", add 'c' to it, 
  and rearrange it to "abc".
- There is no string in startWords that can be used to obtain targetWords[1] = "abcd".
 

Constraints:

1 <= startWords.length, targetWords.length <= 5 * 104
1 <= startWords[i].length, targetWords[j].length <= 26
Each string of startWords and targetWords consists of lowercase English letters only.
No letter occurs more than once in any string of startWords or targetWords.
*/
#ifdef _CVERSION_
//C
/*

*/
int wordCount(char ** startWords, int startWordsSize, char ** targetWords, 
              int targetWordsSize){

}

void Test_GG_wordCount()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Time Limit Exceeded
*/
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int retVal = 0;

        //1. Add to map
        unordered_map<int, unordered_set<string>> umap;
        for(string s : startWords) {
            umap[s.length()].insert(reArrange(s));
        }

        //2. Check each string in targetWords
        for(string s : targetWords) {
            auto it = umap.find(s.length()-1);
            if(it == umap.end()){
                continue;
            }
            string tmpStr;
            for(int i=0; i<s.length(); ++i) {
                tmpStr = s;
                tmpStr.erase(i, 1);
                if((it->second).count(reArrange(tmpStr)) != 0) {
                    retVal++;
                    break;
                }
            }            
        }
        return retVal;
    }
    
    string reArrange(string str) {
        string retStr;
        int letters[26] = {0};
        for(int i=0; i<str.length(); ++i) {
            int askii = str.at(i) - 'a';
            letters[askii]++;
        }
        for(int i=0; i<26; ++i) {
            if(letters[i] == 0) continue;
            string val = std::to_string(letters[i]);
            char c = (char)(i+(int)'a');
            retStr = retStr + val + c;
        }
        return retStr;
    }
};

void Test_GG_wordCount()
{
    LOGD("[CPP] %s\n", __TIME__);
    string start[] = {"ant","act","tack"};
    string target[] = {"tack","act","acti"};
    vector<string> startWords(start, start+3);
    vector<string> targetWords(target, target+3);
    Solution *solution = new Solution();
    int ans = solution->wordCount(startWords, targetWords);
    delete solution;
    LOGD("Ans: %d\n", ans); //expect 3
}

#endif //_CPPVERSION_
