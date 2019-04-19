//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "apiheader.h"

using namespace std;

/*
https://leetcode.com/problems/longest-palindromic-substring/
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"


abcba
abccba
abcccba
abbaaabba
abbcdcbba

*/

string longestPalindrome(string s)
{
    int *flag = new int[s.length()];
    memset(flag, 0, sizeof(int)*s.length());
#if 1
    for(int i=0; i<s.length(); ++i)
    {        
        if (i==0) {            
            flag[i] = 0;
        }
        else {            
            if (s.at(i) == s.at(i-1)) {
                flag[i] = flag[i-1] + 1;
            }
            else {
                flag[i] = 0;
            }
        }
    }
    
    for(int i=0; i<s.length(); ++i)
    {
        cout<<flag[i]<<ends;
    }
    cout<<endl;
#endif
    delete [] flag; 
    return "TBD";
}

void Test_longestPalindrome()
{
    printf("[DBG] %s(%d) %s\n", __FUNCTION__, __LINE__, __TIME__);
    string input = "abcccbaac";
    cout<<"Input: "<<input<<" Result: "<<longestPalindrome(input);    
}