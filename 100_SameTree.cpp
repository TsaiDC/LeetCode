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
https://leetcode.com/problems/same-tree/
100. Same Tree

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> vec1;
        vector<int> vec2;
        getInorder(p, vec1);
        getInorder(q, vec2);
        
        if(vec1.size()!=vec2.size()) return false;
        
        for(int i=0; i<vec1.size(); i++)
        {
            if(vec1[i] != vec2[i]) return false;
        }

        vec1.clear();
        vec2.clear();
        getPreorder(p, vec1);
        getPreorder(q, vec2);
        
        if(vec1.size()!=vec2.size()) return false;
        
        for(int i=0; i<vec1.size(); i++)
        {
            if(vec1[i] != vec2[i]) return false;
        }
#if 0
        vec1.clear();
        vec2.clear();
        getPostorder(p, vec1);
        getPostorder(q, vec2);
        
        if(vec1.size()!=vec2.size()) return false;
        
        for(int i=0; i<vec1.size(); i++)
        {
            if(vec1[i] != vec2[i]) return false;
        }
#endif
        return true;
    }

    void getInorder(TreeNode* root, vector<int> &inorder)
    {
        if(!root) {
            inorder.push_back(-99);
            return;
        }
        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }
    void getPreorder(TreeNode* root, vector<int> &preorder)
    {
        if(!root) {
            preorder.push_back(-99);
            return;
        }
        preorder.push_back(root->val);
        getPreorder(root->left, preorder);         
        getPreorder(root->right, preorder);
    }

    void getPostorder(TreeNode* root, vector<int> &postorder)
    {
        if(!root) {
            postorder.push_back(-99);
            return;
        }
        getPostorder(root->left, postorder);         
        getPostorder(root->right, postorder);
        postorder.push_back(root->val);
    }
};

void Test_isSameTree()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
//    TreeNode *pRoot1 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(8), new TreeNode(9))), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
//    TreeNode *pRoot2 = new TreeNode(5, new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(8), new TreeNode(9))), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    TreeNode *pRoot1 = new TreeNode(1, new TreeNode(1), NULL);
    TreeNode *pRoot2 = new TreeNode(1, NULL, new TreeNode(1));

    
    bool b = solution->isSameTree(pRoot1, pRoot2);
    
    LOGD("Done b: %d\n", b);
    delete solution;
}