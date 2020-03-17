//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

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

/*
https://leetcode.com/problems/copy-list-with-random-pointer/
138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(head == NULL) return NULL;
    Node* pHead = head;
    Node* tmpNode = NULL;
    vector<Node*> oldList;    
    vector<Node*> newList;    
    while(pHead!=NULL)
    {    
        tmpNode = new Node(pHead->val);
        newList.push_back(tmpNode);        
        oldList.push_back(pHead);        
        pHead=pHead->next;
    }
    
    for(int i=oldList.size()-1; i>=0; i--)
    {
        if(oldList[i]->random == NULL) {
            newList[i]->random = NULL;
            continue;
        }
        
        for(int j=0; j<oldList.size(); ++j)
        {
            Node* pTmp = oldList[i]->random;
            if(pTmp->val == oldList[j]->val &&
               pTmp->random == oldList[j]->random &&
               pTmp->next == oldList[j]->next ) {               
               newList[i]->random = newList[j];
               break;
            }
        }
    }
#if 0
    for(int i=0; i<newList.size(); ++i)
    {
        int nextVal = newList[i]->random == NULL ? -1 : newList[i]->random->val;
        LOGD("New: [%d, %d]\n", newList[i]->val, nextVal);
    }
#endif
    for(int i=0; i<newList.size(); ++i)
    {
        if(i+1< newList.size()) {
            newList[i]->next = newList[i+1];
        }
    }    
    return newList[0];
}

void Test_copyRandomList()
{
    LOGD("%s\n", __TIME__);

    Node *p0 = new Node(7);
    Node *p1 = new Node(13);
    Node *p2 = new Node(11);
    Node *p3 = new Node(10);
    Node *p4 = new Node(1);
    p0->next=p1;
    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    p4->next=NULL;

    p0->random = NULL;
    p1->random = p0;
    p2->random = p4;
    p3->random = p2;
    p4->random = p0;
    
    Node* pHead = copyRandomList(p0);
//    Node* pHead = copyRandomList(NULL);
    
    while(pHead!=NULL)
    {
        int nextVal = pHead->random == NULL ? -1 : pHead->random->val;
        LOGD("New: [%d, %d]\n", pHead->val, nextVal);
        pHead = pHead->next;
    }

}