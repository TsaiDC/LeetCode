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

#ifdef _0068_
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
https://leetcode.com/problems/text-justification/
68. Text Justification

Given an array of strings words and a width maxWidth, format the text such that each line has 
exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each 
line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on 
a line does not divide evenly between words, the empty slots on the left will be assigned more 
spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between 
words.

Note:

# A word is defined as a character sequence consisting of non-space characters only.
# Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
# The input array words contains at least one word.

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", 
because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.

Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a",
"computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth

*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_fullJustify()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Ref Solution
Runtime: 0 ms Beats 100%
Memory: 7.3 MB Beats 64.58%
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int left = 0; 
        vector<string> result;

        while (left < words.size()) {
            int right = findRight(left, words, maxWidth);       
            string str = justify(left, right, words, maxWidth);
            result.push_back(str);
            left = right + 1;
        }

        return result;
    }

private:
    int findRight(int left, vector<string>& words, int maxWidth) {
        int right = left;
        int sum = words[right++].length();

        while (right < words.size() && (sum + 1 + words[right].length()) <= maxWidth)
            sum += 1 + words[right++].length();

        return right - 1;
    }

    string justify(int left, int right, vector<string>& words, int maxWidth) {        
        if (right - left == 0) return padResult(words[left], maxWidth);

        bool isLastLine = (right == words.size() - 1);
        int numSpaces = right - left;
        int totalSpace = maxWidth - wordsLength(left, right, words);

        string space = isLastLine ? " " : blank(totalSpace / numSpaces);
        int remainder = isLastLine ? 0 : totalSpace % numSpaces;

        string result;
        for (int i = left; i <= right; i++) {
            result += words[i];
            result += space;
            if(remainder-- > 0) {
                result += " ";
            }
        }
        result.erase(result.find_last_not_of(" \n\r\t")+1);        
        return padResult(result, maxWidth);
    }

    int wordsLength(int left, int right, vector<string>& words) {
        int wordsLength = 0;
        for (int i = left; i <= right; i++) wordsLength += words[i].length();
        return wordsLength;
    }

    string padResult(string result, int maxWidth) {
        return result + blank(maxWidth - result.length());
    }

    string blank(int length) {
        if(length<=0) return "";
        string s(length, ' ');
        return s;
    }
};

void Test_GG_fullJustify()
{ 
    vector<string> input{"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> ans;
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    ans = solution->fullJustify(input, maxWidth);
    delete solution;
    
    for(auto s : ans) {
        LOGD("[ANS] %s\n",s.c_str());
    }
}

#endif// _CPPVERSION_
#endif//_0068_