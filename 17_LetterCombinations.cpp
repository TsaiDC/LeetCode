//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>

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
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

vector<string> letterCombinations(string digits) {
    int c = 4;
    int leng = digits.size();
    int total = pow(c, leng);
    vector<int> row;
    vector<string>ret;
    
    if(leng == 0) {
//        return {};
        return vector<string>();
    }
    LOGD("Str: %s, Leng: %d, str: %c, total: %d\n", digits.c_str(), leng, digits.at(0), total);
    
    
    
    char table[][4] = {
    {'*', '*', '*', '*'},  //0
    {'*', '*', '*', '*'},  //1
    {'a', 'b', 'c', '*'},  //2
    {'d', 'e', 'f', '*'},  //3
    {'g', 'h', 'i', '*'},  //4
    {'j', 'k', 'l', '*'},  //5
    {'m', 'n', 'o', '*'},  //6
    {'p', 'q', 'r', 's'},  //7
    {'t', 'u', 'v', '*'},  //8
    {'w', 'x', 'y', 'z'},  //9
    };
    
    for(int i=leng - 1; i>=0; i--)
    {
        c = pow(4, i);
        row.push_back(c);        
    }    

    int j = 0;
    int dig = 0;
    string str;
    for(int xj=0; xj<total; ++xj)
    {
        j = xj;
        str="";
        for(int i=0; i<row.size(); ++i)
        {
            if(digits.at(i) == '2') dig = 2;
            else if(digits.at(i) == '3') dig = 3;
            else if(digits.at(i) == '4') dig = 4;
            else if(digits.at(i) == '5') dig = 5;
            else if(digits.at(i) == '6') dig = 6;
            else if(digits.at(i) == '7') dig = 7;
            else if(digits.at(i) == '8') dig = 8;
            else if(digits.at(i) == '9') dig = 9;
            
            LOGD("total: %d, i: %d dig: %d = j: %d, %d => %c\n", total, i, dig, j, j/row[i], table[dig][j/row[i]]);
            
            if(table[dig][j/row[i]] == '*') {
                break;
            }

            str.push_back(table[dig][j/row[i]]);            
            j = j - (j/row[i])*row[i];
        }
        if(str.size() == leng) {
            ret.push_back(str);
        }
    }
#if 1
    for(int i=0; i<ret.size(); ++i)
    {
        LOGD("Str: %s\n", ret[i].c_str());
    }
#endif
    return ret;
}

void Test_letterCombinations()
{
    LOGD("%s\n", __TIME__);

    string input = "2";
    vector<string> result = letterCombinations(input);
    LOGD("Done \n");
}
