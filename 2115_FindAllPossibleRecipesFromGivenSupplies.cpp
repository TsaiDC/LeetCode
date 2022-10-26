//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>


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
// Set Ref:
// https://shengyu7697.github.io/std-unordered_set/
//

/*
https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
2115. Find All Possible Recipes from Given Supplies

You have information about n different recipes. 
You are given a string array recipes and a 2D string array ingredients. 
The ith recipe has the name recipes[i], and you can create it if you have all the needed 
ingredients from ingredients[i]. Ingredients to a recipe may need to be created from 
other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you 
initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. 
You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

 

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], 
supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".

Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]],
supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient
 "bread".

Example 3:

Input: recipes = ["bread","sandwich","burger"], 
ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], 
supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient
 "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients 
"bread" and "sandwich".
 

Constraints:

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.

*/
#ifdef _CVERSION_
//C
/*

*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findAllRecipes(char ** recipes, int recipesSize, char *** ingredients, int ingredientsSize, 
                       int* ingredientsColSize, char ** supplies, int suppliesSize, int* returnSize){

}

void Test_GG_findAllRecipes()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
#if 1 //Ref
class Solution {
    public:
    vector<string> findAllRecipes(vector<string>& recipes, 
                                  vector< vector<string> >& ingredients, 
                                  vector<string>& supplies) {
        unordered_map<string, vector<string> > next;
        unordered_map<string, int> indegree;
        
        for(int i=0; i<recipes.size(); ++i) {
            for(int j=0; j<ingredients.size(); ++j) {
                next[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]] +=1;
            }
        }
        
        unordered_set<string> wanted(recipes.begin(), recipes.end());        
        queue<string> q;
        for(string s:supplies)
            q.push(s);
        
        vector<string>rets;
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            if(wanted.find(cur) != wanted.end()) {
                rets.push_back(cur);
            }
            
            for(auto x : next[cur]) {
                indegree[x] -=1;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
    }

};
#endif

#if 0 //Self
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, 
                                  vector< vector<string> >& ingredients, 
                                  vector<string>& supplies) {
        vector<string>ans;
        unordered_set<string> ansSet;
        unordered_set<string>suppliesSet;

        for(string s : supplies) {
            suppliesSet.insert(s);
        }
        
        bool isRefresh = false;
        for(int i=0; i<recipes.size(); ++i) {
            bool isFind = true;
            for(int j=0; j<ingredients[i].size(); ++j) {
                if(suppliesSet.count(ingredients[i][j]) < 1) {
                    isFind = false;
                    break;            
                }
            }
            if(isFind) {
                if(ansSet.count(recipes[i]) == 0) {
                    ansSet.insert(recipes[i]);
                }
                if(suppliesSet.count(recipes[i]) == 0) {
                    suppliesSet.insert(recipes[i]);
                    isRefresh = true;
                }
            }
            if(isRefresh && i == recipes.size()-1) {
                i = 0;
                isRefresh = false;
            } 
        }
        
        for(string s : ansSet) {
            ans.push_back(s);
        }
        return ans;
    }
};
#endif

void Test_GG_findAllRecipes()
{
    LOGD("[CPP] %s\n", __TIME__);    
    Solution *solution = new Solution();
    delete solution;
}

#endif //_CPPVERSION_
