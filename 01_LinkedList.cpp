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
    int getVal(int idx);
    void addNode(int val);
    void showList();
    bool swapNode(int idx1, int idx2);
    int getNum();
    CNode* removeNode(int idx);
    bool insertToLeft(int idx, CNode* pNode);
    
private:
    int mNum;
    CNode* pHead;
    CNode* pTail;
};

bool CNodeList::insertToLeft(int idx, CNode* pNode)
{
    if (idx >= mNum){
        return false;
    }
    
    CNode* ptr = pHead;
    CNode *pP, *pN;
    int i=0;
    while(i!=idx)
    {
        if(i==idx)
            break;
        ++i;
        ptr = ptr->pNext;
    }    
}

int CNodeList::getNum()
{
    return mNum;
}

CNode* CNodeList::removeNode(int idx)
{
    if (idx >= mNum){
        return NULL;
    }
    
    CNode* ptr = pHead;
    CNode *pP, *pN;
    int i=0;
    while(i!=idx)
    {
        if(i==idx)
            break;
        ++i;
        ptr = ptr->pNext;
    }
    
    if(idx==0){
        pHead = pHead->pNext;
    }
    if(idx == mNum-1){
        pTail = pTail->pPre;
    }
    pP = ptr->pPre;
    pN = ptr->pNext;

    if(pP != NULL) {
        pP->pNext = pN;
    }
    if(pN != NULL) {
        pN->pPre = pP;
    }
    return ptr;
}

bool CNodeList::swapNode(int idx1, int idx2)
{
    CNode *p1 = NULL, *p2 = NULL, *ptr;
    int i=0;
    
    if(idx1>mNum || idx2>mNum) {
        return false;
    }
    
    ptr = pHead;
    while (p1==NULL || p2==NULL)
    {
        if(ptr==NULL)
            break;
        
        if(i==idx1) {
            p1 = ptr;
        }
        
        if(i==idx2) {
            p2 = ptr;
        }
        ++i;
        ptr = ptr->pNext;        
    }

    CNode *pP1 = p1->pPre, *pP2 = p2->pPre;
    CNode *pN1 = p1->pNext, *pN2 = p2->pNext;

    if (p1->pNext == p2 ) {
        if(pP1 != NULL) {
            pP1->pNext = p2;
        }
        p2->pPre = pP1;        
        p2->pNext = p1;
        p1->pPre = p2;
        p1->pNext = pN2;
        if(pN2 != NULL){
            pN2->pPre = p1;
        }
    }
    else if(p1->pPre == p2) {
        if(pP2 != NULL) {
            pP2->pNext = p1;
        }
        p1->pPre = pP2;
        p1->pNext = p2;
        p2->pPre = p1;
        p2->pNext = pN1;
        if(pN1 != NULL){
            pN1->pPre = p2;
        }
    }
    else {
        if (pP1 !=NULL) {
            pP1->pNext = p2;
        }
        p2->pPre = pP1;
        
        if (pN1 !=NULL) {
            pN1->pPre = p2;           
        }
        p2->pNext = pN1;
        if (pP2 !=NULL) {
            pP2->pNext = p1;
            
        }
        p1->pPre = pP2;
        if (pN2 !=NULL) {
            pN2->pPre = p1;       
        }
        p1->pNext = pN2;
    }

    //Update pHead & pTail
    if(idx1 == mNum-1) {
        pTail = p2;
        pTail->pNext = NULL;
    }
    if(idx1 == 0) {
        pHead = p2;
        pHead->pPre = NULL;
    }
    if(idx2 == mNum-1) {
        pTail = p1;
        pTail->pNext = NULL;
    }
    if(idx2 == 0) {
        pHead = p1;
        pHead->pPre = NULL;
    }    
    return true;    
}

CNodeList::~CNodeList()
{
    CNode* ptr = NULL;
    while(pHead != NULL)
    {
        --mNum;
        ptr = pHead;
        pHead = pHead->pNext;
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
    ++mNum;
}

int CNodeList::getVal(int idx)
{
    CNode* ptr = pHead;
    while (idx > 0 && ptr !=NULL)
    {
        --idx;
        ptr = ptr->pNext;
    }
    return ptr->mVal;
}

void doQuickSort(CNodeList* pData, int i, int j)
{    
    int p = j;
    int x = i, y = j-1;
    int tmp = 0;
    
    LOGD("QSort: %d -> %d, p: %d\n", x, y, p);
    
    if(x>y) {
//        LOGE("Stop\n");
        return;
    }

    while(x<y)
    {
        while (x<=y && (pData->getVal(x) <= pData->getVal(p))){++x;}        
        while (y>x && (pData->getVal(y) > pData->getVal(p))){--y;}    
        if(x<y) {
            pData->swapNode(x,y);
        }
    }
    
    if (pData->getVal(x) > pData->getVal(p)) {
        pData->swapNode(x,p);
    }     

//    LOGD("p: %d,  0~%d <=> %d~%d \n", x, x-1, x+1, j);
    doQuickSort(pData, 0, x-1);
    doQuickSort(pData, x+1, j);
}

#if 0
void doMergeSort(CNodeList* pData, int i, int j, int* oData)
{
    LOGD("Range: %d -> %d, (%d <-> %d), (%d <->%d)\n", i, j, i, i+(j-i)/2, i+(j-i)/2 + 1, j);

    int tmp = 0;
    if(j-i == 0 || j-i == 1) {
        if(pData->getVal(i) > pData->getVal(j)) {
            pData->swapNode(i, j);
    
        }
        return;
    }

    doMergeSort(pData, i, i+(j-i)/2, oData);
    doMergeSort(pData, i+(j-i)/2 + 1, j, oData);
    int i1 = i, j1 = i+(j-i)/2;
    int i2 = i+(j-i)/2 + 1, j2 = j;
//    LOGE("Start Merge i: %d, j: %d, (%d->%d), (%d->%d)\n", i, j, i1, j1, i2, j2);
    
    int io = i;
    while (i1<=j1 && i2<=j2)
    {
        if(pData->getVal(i1) < pData->getVal(i2)) {
            oData[io] = pData[i1];
            ++i1;
        }
        else {
            oData[io] = pData[i2];
            ++i2;
        }
        ++io;
    }
    while(i1<=j1)
    {
        oData[io] = pData[i1];
        ++i1;
        ++io;
    }
    while(i2<=j2)
    {
        oData[io] = pData[i2];
        ++i2;
        ++io;
    }
}
#endif

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


    //Create 2 list
    for(int i=0; i<10; ++i)
    {
       pList->addNode(i); 
    }

    for(int i=10; i>0; --i)
    {
       pList->addNode(i); 
    }

    pList->showList();
    doQuickSort(pList, 0, pList->getNum()-1);
    pList->showList();
    delete pList;

}
