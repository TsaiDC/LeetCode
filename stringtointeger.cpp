#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <cmath>

#include "apiheader.h"

using namespace std;

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf("[D] %s(%d): ", __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#endif

/*
https://leetcode.com/problems/string-to-integer-atoi/
8. String to Integer (atoi)

Implement atoi which converts a string to an integer.
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
             
Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
             
Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/

int myAtoi(string str) 
{
//#define LOGD(...)
    cout<<"Input: "<<str<<endl;
	if(str.empty()){
        return 0;
    }
	
    int retInt = 0;
	string inStr = str;
	string retStr = "";
	double retDouble = 0;
	double min = -(pow(2,31));
	double max = (pow(2,31))-1;
	bool isPlus = true;
	int dotCount = 0;

	//Remove first spaces
	for(int i=0; i<inStr.length(); ++i)
	{
	    if(!retStr.empty() && inStr.at(i) == ' ') {
		    break;
	    }
	    if(inStr.at(i) != ' '){
		    retStr.push_back(str.at(i));
		}
	}
	if(retStr.empty()){
        return 0;
    }

	//Special case, start with a letter
	if(retStr.at(0) != '+' &&
	   retStr.at(0) != '-' &&	   
	   ( retStr.at(0) < '0' || retStr.at(0) > '9')) {
		return 0;
	}

	if(retStr.at(0) == '-' ||
	   retStr.at(0) == '+') {
	    isPlus = retStr.at(0) == '-' ? false : true;
		retStr.replace(0,1,"");
	}

	LOGD("retStr: %s, isPlus: %d\n", retStr.c_str(), isPlus);

	inStr ="";
	//Remove all letters
	for(int i=0; i<retStr.length(); ++i)
	{
	    if (retStr.at(i) == '.' ) {
		    LOGD("Dot at %d\n", i);
			if(++dotCount>1) {
			   break;; //e.g, "xx.xx.xx"
			}			
		    if(i==0) {
			    return 0; //e.g, ".xxxx"				
			} else {
			    inStr.push_back(retStr.at(i));
			}
		}
		else if ( retStr.at(i) >= '0' && retStr.at(i) <= '9') {
		    inStr.push_back(retStr.at(i));
		}
		else {
		    break;
		}
	}	
	
	retStr = inStr;
	if(retStr.empty()){
	    LOGD("Empty Size\n");
        return 0;
    }
    if (!isPlus) {
	    retStr = "-" + retStr;
	}
	LOGD("Refine Str: %s\n", retStr.c_str());
	istringstream(retStr.c_str()) >> retDouble;
//	cout<<"Double: "<<retDouble<<endl;
//	cout<<"Max: "<<max <<" min: "<<min<<endl;
	if(retDouble > max) {
	    retInt = max;
	}
	else if(retDouble < min) {
	    retInt = min;
	}
	else {
	    retInt = (int)retDouble;
	}
//	cout<<"===========Int: "<<retInt<<endl;
    return retInt;
}

void Test_myAtoi()
{
    LOGD("%s\n", __TIME__);

#define ITEM_NUM 15
    string input[ITEM_NUM] = 
    {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332", 
        "",
		"-",
		" ",
		"3.14159",
		"+1",
		"+-2",
		"+",
		"  -0012a42",
		"   +0 123",
		"-5-"
    };
    
    int output[ITEM_NUM] = 
    {
        42,
        -42,
        4193,
        0,
        -2147483648,
		0,
		0,
		0,
		3,
		1,
		0,
		0,
		-12,
		0,
		-5
    };

    for (int i=0; i<ITEM_NUM; ++i)
    {
        if(myAtoi(input[i]) != output[i]) {
            LOGD("################### Fail: %d, Str: %s != %d\n", i, input[i].c_str(), output[i] );
            break;
        }
    }
}
