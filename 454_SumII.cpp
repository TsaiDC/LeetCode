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
https://leetcode.com/problems/4sum-ii/
454. 4Sum II

Given four lists A, B, C, D of integer values, 
compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, 
all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -228 to 228 - 1 
and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<string, int> mapComb;
        getComb(A, B, C, D, mapComb);
        return mapComb.size();
    }
    
    void getComb(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D, map<string, int>& mapComb) {
        int a, b, c, d;
        if(A.empty()) return;
        if(B.empty()) return;
        if(C.empty()) return;
        if(D.empty()) return;

        a = A.size()-1;
        b = B.size()-1;
        c = C.size()-1;
        d = D.size()-1;
        
        if(A[a]+B[b]+C[c]+D[d] == 0) {
            char buffer [10] ={'\0'};
            map<string, int>::iterator iter;
            sprintf (buffer, "%2d%2d%2d%2d", a, b, c, d);
            string str = buffer;
            iter = mapComb.find(str);
            if(iter == mapComb.end()) {
                mapComb.insert(pair<string, int>(str, 1));
                LOGD("(%d, %d, %d, %d) STR: %s\n", a, b, c, d, str.c_str());
            }            
        }

        vector<int> AA(A);
        vector<int> BB(B);
        vector<int> CC(C);
        vector<int> DD(D);
        
        AA.pop_back();
        BB.pop_back();
        CC.pop_back();
        DD.pop_back();
        
        getComb(AA, B, C, D, mapComb);
        getComb(A, BB, C, D, mapComb);
        getComb(A, B, CC, D, mapComb);
        getComb(A, B, C, DD, mapComb);
    }
};

void Test_fourSumCount()
{
    LOGD("%s\n", __TIME__);
    // int arr1[] = {1,2};
    // int arr2[] = {-2,-1};
    // int arr3[] = {-1,2};
    // int arr4[] = {0,2};
    
    // int arr1[] = {-1,-1};
    // int arr2[] = {-1,1};
    // int arr3[] = {-1,1};
    // int arr4[] = {1,-1};
    
    int arr1[] = {1,1,-1,-1};
    int arr2[] = {-1,-1,1,1};
    int arr3[] = {1,-1,0,-1};
    int arr4[] = {1,1,-1,1};
    int n = sizeof(arr1)/sizeof(arr1[0]);       
    vector<int> num1(arr1, arr1+n);
    vector<int> num2(arr2, arr2+n);
    vector<int> num3(arr3, arr3+n);
    vector<int> num4(arr4, arr4+n);
    Solution *solution = new Solution();
    int ans  = solution->fourSumCount(num1,num2,num3,num4);
    LOGD("Ans: %d\n", ans);
    delete solution;
}