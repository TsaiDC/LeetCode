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
#if 0
    int j1=0, j2 = 0, k=0, m=1;
    for(int i=0; i<s.length(); ++i)
    {
        cout<<"+++"<<s.at(i)<<endl;
        j1=i-m;
        j2=i+m;
        while ( j1>=0 && j2<s.length())
        {
            if(s.at(i) != s.at(i+1)){
                //aba, b!=a
                if(s.at(j1) == s.at(j2)) {
                    ++m;
                }
            }
            else {
                //abba, b==b
            }
        }
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