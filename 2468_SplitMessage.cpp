//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <algorithm>

#include "apiheader.h"

#ifdef _2468_
using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#define _CPPVERSION_

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
// Unorder Map:
// https://shengyu7697.github.io/std-unordered_map/
// https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/
//

/*
https://leetcode.com/problems/split-message-based-on-limit/
2468. Split Message Based on Limit

You are given a string, message, and a positive integer, limit.

You must split message into one or more parts based on limit. 
Each resulting part should have the suffix "<a/b>", where "b" is to be replaced with the 
total number of parts and "a" is to be replaced with the index of the part, 
starting from 1 and going up to b. Additionally, 
the length of each resulting part (including its suffix) should be equal to limit, 
except for the last part whose length can be at most limit.

The resulting parts should be formed such that when their suffixes are removed and they are 
all concatenated in order, they should be equal to message. 
Also, the result should contain as few parts as possible.

Return the parts message would be split into as an array of strings. 
If it is impossible to split message as required, return an empty array.

Example 1:

Input: message = "this is really a very awesome message", limit = 9
Output: [
"thi<1/14>","s i<2/14>","s r<3/14>","eal<4/14>","ly <5/14>","a v<6/14>","ery<7/14>",
" aw<8/14>","eso<9/14>","me<10/14>"," m<11/14>","es<12/14>","sa<13/14>","ge<14/14>"]

Explanation:
The first 9 parts take 3 characters each from the beginning of message.
The next 5 parts take 2 characters each to finish splitting message. 
In this example, each part, including the last, has length 9. 
It can be shown it is not possible to split message into less than 14 parts.

Example 2:

Input: message = "short message", limit = 15
Output: ["short mess<1/2>","age<2/2>"]
Explanation:
Under the given constraints, the string can be split into two parts: 
- The first part comprises of the first 10 characters, and has a length 15.
- The next part comprises of the last 3 characters, and has a length 8.

Constraints:

1 <= message.length <= 10^4
message consists only of lowercase English letters and ' '.
1 <= limit <= 10^4
*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_splitMessage()
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
    vector<string> splitMessage(string message, int limit) {
        
    }
};

void Test_GG_splitMessage()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;
}

#endif// _CPPVERSION_
#endif//_2468_