//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>

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
https://leetcode.com/problems/rotate-list/
61. Rotate List

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    ListNode* ptr = head;
    ListNode* pNewHead = head;
    int count = 0;
    int shift = 0;
    while(ptr != NULL) {
        ptr = ptr->next;
        ++count;
    }
    if (pNewHead == NULL) {
        return pNewHead;
    }
    if(k%count == 0) {
        LOGD("No Need\n");
        return pNewHead;
    }
    shift = count - k%count;
    LOGD("Count: %d, Shift: %d\n", count, shift);

    for(int i=0; i<shift; ++i)
    {
        if(pNewHead!=NULL)
            pNewHead = pNewHead->next;
    }
    LOGD("Count: %d, Shift: %d, new head: %d\n", count, shift, pNewHead->val);
    ptr = pNewHead;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head;
    
    ptr = head;
    for(int i=0; i<shift-1; ++i)
    {
        if(ptr!=NULL)
            ptr = ptr->next;
    }
    ptr->next = NULL;
    
    return pNewHead;    
}

ListNode* insertList(ListNode* head, int val)
{
    ListNode* ptr = head;
    if(ptr == NULL) {
        ptr = new ListNode(val);
        return ptr;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new ListNode(val);    
    return head;
}

void freeList(ListNode* head)
{
    ListNode* ptr = head;
    ListNode* ptmp;

    while(ptr != NULL) {
        ptmp = ptr;
        ptr = ptr->next;
        delete ptmp;
    }
}

void displayList(ListNode* head)
{
    ListNode* ptr = head;
    printf("-> ");
    while(ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void Test_rotateRight()
{
    LOGD("%s\n", __TIME__);
    ListNode* head = NULL;
    head = insertList(head, 1);
    head = insertList(head, 2);
    head = insertList(head, 3);
    head = insertList(head, 4);
    head = rotateRight(head, 4);
    displayList(head);
    freeList(head);
    
    LOGD("Done \n");
}