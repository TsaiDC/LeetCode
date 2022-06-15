//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
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
// Priority Queue
// https://yuihuang.com/cpp-stl-priority-queue/
//

/*
https://leetcode.com/problems/meeting-rooms-ii/
253. Meeting Rooms II

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of conference rooms required.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:
Input: intervals = [[7,10],[2,4]]
Output: 1

Constraints:

1 <= intervals.length <= 10^4
0 <= starti < endi <= 10^6

*/


#ifdef _CVERSION_
//C
/*

*/

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){

}

void Test_AM_minMeetingRooms()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/

//Time Limit Exceeded
class Solution1 {
public:
    int minMeetingRooms(vector< vector<int> >& intervals) {
    
        int count = 0;
        int ans = 0;
        for(int i=0; i<intervals.size(); ++i) {
            count = 0;
            for(int j=0; j<intervals.size(); ++j) {
                if(i == j) continue;
                if(intervals[j][0] <= intervals[i][0] &&
                   intervals[i][0] < intervals[j][1]) {
//                       LOGD("Overlap (%d, %d) -> (%d, %d)\n", intervals[i][0], intervals[i][1], intervals[j][0], intervals[j][1]);
                       ++count;
                }
            }
//            LOGD("Overlap (%d, %d) : %d\n", intervals[i][0], intervals[i][1], count);
            if(count > ans) ans = count;
        }
        return ans+1;
    }
};

/*
Runtime: 116 ms, faster than 7.62% of C++ online submissions for Meeting Rooms II.
Memory Usage: 27.8 MB, less than 5.10% of C++ online submissions for Meeting Rooms II.
*/

bool startTimeCompare(vector<int>a, vector<int>b) {
    return a[0]<b[0];
}

class Solution {
public:
    int minMeetingRooms(vector< vector<int> >& intervals) {
        //1 Sort by start time
        sort(intervals.begin(), intervals.end(), startTimeCompare);
        
        //2 Check the top of min heap, Store the end time of meeting.
        //  The top of Q is the meeting which end time close to the current time
        priority_queue<int, vector<int>, greater<int> >pq;
        
        for(int i=0; i<intervals.size(); ++i){
            if(pq.empty()){
                pq.push(intervals[i][1]);
                continue;
            }
            
            int top = pq.top();
            if(top <= intervals[i][0]) {
                pq.pop();
                pq.push(intervals[i][1]);
            }
            else {
                pq.push(intervals[i][1]);
            }
        }
        return pq.size();
    }
};


void Test_AM_minMeetingRooms()
{
    LOGD("[CPP] %s\n", __TIME__);

    //[[0,30],[5,10],[15,20]]
    vector< vector<int> >input;
    vector<int>v1;
    v1.push_back(0);
    v1.push_back(30);
    input.push_back(v1);

    vector<int>v2;
    v2.push_back(5);
    v2.push_back(10);
    input.push_back(v2);
    
    vector<int>v3;
    v3.push_back(15);
    v3.push_back(20);
    input.push_back(v3);
    
    
    Solution *solution = new Solution();    
    int ans = solution->minMeetingRooms(input);
    delete solution;
    LOGD("Ans: %d\n", ans);
}

#endif// _CPPVERSION_