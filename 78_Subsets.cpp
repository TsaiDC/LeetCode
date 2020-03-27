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
https://leetcode.com/problems/subsets/
78. Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        vector< vector<int> > result;
        return result;
    }
};

/*
C(4,2) = 4 + C(3,1)
C(3,2) = 3 + C(2,1)
C(2,2) = 2 + C(1,1)



C(5,3) = 5 + C(4,2) = 5 + 4 + C(3,1)
       = 5 + C(3,2) = 5 + 3 + C(2,1)
       = 5 + C(2,2) = 5 + 2 + C(1,1)
C(4,3) = 4 + C(3,2) = 4 + 3 + C(2,1)
       = 4 + C(2,2) = 4 + 2 + C(1,1)
C(3,3) = 3 + C(2,2) = 3 + 2 + C(1,1)
*/

void combin(int n, int m)
{
    static vector<int>index;
//    if(n<m) return;
    if(n<=0 || m<=0) return;
    printf("C(%d, %d)\n", n, m);
    if(m==1) {
        LOGD("+++Done\n");
        for(int j=n;j>0; j--)
        {
            index.push_back(j);
            for(int i=0; i<index.size(); ++i)
            {
                printf("%d ", index[i]);
            }
            index.pop_back();
            printf("\n");
        }
        LOGD("---Done\n");
        return;
    }
    for(int i=n; i>=m; i--)
    {
        index.push_back(i);
        printf(" = ");
        for(int j=0; j<index.size(); ++j)
        {
            printf("%d + ", index[j]);
        }        
        combin(i-1, m-1);
        index.pop_back();
    }
    
    printf("\n");
}

void Test_Subsets()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;
    
    vector<int>index;
    combin(5,3);
}