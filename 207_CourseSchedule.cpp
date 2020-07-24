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
https://leetcode.com/problems/course-schedule/
207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

*/

#if 0 //My Solution
class Solution {
public:
    vector<int> findOrder(int numCourses, vector< vector<int> >& prerequisites) {
        return findOrder_My(numCourses, prerequisites);
    }

    vector<int> findOrder_My(int numCourses, vector< vector<int> >& prerequisites) {
        LOGD("N: %d, Size: %d\n", numCourses, prerequisites.size());
        vector<int> ans;
        int *checked = new int[numCourses];
        vector< vector<int> >map(numCourses);
        for(int i=0; i<numCourses; ++i)
            checked[i]=0;

        int x, y;
        for(int i=0; i<prerequisites.size(); ++i)
        {
            x = prerequisites[i][0];
            y = prerequisites[i][1];
            LOGD("[%d, %d]\n", x, y);                        
            map[x].push_back(y);
        }
#if 0
        printf("Map:\n");
        for(int i=0; i<map.size(); ++i)
        {
            printf("%d: ", i);
            for(int j=0; j<map[i].size(); ++j)
            {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
#endif
        for(int i=0; i<map.size(); ++i)
        {
            if(map[i].empty()) {
                ans.push_back(i);
                checked[i] = 1;
                LOGD("Push: %d\n", i);
            }
        }
        
        bool isContinue, isHit;
        int idx = 0;
        vector<int>row;
        do{
            isContinue = false;
            for(int i=0; i<map.size(); ++i)
            {                
                if(checked[i] == 1) continue;
                
                row = map[i];
                isHit = true;
                for(int j=0; j<row.size(); ++j)
                {
                    idx = row[j];
                    LOGD("i: %d, idx: %d \n", i, idx);
                    if(checked[idx]==0) {
                        isHit = false;
                        break;
                    }
                }
                LOGD("Check: %d, isHit: %d\n", i, isHit);
                if(isHit) {
                    ans.push_back(i);
                    checked[i] = 1;
                    isContinue = true;
                    LOGD("Push: %d\n", i);
                }
            }
        }while(isContinue);        
        delete [] checked;
        if(ans.size() != numCourses) ans.clear();
        return ans;
    }
};
#endif

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return true;   
    }
};

void Test_canFinish()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {0,1};
    int arr2[] = {0,2};
    int arr3[] = {1,2};
    int k = 3;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> num1(arr1, arr1+n);
    vector<int> num2(arr2, arr2+n);
    vector<int> num3(arr3, arr3+n);
    vector< vector<int> >prerequisites;
    prerequisites.push_back(num1);
    prerequisites.push_back(num2);
    prerequisites.push_back(num3);

    Solution *solution = new Solution();
    bool b = solution->canFinish(k, prerequisites);
    LOGD("Ans: %d\n", b);
   
    delete solution;
}