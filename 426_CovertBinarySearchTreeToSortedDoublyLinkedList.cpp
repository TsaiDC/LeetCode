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
https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
426. Convert Binary Search Tree to Sorted Doubly Linked List
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers 
in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element 
is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. 
After the transformation, the left pointer of the tree node should point to its predecessor, 
and the right pointer should point to its successor. You should return the pointer to the smallest 
element of the linked list.


Example 1:

Input: root = [4,2,5,1,3]

    4
   / \
  2   5
 / \     
1   3


H
 `1 <-> 2 <-> 3 <-> 4 <-> 5 
  ^                       ^
  `-----------------------'

Output: [1,2,3,4,5]
Explanation: 
The figure below shows the transformed BST. 
The solid line indicates the successor relationship, 
while the dashed line means the predecessor relationship.


Example 2:

Input: root = [2,1,3]
Output: [1,2,3]

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
All the values of the tree are unique.
  
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
};

struct Node* treeToDoublyList(struct Node *root) {
    
}

void Test_FB_treeToDoublyList()
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

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        
    }
};
void Test_FB_treeToDoublyList()
{
    LOGD("[CPP] %s\n", __TIME__);    
    Solution *solution = new Solution();    
    delete solution;
}

#endif //_CPPVERSION_