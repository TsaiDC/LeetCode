//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

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
#define LENGTH 1000
    cout<<"Input: "<<s<<endl;
	string ret ="";
    if(s.length() <=1) {
	    return s;
	}
    else if(s.length() ==2) {
        if (s.at(0) != s.at(1)) {
            ret.push_back(s.at(0));
            return ret;
        }
        else {
            return s;
        }
    }

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
        cout<<flag[i]<<" ";
    }
    cout<<endl;
    
    vector<int>peakPos;
    vector<string>retStr;
    for(int i=1; i<s.length(); ++i)
    {
        if (flag[i] == 0 && flag[i-1] > 0) {
            cout<<"Peak: " <<i-1<<endl;
            peakPos.push_back(i-1);
        }
        else if (i == s.length()-1 && flag[i] != 0){
            cout<<"Peak: " <<i<<endl;
            peakPos.push_back(i);
        }
    }
    
    for (int i=0; i<peakPos.size(); ++i)
    {
        cout<<"Pos: "<< peakPos[i]<<endl;
    
        ret = "";
        ptr = flag[peakPos[i]];
        idx = peakPos[i];
        
        cout<<"idx: " <<idx<<endl;
        mdr = idx - flag[idx]/2;    
        cout<<"start: "<<mdr <<" str: "<<s.at(mdr)<<endl;
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
        }
        retStr.push_back(ret);
    }

    ret ="";
    for(int i=0; i<retStr.size(); ++i)
    {
        cout<<"Ans: "<<retStr[i]<<endl;
        if(retStr[i].size() > ret.size()) {
            ret = retStr[i];
        }
    }
    
    if(ret.size() == 0) {
        ret.push_back(s.at(0));        
    }

    return ret;
}

void Test_longestPalindrome()
{
    LOGD("%s\n", __TIME__);
#define ITEM_NUM 7    
    string input[ITEM_NUM][2] = 
    {
        {"ac",  "a"},
        {"aba", "aba"},
        {"abb",  "bb"},
        {"aaaa", "aaaa"},
        {"abacab", "bacab"},
        {"abcda", "a"},
        {"bananas", "anana"},
    };
    
//  string input = "ac";
//  string input = "aba";
//	string input = "abb";
//	string input = "aaaa";
//	string input = "abacab";
//	string input = "abcda";
//	string input = "bananas";    
 /*   
	for(int i=0; i<1000; ++i)
    {
	    input.push_back('a');
//        cout<<i<<" "<<input.at(i)<<endl;
    }

    for(int i=0; i<input.length(); ++i)
    {
        cout<<i<<" "<<input.at(i)<<endl;
    }
*/
    for (int i=0; i< ITEM_NUM; ++i)
    {
        if (input[i][1] == longestPalindrome(input[i][0])) {
            cout<<"Input: "<<input[i][0] << " Pass"<<endl;
        }
        else {
            cout<<"Input: "<<input[i][0] << " Fail"<<endl;
        }
    }    
}
