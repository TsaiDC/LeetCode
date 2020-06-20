//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <limits.h>

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
https://leetcode.com/problems/binary-tree-inorder-traversal/
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> retVec;
        TreeNode* pTmp;
        vector<TreeNode* > ptr;        
        if(root) {
            ptr.push_back(root);
            LOGD("[ptr]Push %d\n", root->val);
        }
        
        while(!ptr.empty())
        {
            LOGD("-----[Current] %d\n", ptr.back()->val);
            if(ptr.back()->left) {
                pTmp = ptr.back()->left;
                ptr.back()->left = NULL;
                LOGD("[ptr]Push %d, %d->left = NULL\n", pTmp->val, ptr.back()->val);
                ptr.push_back(pTmp);
                continue;
            }
            else {                
                pTmp = ptr.back()->right;
                retVec.push_back(ptr.back()->val);
                LOGE("[STORE] %d\n", ptr.back()->val);
                ptr.pop_back();

                if(pTmp) {
                    ptr.push_back(pTmp);
                    LOGD("[ptr]Push %d\n", pTmp->val);
                }
            }

        }        
        return retVec;
    }
    
    void inorderTraversalRec(TreeNode* root, vector< int > &vec) {
        if(!root) {
            return;
        }
        inorderTraversalRec(root->left, vec);
        vec.push_back(root->val);
        inorderTraversalRec(root->right, vec);
    }
};

void Test_inorderTraversal()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
//    TreeNode *pRoot = new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL));
    
    TreeNode *pRoot = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(8), new TreeNode(9))), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    
    vector<int> retVec1;
    retVec1 = solution->inorderTraversal(pRoot);    

    for(int i=0; i<retVec1.size(); ++i)
    {
        LOGD("1: %d\n", retVec1[i]);
    }
#if 0
    vector<int> retVec2;
    solution->inorderTraversalRec(pRoot, retVec2);    
    for(int i=0; i<retVec2.size(); ++i)
    {
        LOGD("2: %d\n", retVec2[i]);
    }
#endif
    LOGD("Done \n");
    delete solution;
}