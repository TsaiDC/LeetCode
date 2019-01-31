//g++ main.cpp addTwoNumbers.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "apiheader.h"

using namespace std;

//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void freeItem(ListNode* pHead)
{
    ListNode* pTmp;
    
    while(pHead != NULL)
    {
        pTmp = pHead;
        pHead = pHead->next;
        printf("[DBG] %s(%d) %s : Del: %d\n", __FUNCTION__, __LINE__, __TIME__, pTmp->val);
        delete pTmp;
    }
}    

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    printf("[DBG] %s(%d) %s : size: %d\n", __FUNCTION__, __LINE__, __TIME__, 0);
    int a =0, b=0;    
    ListNode *pResult = NULL, *pNext;
    
    while(l1 != NULL || l2 != NULL) {
        b = a;
        a = 0;
        if(l1 != NULL) {
            b += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            b += l2->val;
            l2 = l2->next;
        }
        
        a = b/10;
        b = b%10;
        printf("[DBG] %s(%d) %s : (a,b): %d, %d\n", __FUNCTION__, __LINE__, __TIME__, a, b);        
        if (pResult == NULL) {
            pResult = new ListNode(b);
            pNext = pResult;
        } else {
            pNext->next = new ListNode(b);
            pNext = pNext->next;                      
        }
        if(l1 == NULL && l2 == NULL && a !=0) {
            pNext->next = new ListNode(a);
            pNext = pNext->next;
        }
    }
    
    freeItem (pResult);

    return pResult;
}

void Test_addTwoNumbers()
{
    printf("[DBG] %s(%d) %s : size: %d\n", __FUNCTION__, __LINE__, __TIME__, 0);
/*
    ListNode* input1 = new ListNode(2);
    input1->next = new ListNode(4);
    input1->next->next = new ListNode(3);
    
    ListNode* input2 = new ListNode(5);
    input2->next = new ListNode(6);
    input2->next->next = new ListNode(4);
*/    
/*
    ListNode* input1 = new ListNode(5);
    ListNode* input2 = new ListNode(5);
*/

    ListNode* input1 = new ListNode(1);
    input1->next = new ListNode(8);
    
    
    ListNode* input2 = new ListNode(0);
    
    
    addTwoNumbers(input1, input2);
    
    printf("[DBG] %s(%d) %s : size: %d ========================\n", __FUNCTION__, __LINE__, __TIME__, 0);
    freeItem(input1);
    freeItem(input2);

}