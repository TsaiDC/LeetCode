#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>

#include "apiheader.h"

using namespace std;

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf("[D] %s(%d): ", __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#endif

/*
https://leetcode.com/problems/reverse-integer/
7. Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Assume we are dealing with an environment which could only store integers 
within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when 
the reversed integer overflows.
*/

int reverse(int x)
{
    cout<<"Input: "<<x<<endl;
    int input = x;
    string ret ="", tmpStr;
    int retInt = 0;
    if(input < 0) {
        ret += "-";
        input *= -1;
    }
    std::stringstream ss;
    ss<<input;
    tmpStr = ss.str();
    cout<<"Str: "<<tmpStr <<endl;
  
    for (std::string::reverse_iterator rit=tmpStr.rbegin(); rit!=tmpStr.rend(); ++rit)
    {
      std::cout << *rit;
      ret +=*rit;
    }
  
    std::istringstream is(ret);
    is >> retInt;
    
    LOGD("Result Str: %s, retInt: %d\n", ret.c_str(), retInt);
    
    return retInt;
}

void Test_reverse()
{
    LOGD("%s\n", __TIME__);
    reverse(-2147483648);
}
