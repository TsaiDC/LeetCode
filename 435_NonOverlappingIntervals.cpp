//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>
#include <algorithm>

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
https://leetcode.com/problems/non-overlapping-intervals/
435. Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number 
of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

Constraints:
1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104

*/

bool myCompare(vector<int>a, vector<int>b) {
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector< vector<int> >& intervals) {
        if(intervals.empty()) {
            return 0;
        }
/*
        sort(intervals.begin(), intervals.end(), 
            [](vector<int> a, vector<int> b) {
                return a[1] < b[1];
            }
        );
*/        
        sort(intervals.begin(), intervals.end(), myCompare);
        int count=0, leftBound = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0]<leftBound) {
                count++;
            }
            else {
                leftBound = intervals[i][1];
            }
        }
        return count;
    }
};


void Test_eraseOverlapIntervals()
{
    LOGD("%s\n", __TIME__);
    
    int arr1[] = {1, 2};
    int arr2[] = {1, 3};
    int arr3[] = {2, 4};
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> input1(arr1, arr1+n1);
    vector<int> input2(arr2, arr2+n2);
    vector<int> input3(arr3, arr3+n3);

    vector< vector<int> > map;
    map.push_back(input1);
    map.push_back(input2);
    map.push_back(input3);
    
    Solution *solution = new Solution();
    int ans = solution->eraseOverlapIntervals(map);
    LOGD("Ans: %d\n", ans);
    delete solution;
}
