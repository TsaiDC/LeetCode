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
https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
708. Insert into a Sorted Circular Linked List

Given a Circular Linked List node, which is sorted in ascending order, 
write a function to insert a value insertVal into the list such that it remains a sorted circular list.
The given node can be a reference to any single node in the list and may not necessarily be the 
smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. 
After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is null), you should create a new single circular list 
and return the reference to that single node. Otherwise, you should return the originally given node.

Example 1:


1 ---+
^    |
|    V
4 <- 3 <- Head
 
Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
Explanation: In the figure above, there is a sorted circular list of three elements. 
You are given a reference to the node with value 3, and we need to insert 2 into the list. 
The new node should be inserted between node 1 and node 3. 
After the insertion, the list should look like this, and we should still return node 3.

1 -->2
^    |
|    V
4 <--3 <- Head


Example 2:

Input: head = [], insertVal = 1
Output: [1]
Explanation: The list is empty (given head is null). 
We create a new single circular list and return the reference to that single node.

Example 3:

Input: head = [1], insertVal = 0
Output: [1,0]

*/
#ifdef _CVERSION_
//C
/*

*/

//Definition for a Node.
struct Node {
    int val;
    struct TreeNode *next;
};
 
struct Node* insert(struct Node* head, int insertVal) {
    return NULL;   
}

void Test_FB_insert()
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
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        return NULL;
    }
};
void Test_FB_insert()
{
    LOGD("[CPP] %s\n", __TIME__);    
    Solution *solution = new Solution();    
    delete solution;
}

#endif //_CPPVERSION_