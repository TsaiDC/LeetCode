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
https://leetcode.com/problems/3sum/
15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

//Time Limit Exceeded
vector< vector<int> > threeSum3(vector<int>& nums) {
    vector< vector<int> > retVector;
    vector<int>row;
    if(nums.size()<3) {
        return retVector;
    }
    int leng = nums.size();

    bool firstOK, secondOK, thirdOK;
    char buff[10];    

    map<int, int> mMap;
    map<string, int> mStrMap;
    map<string, int>::iterator iter;
    //1. Create Ref Map
    for(int i=0; i<nums.size(); ++i)
    {
        mMap[nums[i]] = mMap[nums[i]] == 0 ? 1 : mMap[nums[i]] + 1;
    }
    
    vector<vector<vector<double> > > array3D;
    // Set up sizes
    array3D.resize(leng);
    for (int i = 0; i < leng; ++i) {
    array3D[i].resize(leng);

    for (int j = 0; j < leng; ++j)
      array3D[i][j].resize(leng);
    }
    
    for(int i=0; i<leng; ++i)
    {
        for(int j=0;j<leng; ++j)
        {
            for(int k=0; k<leng; ++k)
            {
                firstOK = false; secondOK = false; thirdOK = false;
                if(mMap[nums[i]] > 0){
                    mMap[nums[i]] -=1;
                    firstOK = true;
                }
                if(mMap[nums[j]] > 0){
                    mMap[nums[j]] -=1;
                    secondOK = true;
                }
                if(mMap[nums[k]] > 0){
                    mMap[nums[k]] -=1;
                    thirdOK = true;
                }

                if( firstOK && secondOK && thirdOK && ((nums[i] + nums[j] + nums[k]) == 0)) {                   
                    if(nums[j] < nums[i] || nums[k] < nums[i] || nums[k] < nums[j]) {
                        if (firstOK) mMap[nums[i]] +=1;
                        if (secondOK) mMap[nums[j]] +=1;
                        if (thirdOK) mMap[nums[k]] +=1;                    
                        continue;
                    }
                    memset(buff, '\0', sizeof(buff)/sizeof(buff[0]));
//                    LOGD("%d, %d, %d\n", nums[i], nums[j], nums[k]);
                    sprintf(buff, "%d%d%d", nums[i], nums[j], nums[k]);
//                    LOGD("Buff: %s\n", buff);
                    string strBuff(buff);
                    iter = mStrMap.find(strBuff);
                    if(iter == mStrMap.end()) {
                        LOGD("StrBuff: %s\n", strBuff.c_str());
                        mStrMap[strBuff] = 1;
                        row.clear();
                        row.push_back(nums[i]);
                        row.push_back(nums[j]);
                        row.push_back(nums[k]);
                        retVector.push_back(row);
                    }
                }
                if (firstOK) mMap[nums[i]] +=1;
                if (secondOK) mMap[nums[j]] +=1;
                if (thirdOK) mMap[nums[k]] +=1;                
            }
        }
    }
    if(retVector.size() == 0) {
//        return {};
        return retVector;
    }
    
    return retVector;
}

vector< vector<int> > threeSum2(vector<int>& nums) {
    vector< vector<int> > retVector;
    if(nums.size()<3) {
//        return {};
        return retVector;
    }
    vector<int>row;
    map<int, int> mMap;
    map<int, int>::iterator iter;
    map<int, int>::iterator iter2;
    map<int, int>::iterator iter3;
    
    //1. Create Ref Map
    for(int i=0; i<nums.size(); ++i)
    {
        mMap[nums[i]] = mMap[nums[i]] == 0 ? 1 : mMap[nums[i]] + 1;
    }

    //2.
    int first, second, third, sum;
    for(iter = mMap.begin(); iter != mMap.end(); iter++)
    {
        LOGD("Map: %d -> %d\n", iter->first, iter->second);
        first = iter->first;
        if(first > 0)
            break;
        
        iter->second -= 1;
        sum = 0-first;
        
        for(iter2 = mMap.begin(); iter2 != mMap.end(); iter2++)
        {
            if(iter2->second == 0) {
                continue;
            }
            second = iter2->first;
            iter2->second -= 1;
            
            third = sum - second;
            iter3 = mMap.find(third);
            
            if(iter3 != mMap.end() && iter3->second != 0) {                
                if(second < first || third < first || third < second) {
                    iter2->second += 1;
                    continue;
                }                
                LOGD("%d %d %d\n", first, second, third);
                row.clear();
                row.push_back(first);
                row.push_back(second);
                row.push_back(third);
                retVector.push_back(row);
            }
            iter2->second += 1;
        }
        
        iter->second += 1;
    }

    if(retVector.size() == 0) {
//        return {};
        return retVector;
    }

    return retVector;
}

void Test_threeSum()
{
    LOGD("%s\n", __TIME__);
#if 1
    int arr[] = {-1, 0, 1, 2, -1, -4};
//    int arr[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//    int arr[] = {1, 0, 0, 2, 1, 1, 1};
//    int arr[] = {-1, 0, 1};
//    int arr[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Input: ");
    for(int i=0; i<n; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    vector<int> input(arr, arr+n);
    threeSum3(input);
#endif
    LOGD("Done \n");
}
