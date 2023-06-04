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
Runtime: 373 ms Beats 10.31%
Memory: 152 MB Beats 13.26%
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
        //1 find the parent
        if (root == NULL) {
            return "";
        }

        unordered_map<TreeNode*, TreeNode*> NodeParentMap;
        stack<TreeNode*> startStk;
        stack<TreeNode*> destStk;
        queue<TreeNode*> nodeQ;
        TreeNode* pStart = NULL;
        TreeNode* pDest = NULL;
        nodeQ.push(root);
        NodeParentMap[root] = NULL;

        while (!nodeQ.empty()) {
            TreeNode* pNode = nodeQ.front();
            nodeQ.pop();

            if(pNode == NULL) {
                continue;
            }
            if (pNode->val == startValue) {
                pStart = pNode;
            }
            if (pNode->val == destValue) {
                pDest = pNode;
            }

            if(pNode->left != NULL) {
                nodeQ.push(pNode->left);
                NodeParentMap[pNode->left] = pNode;
            }
            if(pNode->right != NULL) {
                nodeQ.push(pNode->right);
                NodeParentMap[pNode->right] = pNode;
            }
            if (pStart != NULL && pDest != NULL) {
                break;
            }
        }

//        LOGD("Start Node: %d, Dest Node: %d\n", pStart->val, pDest->val);

        //2 Trace back
        TreeNode* pParent = NULL;
        pParent = pStart;
        while(pParent != NULL) {
//            LOGD("S: %d\n", pParent->val);
            startStk.push(pParent);
            pParent = NodeParentMap[pParent];
        }

        pParent = pDest;
        while(pParent != NULL) {
//            LOGD("D: %d\n", pParent->val);
            destStk.push(pParent);
            pParent = NodeParentMap[pParent];
        }

        //3 Find the common root
        while(startStk.top()->val == destStk.top()->val) {            
            startStk.pop();
            destStk.pop();
            if (startStk.empty() || destStk.empty()) {
                break;
            }
        }
        if (startStk.empty()) {
            pParent = NodeParentMap[destStk.top()];
        }
        else {
            pParent = NodeParentMap[startStk.top()];
        }
        
//        LOGD("Common Root: %d\n", pParent->val);

        string strResult;
        //4 Path of Dest to common root
        TreeNode* pTmpNode = pDest;
        int tmpVal = pDest->val;
        while(pTmpNode != NULL &&
              pTmpNode->val != pParent->val) {
            pTmpNode = NodeParentMap[pTmpNode];
            if(pTmpNode->left && pTmpNode->left->val == tmpVal) {
                strResult+="L";
            }
            if(pTmpNode->right && pTmpNode->right->val == tmpVal) {
                strResult+="R";
            }
            tmpVal = pTmpNode->val;
        }
//        LOGD("L: %s\n", strResult.c_str());

        //5 Path of Start to common root       
        pTmpNode = pStart;
        while(pTmpNode != NULL && 
              pTmpNode->val != pParent->val) {
            pTmpNode = NodeParentMap[pTmpNode];
            strResult+="U";
        }
//        LOGD("R: %s\n", strResult.c_str());
        reverse(strResult.begin(), strResult.end());
        return strResult;        
    }
};

void Test_GG_getDirections()
{
    //3, 6
//    TreeNode* pRoot = new TreeNode(5, 
//                                   new TreeNode(1, new TreeNode(3), NULL),
//                                   new TreeNode(2, new TreeNode(6), new TreeNode(4)));

    //1, 2
    TreeNode* pRoot = new TreeNode(2, 
                                   new TreeNode(1), NULL);

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
//    string str = solution->getDirections(pRoot, 3, 6);
    string str = solution->getDirections(pRoot, 1, 2);
    delete solution;
    LOGD("Ans: %s\n", str.c_str());
}

#endif// _CPPVERSION_
#endif// _2096_