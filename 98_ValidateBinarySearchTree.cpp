//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>

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
https://leetcode.com/problems/validate-binary-search-tree/
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void treeDFS(TreeNode* root, bool* pRet) 
{
    if(root == NULL)
        return;
    
    treeDFS(root->left, pRet);
    LOGD("Val: %d\n", root->val);
    treeDFS(root->right, pRet);
}

bool isValidBST(TreeNode* root) {
    bool ret = true;
    treeDFS(root, &ret);
    return ret;
}

void Test_isValidBST()
{
    LOGD("%s\n", __TIME__);
    TreeNode* node[7];
    for(int i=0; i<7 ; ++i)
    {
        node[i] = new TreeNode(i);
    }
    
    TreeNode* pRoot = node[3];
    
    node[3]->left = node[1];
    node[3]->right = node[5];    
    
    node[1]->left = node[0];
    node[1]->right = node[2];
    
    node[0]->left = NULL;
    node[0]->right = NULL;
    
    node[2]->left = NULL;
    node[2]->right = NULL;

    node[5]->left = node[4];
    node[5]->right = node[6];

    node[4]->left = NULL;
    node[4]->right = NULL;

    node[6]->left = NULL;
    node[6]->right = NULL;
    
    bool ret = isValidBST(pRoot);
    
    
    for(int i=0; i<7 ; ++i)
    {
        delete node[i];
    }    
    
    LOGD("Result: %d\n", ret);
    LOGD("Done \n");
}