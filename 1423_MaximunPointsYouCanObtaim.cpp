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

#ifdef _1423_
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
https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
1423. Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated number of points. 
The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. 
You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card
 first will maximize your total score. The optimal strategy is to take the three cards on the right,
 giving a final score of 1 + 6 + 5 = 12.
 
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4. 


Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

Constraints:

1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length
*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_TEST()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 66 ms Beats 69.26%
Memory: 44.3 MB Beats 9.41%
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int count = 0;        
        int headIdx = k-1;
        int tailIdx = cardPoints.size()-1;
        vector<int> values;
        
        for(int i=0; i<k; i++) {
            count+=cardPoints[i];
        }        
        if(k == cardPoints.size()) {
            return count;
        }
        values.push_back(count);

        while(headIdx>=0) {
            count = count - cardPoints[headIdx] + cardPoints[tailIdx];            
            headIdx--;
            tailIdx--;
            values.push_back(count);
        }
        return *max_element(values.begin(), values.end());
    }
};

void Test_GG_maxScore()
{    
    int arr1[] = {1,2,3,4,5,6,1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    int val = solution->maxScore(input1, 3);
    LOGD("Ans: Val: %d\n", val);
    delete solution;
}

#endif// _CPPVERSION_
#endif//_1423_