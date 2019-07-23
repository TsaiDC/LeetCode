//g++ *.cpp -o tool
//https://ocean2002n.pixnet.net/blog/post/86868772-%5B%E6%80%9D%E8%80%83%5D-%E6%AF%8F%E4%BD%8Dgoogle%E5%B7%A5%E7%A8%8B%E5%B8%AB%E9%9D%A2%E8%A9%A6%E5%BF%85%E6%9C%83%E7%9A%8415%E9%81%93%E7%A8%8B%E5%BC%8F%E8%80%83
//https://ocean2002n.pixnet.net/blog/post/86868974

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define GREEN "\033[0;32;32m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#if DEBUG
#define LOGI(...) {printf(GREEN "[I] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGI(...)
#define LOGD(...)
#define LOGE(...)
#endif


/*
Sortings:
http://notepad.yehyeh.net/Content/Algorithm/Sort/Sort.php
*/

#if 0
https://www.itread01.com/content/1550181095.html
public static int[] bigNumberMultiply2(int[] num1, int[] num2){
    int[] result = new int[num1.length + num2.length];

    for (int i = 0; i < num1.length; i++){
        for (int j = 0; j < num2.length; j++){
            result[i + j + 1] += num1[i] * num2[j];
        }
    }

    for(int k = result.length-1; k > 0; k--){
        if(result[k] > 10){
            result[k - 1] += result[k] / 10;
            result[k] %= 10;
        }
    }
    return result;
}
#endif

class CNode
{
public:
    CNode* pNext;
    CNode* pPre;
    int mVal;
    CNode():mVal(0) {}
    CNode(int val): mVal(val), pPre(NULL), pNext(NULL) {}
};

class CNodeList
{
public:
    CNodeList():mNum(0), pHead(NULL), pTail(NULL){}
    ~CNodeList();
    bool getVal(int idx, int* outVal);
    void addNode(int val);
    void showList();
    void swap(int idx1, int idx2);
    
private:
    int mNum;
    CNode* pHead;
    CNode* pTail;
};

CNodeList::~CNodeList()
{
    CNode* ptr = NULL;
    while(pHead != NULL)
    {
        --mNum;
        ptr = pHead;
        pHead = pHead->pNext;
//        LOGD ("Free: %d\n", ptr->mVal);
        delete ptr;
    }
}

void CNodeList::showList()
{
    CNode* ptr = pHead;
    printf("<-- ");
    while(ptr != NULL)
    {
        printf ("%d ", ptr->mVal);
        ptr = ptr->pNext;
    }
    printf(" -->\n");
}

void CNodeList::addNode(int val)
{
    CNode* ptr = new CNode(val);
    if (pTail == NULL) {
        pTail = ptr;
        pHead = ptr;
    }
    else {
        pTail->pNext = ptr;
        ptr->pPre = pTail;
        pTail = ptr;
    }
}

bool CNodeList::getVal(int idx, int* outVal)
{
    CNode* ptr = pHead;
    while (idx > 0 && ptr !=NULL)
    {
        --idx;
        ptr = ptr->pNext;
    }
    *outVal = ptr == NULL ? -1 : ptr->mVal;
    return ptr == NULL ? false : true;
}

//
// Create Linked List
//
typedef struct Node_s {
    struct Node_s *pNext;
    struct Node_s *pPre;
    int mVal;
}Node_t;

static void addNode(Node_t **pHead, Node_t **pTail, int val)
{
    Node_t *pData;
    pData = (Node_t*)malloc (sizeof(Node_t));
    pData->mVal = val;
    pData->pNext = NULL;
    pData->pPre = NULL;

    if(*pHead == NULL) {
        LOGD("Head Node: %d\n", val);
        (*pHead) = pData;
        (*pTail) = pData;
    }
    else {
        LOGD("Tail Node: %d\n", val);    
        (*pTail)->pNext = pData;
        pData->pPre = *pTail;
        (*pTail) = pData;
    }
}

static Node_t* removeNode(Node_t *pData)
{
    Node_t *pL = pData->pPre;
    Node_t *pR = pData->pNext;
    if (pL != NULL) {
        pL->pNext = pR;
    }
    if(pR != NULL) {
        pR->pPre = pL;
    }
    
    return pData;
}

static Node_t* insertToNodeRight(Node_t *pHead, Node_t *pData)
{    
    Node_t *pHR = pHead->pNext;
    
    pHead->pNext = pData;
    pData->pPre = pHead;
    pData->pNext = pHR;

    if (pHR != NULL) {
        pHR->pPre = pData;
    }
    return pHead;
}   

static Node_t* insertToNodeLeft(Node_t *pHead, Node_t *pData)
{
    Node_t *pHL = pHead->pPre;

    pData->pNext = pHead;
    pHead->pPre = pData;    
    pData->pPre = pHL;        
    if(pHL!= NULL) {
        pHL->pNext=pData;
        return pHead;
    } 
    else {
        return pData;
    }
}

Node_t* getList(int start, int end, bool isReverse)
{
    Node_t* pHead = NULL;
    Node_t* pTail = NULL;
    
    if (!isReverse) {
        for(int i=start; i<=end; ++i) {
            addNode(&pHead, &pTail, i);
        }
    }
    else {
        for(int i=end; i>=start; --i) {
            addNode(&pHead, &pTail, i);
        }    
    }
    
    return pHead;
}

void freeList(Node_t *pHead)
{
    Node_t* pTmp = NULL;
    printf("Free <-- ");
    while(pHead!=NULL)
    {
        pTmp = pHead;
        pHead=pHead->pNext;
        printf("%d ", pTmp->mVal);
        free(pTmp);
    }
    printf(" -->\n");
}

