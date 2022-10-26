//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#define _CPPVERSION_

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
// Unorder Map:
// https://shengyu7697.github.io/std-unordered_map/
// https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/
//

/*
https://leetcode.com/problems/minimum-time-difference/
539. Minimum Time Difference

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 
Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".

*/


#ifdef _CVERSION_
//C
/*

*/

int findMinDifference(char ** timePoints, int timePointsSize){

}

void Test_GG_findMinDifference()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //1. Sorting
        vector<int> sortedTime;
        
        for(string s: timePoints) {
            int val = toInt(s);
            sortedTime.push_back(val);
        }
//        std::sort (sortedTime.begin(), sortedTime.end(), mycompare);
//        std::sort (sortedTime.begin(), sortedTime.end(), std::less<int>());
        //2. Difference
        int lastPos = sortedTime.size()-1;
        int minDiff = (sortedTime[0] + 24*60) - sortedTime[lastPos];

        for(int i=1; i<sortedTime.size(); ++i) {
            if((sortedTime[i]) - (sortedTime[i-1]) < minDiff) {
                minDiff = (sortedTime[i]) - (sortedTime[i-1]);
            }
            if(minDiff == 0) {
                return minDiff;
            }
        }
        
        return minDiff;
    }
    
    static int toInt(string s) {
        int pos = s.find_first_of(":");
        string hour = s.substr(0, pos);
        string min = s.substr(pos+1);
//        LOGD("H: %s, M: %s\n", hour.c_str(), min.c_str());
        LOGD("H: %d, M: %d\n", atoi(hour.c_str()), atoi(min.c_str()));
        return atoi(hour.c_str())*60 + atoi(min.c_str());
    }
};

void Test_GG_findMinDifference()
{    
    LOGD("[CPP] %s\n", __TIME__);

    int weight[] = {1, 3};
    vector<int> input(weight, weight+2);
    Solution *solution = new Solution();
    delete solution;
}

#endif// _CPPVERSION_