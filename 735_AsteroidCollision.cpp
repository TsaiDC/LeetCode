//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <cstdlib> 
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
https://leetcode.com/problems/asteroid-collision/
735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its 
direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 10^4
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/


#ifdef _CVERSION_
//C
/*

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){

}

void Test_AM_TEST()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Self Solution, Stack
Runtime: 20 ms, faster than 59.32% of C++ online submissions for Asteroid Collision.
Memory Usage: 17.5 MB, less than 85.05% of C++ online submissions for Asteroid Collision.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        bool isStore = false;
        for(auto & a : asteroids) {            
            if(ret.empty()) {
                ret.push_back(a);
                continue;
            }
            if((ret.back() < 0 && a<0) ||
               (ret.back() > 0 && a>0) ||
               (ret.back() < 0 && a>0)) {
                ret.push_back(a);
                continue;
            }

            //Only handle +,- (Go Right and Go Left)
            isStore = false;
            while(!ret.empty() && ret.back() > 0 && a < 0) {
                if(ret.back() + a == 0) {                    
                    isStore = false;
                    ret.pop_back();
                    break;
                }
                else if(ret.back() + a < 0) {
                    ret.pop_back();
                    isStore = true;
                }
                else {
                    isStore = false;
                    break;
                }                    
            }
            if(isStore) {
                ret.push_back(a);
            }
        }
        return ret;
    }
};

void Test_AM_asteroidCollision()
{
    int arr1[] = {5,-5};
//    int arr1[] = {5,10,-5};
//    int arr1[] = {-2,-1,1,2};    //[-2,-1,1,2]
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n1);

    vector<int> ans;
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    ans = solution->asteroidCollision(input1);
    delete solution;
    
    for(auto &a : ans) {
        LOGD("Ans: %d\n", a);
    }
}

#endif// _CPPVERSION_