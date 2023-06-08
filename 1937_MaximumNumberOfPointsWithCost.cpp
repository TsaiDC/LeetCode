//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <algorithm>

#include "apiheader.h"

#ifdef _1937_
using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#define _CPPVERSION_

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
// Unorder Map:
// https://shengyu7697.github.io/std-unordered_map/
// https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/
//

/*
https://leetcode.com/problems/maximum-number-of-points-with-cost/description/
1937. Maximum Number of Points with Cost

You are given an m x n integer matrix points (0-indexed). Starting with 0 points, 
you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) 
will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in 
the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), 
picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your 
score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.

Example 1:

Input: points = [[1,2,3],
                 [1,5,1],
                 [3,1,1]]
Output: 9

Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), 
and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.

--

Example 2:

Input: points = [[1,5],
                 [2,3],
                 [4,2]]
                 
Output: 11

Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), 
and (2, 0).

You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.

--

Constraints:

m == points.length
n == points[r].length
1 <= m, n <= 10^5
1 <= m * n <= 10^5
0 <= points[r][c] <= 10^5


*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_maxPoints()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
2023/6/7
Time Limit Exceeded
*/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> vals;
        for(int i: points[0]) {
            vals.push_back(i);
        }
               
        for(int i=1; i<points.size(); ++i) {
            countMax(points[i], vals);
        }         
        long long result = *max_element(vals.begin(), vals.end());
        return result;
    }
    
    
    void countMax(vector<int>& row, vector<long long>& vals) {
        vector<long long>tmpMax;
        vector<long long>tmpVals(vals);
        for(int i=0; i<row.size(); ++i) {
            for(int j=0; j<vals.size(); ++j) {
               long long val = vals[j] + row[i] - std::abs(i-j);
               tmpMax.push_back(val);
            }
            long long max = *max_element(tmpMax.begin(), tmpMax.end());
            tmpVals[i] = max;
            tmpMax.clear();
        }
        vals.clear();
        vals=tmpVals;
    }
    
    void dump(vector<int> v) {
        for(int i: v)
            cout<<i<<" ";
        cout<<endl;
    }
    void dump(vector<long long> v) {
        for(long long i: v)
            cout<<i<<" ";
        cout<<endl;
    }
};

void Test_GG_maxPoints()
{
#if 1 //Test 1, Ans: 9
    vector< vector<int> > input;
    int arr1[] = {1,2,3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n1);
    input.push_back(input1);

    int arr2[] = {1,5,1};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> input2(arr2, arr2+n2);
    input.push_back(input2);
    
    int arr3[] = {3,1,1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> input3(arr3, arr3+n3);
    input.push_back(input3);
#endif //Test 1

#if 0 //Test 2, Ans: 11
    vector< vector<int> > input;
    int arr1[] = {1,5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n1);
    input.push_back(input1);

    int arr2[] = {2,3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> input2(arr2, arr2+n2);
    input.push_back(input2);
    
    int arr3[] = {4, 2};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> input3(arr3, arr3+n3);
    input.push_back(input3);
#endif //Test 2


#if 0 //Test 3, Ans: 11
    vector< vector<int> > input;
    int arr1[] = {1, 5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n1);
    input.push_back(input1);

    int arr2[] = {3, 2};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> input2(arr2, arr2+n2);
    input.push_back(input2);
    
    int arr3[] = {4, 2};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> input3(arr3, arr3+n3);
    input.push_back(input3);
#endif //Test 2

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    long long ans = solution->maxPoints(input);
    cout<<"Ans: "<< ans<<endl;
    delete solution;
}

#endif// _CPPVERSION_
#endif//_0000_