//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>

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
https://leetcode.com/problems/palindrome-number/
9. Palindrome Number
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/

bool isPalindrome(int x)
{ 
    cout<<"Input: "<<x<<endl;
	if(x<0) {
	    return false;
	}

	int input = x;
	int n = 0;	
    int j, f;
	int quotient, remainder;	
    
    while( input/10 !=0)
    {
        input /=10;
        ++n;
    }
    input = x;    
    LOGD("Input: %d, Digit: %d\n", input, n);

	while (n>0)
	{
        f = 1;
        j = 0;
        while(j<n)
        {
            f*=10;
            ++j;
        }
        
		quotient = input/f;
		remainder = input%10;
        if(quotient != remainder) {
            LOGE("FAIL N: %d, f: %d, quotient: %d, remainder: %d, new input: %d \n", n, f, quotient, remainder, input);
            return false;
        }
		input = input- f*quotient;
		input /= 10;
		LOGD("N: %d, f: %d, quotient: %d, remainder: %d, new input: %d \n", n, f, quotient, remainder, input);
        n-=2;
	}
    LOGD("Done \n");
    return true;
}

void Test_isPalindrome()
{
    LOGD("%s\n", __TIME__);
#define ITEM_NUM 5
    int input[ITEM_NUM] = 
    {
        1,
        121,
        -121,
        10,
        1001001,
    };
    
    bool output[ITEM_NUM] = 
    {
        true,
        true,
        false,
        false,
        true,
    };
#if 1
    for(int i=0; i<ITEM_NUM; ++i)
    {    
        if (isPalindrome(input[i]) != output[i]) {
            LOGE("Fail i: %d Input: %d\n", i, input[i]);
        }
    }
#else
    isPalindrome(123);
#endif
    LOGD("Done \n");
}