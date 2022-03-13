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
https://leetcode.com/problems/find-leaves-of-binary-tree/
366. Find Leaves of Binary Tree

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.

Example 1:
  1
 2 3  ->  1 -> 1
4 5      2

Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level 
it does not matter the order on which elements are returned.

Example 2:

Input: root = [1]
Output: [[1]]

Constraints:
The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100

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
int** findLeaves(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

}
#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 8 ms, faster than 9.60% of C++ online submissions for Find Leaves of Binary Tree.
Memory Usage: 8.1 MB, less than 92.53% of C++ online submissions for Find Leaves of Binary Tree.
*/

//Definition for a binary tree node.
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
    vector< vector<int> > findLeaves(TreeNode* root) {
        vector< vector<int> > ans;
        vector<int> leafs;
        if(!root) return ans;

        do {
            if(cutLeaf(root, leafs) == 1){
                ans.push_back(leafs);
                break;
            }
            ans.push_back(leafs);
            leafs.clear();
        }while(1);   
        return ans;
    }

    bool cutLeaf(TreeNode* root, vector<int> &leafs) {
        if(!root) return false;

        if(isLeaf(root)){
            leafs.push_back(root->val);
            delete root;
            root = NULL;
            return true;
        }
        
        if(isLeaf(root->left)){
            leafs.push_back(root->left->val);
            delete root->left;
            root->left = NULL;
        }
        if(isLeaf(root->right)){
            leafs.push_back(root->right->val);
            delete root->right;
            root->right = NULL;
        }
        cutLeaf(root->left, leafs);
        cutLeaf(root->right, leafs);
        return false;
    }
    
    bool isLeaf(TreeNode* pNode) {
        if(pNode == NULL) return false;
        if(pNode->left == NULL && pNode->right == NULL) return true;
        return false;
    }

    void showTree(TreeNode* root) {
        if(!root)return;
        LOGD("%d\n", root->val);
        showTree(root->left);
        showTree(root->right);
    }
    
    void deleteTree(TreeNode* root) {
        if(!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        LOGD("Del %d\n", root->val);
        delete root;
        root = NULL;
    }
};

void Test_GG_findLeaves()
{
    LOGD("[CPP] %s\n", __TIME__);
    vector< vector<int> > ans;
    TreeNode *pRoot = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
//    TreeNode *pRoot = new TreeNode(1, new TreeNode(2, new TreeNode(3), NULL), NULL);
//    TreeNode *pRoot = new TreeNode(1, NULL, new TreeNode(2,NULL,new TreeNode(3)));
//    TreeNode *pRoot = new TreeNode(1);
//    TreeNode *pRoot = NULL;
    Solution *solution = new Solution();
    ans = solution->findLeaves(pRoot);
    //solution->deleteTree(pRoot);

    for(int i=0; i<ans.size(); ++i) {
        for(int j=0;j<ans[i].size(); ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    delete solution;
}

#endif //_CPPVERSION_