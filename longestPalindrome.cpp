//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

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
*/

string longestPalindrome(string s)
{
    string strResult;
    string strBuff;
#if 1
    for(int i=0; i<s.length(); ++i)
    {
        cout<<"+++"<<s.at(i)<<endl;
        if(strBuff.back().equal(s.at(i))) {
            cout<<"EVEN!"<<endl;
        }
        strBuff.push_back(s.at(i));
        cout<<"---"<<s.at(i)<<endl;
    }
#endif
    return "TBD";
}

void Test_longestPalindrome()
{
    printf("[DBG] %s(%d) %s\n", __FUNCTION__, __LINE__, __TIME__);
    string input = "cabad";
    cout<<"Input: "<<input<<" Result: "<<longestPalindrome(input);    
}