//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <map>

#include "apiheader.h"

using namespace std;

typedef map<string, int> StrIntMap;
typedef pair<string, int> StrIntPair;

/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int lengthOfLongestSubstring(string s) 
{
    printf("[DBG] %s(%d) s: %s\n", __FUNCTION__, __LINE__, s.c_str());

    int CIDX = 0;
    int Map[200];    
    int *idx = new int[s.length()];
    memset(Map, 0, sizeof(Map[0])*200);
    memset(idx, 0, sizeof(int)*s.length());

    for(int i=0; i<s.length(); ++i)
    {
        printf ("%c -> %d ", s.at(i), (int)s.at(i));
        ++CIDX;
        if(i==0) {
            idx[i] = CIDX;
            Map[(int)s.at(i)] = i+1;
            printf ("(%d) CIDX: %d, Map[%d] = %d", __LINE__, CIDX, (int)s.at(i), i+1);
            printf ("\n");
            continue;
        }
        
        if (Map[(int)s.at(i)] ==0) {
            idx[i] = CIDX;
            Map[(int)s.at(i)] = i+1;
            printf ("(%d) CIDX: %d, Map[%d] = %d", __LINE__, CIDX, (int)s.at(i), i+1);
        }
        else {
            i = Map[(int)s.at(i)];
            CIDX = 0;
            memset(Map, 0, sizeof(Map[0])*200);
            printf ("(%d) Move i: %d, Reset CIDX, MAP", __LINE__, i);
//            printf ("(%d) CIDX: %d, Map[%d] = %d", __LINE__, CIDX, (int)s.at(i), i+1);
        }
        printf ("\n");
    }
    
    for(int i=0; i<s.length(); ++i)
    {
        printf("%d ", idx[i]);
    }
    printf("\n");
    delete []idx; 
    return 0;
}

void Test_lengthOfLongestSubstring()
{
    printf("[DBG] %s(%d) %s\n", __FUNCTION__, __LINE__, __TIME__);
    lengthOfLongestSubstring("abcdbb");
}