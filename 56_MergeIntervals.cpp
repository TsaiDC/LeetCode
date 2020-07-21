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
class Solution {
public:
    vector< vector<int> > merge(vector< vector<int> >& intervals) {
        vector< vector<int> > ans;
        return ans;
    }
};

void Test_merge()
{
    // int arr1[] = {1,0};
    // int arr2[] = {2,0};
    // int arr3[] = {3,1};
    // int arr4[] = {3,2};
    // int k = 4;
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
    delete solution;
}