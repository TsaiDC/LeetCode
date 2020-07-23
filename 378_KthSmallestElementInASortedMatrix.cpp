//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>

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
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
378. Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
1 5 9 10 11 12 13 13 15
return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

class Solution {
public:
    int kthSmallest(vector< vector<int> >& matrix, int k) {
        if(matrix.empty())return 0;
        
        int min = matrix.front().front();
        int max = matrix.back().back();
        
        vector<int> dp(max-min+1,0);
        
        int order = 0;
        for(int i=0; i<matrix.size(); ++i)
        {
             for(int j=0; j<matrix[i].size(); ++j)
             {                 
                 dp[matrix[i][j]-min]+=1;              
             }
        }
        
        for(int i=0; i<dp.size(); ++i)
        {
            order+=dp[i];
            if(order>=k) {order = i;break;}
        }        
        return (order+min);        
    }
};

void Test_kthSmallest()
{
    LOGD("%s\n", __TIME__);

    int arr1[] = {1,5,9};
    int arr2[] = {10,11,13};
    int arr3[] = {12,13,15};
    int k = 8;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> num1(arr1, arr1+n);
    vector<int> num2(arr2, arr2+n);
    vector<int> num3(arr3, arr3+n);
    vector< vector<int> > input;
    input.push_back(num1);
    input.push_back(num2);
    input.push_back(num3);
    
    Solution *solution = new Solution();
    int ans = solution->kthSmallest(input, k);
    LOGD("Ans: %d\n", ans);
    delete solution;
}