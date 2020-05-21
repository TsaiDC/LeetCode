//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>

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

//            LOGD("i: %d, V1: %d, V2: %d\n", i, v1.size(), v2.size());
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
    vector<int> getMaxCombine(vector<int>& num1, vector<int>& num2)
    {
        vector<int> vector_int;
        int i, j;
#if 1
        printf("N1: ");
        for(i=0; i<num1.size(); ++i)
        {
            printf("%d ", num1[i]);
        }
        printf("\n");
        printf("N2: ");
        for(i=0; i<num2.size(); ++i)
        {
            printf("%d ", num2[i]);
        }
        printf("\n");        
#endif

        for(i=0, j=0; i<num1.size() && j<num2.size();)
        {
            if(num1[i]==num2[j]) {
                int x=i, y=j;
                while(num1[x]==num2[y])
                {
                    ++x;
                    ++y;
                    if(x==num1.size() || y==num2.size()) break;
                }
                
                if(x==num1.size() && y < num2.size()) {
                    LOGD("Push 2: %d\n", num2[j]);
                    vector_int.push_back(num2[j]);
                    ++j;
                }
                else if(x < num1.size() && y == num2.size()) {
                    LOGD("Push 1: %d\n", num1[i]);
                    vector_int.push_back(num1[i]);
                    ++i;
                }
                else if(x < num1.size() && y < num2.size()) {
                    if(num1[x]>num2[y]) {
                        LOGD("Push 1: %d\n", num1[i]);
                        vector_int.push_back(num1[i]);
                        ++i;
                    }
                    else {
                        LOGD("Push 2: %d\n", num2[j]);
                        vector_int.push_back(num2[j]);
                        ++j;
                    }
                }
            } else if(num1[i]>num2[j]) {
                LOGD("Push 1: %d\n", num1[i]);
                vector_int.push_back(num1[i]);
                ++i;
            }
            else {
                LOGD("Push 2: %d\n", num2[j]);
                vector_int.push_back(num2[j]);
                ++j;
            }
        }
        while(i<num1.size())
        {
            vector_int.push_back(num1[i]);
            ++i;
        }
        while(j<num2.size())
        {
            vector_int.push_back(num2[j]);
            ++j;
        }
#if 1
        printf("Combine: ");
        for(i=0; i<vector_int.size(); ++i)
        {
            printf("%d ", vector_int[i]);
        }
        printf("\n");
#endif
        return vector_int;
    }

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
    int arr1[] = {3, 4, 6, 5};
    int arr2[] = {9, 1, 2, 5, 8, 3};
    int k = 5;
#endif
#if 0
    int arr1[] = {6, 7};
    int arr2[] = {6, 0, 4};
    int k = 5;
#endif

#if 0
    int arr1[] = {3, 9};
    int arr2[] = {8, 9};
    int k = 3;
#endif

#if 0
    int arr1[] = {5, 5, 1};
    int arr2[] = {4, 0, 1};
    int k = 3;
#endif

#if 1
    int arr1[] = {2,0,2,1,2,2,2,2,0,1,0,0,2,0,2,0,2,1,0,1,1,0,1,0,1,2,1,1,1,0,1,2,2,1,0,0,1,2,1,2,2,1,1,0,1,2,0,2,0,1,2,0,2,1,1,1,2,0,0,1,0,2,1,2,0,1,0,0,0,1,2,1,0,1,1,2,0,2,2,0,0,1,1,2,2,1,1,2,2,1,0,1,2,0,1,2,2,0,0,0,2,0,2,0,2,2,0,1,1,1,1,2,2,2,2,0,0,2,2,2,2,0,2,0,1,0,0,2,1,0,0,2,0,2,1,1,1,1,0,1,2,0,2,1,0,1,1,1,0,0,2,2,2,0,2,1,1,1,2,2,0,0,2,2,2,2,2,0,2,0,2,0,2,0,0,1,0,1,1,0,0,2,1,1,2,2,2,1,2,2,0,0,2,1,0,2,1,2,1,1,1,0,2,0,1,1,2,1,1,0,0,1,0,1,2,2,2,0,2,2,1,0,1,2,1,2,0,2,2,0,1,2,2,1,2,2,1,1,2,2,2,2,2,1,2,0,1,1,1,2,2,2,0,2,0,2,0,2,1,1,0,2,2,2,1,0,2,1,2,2,2,0,1,1,1,1,1,1,0,0,0,2,2,0,1,2,1,0,0,2,2,2,2,1,0,2,0,1,2,0};
    int arr2[] = {1,1,1,0,0,1,1,0,2,1,0,1,2,1,0,2,2,1,0,2,0,1,1,0,0,2,2,0,1,0,2,0,2,2,2,2,1,1,1,1,0,0,0,0,2,1,0,2,1,1,2,1,2,2,0,2,1,0,2,0,0,2,0,2,2,1,0,1,0,0,2,1,1,1,2,2,0,0,0,1,1,2,0,2,2,0,1,0,2,1,0,2,1,1,1,0,1,1,2,0,2,0,1,1,2,0,2,0,1,2,1,0,2,0,1,0,0,0,1,2,1,2,0,1,2,2,1,1,0,1,2,1,0,0,1,0,2,2,1,2,2,0,0,0,2,0,0,0,1,0,2,0,2,1,0,0,1,2,0,1,1,0,1,0,2,2,2,1,1,0,1,1,2,1,0,2,2,2,1,2,2,2,2,0,1,1,0,1,2,1,2,2,0,0,0,0,0,1,1,1,2,1,2,1,1,0,1,2,0,1,2,1,2,2,2,2,0,0,0,0,2,0,1,2,0,1,1,1,1,0,1,2,2,1,0,1,2,2,1,2,2,2,0,2,0,1,1,2,0,0,2,2,0,1,0,2,1,0,0,1,1,1,1,0,0,2,2,2,2,0,0,1,2,1,1,2,0,1,2,1,0,2,0,0,2,1,1,0,2,1,1,2,2,0,1,0,2,0,1,0};
    int k = 600;
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
    printf("Ans: ");
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