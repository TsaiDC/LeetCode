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

#include "apiheader.h"

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
https://leetcode.com/problems/boundary-of-binary-tree/
545. Boundary of Binary Tree

The boundary of a binary tree is the concatenation of the root, the left boundary, 
the leaves ordered from left-to-right, and the reverse order of the right boundary.

The left boundary is the set of nodes defined by the following:

# The root node's left child is in the left boundary. If the root does not have a left child, 
  then the left boundary is empty.
# If a node in the left boundary and has a left child, then the left child is in the left boundary.
# If a node is in the left boundary, has no left child, but has a right child, 
  then the right child is in the left boundary.
# The leftmost leaf is not in the left boundary.

The right boundary is similar to the left boundary, except it is the right side of the root's 
right subtree. Again, the leaf is not part of the right boundary, and the right boundary is empty 
if the root does not have a right child.


The leaves are nodes that do not have any children. For this problem, the root is not a leaf.

Given the root of a binary tree, return the values of its boundary.


Example 1:

   1
    \
     2
    / \
   3   4
   
Input: root = [1,null,2,3,4]
Output: [1,3,4,2]
Explanation:
- The left boundary is empty because the root does not have a left child.
- The right boundary follows the path starting from the root's right child 2 -> 4.
  4 is a leaf, so the right boundary is [2].
- The leaves from left to right are [3,4].
Concatenating everything results in [1] + [] + [3,4] + [2] = [1,3,4,2].


Example 2:


Input: root = [1,2,3,4,5,6,null,null,null,7,8,9,10]
Output: [1,2,4,7,8,9,10,6,3]
Explanation:
- The left boundary follows the path starting from the root's left child 2 -> 4.
  4 is a leaf, so the left boundary is [2].
- The right boundary follows the path starting from the root's right child 3 -> 6 -> 10.
  10 is a leaf, so the right boundary is [3,6], and in reverse order is [6,3].
- The leaves from left to right are [4,7,8,9,10].
Concatenating everything results in [1] + [2] + [4,7,8,9,10] + [6,3] = [1,2,4,7,8,9,10,6,3].
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-1000 <= Node.val <= 1000

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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* boundaryOfBinaryTree(struct TreeNode* root, int* returnSize){

}
void Test_AM_boundaryOfBinaryTree()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Self Solution
Runtime: 22 ms, faster than 19.98% of C++ online submissions for Boundary of Binary Tree.
Memory Usage: 22.6 MB, less than 7.49% of C++ online submissions for Boundary of Binary Tree.
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ret;
        vector<int>left;
        vector<int>leaves;
        stack<int>right;
        unordered_map<TreeNode*,  int>map;

        if(!root) return ret;

        ret.push_back(root->val);
        map[root] = 1;

        //Find left most
        TreeNode* pLeft = root->left;
        while (pLeft) {
//            LOGD("Left: %d\n", pLeft->val);
            map[pLeft] = 1;
            left.push_back(pLeft->val);
            pLeft = pLeft->left != NULL ? pLeft->left : pLeft->right;
        }

        //Find leaves
        TreeNode* pLeaf = root;
        findLeaf(pLeaf, leaves, map);
        
        //Find right most
        TreeNode* pRight = root->right;
        while (pRight) {
            if(map.find(pRight)==map.end()) {
//                LOGD("Right: %d\n", pRight->val);
                map[pRight] = 1;
                right.push(pRight->val);
            }
            pRight = pRight->right != NULL ? pRight->right : pRight->left;
        }
        
        for(auto & p : left)
            ret.push_back(p);
        for(auto & p : leaves)
            ret.push_back(p);
        while(!right.empty()) {
            ret.push_back(right.top());
            right.pop();
        }
        
        return ret;
    }
    
    void findLeaf(TreeNode* root, vector<int>& leaves, unordered_map<TreeNode*,int>& map) {
        if(!root) return;        
        if(root->left == NULL && root->right == NULL) {
            if(map.find(root)==map.end()) {
//                LOGD("Leaf: %d \n", root->val);
                map[root] = 1;
                leaves.push_back(root->val);
            }
        }
        findLeaf(root->left, leaves, map);
        findLeaf(root->right,leaves, map);
    }
    
    void preOrder(TreeNode* root) {
        if(!root) return;
//        LOGD("%d \n", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};

void Test_AM_boundaryOfBinaryTree()
{
    LOGD("[CPP] %s\n", __TIME__);
#if 0
//Example 1
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node3, node4);
    TreeNode* node1 = new TreeNode(1, NULL, node2);
#endif

#if 0
//Example 2
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node10 = new TreeNode(10);
    TreeNode* node5 = new TreeNode(5, node7, node8);
    TreeNode* node6 = new TreeNode(6, node9, node10);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* node3 = new TreeNode(3, node6, NULL);
    TreeNode* node1 = new TreeNode(1, node2, node3);
#endif

#if 1
    TreeNode* node1 = new TreeNode(1);
#endif

    vector<int> ans;
    Solution *solution = new Solution();
//    solution->preOrder(node1);
    ans = solution->boundaryOfBinaryTree(node1);
    delete solution;
    
    for(auto& p:ans) {
        LOGD("Ans: %d\n", p);
    }
}

#endif// _CPPVERSION_