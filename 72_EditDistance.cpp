//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

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
https://leetcode.com/problems/edit-distance/
72. Edit Distance

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

//Solution Ref:
//https://www.itread01.com/content/1546695917.html

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        if(len1 == 0) return len2;
        if(len2 == 0) return len1;

        int lenr = len1+1;
        int lenc = len2+1;
        int up, left, left_up, min;

        int **dp = new int*[lenr];
        for(int i=0; i<lenr; i++)
        {
            dp[i] = new int[lenc];
        }

        for(int i=0; i<lenr; i++)
        {
            for(int j=0; j<lenc; j++)
            {
                if(i==0) {
                    dp[i][j] = j;
                    continue;
                }
                if(j==0) {
                    dp[i][j] = i;
                    continue;
                }
                up = dp[i-1][j] + 1;
                left = dp[i][j-1] + 1;
                left_up = dp[i-1][j-1] + (word1.at(i-1) == word2.at(j-1) ? 0 : 1);

                min = up > left ? left : up;
                min = min > left_up ? left_up : min;
                dp[i][j] = min;
            }
        }
        return min;
    }
};

void Test_minDistance()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    int min = solution->minDistance("abcd", "gbcdz");
    delete solution;
}