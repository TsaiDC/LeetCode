//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <queue>

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
https://leetcode.com/problems/course-schedule-ii/
210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, 
for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector< vector<int> >& prerequisites) {
        vector<int> ans;
        return ans;
    }
};

void Test_findOrder()
{
    // int arr1[] = {3,2,1,5,6,4};
    // int k = 2;
    // int arr1[] = {3,2,3,1,2,4,5,5,6};
    // int k = 4;
    int arr1[] = {-1,2,0};
    int k = 2;
    // int arr1[] = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    // int k = 20;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> numbs(arr1, arr1+n);
    vector<int> numbs0(arr1, arr1+n);
    
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;
}