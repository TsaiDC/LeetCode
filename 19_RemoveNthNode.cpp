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

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//

/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
19. Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

    if(head == NULL || n <= 0) {
        return head;
    }
    
    ListNode *pHead = head;
    vector<ListNode*> listp;
    int idx = 0;
    while (pHead != NULL)
    {
        listp.push_back(pHead);
        pHead = pHead->next;
    }
/*
    for(int i=0; i<listp.size(); ++i)
    {
        LOGD("%d \n", listp[i]->val);
    }
*/
    idx = listp.size() - n;
    if(idx<0) {
        LOGE("Wrong Idx: %d\n", idx);
        return head;
    }    
    LOGD("Remove: %d\n", listp[idx]->val);
    int left = idx - 1;
    int right= idx + 1;    


    pHead = head;

    //At Left
    if(left < 0) {
        if(listp.size() == 1) {
            free(listp[0]);
            return NULL;
        }
        else {
            pHead = listp[1];
            return pHead;
        }
    }

    //At Right    
    if(right >=listp.size()){
        listp[left]->next = NULL;
        free(listp[idx]);
        return pHead;
    }

    //At Middle
    listp[left]->next = listp[right];
    free(listp[idx]);
    return pHead;
}

void Test_removeNthFromEnd()
{
    LOGD("%s\n", __TIME__);
    ListNode *pHead = NULL, *pTail = NULL, *pTmp = NULL;
    
    for(int i=1; i<6; ++i)
    {
        pTmp = (ListNode*) malloc(sizeof(ListNode));
        pTmp->val = i;
        pTmp->next = NULL;
        
        if(pHead == NULL) {
            pHead = pTmp;
        }
        if(pTail == NULL) {
            pTail = pTmp;
        }
        else {
            pTail->next = pTmp;
            pTail = pTmp;
        }
    }

    printf("Iput: ");
    pTail = pHead;
    while(pTail != NULL)
    {
        printf("%d ", pTail->val);
        pTail = pTail->next;
    }
    printf("\n");

    pHead = removeNthFromEnd(pHead, 1);
    
    printf("Oput: ");
    while(pHead != NULL)
    {
        pTmp = pHead;
        pHead = pHead->next;
        printf("%d ", pTmp->val);
        free(pTmp);
    }
    printf("\n");
    
    LOGD("Done \n");
}