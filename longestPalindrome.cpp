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
#define LENGTH 2000
    cout<<"Input: "<<s<<endl;
	string ret;
    if(s.length() <=1) {
	    return s;
	}
/*	
	else if(s.length() ==2 && s.at(0) != s.at(1)) {
	    ret.push_back(s.at(0));
	    return ret;
	}
*/
    
//    int *flag = new int[s.length()];
//    memset(flag, 0, sizeof(int)*s.length());
    int flag[LENGTH];
    memset(flag, 0, sizeof(int)*LENGTH);

	
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
        cout<<flag[i]<<" ";
    }
    cout<<endl;
    
    cout<<"idx: " <<idx<<endl;
    mdr = idx - flag[idx]/2;    
    cout<<"start: "<<mdr <<" str: "<<s.at(idx)<<endl;
//    memset(flag, 0, sizeof(int)*s.length());
	memset(flag, 0, sizeof(int)*LENGTH);
    
	bool isOdd = false;
	if( (ptr < 3) &&
	    ((mdr-1) >=0) && 
	    ((mdr+1) <= s.length()-1) && 
		s.at(mdr-1) == s.at(mdr+1)) {
		isOdd = true;
    }
	
    if (isOdd) {
        cout<<"Odd" <<endl;
        flag[mdr] = 1;
        for (int i=1; i<s.length(); i++)
        {
		    cout<<"Mdr: " <<mdr<<" i: "<<i<<" Leng: "<<s.length()<<endl;
            if((mdr + i) > (s.length()-1) ||((mdr - i) < 0)) {
                break;
            }

			if (s.at(mdr + i) == s.at(mdr - i)) {
				flag[mdr + i] = 1;
				flag[mdr - i] = 1;
			}
			else {
				break;
			}

        }
    }
    else {
        cout<<"Even" <<endl;      
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
    
    cout<<"======"<<endl;
    for(int i=0; i<s.length(); ++i)
    {
        cout<<flag[i]<<endl;
        if (flag[i] ==1) {
            ret.push_back(s.at(i));
        }
    }
    cout<<endl;
    cout<<"Str: "<<ret<<endl;

    if(ret.length() ==0) {
	    ret.push_back(s.at(0));
	    return ret;
	}
//    delete [] flag; 
    return ret;
}

void Test_longestPalindrome()
{
    printf("[DBG] %s(%d) %s\n", __FUNCTION__, __LINE__, __TIME__);
//    string input = "aba";
//	string input = "abb";
//	string input = "aaaa";
	string input = "abacab";
 /*   
	for(int i=0; i<1000; ++i)
    {
	    input.push_back('a');
//        cout<<i<<" "<<input.at(i)<<endl;
    }
*/
    for(int i=0; i<input.length(); ++i)
    {
        cout<<i<<" "<<input.at(i)<<endl;
    }
    
    cout<<"Input: "<<input<<" Result: "<<longestPalindrome(input);    
}
