//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

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
https://leetcode.com/problems/task-scheduler/
621. Task Scheduler

Given a char array representing tasks CPU need to do. 
It contains capital letters A to Z where different letters represent different tasks. 
Tasks could be done without original order. 
Each task could be done in one interval. 
For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, 
there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 
["A","A","B","B","C","C","D","D","E","E","F","F","G","G","H","H","I","I","J","J","K","K","L","L","M","M","N","N","O","O","P","P","Q","Q","R","R","S","S","T","T","U","U","V","V","W","W","X","X","Y","Y","Z","Z"]
2
Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

//AAABBB
//0361
//AB_AB_AB
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_idx(-1, tasks.size());
        map<char, int> mapRecord;
        map<char, int>::iterator iter;
        int leng = tasks.size();
        int max_leng = leng*(n+1);
        char *p = (char*) malloc(sizeof(char)*max_leng);
        memset(p, '\0', max_leng);

        for(int i=0; i<tasks.size(); ++i)
        {
            iter = mapRecord.find(tasks[i]);
            if(iter != mapRecord.end()) {
                //Exist
                int next_idx = iter->second + n + 1;
                if(p[next_idx]=='\0') {
                    p[next_idx]=tasks[i];
                    mapRecord[tasks[i]] = next_idx;
                }
                else {
                    //Shift to right
                    p[next_idx]=tasks[i];
                }
            }
            else {
                //First appear
                //1. Update Idx record list
                for(int j=0; j<i; ++j) {
                    if(task_idx[j]>0) task_idx[j]++;
                }

                //2. Update the last idx map
                for(iter = mapRecord.begin(); iter != mapRecord.end(); iter++)
                    iter->second+=1;

                //3. Update the char idx.
                task_idx[i] = 0;
                
                //4. Refresh record
                memset(p, '\0', max_leng);
                for(int j=0; j<i; ++j) {
                    p[task_idx[j]] = tasks[j];
                }
            }
        }
        free(p);
        return 0;
    }
#if 0
    int leastInterval(vector<char>& tasks, int n) {
        int leng = tasks.size();
        int max_leng = leng*(n+1);
        char *p = (char*) malloc(sizeof(char)*max_leng);
        memset(p, '\0', max_leng);
        map<char, int> mapRecord;
        map<char, int>::iterator iter;
        int idx=0;
        for(int i=0; i<tasks.size(); ++i)
        {
            if(idx>=max_leng) {
                LOGE("ERROR\n");
                break;
            }

            iter = mapRecord.find(tasks[i]);
            if(iter != mapRecord.end()) {                
                idx= iter->second + n + 1;
                LOGD("%c(%d) -> (%d)\n", tasks[i], iter->second, idx);
                while(p[idx]!='\0') idx++;
                p[idx]=tasks[i];
                mapRecord[tasks[i]] = idx;
            }
            else {
                idx=0;
                while(p[idx]!='\0') idx++;
                LOGD("%c -> (%d)\n", tasks[i], idx);
                p[idx]=tasks[i];
                mapRecord[tasks[i]] = idx;
            }
        }
        
        printf("\n");
        idx=0;
        for(int i=0; i<max_leng; i++)
        {
            if(p[i]!='\0') {
                printf("%c", p[i]);
                idx++;
            }
            else {
                printf("_");
            }
            if(idx==leng) {
                idx = i+1;
                break;
            }
        }
        printf("\n idx: %d\n", idx);

        free(p);
        return idx;
    }
#endif
};

void Test_TaskScheduler()
{
    LOGD("%s\n", __TIME__);
//    char arr1[] = {'A','A','A','B','B','B'};
    char arr1[] = {'A','A','B','B','C','C','D','D','E','E','F','F','G','G','H','H','I','I','J','J','K',
                   'K','L','L','M','M','N','N','O','O','P','P','Q','Q','R','R','S','S','T','T','U','U',
                   'V','V','W','W','X','X','Y','Y','Z','Z'};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<char> input1(arr1, arr1+n);
    Solution *solution = new Solution();
    solution->leastInterval(input1, 2);
    delete solution;
}