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
#include <algorithm>

#include "apiheader.h"
#ifdef _2096_

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
https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
2096. Step-By-Step Directions From a Binary Tree Node to Another

You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 
to n. You are also given an integer startValue representing the value of the start node s, and a 
different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions 
of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter 
indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

Example 1:

    5
   ' `
  1   2
 '   '  `
3    6   4

Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 ¡÷ 1 ¡÷ 5 ¡÷ 2 ¡÷ 6.

Constraints:

The number of nodes in the tree is n.
2 <= n <= 10^5
1 <= Node.val <= n
All the values in the tree are unique.
1 <= startValue, destValue <= n
startValue != destValue

*/


#ifdef _CVERSION_
//C
/*

*/

void Test_GG_getDirections()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/

/**
    Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
    }
};

void Test_GG_getDirections()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;
}

#endif// _CPPVERSION_
#endif// _2096_