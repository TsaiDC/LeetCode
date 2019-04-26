#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "apiheader.h"

using namespace std;

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf("[D] %s(%d): ", __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#endif

/*
https://leetcode.com/problems/zigzag-conversion/
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

string convert(string s, int numRows) 
{
    string ret = "TBD";
    return ret;
}
void Test_convert()
{
    LOGD("%s\n", __TIME__);
    convert("AAA", 3);
}
