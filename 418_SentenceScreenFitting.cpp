//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>

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

/*
https://leetcode.com/problems/sentence-screen-fitting/
418. Sentence Screen Fitting

Given a rows x cols screen and a sentence represented as a list of strings, return the number of 
times the given sentence can be fitted on the screen.

The order of words in the sentence must remain unchanged, and a word cannot be split into two lines.
A single space must separate two consecutive words in a line.

Example 1:

Input: sentence = ["hello","world"], rows = 2, cols = 8
Output: 1
Explanation:
hello---
world---
The character '-' signifies an empty space on the screen.

Example 2:

Input: sentence = ["a", "bcd", "e"], rows = 3, cols = 6
Output: 2
Explanation:
a-bcd- 
e-a---
bcd-e-
The character '-' signifies an empty space on the screen.

Example 3:

Input: sentence = ["i","had","apple","pie"], rows = 4, cols = 5
Output: 1
Explanation:
i-had
apple
pie-i
had--
The character '-' signifies an empty space on the screen.

Constraints:

1 <= sentence.length <= 100
1 <= sentence[i].length <= 10
sentence[i] consists of lowercase English letters.
1 <= rows, cols <= 2 * 10^4

*/
#ifdef _CVERSION_
//C
/*

*/
int wordsTyping(char ** sentence, int sentenceSize, int rows, int cols){

}

void Test_GG_wordsTyping()
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
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int i=0;
        int idx;
        int itemCount = sentence.size();
        int strLen;
        int rowSpace = cols;
        int rowCount = 0;
        while(rowCount < rows) {
            idx = i% itemCount;
            ++i;
            strLen = sentence[idx].length();            
            if(strLen > cols) return 0;                        
            
            if(strLen < rowSpace) {
                rowSpace = rowSpace - strLen - 1;
                LOGD("[%d] Str[%d]: %s, rowSpace: %d,\n", rowCount, idx, sentence[idx].c_str(), rowSpace);
                if(rowSpace == 0) {
                    rowSpace = cols;
                    ++rowCount;
                }
            }
            else if(strLen == rowSpace) {
                LOGD("[%d] Str[%d]: %s, rowSpace: %d,\n", rowCount, idx, sentence[idx].c_str(), rowSpace);                
                rowSpace = cols;
                ++rowCount;
            }
            else { //if(strLen > rowSpace)                
                ++rowCount;
                if(rowCount >= rows) {
                    --i;
                    break;
                }
                rowSpace = cols - strLen - 1;
                LOGD("[%d] Str[%d]: %s, rowSpace: %d,\n", rowCount, idx, sentence[idx].c_str(), rowSpace);
                if(rowSpace == 0) {
                    rowSpace = cols;
                    ++rowCount;
                }
            }                       
        }
        LOGD("i: %d, itemCount: %d\n", i, itemCount);
        return i/itemCount;
    }
};

#if 0
//Ref Solution
class Solution {
public:
	int wordsTyping(String[] sentence, int rows, int cols)
		string s = string.Join(" ", sentence) + " ";
		int len = s.Length, count = 0;
		int[] dp = new int[len];
		for (int i = 1; i < len; ++i)
		{
			dp[i] = s[i] == ' ' ? 1 : dp[i - 1] - 1;
		}
		for (int i = 0; i < rows; ++i)
		{
			count += cols;
			count += dp[count % len];
		}
		return count / len;
	}
};
#endif

void Test_GG_wordsTyping()
{
    LOGD("[CPP] %s\n", __TIME__);
    int rows = 3, cols = 6;
    string str[] = {"a", "bcd", "e"};
//    int rows = 2, cols = 8;
//    string str[] = {"hello","world"};
//    int rows = 1, cols = 10;
//    string str[] = {"hello","leetcode"};
    
    int n = sizeof(str)/sizeof(str[0]);
    vector<string> input1(str, str+n);
    Solution *solution = new Solution();
    int b = solution->wordsTyping(input1, rows, cols);
    LOGD("Ans: %d\n", b);
    delete solution;
}

#endif //_CPPVERSION_