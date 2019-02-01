//g++ main.cpp addTwoNumbers.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "apiheader.h"

using namespace std;

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

int lengthOfLongestSubstring(string s) {
    return 0;
}

void Test_lengthOfLongestSubstring()
{
    printf("[DBG] %s(%d) %s\n", __FUNCTION__, __LINE__, __TIME__);
    lengthOfLongestSubstring(NULL);
}