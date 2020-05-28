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
https://leetcode.com/problems/unique-binary-search-trees/
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> table;
        //f(0)
        table.push_back(1);
        //f(1)
        table.push_back(1);
        if(n<2) return 1;

        int x = 0;
        for(int i=2;i<=n; ++i)
        {
            x = 0;
            for(int j=0; j<i; ++j)
            {
                x = x + table[j]*table[i-j-1];
                LOGD("f(%i) = %d + %d\n", i, j, i-j-1);
            }
            LOGD("f(%d) = %d\n", i, x);
            table.push_back(x);
        }
        
        return x;
    }
};

void Test_numTrees()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    int n = 2;
    n = solution->numTrees(n);
    LOGD("Ans: %d\n", n);
    delete solution;
}