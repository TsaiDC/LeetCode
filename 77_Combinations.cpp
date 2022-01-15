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

#if 0

/*
Runtime: 11 ms, faster than 92.37% of C++ online submissions for Combinations.
Memory Usage: 8.9 MB, less than 92.41% of C++ online submissions for Combinations.
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
#endif


/*
Runtime: 32 ms, faster than 48.08% of C++ online submissions for Combinations.
Memory Usage: 9.1 MB, less than 65.12% of C++ online submissions for Combinations.
*/
class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > result;
        vector<int> ans;
        Solution::_combine(0, n, k, ans, result);
        return result;
    }

    static void _combine(int pos, int n, int k, vector<int> &ans, vector< vector<int> > &result)
    {
        if(ans.size()==k) {
            result.push_back(ans);
            return;
        }

        // 0 1 2 3,  n:4 k:3
        for(int i=pos; i<n; ++i)
        {
            ans.push_back(i+1);
            _combine(i+1, n, k, ans, result);
            ans.pop_back();
        }
    }
};


void Test_combine()
{
    LOGD("%s\n", __TIME__);    
    Solution *solution = new Solution();
    vector< vector<int> > ans;
    ans = solution->combine(4, 4);

    delete solution;

    LOGD("-- ANS --\n");
    for(int i=0; i<ans.size(); ++i)
    {
        for(int j=0; j<ans[0].size(); ++j)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
