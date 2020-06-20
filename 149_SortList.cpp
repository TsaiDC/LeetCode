//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>

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
https://leetcode.com/problems/sort-list/
148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //divide the list into two parts 
        fast = slow->next;
        slow->next = NULL;
        
        return merge2(sortList(head), sortList(fast));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dump(0);
        ListNode* cur = &dump;
        
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
                
            cur = cur->next;
        }
        
        if (l1 != NULL)
            cur->next = l1;
        else
            cur->next = l2;
            
        return dump.next;
    }
    
    ListNode* merge2(ListNode* l1, ListNode* l2)
    {
        ListNode *pHead = NULL;
        ListNode *pTail = NULL;
        while (l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2-> val) {
                if (!pHead) {
                    pHead = l1;
                    pTail = l1;
                }
                else {
                    pTail->next = l1;
                    pTail = pTail->next;
                }
                l1 = l1->next;
            }
            else {
                if (!pHead) {
                    pHead = l2;
                    pTail = l2;
                }
                else {
                    pTail->next = l2;
                    pTail = pTail->next;
                }
                l2 = l2->next;
            }
        }
        if(l1!=NULL) {
            pTail->next = l1;
        }
        if(l2!=NULL) {
            pTail->next = l2;
        }
        return pHead;
    }
};

void Test_sortList()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    ListNode *pTmp;
    ListNode *pHead = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    pHead = solution->sortList(pHead);
    
    while(pHead)
    {
        pTmp = pHead;
        pHead = pHead->next;
        LOGD("%d\n", pTmp->val);
        delete pTmp;
    }

    ListNode *p1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode *p2 = new ListNode(7, new ListNode(6, new ListNode(5, new ListNode(4))));
    pHead = solution->merge2(p1, p2);
    while(pHead)
    {
        pTmp = pHead;
        pHead = pHead->next;
        LOGD("- %d\n", pTmp->val);
        delete pTmp;
    }
    
    delete solution;
}