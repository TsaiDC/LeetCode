//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>
#include <queue> 

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
https://leetcode.com/problems/create-maximum-number/
321. Create Maximum Number

Given two arrays of length m and n with digits 0-9 representing two numbers. 
Create the maximum number of length k <= m + n from digits of the two. 
The relative order of the digits from the same array must be preserved. 
Return an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        vector<int> Max;
        vector<int> v1;
        vector<int> v2;
        if(nums1.empty()) return nums2;
        if(nums2.empty()) return nums1;
        
        for(int i=0; i<k; ++i) Max.push_back(0);

        for(int i=k; i>=0; i--)
        {
            v1 = getKdigitMax(nums1, i);
            v2 = getKdigitMax(nums2, k-i);

            if(v1.size() + v2.size() !=k) {
                continue;
            }

            ret = getMaxCombine(v1, v2);
            Max = getMaxInt(Max, ret);
        }

        return Max;
    }
    
    vector<int> getMaxInt(vector<int>& num1, vector<int>& num2)
    {
        vector<int> vector_int = num1;
        for(int i=0; i<num1.size(); ++i)
        {
            if(num1[i] == num2[i]) continue;
            if(num1[i]>num2[i]) return num1;
            if(num1[i]<num2[i]) return num2;
        }
        return vector_int;
    }

    bool getRemoveVec(vector<int>& num1, vector<int>& num2, int i)
    {    
        if(num1.size() == num2.size()){
            //The same vector length
            //A: x,x,x
            //B: x,x,x
            if(num1[i] > num2[i]) {
                //A: x,2,...
                //B: x,1,...
                return true;
            }
            else if(num1[i] < num2[i]) {
                //A: x,1,...
                //B: x,2,...
                return false;
            }
            else if(num1[i] == num2[i]) {
                //A: x,2,...
                //B: x,2,...
                if(i == num1.size()) {
                    //Two vector are the same
                    //A: x,x
                    //B: x,x
                    return true;
                }
                else{
                    //A: x,z,...
                    //B: x,y,...
                    return getRemoveVec(num1, num2, i+1);
                }
            }
        }
        else if(num1.size() > num2.size()){
            //Vector A is longer
            //A: x,x,x
            //B: x,x
            if(i<num2.size()) {
                //     i
                //A: 5,x,y,z,...
                //B: 5,w
                
                //     i
                //A: 5,6,y,z,...
                //B: 5,4
                if(num1[i]>num2[i]) return true;

                //     i
                //A: 5,4,y,z,...
                //B: 5,6
                if(num1[i]<num2[i]) return false;
                
                //     i
                //A: 5,4,y,z,...
                //B: 5,4
                if(num1[i]==num2[i]) return getRemoveVec(num1, num2, i+1);
            }
            else {            
                //i>=num2.size()
                // Check Vector A only
                //   i
                //A: y,z,...
                //B: 
                if(num2.empty()) return true;

                //     i
                //A: a,y,z,...
                //B: a
                int j = i;
                for(j=i; j<num1.size(); j++)
                {
                    //     i
                    //A: 3,4,z,...
                    //B: 3
                    if(num1[j]>num1[i-1]) return true;
                    //     i
                    //A: 3,2,z,...
                    //B: 3
                    if(num1[j]<num1[i-1]) return false;
                    //     i
                    //A: 3,3,z,...
                    //B: 3
                    if(num1[j]==num1[i-1]) continue;
                }
                
                if(j==num1.size()){
                    //       j
                    //A: 3,3,3
                    //B: 3
                    return false;
                }
            }
        }
        else { //num1.size() < num2.size()            
            //Vector B is longer
            //A: x,x
            //B: x,x,x
            if(i<num1.size()) {
                //     i
                //A: 5,w
                //B: 5,x,y,z,...
                
                //     i
                //A: 5,6
                //B: 5,4,y,z,...
                if(num1[i]>num2[i]) return true;

                //     i
                //A: 5,4
                //B: 5,6,y,z,...
                if(num1[i]<num2[i]) return false;
                
                //     i
                //A: 5,4
                //B: 5,4,y,z,...
                if(num1[i]==num2[i]) return getRemoveVec(num1, num2, i+1);
            }
            else {            
                //i>=num1.size()
                // Check Vector B only
                //   i
                //A: 
                //B: y,z,...
                if(num1.empty()) return false;

                //     i
                //A: a
                //B: a,y,z,...
                int j = i;
                for(j=i; j<num2.size(); j++)
                {
                    //     i
                    //A: 3
                    //B: 3,4,z,...
                    if(num2[j]>num2[i-1]) return false;
                    //     i
                    //A: 3
                    //B: 3,2,z,...
                    if(num1[j]<num1[i-1]) return true;
                    //     i
                    //A: 3,3,z,...
                    //B: 3
                    if(num1[j]==num1[i-1]) continue;
                }
                
                if(j==num2.size()){
                    //       j
                    //A: 3
                    //B: 3,3,3
                    return true;
                }
            }
        }
        return true;
    }
