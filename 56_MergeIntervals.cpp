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


/*
https://leetcode.com/problems/merge-intervals/
56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

#define DEBUG 1
#if DEBUG
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#define LOGE(...)
#endif

class Solution {
public:
    vector< vector<int> > merge(vector< vector<int> >& intervals) {
        vector< vector<int> > ans;
        if(intervals.empty()) return ans;
        if(intervals.size()==1) return intervals;

#if DEBUG
        LOGD("Unsort:\n");
        for(int i=0; i<intervals.size(); ++i)
        {
            printf("%d: ", i);
            for(int j=0; j<intervals[i].size(); ++j)
            {
                printf("%d ", intervals[i][j]);
            }
            printf("\n");
        }
        printf("\n");
#endif
       
        //Sort intervals[i][0]
        vector<int>row;
        for(int i=0; i<intervals.size(); ++i)
        {
            for(int j=i+1; j<intervals.size(); ++j)
            {
                if(intervals[j][0] < intervals[i][0]) {
                    row = intervals[j];
                    intervals[j] = intervals[i];
                    intervals[i] = row;
                }
            }
        }

#if DEBUG
        LOGD("Sort:\n");
        for(int i=0; i<intervals.size(); ++i)
        {
            printf("%d: ", i);
            for(int j=0; j<intervals[i].size(); ++j)
            {
                printf("%d ", intervals[i][j]);
            }
            printf("\n");
        }
        printf("\n");
#endif

        int start = intervals[0][0];
        int end = intervals[0][1];
       
        for(int i=1; i<intervals.size(); ++i)
        {
            LOGD("%d <-> %d, (%d)= %d <-> %d\n", start, end, i, intervals[i][0], intervals[i][1]);
            if(intervals[i][0] >= start && intervals[i][0] <= end){
                end = intervals[i][1] > end ? intervals[i][1] : end;
                if(i== intervals.size()-1){
                    row.clear();
                    row.push_back(start);
                    row.push_back(end);
                    ans.push_back(row);
                }
                continue;
            }
            if(intervals[i][0] > end){
                row.clear();
                row.push_back(start);
                row.push_back(end);
                ans.push_back(row);
                start = intervals[i][0];
                end = intervals[i][1];
                LOGD("Input: %d <-> %d, Update: %d <-> %d\n", row[0], row[1], start, end);
                if(i== intervals.size()-1){
                    row.clear();
                    row.push_back(start);
                    row.push_back(end);
                    ans.push_back(row);
                }
                continue;
            }
        }
       
        return ans;
    }
    vector< vector<int> > merge1(vector< vector<int> >& intervals) {
        vector< vector<int> > ans;
        if(intervals.empty()) return ans;
        int min = intervals[0][0];
        int max = intervals[0][0];
        
        for(int i=0; i<intervals.size(); ++i)
        {
            for(int j=0; j<intervals[i].size(); ++j)
            {
                if(intervals[i][j]>max) max = intervals[i][j];
                if(intervals[i][j]<min) min = intervals[i][j];
            }
        }
        
        LOGD("Min: %d, Max: %d\n", min, max);
        int num = max-min+1;
        int *checked = new int[num];
        for(int i=0; i<num; ++i)
            checked[i]=0;

        int fill_num = 0;
        int current_num = 0;
        for(int i=0; i<intervals.size(); ++i)
        {
            LOGD("Fill %d(%d)->%d(%d)\n", intervals[i].front(), intervals[i].front()-min, intervals[i].back(), intervals[i].back()-min);
            int js=intervals[i].front();
            int je=intervals[i].back();
            if(checked[js-min]==0 && checked[je-min] == 0){ 
                fill_num++;
                current_num = fill_num;
            }
            else {
                current_num = checked[js-min]==0 ? checked[je-min] : checked[js-min];
            }
            
            for(; js<=intervals[i].back(); ++js)
            {                
                checked[js-min]=current_num;                
                LOGD("%d = %d\n", js-min, current_num);
            }
        }
#if DEBUG
        printf("Checked: ");
        for(int i=0; i<num; ++i)
        {
            printf("%d ", checked[i]);
        }
        printf("\n");
#endif        
        int start = -1, end = -1;
        vector<int>row;
        for(int i=0; i<num; ++i)
        {
            if(checked[i] == 0) {
                if(start>=0 && end >=start){
                    LOGD("I: %d, Start: %d, End: %d\n", i, start, end);
                    row.clear();
                    row.push_back(start+min);
                    row.push_back(end+min);
                    ans.push_back(row);
                    start = -1;
                    continue;
                }
                else {
                    continue;
                }
            }
            if(start==-1) {start = i; LOGD("Set Start: %d\n", i);}
            if(start>=0) {
                LOGD("checked[%d]: %d ?= checked[%d]: %d\n", i, checked[i], start, checked[start]);
                if(checked[i] == checked[start]){
                    if(i==num-1){
                        end = i;
                        LOGD("Start: %d, End: %d\n", start, end);
                        row.clear();
                        row.push_back(start+min);
                        row.push_back(end+min);
                        ans.push_back(row);
                        start = i;
                        // end = -1;
                    }
                    else {
                        end = i;
                    }
                }
                else {
                    end =i-1;
                    LOGD("I: %d, Start: %d, End: %d\n", i, start, end);
                    row.clear();
                    row.push_back(start+min);
                    row.push_back(end+min);
                    ans.push_back(row);
                    start = i;
                    
                    //For last item
                    if(start == num-1){
                        LOGD("Start: %d, End: %d\n", start, start);
                        row.clear();
                        row.push_back(start+min);
                        row.push_back(start+min);
                        ans.push_back(row);
                    }
                }
            }      
        }
        
        delete [] checked;
        return ans;
    }
};

void Test_merge()
{
    int arr1[] = {1,3};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> num1(arr1, arr1+n);
    vector< vector<int> >prerequisites;
    prerequisites.push_back(num1);

    
    // int arr1[] = {1,3};
    // int arr2[] = {2,6};
    // int arr3[] = {8,10};
    // int arr4[] = {15,18};    
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // vector<int> num1(arr1, arr1+n);
    // vector<int> num2(arr2, arr2+n);
    // vector<int> num3(arr3, arr3+n);
    // vector<int> num4(arr4, arr4+n);
    // vector< vector<int> >prerequisites;
    // prerequisites.push_back(num1);
    // prerequisites.push_back(num2);
    // prerequisites.push_back(num3);
    // prerequisites.push_back(num4);

    //[[2,3],[5,5],[2,2],[3,4],[3,4]]
    //[[2,4],[5,5]]
    // int arr1[] = {2,3};
    // int arr2[] = {5,5};
    // int arr3[] = {2,2};
    // int arr4[] = {3,4};
    // int arr5[] = {3,4};    
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // vector<int> num1(arr1, arr1+n);
    // vector<int> num2(arr2, arr2+n);
    // vector<int> num3(arr3, arr3+n);
    // vector<int> num4(arr4, arr4+n);
    // vector<int> num5(arr5, arr5+n);
    // vector< vector<int> >prerequisites;
    // prerequisites.push_back(num1);
    // prerequisites.push_back(num2);
    // prerequisites.push_back(num3);
    // prerequisites.push_back(num4);
    // prerequisites.push_back(num5);
    
    // int arr1[] = {1,4};
    // int arr2[] = {0,1};
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // vector<int> num1(arr1, arr1+n);
    // vector<int> num2(arr2, arr2+n);
    // vector< vector<int> >prerequisites;
    // prerequisites.push_back(num1);
    // prerequisites.push_back(num2);
    
    
    //[[2,3],[4,6],[5,7],[3,4]]
    //[[2,7]]
    // int arr1[] = {2,3};
    // int arr2[] = {4,6};
    // int arr3[] = {5,7};
    // int arr4[] = {3,4};
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // vector<int> num1(arr1, arr1+n);
    // vector<int> num2(arr2, arr2+n);
    // vector<int> num3(arr3, arr3+n);
    // vector<int> num4(arr4, arr4+n);
    // vector< vector<int> >prerequisites;
    // prerequisites.push_back(num1);
    // prerequisites.push_back(num2);
    // prerequisites.push_back(num3);
    // prerequisites.push_back(num4);
    LOGD("%s\n", __TIME__);
    
#if 1
    LOGD("Map:\n");
    for(int i=0; i<prerequisites.size(); ++i)
    {
        printf("%d: ", i);
        for(int j=0; j<prerequisites[i].size(); ++j)
        {
            printf("%d ", prerequisites[i][j]);
        }
        printf("\n");
    }
    printf("\n");
#endif
    Solution *solution = new Solution();
    prerequisites = solution->merge(prerequisites);

#if 1
    LOGD("Ans:\n");
    for(int i=0; i<prerequisites.size(); ++i)
    {
        printf("%d: ", i);
        for(int j=0; j<prerequisites[i].size(); ++j)
        {
            printf("%d ", prerequisites[i][j]);
        }
        printf("\n");
    }
    printf("\n");
#endif
    
    delete solution;
}