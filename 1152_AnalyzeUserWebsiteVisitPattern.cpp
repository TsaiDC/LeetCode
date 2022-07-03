//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>

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
https://leetcode.com/problems/analyze-user-website-visit-pattern/
1152. Analyze User Website Visit Pattern


*/


#ifdef _CVERSION_
//C
/*

*/

void Test_AM_mostVisitedPattern()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Ref Solution
Runtime: 70 ms, faster than 38.81% of C++ online submissions for Analyze User Website Visit Pattern.
Memory Usage: 27.1 MB, less than 13.29% of C++ online submissions for Analyze User Website Visit Pattern.
*/
class Solution {
public:
    void chooseK(int k, map<int, string> & user, map<int, string>::iterator it, vector<string> & container, unordered_set<string> & mySet){
        if (container.size() == k){
            mySet.insert(container[0] + ',' + container[1] + ',' + container[2]);
            return;
        }
        if (it == user.end()){
            return;
        }
        
        container.push_back(it->second);
        chooseK(k, user, next(it), container, mySet);
        container.pop_back();
        chooseK(k, user, next(it), container, mySet);
    }
    
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>> users;
        // user name: <timestamp, website>
        unordered_map<string, int> visited;
        // count the time of visiting 3-sequence websites 
        // 3-sequence websites is represented by a string
        
        // initiate users
        int n = username.size();
        for(int i = 0; i < n; i++){
            users[username[i]][timestamp[i]] = website[i];
        }
        
        for(auto user : users){
            unordered_set<string> mySet;

            // reduce duplicate of every 3-sequence websites
            // for(auto i = user.second.begin(); i != user.second.end(); i++){
            //     for(auto j = next(i); j != user.second.end(); j++){
            //         for(auto k = next(j); k != user.second.end(); k++){
            //             mySet.insert(i->second + ',' + j->second + ',' + k->second);
            //         }
            //     }
            // }

            vector<string> tmpVec;
            chooseK(3, user.second, user.second.begin(), tmpVec, mySet);
            // count the number of users who visited these 3-sequence websites
            for(auto websites : mySet){
                if (visited.count(websites)) visited[websites]++;
                else visited[websites] = 1;
            }
        }
        
        // find the largest counter with smallest string
        string resString;
        int largestCounter = 0;
        for(auto webVisited : visited){
            if (webVisited.second > largestCounter) {
                resString = webVisited.first;
                largestCounter = webVisited.second;
                
            }
            else if (webVisited.second == largestCounter && webVisited.first < resString){
                resString = webVisited.first;
            }
        }
        
        // splite the resstring into string vector
        vector<string> res;
        res.push_back(resString.substr(0, resString.find(',')));
        resString = resString.substr(resString.find(',') + 1);
        res.push_back(resString.substr(0, resString.find(',')));
        resString = resString.substr(resString.find(',') + 1);
        res.push_back(resString);
        return res;
    }
};

void Test_AM_mostVisitedPattern()
{
    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;    
}

#endif// _CPPVERSION_