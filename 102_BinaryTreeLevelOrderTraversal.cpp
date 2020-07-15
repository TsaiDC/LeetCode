//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
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

/*
https://leetcode.com/problems/binary-tree-level-order-traversal/
102. Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#ifndef nullptr
#define nullptr NULL
#endif

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
    vector< vector<int> > levelOrder(TreeNode* root) {    
        vector< vector<int> > ans;
        vector<int> rowNums;
        queue<TreeNode*> Nodes;
        queue<TreeNode*> rowNodes;
        TreeNode *pNode;
        if(!root) return ans;
        rowNodes.push(root);
        while(!rowNodes.empty())
        {
            rowNums.clear();

            while(!rowNodes.empty())
            {
                pNode = rowNodes.front();
                rowNodes.pop();
                if(pNode){
                    rowNums.push_back(pNode->val);
                    Nodes.push(pNode);
                }                
            }
            ans.push_back(rowNums);

            while(!Nodes.empty())
            {
                pNode = Nodes.front();
                Nodes.pop();
                if(pNode->left){
                    rowNodes.push(pNode->left);
                }
                if(pNode->right){
                    rowNodes.push(pNode->right);
                }                
            }
        }
        return ans;
    }
};

TreeNode* getTree()
{
    TreeNode *pRoot = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    return pRoot;
}

void Test_levelOrdere()
{
    LOGD("%s\n", __TIME__);
    TreeNode *pRoot = getTree();
    Solution *solution = new Solution();
    vector< vector<int> > ans = solution->levelOrder(pRoot);
    for(int i=0; i<ans.size(); ++i)
    {
        for(int j=0; j<ans[i].size(); ++j)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    delete solution;
}