#if 1
    vector<int> getMaxCombine(vector<int>& num1, vector<int>& num2)
    {
        vector<int> tmp1(num1.begin(), num1.end());        
        vector<int> tmp2(num2.begin(), num2.end());
        vector<int> vector_int;
        int eraseCount = 0;
        int eraseTarget = 0;

        while(!tmp1.empty() && !tmp2.empty())
        {
            if(tmp1[0] > tmp2[0]) {
                vector_int.push_back(tmp1[0]);
                LOGD("Push A: %d\n", tmp1[0]);
                tmp1.erase(tmp1.begin());
            }
            else if(tmp1[0] < tmp2[0]) {
                LOGD("Push B: %d\n", tmp2[0]);
                vector_int.push_back(tmp2[0]);
                tmp2.erase(tmp2.begin());
            }
            else { //tmp1[0] == tmp2[0]
                if(getRemoveVec(tmp1, tmp2, 0)) {
                    LOGD("Push A: %d\n", tmp1[0]);
                    vector_int.push_back(tmp1[0]);
                    tmp1.erase(tmp1.begin());
                }
                else {
                    LOGD("Push B: %d\n", tmp2[0]);
                    vector_int.push_back(tmp2[0]);
                    tmp2.erase(tmp2.begin());
                }
            }
        }
        LOGD("@@ %d, %d, %d\n", vector_int.size(), tmp1.size(), tmp2.size());
        for(int i=0; i<tmp1.size(); ++i)
        {
            vector_int.push_back(tmp1[i]);
        }
        for(int i=0; i<tmp2.size(); ++i)
        {
            vector_int.push_back(tmp2[i]);
        }
        return vector_int;
    }
#endif

    vector<int> getKdigitMax(vector<int>& num, int k)
    {        
        int kk = num.size()-k;
        vector<int> vector_str;
        if(k>num.size()) return vector_str;

        for(int i=0; i<num.size(); ++i)
        {
            if(kk ==0 || vector_str.empty()) {
                vector_str.push_back(num.at(i));
                continue;            
            }
            
            while(vector_str.back() < num.at(i)){
                vector_str.pop_back();
                kk--;
                if(vector_str.empty() || kk == 0) {
                    break;
                }
            }
            vector_str.push_back(num.at(i));
        }

        while(kk>0)
        {
            vector_str.pop_back();
            kk--;
        }
        return vector_str;
    }
};

