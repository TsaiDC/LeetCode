//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define _CPPVERSION_

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
https://leetcode.com/problems/moving-average-from-data-stream/
346. Moving Average from Data Stream

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
 

Example 1:

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
*/
#ifdef _CVERSION_
//C
/*

*/
typedef struct {
    
} MovingAverage;


MovingAverage* movingAverageCreate(int size) {
    
}

double movingAverageNext(MovingAverage* obj, int val) {
  
}

void movingAverageFree(MovingAverage* obj) {
    
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/

void Test_FB_MovingAverage()
{
    LOGD("[C] %s\n", __TIME__);
}
#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
class MovingAverage {
public:
    MovingAverage(int size) {
        
    }
    
    double next(int val) {
        return 0;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

void Test_FB_MovingAverage()
{
    LOGD("[CPP] %s\n", __TIME__);
    MovingAverage *movingAverage = new MovingAverage(3);
    movingAverage->next(1); // return 1.0 = 1 / 1
    movingAverage->next(10); // return 5.5 = (1 + 10) / 2
    movingAverage->next(3); // return 4.66667 = (1 + 10 + 3) / 3
    movingAverage->next(5); // return 6.0 = (10 + 3 + 5) / 3
    delete movingAverage;
}

#endif //_CPPVERSION_