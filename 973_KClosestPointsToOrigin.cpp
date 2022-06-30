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

#include "apiheader.h"

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
https://leetcode.com/problems/k-closest-points-to-origin/
973. K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and 
an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., กิ(x1 - x2)^2 + (y1 - y2)^2).

You may return the answer in any order. The answer is guaranteed to be unique 
(except for the order that it is in).

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

Constraints:

1 <= k <= points.length <= 10^4
-10^4 < xi, yi < 10^4

*/


#ifdef _CVERSION_
//C
/*

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes){

}

void Test_AM_kClosest()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
class Solution {
public:
    vector< vector<int> > kClosest(vector< vector<int> >& points, int k) {
        vector< vector<int> >ans;
        int left = 0, right = points.size()-1, idx;
        idx = getSortK(points, left, right-1, right);
        LOGD("idx: %d\n", idx);
        return ans;
    }
    
    int getSortK(vector< vector<int> >& point, int i, int j, int k) {                
        long long lengthK = getLength(point[k][0], point[k][1]);
        
        while(i<j) {
            while(getLength(point[i][0], point[i][1]) < lengthK && i<j) ++i;
            while(getLength(point[j][0], point[j][1]) > lengthK && i<j) --j;
            //Swap(i, k)
            int x = point[i][0];
            int y = point[i][1];
            point[i][0] = point[k][0];
            point[i][1] = point[k][1];
            point[i][0] = x;
            point[i][1] = y;
        }
        return i;
    }
    
    long long getLength(int x, int y) {
        return x*x+y*y;
    }
};

void Test_AM_kClosest()
{
    LOGD("[CPP] %s\n", __TIME__);
    vector< vector<int> > ans;
//    [[3,3],[5,-1],[-2,4]], k = 2
    int arr1[] = {3,3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n1);
    int arr2[] = {5,-1};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> input2(arr2, arr2+n2);
    int arr3[] = {-2,4};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> input3(arr3, arr3+n3);

    vector< vector<int> > input;
    input.push_back(input1);
    input.push_back(input2);
    input.push_back(input3);
    
    Solution *solution = new Solution();
    ans = solution->kClosest(input, 2);
    delete solution;
}

#endif// _CPPVERSION_