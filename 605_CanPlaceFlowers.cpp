//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

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
https://leetcode.com/problems/can-place-flowers/
605. Can Place Flowers

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
*/

/*
Runtime: 21 ms, faster than 66.62% of C++ online submissions for Can Place Flowers.
Memory Usage: 21.3 MB, less than 23.20% of C++ online submissions for Can Place Flowers.
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        vector<int> aa(flowerbed.size(), 0);

        if(flowerbed.size()<1) return false;
        if(flowerbed.size() == 1) {
            if(flowerbed[0] == 0) ++count;
            return count >=n ;  
        } 
        
        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
            aa[0] = 1;
            aa[1] = 1;
            ++count;
        }
        for(int i=2; i<flowerbed.size(); ++i) {
            if(flowerbed[i] == 1){ ++i; continue;}
            if(flowerbed[i-1] == 1){ continue;}
            if(i<flowerbed.size()-1 && flowerbed[i+1] == 1){ continue;}
            aa[i] = max(aa[i-1], 1+ aa[i-2]);
            if(aa[i-1] < 1+ aa[i-2]) {
                ++count;
            }
        }
        
        printf("AA: ");
        for(int i=0; i<aa.size(); ++i)
        {
            printf("%d ", aa[i]);
        }
        printf("\n");
        return count>=n;
    }
};

void Test_canPlaceFlowers()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {0, 1, 0};
//    int arr1[] = {1,0,0,0,1,0,0};
    
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n);
    Solution *solution = new Solution();
    bool b = solution->canPlaceFlowers(input1, 1);
    LOGD("Ans: %d\n", b);
    delete solution;
}