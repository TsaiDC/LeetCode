//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
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

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//

/*
https://leetcode.com/problems/combinations/
77. Combinations

Given two integers n and k, return all possible combinations of k numbers 
out of the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n

*/

class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        LOGD("\n");
        vector< vector<int> > result;
        vector<int> row(k);
        _combine(n, k, row, result);

        return result;
    }
    
    
    void _combine(int n, int r, vector<int>&row, vector< vector<int> >&result)
    {
        for(int i=n; i>=r; i--)
        {
            LOGD("Idx: %d, C(%d, %d) \n", i, n, r);
            row[r-1] = i;
            if(r>1) {
                _combine(i-1, r-1, row, result);
            }
            else {
                for(int j=0; j<row.size(); j++)
                {
                    printf("%d ", row[j]);
                }
                printf("\n");
                result.push_back(row);
            }
        }
    }
};

void Test_combine()
{
    LOGD("%s\n", __TIME__);    
    Solution *solution = new Solution();
    solution->combine(4, 3);
//    vector<int>row(3);
//    solution->_combine(4, 3, row);
    delete solution;
}