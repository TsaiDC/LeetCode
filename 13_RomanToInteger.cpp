//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>

#include "apiheader.h"

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
https://leetcode.com/problems/roman-to-integer/
13. Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.


Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 
12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, 
the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

*/


#ifdef _CVERSION_
//C
/*

*/

int romanToInt(char * s){

}

void Test_AM_romanToInt()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 64 ms, faster than 5.21% of C++ online submissions for Roman to Integer.
Memory Usage: 12.7 MB, less than 5.09% of C++ online submissions for Roman to Integer.
*/

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<string, int> map;
        unordered_map<string, int>::iterator it;
        map.insert(std::make_pair("I",  1));
        map.insert(std::make_pair("IV", 4));
        map.insert(std::make_pair("V",  5));
        map.insert(std::make_pair("IX", 9));
        map.insert(std::make_pair("X",  10));
        map.insert(std::make_pair("XL", 40));
        map.insert(std::make_pair("L",  50));
        map.insert(std::make_pair("XC", 90));
        map.insert(std::make_pair("C",  100));
        map.insert(std::make_pair("CD", 400));
        map.insert(std::make_pair("D",  500));
        map.insert(std::make_pair("CM", 900));
        map.insert(std::make_pair("M",  1000));
        
        string str1, str2;
        for(int i=0; i<s.length(); ++i)
        {
            str1 = s.substr(i,1);
            if(i == s.length()-1) {
                str2 = str1 + "#";
            }
            else {
                str2 = s.substr(i,2);
            }
            
            if((it = map.find(str2)) != map.end()) {
//                LOGD("S: %s (%d)\n", str2.c_str(), it->second);
                ++i;
                ans += it->second;
            }
            else {
                if((it = map.find(str1)) != map.end()) {
//                    LOGD("S: %s (%d)\n", str1.c_str(), it->second);
                    ans += it->second;
                }
                else {
                    //TODO
                }
            }
        }
        
        return ans;
    }
};

void Test_AM_romanToInt()
{
    LOGD("[CPP] %s\n", __TIME__);

    int ans;
//    string S = "LVIII";  //58
    string S = "MCMXCIV";  //1994
    Solution *solution = new Solution();
    ans = solution->romanToInt(S);
    LOGD("S: %s -> %d\n", S.c_str(), ans);
    delete solution;    
}

#endif// _CPPVERSION_