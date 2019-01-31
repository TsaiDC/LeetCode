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
//        printf("[DBG] %s(%d) %s : Del: %d\n", __FUNCTION__, __LINE__, __TIME__, pTmp->val);
        delete pTmp;
    }
}    

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    printf("[DBG] %s(%d) %s : size: %d\n", __FUNCTION__, __LINE__, __TIME__, 0);
    return NULL;
}

void Test_addTwoNumbers()
{
    printf("[DBG] %s(%d) %s : size: %d\n", __FUNCTION__, __LINE__, __TIME__, 0);
    ListNode* input1 = new ListNode(2);
    input1->next = new ListNode(4);
    input1->next->next = new ListNode(3);
    
    ListNode* input2 = new ListNode(5);
    input2->next = new ListNode(6);
    input2->next->next = new ListNode(4);
    
    addTwoNumbers(input1, input2);
    
    freeItem(input1);
    freeItem(input2);

}