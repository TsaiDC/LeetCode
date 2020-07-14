//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <queue>

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
https://leetcode.com/problems/linked-list-cycle-ii/
142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

To represent a cycle in the given linked list, 
we use an integer pos which represents the position (0-indexed) 
in the linked list where tail connects to. 
If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: 
There is a cycle in the linked list, 
where tail connects to the second node.

(3)->(2)->(0)->(-4)
      \_________|

Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: 
There is a cycle in the linked list, 
where tail connects to the first node.

(1)->(2)
  \___|

Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

(1)

*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *pSlow = head;
        ListNode *pFast = NULL;

        if(!pSlow)
            return NULL;
        
        if(pSlow->next != NULL) {
            pFast = pSlow->next->next;
        }

        while(pSlow != pFast)
        {
            if(!pSlow || !pFast) {
                break;
            }

            pSlow = pSlow->next;

            if(pFast->next) {
                pFast = pFast->next->next;
            }
            else {
                pFast = NULL;
            }
        }
        return pFast;
    }
};

vector<ListNode*> items;
ListNode *getList()
{
#if 1
    int arr1[] = {-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5};
    int pos = 24;
#endif
#if 0
    int arr1[] = {3,2,0,-4};
    int pos = 1;
#endif

    int n = sizeof(arr1)/sizeof(arr1[0]);    
    ListNode* p;
    
    for(int i=0; i<n; ++i)
    {
        p = new ListNode(arr1[i]);
        items.push_back(p);
    }
    
    for(int i=0; i<items.size()-1; ++i)
    {
        items[i]->next = items[i+1];        
    }
    items[items.size()-1]->next = items[pos];

    p = items[0];
    int count = 0;
    while(count < n+1) {
        LOGD("%2d, %d\n", count, p->val);        
        p=p->next;
        count++;
    }    

    return items[0];
}

void Test_detectCycle()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    ListNode *p1 = getList();

    ListNode *pAns = solution->detectCycle(p1);
    if(pAns) {
        LOGD("Ans, idx val = %d\n", pAns->val);
    }
    else {
        LOGD("Ans: NULL, No circle\n");
    }
    
    delete solution;
    for(int i=0;i<items.size(); ++i)
    {
        delete items[i];
    }
}