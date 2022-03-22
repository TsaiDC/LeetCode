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
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
1650. Lowest Common Ancestor of a Binary Tree III
Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
According to the definition of LCA on Wikipedia: 
"The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has 
both p and q as descendants (where we allow a node to be a descendant of itself)."

Example 1:

      3
   /     \
  5       1
 / \     / \
6   2   0   8
   / \
  7   4

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.


Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself 
according to the LCA definition.

Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

*The number of nodes in the tree is in the range [2, 10^5].
*-10^9 <= Node.val <= 10^9
*All Node.val are unique.
*p != q
*p and q exist in the tree.

*/
#ifdef _CVERSION_
//C
/*

*/

// Definition for a Node.
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* lowestCommonAncestor(struct Node* p,struct Node* q) {
	
}

void Test_FB_lowestCommonAncestor()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
    }
};

void Test_FB_lowestCommonAncestor()
{
    LOGD("[CPP] %s\n", __TIME__);    
    Solution *solution = new Solution();
    delete solution;
}

#endif //_CPPVERSION_