//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>

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
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
114. Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 typedef struct TreeNode_s {
     int val;
     struct TreeNode_s *left;
     struct TreeNode_s *right;     
 }TreeNode;
 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        LOGD("Val: %d\n", root->val);       
        flatten(root->left);
        flatten(root->right);
    }
};

void preorder(TreeNode* root) {
    if(root==NULL) return;
    LOGD("Val: %d\n", root->val);
    preorder(root->left);
    preorder(root->right);
}

void Test_flatten()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    TreeNode* node1 = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* node2 = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* node3 = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* node4 = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* node5 = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* node6 = (TreeNode*) malloc(sizeof(TreeNode));
    
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    node5->val = 5;
    node6->val = 6;
    
    node1->left  = node2;
    node1->right = node5;
    node2->left  = node3;
    node2->right = node4;
    node3->left  = NULL;
    node3->right = NULL;
    node4->left  = NULL;
    node4->right = NULL;
    node5->left  = NULL;
    node5->right = node6;
    node6->left  = NULL;
    node6->right = NULL;
    
    solution->flatten(node1);
//    preorder(node1);
    
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete solution;
}