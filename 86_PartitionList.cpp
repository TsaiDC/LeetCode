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
https://leetcode.com/problems/partition-list/
86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        ListNode *pMS = NULL;
        ListNode *pME = NULL;
        ListNode *pSS = NULL;
        ListNode *pSE = NULL;
        ListNode *pC = head;
        
        while(pC != NULL)
        {
            if(pC->val< x ) {
                if(pSS == NULL) {
                    pSS = pC;
                }
                if(pSE == NULL) {
                    pSE = pC;
                }
                else {
                    pSE->next = pC;
                    pSE = pSE->next;
                }
            }
            else {
                if(pMS == NULL) {
                    pMS = pC;
                }
                if(pME == NULL) {
                    pME = pC;
                }
                else {
                    pME->next = pC;
                    pME = pME->next;
                }
            }
            pC=pC->next;
        }
        if(pSE == NULL) {
            return pMS;
        } else {
            pSE->next = pMS;    
        }
        
        if(pME != NULL) {
            pME->next = NULL;
        }
        
        return pSS;
    }
};
void Test_partition()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;
}