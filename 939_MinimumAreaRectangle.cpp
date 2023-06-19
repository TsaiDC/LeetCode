//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#include "apiheader.h"

#ifdef _0939_
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
https://leetcode.com/problems/minimum-area-rectangle/
939. Minimum Area Rectangle

You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of a rectangle formed from these points, with sides parallel to 
the X and Y axes. If there is not any such rectangle, return 0.

Example 1:

Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4

Example 2:

Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2

Constraints:

1 <= points.length <= 500
points[i].length == 2
0 <= xi, yi <= 4 * 10^4
All the given points are unique.

*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_minAreaRect()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
 
        return h1 ^ h2;
    }
};

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set< pair<int,int>, pair_hash >pointsMap;

        int area = 0;

        for(auto a: points) {
            LOGD("Put (%d, %d)\n", a[0], a[1]);
            pointsMap.insert(std::make_pair(a[0], a[1]));
        }
        

        for(int i = 0; i<points.size(); ++i) {
            for(int j=1+1; j<points.size(); ++j) {
                pair<int, int> node1 = make_pair(points[i][0], points[j][1]);
                pair<int, int> node2 = make_pair(points[j][0], points[i][1]);
                
                LOGD("(%d, %d) -> (%d, %d) \n", points[i][0], points[i][1], points[j][0], points[j][1]);
                if(pointsMap.count(node1) > 0 && pointsMap.count(node2) > 0) {

                    int tmpArea = std::abs(points[i][0] - points[j][0]) * 
                                  std::abs(points[i][1] - points[j][1]);
                    area = area < tmpArea ? tmpArea : area; 
                    LOGD("Hit Area: %d\n", tmpArea);
                }
            }
        }

        return area;
    }
};

void Test_GG_minAreaRect()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

//   [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
    vector<int> v1{1,1};
    vector<int> v2{1,3};
    vector<int> v3{3,1};
    vector<int> v4{3,3};
    vector<int> v5{4,1};
    vector<int> v6{3,3};
    
    vector<vector<int>>input;
    input.push_back(v1);
    input.push_back(v2);
    input.push_back(v3);
    input.push_back(v4);
    input.push_back(v5);
    input.push_back(v6);
    
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    int ans = solution->minAreaRect(input);
    LOGD("Ans: %d\n", ans)
    delete solution;
}

#endif// _CPPVERSION_
#endif//_0939_