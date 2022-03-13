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
https://leetcode.com/problems/logger-rate-limiter/
359. Logger Rate Limiter

Design a logger system that receives a stream of messages along with their timestamps. 
Each unique message should only be printed at most every 10 seconds 
(i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. 
Several messages may arrive at the same timestamp.

Implement the Logger class:

Logger() Initializes the logger object.
bool shouldPrintMessage(int timestamp, string message) 
Returns true if the message should be printed in the given timestamp, otherwise returns false.

Example 1:

Input
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output
[null, true, true, false, false, false, true]

Explanation
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
 

Constraints:

0 <= timestamp <= 109
Every timestamp will be passed in non-decreasing order (chronological order).
1 <= message.length <= 30
At most 104 calls will be made to shouldPrintMessage.

*/
#ifdef _CVERSION_
//C
/*

*/
typedef struct {
    
} Logger;


Logger* loggerCreate() {
    
}

bool loggerShouldPrintMessage(Logger* obj, int timestamp, char * message) {
  
}

void loggerFree(Logger* obj) {
    
}

/**
 * Your Logger struct will be instantiated and called as such:
 * Logger* obj = loggerCreate();
 * bool param_1 = loggerShouldPrintMessage(obj, timestamp, message);
 
 * loggerFree(obj);
*/

void Test_GG_shouldPrintMessage()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 102 ms, faster than 54.29% of C++ online submissions for Logger Rate Limiter.
Memory Usage: 32.6 MB, less than 14.78% of C++ online submissions for Logger Rate Limiter.
*/
class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        hash<string> hash_obj;
        unsigned int hasVal = hash_obj(message);
        LOGD("%s : %d\n", message.c_str(), hasVal);
        map<unsigned int, int>::iterator iter;
        
        iter = mMapMessage.find(hasVal);
        if(iter != mMapMessage.end()){
            if(timestamp >= iter->second) {
                iter->second = timestamp +10;
                return true;
            }
            else {
                return false;
            }
        }
        else {
            mMapMessage[hasVal] = timestamp + 10;
            return true;
        }
        return false;
    }

private:
    map<unsigned int, int> mMapMessage;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
 
void Test_GG_shouldPrintMessage()
{
    LOGD("[CPP] %s\n", __TIME__);
    bool ans;
    Logger *logger = new Logger();
    ans = logger->shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
    LOGD("Ans: %d\n", ans);
    ans = logger->shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
    LOGD("Ans: %d\n", ans);
    ans = logger->shouldPrintMessage(3, "foo");  // 3 < 11, return false
    LOGD("Ans: %d\n", ans);
    ans = logger->shouldPrintMessage(8, "bar");  // 8 < 12, return false
    LOGD("Ans: %d\n", ans);
    ans = logger->shouldPrintMessage(10, "foo"); // 10 < 11, return false
    LOGD("Ans: %d\n", ans);
    ans = logger->shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
    LOGD("Ans: %d\n", ans);
 
    delete logger;
}

#endif //_CPPVERSION_