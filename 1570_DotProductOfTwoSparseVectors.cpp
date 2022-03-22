//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>

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
https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
1570. Dot Product of Two Sparse Vectors

Given two sparse vectors, compute their dot product.

Implement class SparseVector:

*SparseVector(nums) Initializes the object with the vector nums
*dotProduct(vec) Compute the dot product between the instance of SparseVector and vec

A sparse vector is a vector that has mostly zero values, 
you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

Example 1:

Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8

Example 2:

Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0

Example 3:

Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6

Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 100

*/
#ifdef _CVERSION_
//C
/*

*/
typedef struct {
    
} SparseVector;


SparseVector* sparseVectorCreate(int* nums, int numsSize) {
    
}

// Return the dotProduct of two sparse vectors
int sparseVectordotProduct(SparseVector* obj, SparseVector* vec) {
  
}

/**
 * Your SparseVector struct will be instantiated and called as such:
 * SparseVector* v1 = sparseVectorCreate(nums1, nums1Size);
 * SparseVector* v2 = sparseVectorCreate(nums2, nums2Size);
 * int ans = sparseVectordotProduct(v1, v2);
*/

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 176 ms, faster than 95.93% of C++ online submissions for Dot Product of Two Sparse Vectors.
Memory Usage: 172.8 MB, less than 23.41% of C++ online submissions for Dot Product of Two Sparse Vectors.
*/

class SparseVector {
public:
    vector<int> mVector;    
    SparseVector(vector<int> &nums) {
        mVector = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for(int i=0; i<mVector.size(); ++i) {
            ans += mVector[i]*vec.mVector[i];
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

void Test_FB_dotProduct()
{
    LOGD("[CPP] %s\n", __TIME__);
    int inums1[] = {1,0,0,2,3};
    int inums2[] = {0,3,0,4,0};
    vector<int> nums1(inums1, inums1+5);
    vector<int> nums2(inums2, inums2+5);
    SparseVector v1(nums1);
    SparseVector v2(nums2);
    int ans = v1.dotProduct(v2);
    LOGD("Ans: %d\n", ans);
}

#endif //_CPPVERSION_