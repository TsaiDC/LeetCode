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
    cout<<"Input: "<<s<<" Row: "<<numRows<<endl;

    if(numRows <= 1) {
        return s;
    }
    string ret = "";
    int strLen = s.length();
    int blockSize = numRows + (numRows-2);
    int blocks = (strLen+blockSize)/blockSize;

    LOGD("Strleng: %d, Block Size: %d, Block: %d\n", strLen, blockSize, blocks);
    int x=blocks*(numRows-1), row=numRows;
    int tmp = 0;

    for(int j=0; j<row ; ++j)
    {
        for(int i=0; i<x; ++i)
        {
            if((i%(row-1) == 0) || ((i+j)%(row-1) == 0)) {
                tmp = 2*i+j;
//                printf("%d ", tmp);
                if(tmp<strLen) {
                    ret.push_back(s.at(tmp));
                }
            }
        }
    }
//    printf("\n");
    LOGD("Result: %s\n", ret.c_str());
    return ret;
}
void Test_convert()
{
    LOGD("%s\n", __TIME__);
    convert("", 5);
}
