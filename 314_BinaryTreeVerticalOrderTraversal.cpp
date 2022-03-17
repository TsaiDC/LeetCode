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
https://leetcode.com/problems/binary-tree-vertical-order-traversal/
314. Binary Tree Vertical Order Traversal

Given the root of a binary tree, return the vertical order traversal of its nodes' values. 
(i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Example 1:

  3
9   20
  15  7
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Example 2:

      3
    /   \
   9     8
  / \   / \
 4  0  1   7
Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]



Example 3:

     3
  9      8
4   0  1   7
  5     2
Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]

*/
#ifdef _CVERSION_
//C
/*

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** verticalOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

}
void Test_FB_verticalOrder()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
/**
 * Definition for a binary tree node.
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
    vector< vector<int> > verticalOrder(TreeNode* root) {
        vector< vector<int> > ans;
        map<int, vector<int> > xmap;
        preOrder(root, 0, xmap);
        return ans;
    }
    
    void preOrder(TreeNode* root, int col, map<int, vector<int> >xmap) {
        if(!root) return;
        
        map<int, vector<int> >::iterator iter;
        iter = xmap.find(col);
        if(iter != xmap.end()){
            iter->second.push_back(root->val);
            LOGD("Col: %d, Val: %d\n",  col, root->val);
        }
        else {
            vector<int> cols;
            cols.push_back(root->val);
            xmap[col] = cols;
            LOGD("Col: %d, Val: %d\n",  col, root->val);
        }
      
        preOrder(root->left, col-1, xmap);
        preOrder(root->right, col+1, xmap);
    }
};
void Test_FB_verticalOrder()
{
    LOGD("[CPP] %s\n", __TIME__);
    TreeNode *pRoot = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    Solution *solution = new Solution();
    solution->verticalOrder(pRoot);
    delete solution;
}

#endif //_CPPVERSION_