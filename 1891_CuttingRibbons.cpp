//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <climits>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define _CPPVERSION_

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
https://leetcode.com/problems/cutting-ribbons/
1891. Cutting Ribbons

You are given an integer array ribbons, where ribbons[i] represents the length of the ith ribbon, 
and an integer k. 
You may cut any of the ribbons into any number of segments of positive integer lengths, 
or perform no cuts at all.

For example, if you have a ribbon of length 4, you can:
Keep the ribbon of length 4,
*Cut it into one ribbon of length 3 and one ribbon of length 1,
*Cut it into two ribbons of length 2,
*Cut it into one ribbon of length 2 and two ribbons of length 1, or
*Cut it into four ribbons of length 1.

Your goal is to obtain k ribbons of all the same positive integer length. 
You are allowed to throw away any excess ribbon as a result of cutting.

Return the maximum possible positive integer length that you can obtain k ribbons of, 
or 0 if you cannot obtain k ribbons of the same length.

Example 1:

Input: ribbons = [9,7,5], k = 3
Output: 5
Explanation:
- Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
- Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
- Keep the third ribbon as it is.
Now you have 3 ribbons of length 5.

Example 2:

Input: ribbons = [7,5,9], k = 4
Output: 4
Explanation:
- Cut the first ribbon to two ribbons, one of length 4 and one of length 3.
- Cut the second ribbon to two ribbons, one of length 4 and one of length 1.
- Cut the third ribbon to three ribbons, two of length 4 and one of length 1.
Now you have 4 ribbons of length 4.

Example 3:

Input: ribbons = [5,7,9], k = 22
Output: 0
Explanation: You cannot obtain k ribbons of the same positive integer length.

Constraints:

1 <= ribbons.length <= 105
1 <= ribbons[i] <= 105
1 <= k <= 109

*/
#ifdef _CVERSION_
//C
/*

*/

int maxLength(int* ribbons, int ribbonsSize, int k){

}

void Test_FB_maxLength()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 176 ms, faster than 93.94% of C++ online submissions for Cutting Ribbons.
Memory Usage: 92.4 MB, less than 91.04% of C++ online submissions for Cutting Ribbons.
*/

class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        
        int low = 1; // min possible ribbon size      
        int high = INT_MIN; // max possible ribbon size       
        for (auto x : ribbons) {
            high = max(high, x);
        }
        
        int count = 0; // how many ribbons of size mid could we cut?
        int mid = 0; // current ribbon size
        while (low <= high) {
            mid = low + (high-low)/2;
            count = 0;
            
            // get how many ribbons we can get of size mid
            for (auto x: ribbons) {
                count += x/mid;
            }
            
            if (count < k) { // mid was too big, so lower the range
                high = mid - 1;
            } else { // we were able to make K cuts of size mid but let's see if we can get a bigger cut size
                low = mid + 1;
            }
        }
        
        if (high < 0) return 0;
        return high;
    }
};

#if 0
/*
Time Limit Exceeded
*/
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int avg = 0;
        for(int i:ribbons) {
            avg += i;
        }
        avg = avg/k;
        
        int count = 0;
        int lastAvg = 0;
        int tmp;
        while(avg>0) {
            for(int i:ribbons) {
                count += i/avg;                
            }
            if(count < k) {
                count = 0;
                tmp = avg;                
                avg = avg - (avg-lastAvg)/2;
                lastAvg = tmp;
            }
            else if(count > k) {
                count = 0;
                tmp = avg;
                avg = avg + (lastAvg-avg)/2;
                lastAvg = tmp;
            }
            else {
                break;
            }
        }
        return avg;
    }
};
#endif

void Test_FB_maxLength()
{
    LOGD("[CPP] %s\n", __TIME__);
//    int aa[] = {9,7,5};
//    int k = 3;

//    int aa[] = {7,5,9};
//    int k = 4;

//    int aa[] = {5, 7, 9};
//    int k = 22;

    int aa[] = {100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,1,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000};
    int k = 49;
    
    int len = sizeof(aa)/sizeof(aa[0]);
    vector<int> input(aa, aa+len);
    Solution *solution = new Solution();
    int ans = solution->maxLength(input, k);    
    delete solution;
    LOGD("Ans: %d\n", ans);
}

#endif //_CPPVERSION_