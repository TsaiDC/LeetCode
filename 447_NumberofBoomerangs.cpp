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

#ifdef _0447_
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
https://leetcode.com/problems/number-of-boomerangs/
447. Number of Boomerangs

You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. 
A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the 
distance between i and k (the order of the tuple matters).

Return the number of boomerangs.

Example 1:

Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].

Example 2:

Input: points = [[1,1],[2,2],[3,3]]
Output: 2

Example 3:

Input: points = [[1,1]]
Output: 0

Constraints:

n == points.length
1 <= n <= 500
points[i].length == 2
-10^4 <= xi, yi <= 10^4
All the points are unique.
*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_numberOfBoomerangs()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 601 ms Beats 62.42%
Memory: 85 MB Beats 89.17%
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {    
        int dist;
        int count = 0;
        int retVal = 0;
        unordered_map<int,int> distMap;
        unordered_map<int,int>::iterator distIter;
        for(int i=0; i<points.size(); ++i) {
            distMap.clear();
            for(int j=0; j<points.size(); ++j) {
                if(i==j) continue;
                dist = getDist(points[i], points[j]);
                if(distMap.find(dist) == distMap.end()) {
                    distMap[dist] = 1;
                }
                else {
                    distMap[dist] += 1;
                }
            }
            count = 0;
            for(distIter = distMap.begin(); distIter != distMap.end(); ++distIter) {
                if(distIter->second < 2) continue;
                count += (distIter->second) * (distIter->second -1); 
            }
            retVal += count;
        }
        return retVal;
    }
    
    int getDist(vector<int>&a, vector<int>&b) {
        return ((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]));
    }
};

void Test_GG_numberOfBoomerangs()
{
#if 0
    //points = [[0,0],[1,0],[2,0]]
    vector<int> p1{1,0};
    vector<int> p2{1,0};
    vector<int> p3{2,0};
#endif
    //[[1,1],[2,2],[3,3]]
    vector<int> p1{1,1};
    vector<int> p2{2,2};
    vector<int> p3{3,3};
    vector<vector<int>> input {p1, p2, p3};

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    int ans = solution->numberOfBoomerangs(input);
    LOGD("Ans: %d\n", ans);
    delete solution;
}

#endif// _CPPVERSION_
#endif//_0447_