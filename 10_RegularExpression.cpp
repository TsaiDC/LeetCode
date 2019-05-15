//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

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


/*
https://leetcode.com/problems/regular-expression-matching/
10. Regular Expression Matching

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

bool isMatch(string s, string p)
{ 
    cout<<"S: "<<s<<" P: "<<p<<endl;
    return true;
}

void Test_isMatch()
{
    LOGD("%s\n", __TIME__);

#define ITEM_NUM 5
    int input[ITEM_NUM] = 
    {
        1,
        121,
        -121,
        10,
        1001001,
    };
    
    bool output[ITEM_NUM] = 
    {
        true,
        true,
        false,
        false,
        true,
    };
#if 0
    for(int i=0; i<ITEM_NUM; ++i)
    {    
        if (isPalindrome(input[i]) != output[i]) {
            LOGE("Fail i: %d Input: %d\n", i, input[i]);
        }
    }
#else
    isMatch("aa", "a*");
#endif

    LOGD("Done \n");
}