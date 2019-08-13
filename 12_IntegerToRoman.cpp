//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#define LOGE(...)
#endif


/*
https://leetcode.com/problems/integer-to-roman/
12. Integer to Roman

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"

Example 2:

Input: 4
Output: "IV"

Example 3:

Input: 9
Output: "IX"

Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

string intToRoman(int num) {
    string str ="";
    int leng = 13;
    int    A[] =  {1000,   900, 500,  400,  100,    90,  50,   40,  10,    9,   5,    4,   1};
    string B[] =  { "M",  "CM", "D", "CD",  "C",  "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    int a = 0, b = 0, val = num;
    
    for(int i=0; i<leng; ++i)
    {
        a = val/A[i];
        b = val%A[i];
        for(int j=0; j<a; ++j)
        {
            str.append(B[i]);
        }
//        LOGD("a: %d, b: %d, val: %d,  str: %s\n", a, b, val, str.c_str());
        val = val - a*A[i];
    }
//    LOGD("num: %d, str: %s\n", num, str.c_str());
    return str;
}

void Test_intToRoman()
{
    LOGD("%s\n", __TIME__);
    intToRoman(3);
    intToRoman(4);
    intToRoman(99);
    intToRoman(58);
    intToRoman(1994);
    LOGD("Done \n");
}