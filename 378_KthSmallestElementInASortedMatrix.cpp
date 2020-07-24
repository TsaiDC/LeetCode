//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>
#include <algorithm>

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
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
378. Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
1 5 9 10 11 12 13 13 15
return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

class Solution {
public:
#if 1 //Ref Solution
    int kthSmallest(vector< vector<int> >& matrix, int k) {
        int n = matrix.size();
        
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        while (left < right) {
            int midv = (left + right) / 2;
            
            int count = 0;  // number of elements no bigger than midv
            for (int i = 0; i < n; i++) {
                vector<int>& row = matrix[i];
                count += std::upper_bound(row.begin(), row.end(), midv) - row.begin();
            }
            
            if (count < k) {
                left = midv + 1;
            } else {
                right = midv;    
            }
        }
        return left;
    }
#endif
#if 0 //My Solution
    int kthSmallest(vector< vector<int> >& matrix, int k) {
        if(matrix.empty())return 0;
        
        int min = matrix.front().front();
        int max = matrix.back().back();
        
        vector<int> dp(max-min+1,0);
        
        int order = 0;
        for(int i=0; i<matrix.size(); ++i)
        {
             for(int j=0; j<matrix[i].size(); ++j)
             {                 
                 dp[matrix[i][j]-min]+=1;              
             }
        }
        
        for(int i=0; i<dp.size(); ++i)
        {
            order+=dp[i];
            if(order>=k) {order = i;break;}
        }        
        return (order+min);        
    }
#endif
};

int TestBound () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
  
  for(int a:v) {
      LOGD("Array: %d\n", a);
  }

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 5); //
  up= std::upper_bound (v.begin(), v.end(), 5); //

  LOGD("Begin: %d, End: %d, Low: %d, Up: %d\n", *v.begin(), *v.end(), *low, *up);
  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}

void Test_kthSmallest()
{
    LOGD("%s\n", __TIME__);

    int arr1[] = {1,5,9};
    int arr2[] = {10,11,13};
    int arr3[] = {12,13,15};
    int k = 8;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> num1(arr1, arr1+n);
    vector<int> num2(arr2, arr2+n);
    vector<int> num3(arr3, arr3+n);
    vector< vector<int> > input;
    input.push_back(num1);
    input.push_back(num2);
    input.push_back(num3);
    
    Solution *solution = new Solution();
    int ans = solution->kthSmallest(input, k);
    LOGD("Ans: %d\n", ans);
    delete solution;
    
    TestBound ();
}