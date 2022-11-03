//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>


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
// Set Ref:
// https://shengyu7697.github.io/std-unordered_set/
//
// Priority Queue:
// https://yuihuang.com/cpp-stl-priority-queue/
//

/*
https://leetcode.com/problems/single-threaded-cpu/
1834. Single-Threaded CPU

You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where 
tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at 
enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the 
following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest 
processing time. If multiple tasks have the same shortest processing time, it will choose the task 
with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.

Example 1:

Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows: 
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the 
  shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest.
  Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.

Example 2:

Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]
Explanation: The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.

Constraints:

tasks.length == n
1 <= n <= 10^5
1 <= enqueueTimei, processingTimei <= 10^9

*/
#ifdef _CVERSION_
//C
/*

*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getOrder(int** tasks, int tasksSize, int* tasksColSize, int* returnSize){

}

void Test_GG_getOrder()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime
1602 ms
Beats
17.63%
*/
//[processing time, idx]
typedef pair<long, long> PII;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        for(int i=0; i<tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        
        std:sort(tasks.begin(), tasks.end());
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        
        long curTime = 0;
        vector<int>rets;
        for(auto task:tasks) {
            while(curTime < task[0] && !pq.empty()) {
                rets.push_back(pq.top().second);
                curTime += pq.top().first;
                pq.pop();
            }
            curTime = max(curTime, (long)task[0]);
            pq.push({task[1], task[2]});
        }
        
        while(!pq.empty()) {
            rets.push_back(pq.top().second);
            pq.pop();
        }
        return rets;
    }
};

void Test_GG_getOrder()
{
    LOGD("[CPP] %s\n", __TIME__);    
    Solution *solution = new Solution();
    delete solution;    
}

#endif //_CPPVERSION_
