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
https://leetcode.com/problems/strings-differ-by-one-character/
1554. Strings Differ by One Character

Given a list of strings dict where all the strings are of the same length.
Return true if there are 2 strings that only differ by 1 character in the same index, otherwise return false.

Example 1:

Input: dict = ["abcd","acbd", "aacd"]
Output: true
Explanation: Strings "abcd" and "aacd" differ only by one character in the index 1.

Example 2:

Input: dict = ["ab","cd","yz"]
Output: false

Example 3:

Input: dict = ["abcd","cccc","abyd","abab"]
Output: true

*/
#ifdef _CVERSION_
//C
/*

*/
bool differByOne(char ** dict, int dictSize){

}

void Test_GG_differByOne()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
//Time Limit Exceeded
/*
class Solution {
public:
    bool differByOne(vector<string>& dict) {
        if(dict.empty()) return false;
        int strLen = dict[0].length();
        string tmp;
        char c;
        unsigned int hasVal, hasVal2;
        hash<string> hash_obj;

        for(int x=0; x<dict.size(); ++x){
            for(int i=0; i<strLen; ++i) {
                tmp = dict[x];
                c = tmp.at(i);
                tmp.erase(i, 1);
                hasVal = hash_obj(tmp);
                for(int j=x+1; j<dict.size(); ++j){
                    if(dict[j].at(i) != c) {
                        tmp = dict[j];
                        tmp.erase(i, 1);
                        hasVal2 = hash_obj(tmp);
                        LOGD("%s (%u) ?= %s (%u)\n", dict[0].c_str(), hasVal, dict[j].c_str(), hasVal2);
                        if( hasVal2 == hasVal) {                        
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
*/

/*
Runtime: 698 ms, faster than 40.14% of C++ online submissions for Strings Differ by One Character.
Memory Usage: 157.9 MB, less than 44.94% of C++ online submissions for Strings Differ by One Character.
*/
class Solution {
public:
    bool differByOne(vector<string>& dict) {
        if(dict.empty()) return false;
        string tmp;
        unsigned int hasVal;
        hash<string> hash_obj;
        map<unsigned int, string>::iterator iter;
        map<unsigned int, string> mMap;
        for(int j=0; j<dict[0].length(); ++j) {
            for(int i=0; i<dict.size(); ++i) {            
                tmp = dict[i];
                tmp.erase(j, 1);
                hasVal = hash_obj(tmp);
                iter = mMap.find(hasVal);
                if(iter != mMap.end()){
                    return true;
                }
                else {
                    mMap[hasVal] = dict[i];
                }
            }
            mMap.clear();
        }
        return false;
    }
};

void Test_GG_differByOne()
{
    LOGD("[CPP] %s\n", __TIME__);
//    string str[] = {"aaaddb","aaaacd","aaacda","aaaaba","aaaccd"};
//    string str[] = {"abcd","acbd", "aacd"};
//    string str[] = {"ab","cd","yz"};
//    string str[] = {"abcde","abaaa","aaade"};
    string str[] = {"da","ae"};
    int n = sizeof(str)/sizeof(str[0]);
    vector<string> input1(str, str+n);
    Solution *solution = new Solution();
    bool b = solution->differByOne(input1);
    LOGD("B: %d\n", b ? 1 : 0);
    delete solution;
}

#endif //_CPPVERSION_