void showList(const char *str, Node_t* pHead)
{
    Node_t* pTmp = pHead;
    printf("%s <-- ", str);
    while(pTmp!=NULL)
    {
        printf("%d ", pTmp->mVal);
        pTmp = pTmp->pNext;
    }
    printf(" -->\n");
}

void showListNum(const char *str, Node_t* pHead, int num)
{
    printf("%s ", str);
    printf("<-- ");
    for(int i=0;i<num && pHead != NULL; ++i)
    {
        printf("%d ", pHead->mVal);
        pHead = pHead->pNext;
    }
    printf(" -->\n");
}

Node_t* mergeList(Node_t* pList1, int list1_num, Node_t* pList2, int list2_num)
{ 
    //Store the start/end point
    Node_t *pS = pList1->pPre;
    Node_t *pE = pList2;
    Node_t *pList = NULL;
    for(int i=0; i<list2_num; ++i) {
        pE = pE->pNext;
    }
#if 1
    //Merge 2 list 
    Node_t *p1, *p2, *pNode;
    int num1 = list1_num;
    int num2 = list2_num;
   
    p1 = pList1;
    p2 = pList2;

    while( (num1>0) && (num2 > 0))
    {        
        LOGE("Num1: %d Val: %d, Num2: %d, Val: %d\n", num1, p1->mVal, num2, p2->mVal);

        if(p1->mVal > p2->mVal) {
            LOGD("Remove %d, Insert\n", p2->mVal);
            //Remove p2
            --num2;
            pNode = p2;
            p2 = p2->pNext;            
            removeNode(pNode);

            //Insert to left of P1
            insertToNodeLeft(p1, pNode);
            if (pList == NULL) {
                pList = pNode;
            }
            if(num2 == 0) {
                break;
            }
        }
        else {
            LOGD("Move to Next %d\n", p1->mVal);
            if (pList == NULL) {
                pList = p1;
            } 
            if(--num1 == 0) {
                //TODO
                break;
            }
            p1 = p1->pNext;
        }
    }
    
    LOGD("=============== NUM1: %d, NUM2: %d\n", num1, num2);

#if 1
    pList->pPre = pS;
    if(pS != NULL) {
        pS->pNext = pList;
    }
    
    if (num2 == 0) {
        while (num1>1)
        {
            --num1;
            p1 = p1->pNext;
        }
        p1->pNext = p2;
        if(p2 != NULL) {
            p2->pPre = p1;
        }
    }
    
    if (num1 == 0) {
        p1->pNext = p2;
        if(p2 != NULL) {
            p2->pPre = p1;
        }        
    }

#endif
    showListNum("Merge", pList, list1_num + list2_num );
#endif    
    return pList;
}

void doMergeSortList(Node_t *pList, int num)
{
    int LNum = num/2;
    int RNum = num-LNum;
    Node_t *pL = pList; 
    Node_t *pR = pList;
    
    LOGD("N: %d, L: %d, R: %d\n", num, LNum, RNum);
    if(LNum ==0 || RNum == 0) {
        LOGE(" Return - N: %d, L: %d, R: %d\n", num, LNum, RNum);
        return;
    }
    
    showListNum("--1", pL, LNum);
    doMergeSortList(pL, LNum);  
    for(int i=0; i<LNum; ++i)
    {
        pR = pR->pNext;
    }
    showListNum("--2", pR, RNum);
    doMergeSortList(pR,RNum);
    pL = mergeList(pL, LNum, pR, RNum);
}

void Test_sortingList()
{
    LOGI("%s\n", __TIME__);
    CNodeList *pList = new CNodeList();
    pList->addNode(1);
    pList->addNode(3);
    pList->addNode(5);
    pList->showList();
    delete pList;
#if 0
    Node_t *pList1, *pList2, *pList3, *pNode;

#if 1
    pList1 = getList(1,3, false);
    pList2 = getList(2,4, true);
#else
    addNode(&pList1, &pNode, 1);
    addNode(&pList1, &pNode, 3);
    addNode(&pList1, &pNode, 5);
    
    addNode(&pList2, &pNode, 2);
    addNode(&pList2, &pNode, 4);
    addNode(&pList2, &pNode, 6);
#endif
    //Combine 2 lists
    Node_t* pTail = pList1;
    while(pTail->pNext != NULL) {
        pTail = pTail->pNext;
    }
    pTail->pNext = pList2;
    pList2->pPre = pTail;

    showList("L1", pList1);
    showList("L2", pList2);
    
    pList1 = mergeList(pList1, 3, pList2, 3);
    showListNum("XL1", pList1, 6);
    
    doMergeSortList(pList1, 6);

//    pNode = removeNode(&pList2);
//    LOGD ("Remove Node: %d\n", pNode->mVal);
//    showList("XL1", pList1);
//    showList("XL2", pList2);
//    pList3 = pList1;
//    pList3 = pList3->pNext;
//    pList3 = pList3->pNext;
//    pList3 = pList3->pNext;
//    pList3 = pList3->pNext;
//    insertToNodeLeft(&pList3, pNode);
//    
//    while (pList3->pNext != NULL)
//    {
//        pList3 = pList3->pNext;
//    }
//    LOGD ("P3 Node: %d\n", pList3->mVal);
//    insertToNodeRight(&pList3, pNode);
//    showList("XL2", pList1);
//    freeList(pList1);
#endif
}
