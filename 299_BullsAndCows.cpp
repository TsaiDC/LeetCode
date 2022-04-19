//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <climits>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define _CPPVERSION_

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#define LOGE(...)
#endif

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//

/*
https://leetcode.com/problems/bulls-and-cows/
299. Bulls and Cows

You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. 
When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but 
are located in the wrong position. Specifically, the non-bull digits in the guess that 
could be rearranged such that they become bulls.

Given the secret number secret and your friend's guess guess, 
return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the 
number of cows. Note that both secret and guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"


Example 2:

Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:

"1123"        "1123"
  |      or     |
"0111"        "0111"

Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits 
can only be rearranged to allow one 1 to be a bull.


Constraints:

* 1 <= secret.length, guess.length <= 1000
* secret.length == guess.length
* secret and guess consist of digits only.

*/
#ifdef _CVERSION_
//C
/*

*/
char * getHint(char * secret, char * guess){

}

void Test_GG_getHint()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
class Solution {
public:
    string getHint(string secret, string guess) {
        
    }
};

void Test_GG_getHint()
{
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;    
}

#endif //_CPPVERSION_
