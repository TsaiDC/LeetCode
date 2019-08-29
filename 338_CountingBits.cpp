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

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//

/*
https://leetcode.com/problems/counting-bits/
338. Counting Bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
*/

int getLog2(int num)
{
    if(num == 0){
        return 0;
    }
    
    int i=0;
    int val = 2;
    while(val<= num) {
        val*=2;
        ++i;
    }
    return i;
}

int getPow2(int exp)
{
    int val = 2;
    if(exp == 0)
        return 1;
    if(exp == 1)
        return val;

    for(int i=1; i<exp; ++i)
    {
        val*=2;
    }
    return val;
}

vector<int> countBits(int num) {
    vector<int> result;

    int bitPos = 0;
    int left = 0;
 
    for(int i=0; i<=num; i++)
    {       
        if(i==0){
            result.push_back(0); //0
            continue;
        }
        if(i==1){
            result.push_back(1); //1
            continue;
        }
        bitPos = 0; left = 0;   
        bitPos = getLog2(i);
        left = i - getPow2(bitPos);
//        LOGD("i: %d, b: %d, left: %d, Result[%d]\n", i, bitPos, left, left);

        result.push_back(1 + result[left]);       
    }

    return result;
}
void Test_countBits()
{
    LOGD("%s\n", __TIME__);
    vector<int> result;
    for(int i=0; i<10; ++i)
    {
        result.clear();
        result = countBits(i);
        printf("%2d -> ",i);
        for(int j=0; j<result.size(); ++j)
        {
            printf("%d ", result[j]);
        }
        printf("\n");
    }
    LOGD("Done \n");
}