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
    vector<int> getMaxCombine(vector<int>& num1, vector<int>& num2)
    {
        vector<int> tmp1 = num1;
        vector<int> tmp2 = num2;
        vector<int> vector_int;
        int i, j;
#if 1
        printf("N1: { \n");
        for(i=0; i<num1.size(); ++i)
        {
            if(i>0 && i%10 ==0)
                printf("\n");
            printf("%d ,", num1[i]);
        }
        printf("\n} \n");

        printf("N2: { \n");
        for(i=0; i<num2.size(); ++i)
        {
            if(i>0 && i%10 ==0)
                printf("\n");
            printf("%d ,", num2[i]);
        }
        printf("\n} \n");
#endif
        int vSize = -1;
        for(i=0, j=0; i<num1.size() && j<num2.size();)
        {
            vSize = vector_int.size();
            LOGD("Check i: %d, j: %d\n", i,j);
            if(num1[i]==num2[j]) {
                int x=i, y=j;
                LOGD("=Check i: %d, j: %d\n", i,j);
                while(num1[x]==num2[y])
                {
                    LOGD("Push = (x: %d, y: %d): %d\n", x, y, num2[j]);
                    vector_int.push_back(num2[j]);
                    ++x;
                    ++y;
                    if(x==num1.size() || y==num2.size()) break;
                }
                LOGD("  Check x: %d, y: %d\n", x, y);
                if(x==num1.size() && y < num2.size()) {
                    i = x;
                    int yy = y;
                    while(yy<num2.size() && num2[yy] == num2[yy-1]){
                        LOGD("Push B: %d\n", num2[yy-1]);
                        vector_int.push_back(num2[yy-1]);
                        ++yy;
                    }
                    if(yy == num2.size()) {
                        //2
                        //2,2,2
                        LOGD("Push B: %d\n", num2[yy-1]);
                        vector_int.push_back(num2[yy-1]);
                        j=yy;
                    }
                    else {
                        //2
                        //2,4,3
                        if(num2[yy] > num2[yy-1]) {
                            LOGD("Push B: %d\n", num2[yy]);
                            vector_int.push_back(num2[yy]);
//                            LOGD("Push A: %d\n", num1[x-1]);
//                            vector_int.push_back(num1[x-1]);
                            j=yy+1;
                        }
                        //2
                        //2,1,1
                        else if(num2[yy] < num2[yy-1]) {
                            LOGD("Push A: %d\n", num1[x-1]);
                            vector_int.push_back(num1[x-1]);
//                            LOGD("Push B: %d\n", num2[yy]);
//                            vector_int.push_back(num2[yy]);
                            j=yy;
                        }
                        else {
                            LOGE("Error\n");
                        }
                    }
                    LOGD("I: %d, j: %d\n",i, j);
                }
                else if(x < num1.size() && y == num2.size()) {
                    j = y;
                    int xx = x;
                    while(xx<num1.size() && num1[xx] == num1[xx-1]){
                        LOGD("Push A: %d\n", num1[xx-1]);
                        vector_int.push_back(num1[xx-1]);
                        ++xx;
                    }
                    if(xx == num1.size()) {                        
                        //2,2,2
                        //2
                        LOGD("Push A: %d\n", num1[xx-1]);
                        vector_int.push_back(num1[xx-1]);
                        i=xx;
                    }
                    else {
                        //2,3,2
                        //2
                        if(num1[xx] > num1[xx-1]) {
                            LOGD("Push A: %d\n", num1[xx]);
                            vector_int.push_back(num1[xx]);
//                            LOGD("Push B: %d\n", num2[y-1]);
//                            vector_int.push_back(num2[y-1]);
                            i=xx+1;
                        } 
                        //2,1,3
                        //2                        
                        else if(num1[xx] < num1[xx-1]) {
                            LOGD("Push B: %d\n", num2[y-1]);
                            vector_int.push_back(num2[y-1]);
//                            LOGD("Push A: %d\n", num1[xx]);
//                            vector_int.push_back(num1[xx]);
                            i=xx;
                        }
                        else {
                            LOGE("Error\n");
                        }
                    }
                    LOGD("I: %d, j: %d\n",i, j);
                }
                else if(x < num1.size() && y < num2.size()) {
                    if(num1[x]>num2[y]) {
                        if(num1[x] > num1[x-1]) {                            
                            //6,6,7
                            //6,6,0
                            LOGD("Push A: %d\n", num1[x]);
                            vector_int.push_back(num1[x]);
                            i=x+1;                            
                        }
                        else {
                            //6,6,5
                            //6,6,0
                            i = x;                            
                        }
                    }
                    else {
                        if(num2[y] > num1[x-1]) {
                            //6,6,0
                            //6,6,7
                            LOGD("Push B: %d\n", num2[y]);
                            vector_int.push_back(num2[y]);
                            j=y+1;
                        }
                        else {
                            //6,6,0
                            //6,6,5                            
                            j = y;
                        }
                    }
                }
                else if(x==num1.size() && y == num2.size()) {
                    //2,2,2
                    //2,2,2
                    //2,2,2
                    for(int xx=i; xx<x;++xx)
                        vector_int.push_back(num1[xx]);
                    i=x;
                    j=y;
                }
            }
            else if(num1[i]>num2[j]) {
                LOGD("Push 1: %d\n", num1[i]);
                vector_int.push_back(num1[i]);
                ++i;
            }
            else if(num1[i]<num2[j]) {
                LOGD("Push 2: %d\n", num2[j]);
                vector_int.push_back(num2[j]);
                ++j;
            }
            else {
                LOGE("Error\n");
            }
            
            if(vSize == vector_int.size()){
                LOGE("Stop at size: %d\n", vSize);
                break;
            }
        }
        LOGD("--------------------------------------i: %d, j: %d\n", i, j);
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

#if 1
//[7,3,8,2,5,6,4,4,0,6,5,7,6,2,0]
 //7 3 8 2 5 6 4 4 0 6 0 5 7 6 2
    int arr1[] = {2,5,6,4,4,0};
    int arr2[] = {7,3,8,0,6,5,7,6,2};
    int k = 15;
#endif

#if 0
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