void Test_maxNumber()
{
    LOGD("%s\n", __TIME__);
#if 0
//[9, 8, 6, 5, 3]
    int arr1[] = {3, 4, 6, 5};
    int arr2[] = {9, 1, 2, 5, 8, 3};
    int k = 5;
#endif
#if 0
//6 7 6 0 4
    int arr1[] = {6, 7};
    int arr2[] = {6, 0, 4};
    int k = 5;
#endif

#if 0
//9 8 9
    int arr1[] = {3, 9};
    int arr2[] = {8, 9};
    int k = 3;
#endif

#if 0
//5 5 4
    int arr1[] = {5, 5, 1};
    int arr2[] = {4, 0, 1};
    int k = 3;
#endif

#if 0
//6 5 1
    int arr2[] = {5, 6, 0};
    int arr1[] = {5, 1, 1};
    int k = 3;
#endif

#if 0
//[9,9,3,1,2,0]
    int arr1[] = {3,4,8,9,3,0};
    int arr2[] = {6,1,9,1,1,2};
    int k = 6;
#endif

#if 0
//[7,3,8,2,5,6,4,4,0,6,5,7,6,2,0]
 //7 3 8 2 5 6 4 4 0 6 0 5 7 6 2
    int arr1[] = {2,5,6,4,4,0};
    int arr2[] = {7,3,8,0,6,5,7,6,2};
    int k = 15;
#endif

#if 0
//[9,9,9,9,9,9,9,7,8,7,6,1,7,2,7,5,5,1,5,2,5,7,1,0,4,3,8,7,3,8,5,3,8,3,4,0,2,3,8,2,7,1,2,3,8,7,6,7,1,1,3,9,0,5,2,8,2,8,7,5,0,8,0,7,2,8,5,6,5,9,5,1,5,2,6,2,4,9,9,7,6,5,7,9,2,8,8,3,5,9,5,1,8,8,4,6,6,3,8,4,6,6,1,3,4,1,6,7,0,8,0,3,3,1,8,2,2,4,5,7,3,7,7,4,3,7,3,0,7,3,0,9,7,6,0,3,0,3,1,5,1,4,5,2,7,6,2,4,2,9,5,5,9,8,4,2,3,6,1,9]
// 9 9 9 9 9 9 9 7 8 7 6 1 7 2 7 5 5 1 5 2 5 7 1 0 4 3 8 7 3 8 5 3 8 3 4 0 2 3 8 2 7 1 2 3 8 7 6 7 1 1 3 9 0 5 2 8 2 8 7 5 0 8 0 7 2 8 5 6 5 9 5 1 5 2 6 2 4 9 9 7 6 5 7 9 2 8 8 3 5 9 5 1 8 8 4 6 6 3 8 4 6 6 1 3 4 1 6 7 0 8 0 3 3 1 8 2 2 4 5 7 3 7 7 4 3 7 3 0 7 3 0 9 7 6 0 3 0 3 1 5 1 4 5 2 7 6 2 4 2 9 5 5 9 8 4 2 3 6 1 9
    int arr1[] = {3,3,3,2,3,7,3,8,6,0,5,0,7,8,9,2,9,6,6,9,9,7,9,7,6,1,7,2,7,5,5,1};
    int arr2[] = {5,6,4,9,6,9,2,2,7,5,4,3,0,0,1,7,1,8,1,5,2,5,7,0,4,3,8,7,3,8,5,3,8,3,4,0,2,3,8,2,7,1,2,3,8,7,6,7,1,1,3,9,0,5,2,8,2,8,7,5,0,8,0,7,2,8,5,6,5,9,5,1,5,2,6,2,4,9,9,7,6,5,7,9,2,8,8,3,5,9,5,1,8,8,4,6,6,3,8,4,6,6,1,3,4,1,6,7,0,8,0,3,3,1,8,2,2,4,5,7,3,7,7,4,3,7,3,0,7,3,0,9,7,6,0,3,0,3,1,5,1,4,5,2,7,6,2,4,2,9,5,5,9,8,4,2,3,6,1,9};
    int k = 160;
#endif

#if 1
    int arr1[] = {2,0,2,1,2,2,2,2,0,1,0,0,2,0,2,0,2,1,0,1,1,0,1,0,1,2,1,1,1,0,1,2,2,1,0,0,1,2,1,2,2,1,1,0,1,2,0,2,0,1,2,0,2,1,1,1,2,0,0,1,0,2,1,2,0,1,0,0,0,1,2,1,0,1,1,2,0,2,2,0,0,1,1,2,2,1,1,2,2,1,0,1,2,0,1,2,2,0,0,0,2,0,2,0,2,2,0,1,1,1,1,2,2,2,2,0,0,2,2,2,2,0,2,0,1,0,0,2,1,0,0,2,0,2,1,1,1,1,0,1,2,0,2,1,0,1,1,1,0,0,2,2,2,0,2,1,1,1,2,2,0,0,2,2,2,2,2,0,2,0,2,0,2,0,0,1,0,1,1,0,0,2,1,1,2,2,2,1,2,2,0,0,2,1,0,2,1,2,1,1,1,0,2,0,1,1,2,1,1,0,0,1,0,1,2,2,2,0,2,2,1,0,1,2,1,2,0,2,2,0,1,2,2,1,2,2,1,1,2,2,2,2,2,1,2,0,1,1,1,2,2,2,0,2,0,2,0,2,1,1,0,2,2,2,1,0,2,1,2,2,2,0,1,1,1,1,1,1,0,0,0,2,2,0,1,2,1,0,0,2,2,2,2,1,0,2,0,1,2,0};
    int arr2[] = {1,1,1,0,0,1,1,0,2,1,0,1,2,1,0,2,2,1,0,2,0,1,1,0,0,2,2,0,1,0,2,0,2,2,2,2,1,1,1,1,0,0,0,0,2,1,0,2,1,1,2,1,2,2,0,2,1,0,2,0,0,2,0,2,2,1,0,1,0,0,2,1,1,1,2,2,0,0,0,1,1,2,0,2,2,0,1,0,2,1,0,2,1,1,1,0,1,1,2,0,2,0,1,1,2,0,2,0,1,2,1,0,2,0,1,0,0,0,1,2,1,2,0,1,2,2,1,1,0,1,2,1,0,0,1,0,2,2,1,2,2,0,0,0,2,0,0,0,1,0,2,0,2,1,0,0,1,2,0,1,1,0,1,0,2,2,2,1,1,0,1,1,2,1,0,2,2,2,1,2,2,2,2,0,1,1,0,1,2,1,2,2,0,0,0,0,0,1,1,1,2,1,2,1,1,0,1,2,0,1,2,1,2,2,2,2,0,0,0,0,2,0,1,2,0,1,1,1,1,0,1,2,2,1,0,1,2,2,1,2,2,2,0,2,0,1,1,2,0,0,2,2,0,1,0,2,1,0,0,1,1,1,1,0,0,2,2,2,2,0,0,1,2,1,1,2,0,1,2,1,0,2,0,0,2,1,1,0,2,1,1,2,2,0,1,0,2,0,1,0};
    int k = 600;
#endif


#if 0
//    int arr1[] = {0, 2, 1, 2, 2, 2, 2, 0, 1, 0 };
//    int arr2[] = {0, 0, 1, 1, 0, 2, 1, 0, 1, 2 };
//    int k = 20;
//    int arr1[] = {0, 2, 1, 2, 2, 2, 2, 0 };
//    int arr2[] = {0, 0, 1, 1, 0, 2, 1, 0 };
//    int k = 16;
//    int arr1[] = { 2, 2, 0 };
//    int arr2[] = { 2, 1, 0 };
//    int k = 6;
    
    int arr1[] = { 2, 0 };
    int arr2[] = { 1, 0 };
    int k = 4;
#endif
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> input1(arr1, arr1+n1);
    vector<int> input2(arr2, arr2+n2);
    vector<int> result;

#if 0
    input1.clear();
    input2.clear();
    input2.push_back(1);
    k = 1;
#endif
    Solution *instance = new Solution();
    result = instance->maxNumber(input1, input2, k);
    printf("Ans size: %d \n", result.size());
    for(int i=0; i<result.size(); ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
/*
    vector<int> result1 = instance->getKdigitMax(input1, 2);
    vector<int> result2 = instance->getKdigitMax(input2, 3);
    instance->getMaxCombine(result1, result2);
*/
    delete instance;
}