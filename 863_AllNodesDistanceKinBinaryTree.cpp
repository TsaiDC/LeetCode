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
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
863. All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.


Example 2:

Input: root = [1], target = 1, k = 3
Output: []

Constraints:
The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
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
int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize) {
    
}

void Test_AM_distanceK()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Self Solution, Tree->Graph->BFS
Runtime: 12 ms, faster than 39.56% of C++ online submissions for All Nodes Distance K in Binary Tree.
Memory Usage: 15.6 MB, less than 11.14% of C++ online submissions for All Nodes Distance K in Binary Tree.
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* pTarget = NULL;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;    
        unordered_map<TreeNode*, TreeNode*>treeMap;    //<Node, Parent of Node
        unordered_map<int, int>recordMap;
        queue<TreeNode*> treeQueue;

        //Tree to Map, O(n)
        initMap(treeMap, root, target);

        //Map to graph, O(n)
        initGraph(treeMap);
/*
        for(auto &p:treeMap) {
            if(p.second) {
                LOGD("Grap: node: %d, parent: %d\n", p.first->val, p.second->val);
            }
            else {
                LOGD("Grap: node: %d, parent: NULL\n", p.first->val);
            }
        }
*/
        //Find the answer
        if(!pTarget) return ans;
        treeQueue.push(pTarget);        
        for(int i=0; i<k; ++i) {
            getAns(treeQueue, treeMap, recordMap);
        }
        
        while(!treeQueue.empty()) {
            TreeNode* pTop = treeQueue.front();
            treeQueue.pop();
            if(pTop) {
                ans.push_back(pTop->val);
            }
        }            

        return ans;
    }
    
    int getAns(queue<TreeNode*>& Q, unordered_map<TreeNode*, TreeNode*>& treeMap, unordered_map<int, int>& recordMap) {
        int count = 0;
        unordered_map<TreeNode*, TreeNode*>::iterator iter;
        queue<TreeNode*>newQ;
//        LOGD("+++++\n");
        while(!Q.empty()) {
            TreeNode* pTop = Q.front();
            Q.pop();
            if(!pTop)continue;
//            LOGD("Get: %d => ", pTop->val);
            recordMap[pTop->val] = 1;

            if(pTop->left && 
               recordMap.find(pTop->left->val) == recordMap.end()) {
               newQ.push(pTop->left);  //left child
               ++count;                    
//               printf("%d ", pTop->left->val);
            }
            if(pTop->right && 
               recordMap.find(pTop->right->val) == recordMap.end()) {
               newQ.push(pTop->right);  //left child
               ++count;                    
//               printf("%d ", pTop->left->val);
            }
            if((iter = treeMap.find(pTop))!= treeMap.end()) {
                if(iter->second != NULL &&
                   recordMap.find(iter->second->val) == recordMap.end()) {
                    newQ.push(iter->second);  //parent
                    ++count;
//                    printf("%d ", iter->second->val);
                }
            }
        }

        Q = newQ;
//        LOGD("-----\n");
        return count;
    }
    void initMap(unordered_map<TreeNode*, TreeNode*>& treeMap, TreeNode* root, TreeNode* target)
    {
        if(!root) return;
        if(root->val == target->val) pTarget = target;
        treeMap[root] = NULL;        
        initMap(treeMap, root->left, target);
        initMap(treeMap, root->right, target);
    }
    
    void initGraph(unordered_map<TreeNode*, TreeNode*>& treeMap)
    {
        unordered_map<TreeNode*, TreeNode*>::iterator iter;
        unordered_map<TreeNode*, TreeNode*>::iterator iChild;
        for(iter=treeMap.begin(); iter!=treeMap.end(); ++iter) {
            TreeNode* pLeft = iter->first->left;
            TreeNode* pRight = iter->first->right;
            if(pLeft) {
                iChild = treeMap.find(pLeft);
                treeMap[iChild->first] = iter->first;
            }
            if(pRight) {
                iChild = treeMap.find(pRight);
                treeMap[iChild->first] = iter->first;
            }
        }
    }
};

void Test_AM_distanceK()
{
    LOGD("[CPP] %s\n", __TIME__);
    TreeNode* node[9];
    TreeNode* pRoot;
    for(int i=0; i<9; ++i) {
        node[i] = new TreeNode(i);
    }
    pRoot = node[3];
    node[3]->left = node[5];
    node[3]->right = node[1];
    node[5]->left = node[6];
    node[5]->right = node[2];
    node[1]->left = node[0];
    node[1]->right = node[8];
    node[2]->left = node[7];
    node[2]->right = node[4];
    vector<int>ans;
    Solution *solution = new Solution();
    ans = solution->distanceK(pRoot, node[5], 2);
    delete solution;
    
    for(int a: ans) {
        LOGD("Ans: %d\n", a);
    }
    
    for(int i=0; i<9; ++i) {
        delete node[i];
    }
}

#endif// _CPPVERSION_