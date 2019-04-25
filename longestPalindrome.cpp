//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "apiheader.h"

using namespace std;

//#define LOGD(...) {printf("[D] %s(%d): ", __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGD(...)

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
    if(s.length()<2){
        return s;
    }
    vector<int>OddPeak;
    vector<int>EvenPeak;
    vector<string>retStr;
	string ret ="";
    int flag[LENGTH][3];

    memset(flag, 0, sizeof(int)*LENGTH*3);

    
    for(int i=1; i<s.length(); ++i)
    {
	    //Check Odd Case, e.g. aba
        if ((i < s.length()-1) &&
		    (s.at(i-1) == s.at(i+1))) {
            flag[i][0] = 1;
        }
        else {
            flag[i][0] = 0;
        }
		if (s.at(i-1) == s.at(i)) {
		    flag[i][2] = flag[i-1][2] + 1;
		}
		
		//Check Even Case, e.g. aaaa
        if (s.at(i-1) == s.at(i)) {
            flag[i][1] = flag[i-1][1] + 1;
        }
        else {
            flag[i][1] = 0;
        }
    }

    //Refine Odd flag
    for(int i=s.length()-1; i>=0; --i)
    {
	    if(flag[i][2] > 1) {
		    int ptr = flag[i][2];
		    for(int j=i, k=flag[i][2]; j>0 && k>0; --j, --k)
			{
			    flag[j][0] = 0;
                flag[j][2] = 0;
			}
			flag[ptr/2][0] = 1;
		}
	}
	
    for(int i=1; i<s.length(); ++i)
    {
       //Find Odd Peak
       if(flag[i][0] == 1) {
           OddPeak.push_back(i);
       }
       //Find Even Peak
       if(flag[i][1] ==0 && flag[i-1][1] != 0) {
           EvenPeak.push_back(i-1);
       }
       else if(flag[i][1] !=0 && i == s.length()-1) {
           EvenPeak.push_back(i);
       }
    }
#if 0
    for(int i=0; i<s.length(); ++i)
    {
        LOGD("%d %c %d %d %d\n", i, s.at(i), flag[i][0], flag[i][2], flag[i][1]);
    }
    
    for(int i=0; i<OddPeak.size(); ++i)
    {
        LOGD("Odd Peak %d\n", OddPeak[i]);
    }

    for(int i=0; i<EvenPeak.size(); ++i)
    {
        LOGD("Even Peak %d\n", EvenPeak[i]);
    }
#endif
#if 1
    //Get Odd Peak STR
    for(int i=0; i<OddPeak.size(); ++i)
    {
//        cout<<"----------- "<<OddPeak[i]<<endl;
        int j = OddPeak[i];
        int k=1;
        ret = "";
        ret.push_back(s.at(j));
        
        while((j-k>=0) && (j+k<s.length()) && (s.at(j-k) == s.at(j+k)))
        {
            ret = s.at(j-k) + ret + s.at(j+k);
//            cout<<"Pos: "<<j<<" : "<<s.at(j-k)<<" " << ret<<" "<< s.at(j+k)<<endl;
            ++k;
        }

        retStr.push_back(ret);
    }
#endif

    //Get Even Peak Str
    for(int i=0; i<EvenPeak.size(); ++i)
    {
        int k, j;
        k = EvenPeak[i] - flag[EvenPeak[i]][1]/2;
        j = k-1;
        LOGD("P: %d, val: %d, j: %d K: %d\n", EvenPeak[i], flag[EvenPeak[i]][1], j, k);
        ret = "";
        while(j>=0 && k<s.length())
        {
            if (s.at(j) == s.at(k)) {
                ret = s.at(j) + ret + s.at(k);
            }
            else {
                break;
            }
            --j;
            ++k;
        }
        LOGD("Even: Result: %s\n", ret.c_str());
        retStr.push_back(ret);
    }

    ret ="";
    for(int i=0; i<retStr.size(); ++i)
    {
//        LOGD("Ans: %s\n", retStr[i].c_str());
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
#if 0
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

    for (int i=0; i< ITEM_NUM; ++i)
    {
        if (input[i][1] == longestPalindrome(input[i][0])) {
            cout<<"Input: "<<input[i][0] << " Pass"<<endl;
        }
        else {
            cout<<"Input: "<<input[i][0] << " Fail"<<endl;
        }
    }
#endif

#if 1
//  string input = "ac";
//  string input = "aba";
//	string input = "abb";
//	string input = "aaaaaa";
//	string input = "aacbbbb";
//	string input = "abacab";
//	string input = "abcda";
//	string input = "bananas";
//  string input = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string input = "azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc";
	//"sooos"
    cout<<"Input: "<<input<<" : "<<longestPalindrome(input)<<endl;
#endif
}
