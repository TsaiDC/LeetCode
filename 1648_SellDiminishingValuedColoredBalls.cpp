//g++ *.cpp -o tool
#ifdef _1648_
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
https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
1648. Sell Diminishing-Valued Colored Balls

You have an inventory of different colored balls, and there is a customer that wants orders balls 
of any color.

The customer weirdly values the colored balls. Each colored ball's value is the number of balls of 
that color you currently have in your inventory. For example, if you own 6 yellow balls, 
the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow 
balls left, so the next yellow ball is then valued at 5 
(i.e., the value of the balls decreases as you sell more to the customer).

You are given an integer array, inventory, where inventory[i] represents the number of balls of 
the ith color that you initially own. You are also given an integer orders, which represents the 
total number of balls that the customer wants. You can sell the balls in any order.

Return the maximum total value that you can attain after selling orders colored balls. 
As the answer may be too large, return it modulo 10^9 + 7.


Example 1:

Input: inventory = [2,5], orders = 4
Output: 14
Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
The maximum total value is 2 + 5 + 4 + 3 = 14.

Example 2:

Input: inventory = [3,5], orders = 6
Output: 19
Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
 

Constraints:

1 <= inventory.length <= 10^5
1 <= inventory[i] <= 10^9
1 <= orders <= min(sum(inventory[i]), 10^9)

*/


#ifdef _CVERSION_
//C
/*

*/
int maxProfit(int* inventory, int inventorySize, int orders){

}

void Test_AM_maxProfit()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_

// OJ: https://leetcode.com/contest/weekly-contest-214/problems/sell-diminishing-valued-colored-balls/
// Author: github.com/lzl124631x
// Time: O(Nlog(max(A)))
// Space: O(N)
class Solution {
    map<int, int, greater<int>> m;
    bool valid(int M, int T) {
        for (auto &[n , cnt] : m) {
            if (n <= M) break;
            T -= (long)cnt * (n - M);
            if (T <= 0) return true;
        }
        return T <= 0;
    }
public:
    int maxProfit(vector<int>& A, int T) {
        long ans = 0, mod = 1e9+7, L = 0, R = *max_element(begin(A), end(A));
        for (int n : A) m[n]++;
        while (L <= R) {
            long M = (L + R) / 2;
            if (valid(M, T)) L = M + 1;
            else R = M - 1;
        }
        for (auto &[n , cnt] : m) {
            if (n <= L) break;
            T -= cnt * (n - L);
            ans = (ans + (n + L + 1) * (n - L) / 2 % mod * cnt % mod) % mod;
        }
        if (T) ans = (ans + L * T % mod) % mod;
        return ans;
    }
};

#if 0
//C++
/*
Self,
Priority Queue
Time Limit Exceeded
*/

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long mod = 1e9 + 7;
        long ans = 0;
        int count = orders;
        priority_queue<int> pq;
        for(int i : inventory)
            pq.push(i);        
    
        int tmp;
        while(!pq.empty() && count > 0) {
            tmp = pq.top();
            pq.pop();
            //1, 2, 3, 4, 5
            //1, 2  3, 4, 5
            //((5+1)*5)/2 - ((5-3) + 1)*2/2 = 15 - 3 = 12
            // (5+3)*3/2 = 12
            if(pq.empty()) {
                if(count>0) {
                    long valAll = count%2 == 0 ? (count/2) * (tmp + (tmp - count + 1 )) :
                                                 ((tmp + (tmp - count + 1 ))/2)*count;
                    ans = ans + valAll;                    
                    ans %= mod;
                    tmp-=count; 
                    count = 0;
                }
            }
            else {
                while(pq.top()<=tmp && count>0) {
                    ans+=tmp;
                    ans %= mod;
                    count--;
                    tmp--;
                }
            }
//            LOGD("Count: %d, Ans: %d, %d\n", count, ans, tmp);            
            pq.push(tmp);            
        }
        return (int)ans;
    }
};
#endif

void Test_AM_maxProfit()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
//    int arr1[] = {2,5};
//    int order = 4;
//    int arr1[] = {3,5};
//    int order = 6;
//    vector<int> input(arr1, arr1+2);

    int arr1[] = {1000000000};
    int order = 1000000000;
    vector<int> input(arr1, arr1+1);
    Solution *solution = new Solution();
    int ans = solution->maxProfit(input, order);
    delete solution;
    LOGD("Ans: %d\n", ans);
}

#endif// _CPPVERSION_
#endif// _1648_