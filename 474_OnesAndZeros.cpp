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

/*
https://leetcode.com/problems/ones-and-zeroes/
474. Ones and Zeroes

In the computer world, use restricted resource you have to generate
maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively.
On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. 
Each 0 and 1 can be used at most once.

Note:

The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.

Example 1:

Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by 6the using of 5 0s and 3 1s, 
which are бз10,би0001би,би1би,би0би
 

Example 2:

Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. 
Better form "0" and "1".

*/

#if 0
int findMaxForm(vector<string>& strs, int m, int n) {
    return 0;    
8}
#endif

#if 1
//Ref: https://leetcode.com/problems/ones-and-zeroes/discuss/465535/C%2B%2B-2D(memory%3A-beats-100)-dp-matrix-solution-with-detailed-explanation
static int count(string str, char z) {
    int result =0;
    for(int i=0; i<str.length(); ++i)
    {
        if(str.at(i) == z) {
            result++;
        }
    }
    return result;
}
int findMaxForm(vector<string>& strs, int m, int n) {

    // each entry: no. of strings that can be formed with m and n
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    
    /*
        This is a knapsack problem with 'm' and 'n' that can be considered weights.
        So just like the classical problem can be solved with 1D array, for m and n
        we use 2D matrix.
        
        For each entry: check if current string can be formed 
                        + no. of strings that can be formed with remaining n and m
                        
        For doing this if we start from top and go towards bottom(smallest value of n and m to largest), 
        then we end up counting reduntant things. Eg: m = 10, n = 10 will also capture the string that
        m = 1, n = 1 can. So if the current string is such that it can be captured by last m and n values and
        the current m and n can also cover it, then when we do dp[i - zeros][j - ones], it will give us 1 for the same 
        thing again.
        So we iterate through the strings, and for the current string we start filling m X n matrix from bottom right
        to top left. So since upper values can be filled only when the lower values are filled so this time when
        1 +  dp[i - zeros][j - ones] is done, dp[i - zeros][j - ones] will only account for the values till the 
        string before the current string.
        for ith string, dp[i][j] has info about the ith string and dp[i-1][j-1] has info till i-1th string, 
        so adding it won't create any redundancy.
    */
    
//    for(const string& str: strs) {
    for(int z=0; z<strs.size(); ++z) {
        string str = strs[z];
        // calculate the no. of ones and zeros required
        //int zeros = count(str.begin(), str.end(), '0');
        int zeros = count(str, '0');
        int ones = str.size() - zeros;
        //LOGD("Str: %s, Zero: %d, Ones: %d\n", str.c_str(), zeros, ones);
        printf("\n");

        for(int i = m; i >= zeros; i--) {        
            for(int j = n; j >= ones; j--) {
                LOGD("Str: %s, Zero: %d, Ones: %d, dp[%d, %d] = dp[%d, %d] ? 1 + dp[%d, %d] \n", str.c_str(), zeros, ones, i, j, i, j, i - zeros, j - ones);
                dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
            }
        }

/*        
        for(int i = m; i >= 0; i--) {
            for(int j = n; j >= 0; j--) {
                // current can be considered iff we have required no. of ones and zeros
                int including_current = (zeros <= i && ones <= j) ? 1 + dp[i - zeros][j - ones] : 0;
                LOGD("i: %d, j: %d, including_current: %d\n", i, j, including_current);
//                dp[i][j] = max(dp[i][j], including_current);
            }
        }
*/
    }
    return dp[m][n];
}
#endif

void Test_OnesAndZeros()
{
    LOGD("%s\n", __TIME__);
    string arr[] = {"10", "0001", "111001", "1", "0"};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<string> input(arr, arr+n);
    
    int ans = findMaxForm(input, 5, 3);
    LOGD("Ans: %d\n", ans);
}