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
    string ret;
    int *flag = new int[s.length()];
    memset(flag, 0, sizeof(int)*s.length());

    for(int i=0; i<s.length(); ++i)
    {        
        if (i==0) {            
            flag[i] = 0;
        }
        else {
            if(i!= s.length()-1) {
                if (s.at(i-1) == s.at(i+1)) {
                    flag[i] = flag[i-1] + 1;
                }
                else if (s.at(i-1) == s.at(i)) {
                    flag[i] = flag[i-1] + 1;
                }
                else {
                    flag[i] = 0;
                }
            }
            else {
                if (s.at(i-1) == s.at(i)) {
                    flag[i] = flag[i-1] + 1;
                }
                else {
                    flag[i] = 0;
                }
            }
        }
    }
    
    int ptr = 0, idx = 0,mdr = 0;
    for(int i=0; i<s.length(); ++i)
    {
        if (flag[i] > ptr) {
            ptr = flag[i];
            idx = i;
        }
//        cout<<flag[i]<<ends;
    }
//    cout<<endl;
    
//    cout<<"idx: " <<idx<<endl;
    mdr = idx - flag[idx]/2;    
//    cout<<"start: "<<mdr <<" str: "<<s.at(idx)<<endl;
    memset(flag, 0, sizeof(int)*s.length());
    
    if (idx%2 == 0) {
//        cout<<"Odd" <<endl;
        flag[mdr] = 1;
        for (int i=1; i<s.length(); i++)
        {
            if((mdr + i) > s.length()) {                
                break;
            }
            else if((mdr - i) < 0) {                
                break;
            }
            else {
                if (s.at(mdr + i) == s.at(mdr - i)) {
                    flag[mdr + i] = 1;
                    flag[mdr - i] = 1;
                }
                else {
                    break;
                }
            }                
        }
    }
    else {
//        cout<<"Even" <<endl;      
        for (int i=mdr, j=mdr-1; i<s.length() && j>=0; ++i, --j)
        {
            if (s.at(i) == s.at(j)) {
                flag[i] = 1;
                flag[j] = 1;                
            }
            else {
                break;
            }
        }
    }
    
//    cout<<"======"<<endl;
    for(int i=0; i<s.length(); ++i)
    {
//        cout<<flag[i]<<endl;
        if (flag[i] ==1) {
            ret.push_back(s.at(i));
        }
    }
//    cout<<endl;
//    cout<<"Str: "<<ret<<endl;

    delete [] flag; 
    return ret;
}

void Test_longestPalindrome()
{
    printf("[DBG] %s(%d) %s\n", __FUNCTION__, __LINE__, __TIME__);
    string input = "abcba";
    
    for(int i=0; i<input.length(); ++i)
    {
        cout<<i<<" "<<input.at(i)<<endl;
    }
    
    cout<<"Input: "<<input<<" Result: "<<longestPalindrome(input);    
}