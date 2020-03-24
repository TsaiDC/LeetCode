//g++ *.cpp -o tool

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
140
https://tkucsiepr.pixnet.net/blog/post/6167009
*/

#if 0
https://www.youtube.com/watch?v=9qFR2WQGqkU
public String minWindow<string s, string t)
{
    if(s.size()<t.size()) {
        return "";
    }
    map<char, int>::iterator iter;
    map<char, int> wordDict = constructWord(t);
    int slow = 0, minLen = INT_MAX, matchCount = 0, index = 0;
    for(int fast = 0; fast < s.size(); ++fast)
    {
        char ch = s.at(fast);
        iter = wordDict.find(ch);
        if(iter == wordDict.end()) {
            continue;
        }
        if(iter->second == 1) {
            matchCount++;
        }        
        wordMap[c] -= 1;

        while(matchCount == wordDict.size())
        {
            //Find a valid substr
            if(fast - slow +1 < minLen) {
                minLen = fast-slow+1;
                index = slow;
            }
            
            char left = s.at(slow++);
            iter = wordDict.find(left);
            if(iter == wordDict.end()) {
                continue;
            }            
            
            if(iter->second == 0) {
                --matchCount;
            }
            wordDict[left] += 1;
        }
    }
    return minLen == INT_MAX ? "" : s.substring(index, index+minLen);
}

public map<char, int> constructWord(string t)
{
    map<char, int> wordMap;
    map<char, int>::iterator iter;
    
    for(int i=0; i<t.size(); ++i)
    {
        char c = t.at(i);
        int val = 
        iter = wordMap.find(c);
        if(iter != wordMap.end())
            wordMap[c] += 1;
        else
            wordMap[c] = 1;
    }  
}

#endif
//Merge Sort with linked list
#if 0
//The main function
public static Node merge_sort(Node head) 
{
    if(head == null || head.next == null) 
        return head;

    Node middle = getMiddle(head);      //get the middle of the list
    Node left_head = head;
    Node right_head = middle.next; 
    middle.next = null;             //split the list into two halfs

    return merge(merge_sort(left_head), merge_sort(right_head));  //recurse on that
}

//Merge subroutine to merge two sorted lists
public static Node merge(Node a, Node b)
{
    Node dummyHead = new Node();

    for(Node current  = dummyHead; a != null && b != null; current = current.next;)
    {
        if(a.data <= b.data) 
        {
            current.next = a; 
            a = a.next; 
        }
        else
        { 
            current.next = b;
            b = b.next; 
        }

    }
    current.next = (a == null) ? b : a;
    return dummyHead.next;
}

//Finding the middle element of the list for splitting
public static Node getMiddle(Node head)
{
    if(head == null) 
        return head;

    Node slow = head, fast = head;

    while(fast.next != null && fast.next.next != null)
    {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
}
#endif

static void showList(int* pData, int leng)
{
    printf("<-- ");
    for(int i=0; i<leng; ++i)
    {
        printf("%d ", pData[i]);
    }
    printf("-->\n");
}

void doInsertionSort(int* pData, int leng)
{
    LOGD("\n");
    int tmp = 0;
    int i, j;
    bool isSwap = false;
    for(i=1; i<leng; ++i)
    {    
        tmp = pData[i];
        LOGE("PTR: %d, data: %d\n", i, tmp);
        for(j=i; j>0 && tmp < pData[j-1]; --j)
        {                        
            LOGE("SHIFT   pData[%d]=%d <-> pData[%d]=%d\n", j, pData[j], j-1, pData[j-1]);
            pData[j] = pData[j-1];
        }        

        LOGE("SWAP    i: %d j: %d, pData: %d\n", i, j, pData[j]);
        pData[j] = tmp;               
    }
}

void doSelectionSort(int* pData, int leng)
{
    LOGD("\n");
    int ptr, tmp;
    for(int i=0; i<leng; ++i)
    {
        ptr=i;
        LOGE("-- i: %d PTR %d, D: %d\n",i, ptr, pData[ptr]);
        for(int j=i; j<leng; ++j)
        {
            if(pData[j] < pData[ptr]) {
                ptr = j;
            }
        }
        printf("ptr: %d, Min: %d\n", ptr, pData[ptr]);
        
        LOGE("Swap pData[%d] <-> pDat[%d]\n", i, ptr);
        tmp = pData[i];
        pData[i] = pData[ptr];
        pData[ptr] = tmp;

        for(int x=0;x<leng; ++x)
        {
            printf("%d ", pData[x]);
        }
        printf("\n");
    }    
    
}

void doBubbleSort(int* pData, int leng)
{
    LOGD("\n");
    int i, j, tmp;
    bool isSwap = true;
    for(i=0; i<leng-1 && isSwap == true; i++)
    {
        isSwap = false;
        for(j=0; j<leng-1; ++j)
        {
            if(pData[j+1]<pData[j]) {
//              LOGD("Swap pData[%d]=%d, pData[%d]=%d\n", j+1, pData[j+1], j, pData[j]);
                tmp = pData[j+1];
                pData[j+1] = pData[j];
                pData[j] = tmp;
                isSwap = true;
            }
        }
    }
}

void doQuickSort(int* pData, int i, int j)
{
//    LOGD("Range: %d -> %d\n", i, j);
#if 0
    LOGD("+++Input\n");
    printf("->");
    for(int xx=i; xx<=j; ++xx)
    {
        printf("%d ", pData[xx]);
    }
    printf("\n");
    LOGD("---Input\n");
#endif

    int p = j;
    int x = i, y = j-1;
    int tmp = 0;
    
    if(x>y) {
//        LOGE("Stop\n");
        return;
    }
    
    while(x<y)
    {
        while (x<=y && (pData[x] < pData[p])){++x;}
        while (y>=x && (pData[y] > pData[p])){--y;}    
        
//        LOGD("P(%d):%d, x(%d):%d, y(%d):%d\n", p, pData[p], x, pData[x], y, pData[y]);
        
        if(x<y) {
            tmp = pData[x];
            pData[x] = pData[y];
            pData[y] = tmp;
        }
#if 0   
        printf("--");
        for(int xx = i; xx<j; ++xx)
        {
            printf("%d ",pData[xx]);
        }
        printf("\n");
#endif
    }

//    LOGE("Final Swap P(%d):%d, x(%d):%d, y(%d):%d\n", p, pData[p], x, pData[x], y, pData[y]);
    if (pData[x] > pData[p]) {
        tmp = pData[x];
        pData[x] = pData[p];
        pData[p] = tmp;
    }
#if 0
    printf("<-");
    for(int xx = i; xx<=j; ++xx)
    {
        printf("%d ",pData[xx]);
    }
    printf("\n");
#endif
//    LOGD("p: %d,  0~%d <=> %d~%d \n", x, x-1, x+1, j);
    doQuickSort(pData, 0, x-1);
    doQuickSort(pData, x+1, j);
}

void doQuickSort2(int* pData, int i, int j) {
    if(i>=j) return;
    LOGD("Sort: %d->%d\n", i, j);    
    int l = i, r=j-1;
    int temp;
    while(1)
    {   
        //Find L,R index    
        while(pData[r] > pData[j])r--;
        while(pData[l] < pData[j])l++;
        if(r>l) {            
            temp = pData[r];
            pData[r] = pData[l];
            pData[l] = temp;
        }
        else {
            temp = pData[j];
            pData[j] = pData[l];
            pData[l] = temp;
            break;
        }        
    }
    doQuickSort2(pData, i, l-1);
    doQuickSort2(pData, l+1, j);
}

void doMergeSort(int* pData, int i, int j, int* oData)
{
    LOGD("Range: %d -> %d, (%d <-> %d), (%d <->%d)\n", i, j, i, i+(j-i)/2, i+(j-i)/2 + 1, j);

    int tmp = 0;
    if(j-i == 0 || j-i == 1) {
//        LOGD("Single Item i: %d, j: %d\n", i, j);
        if(pData[i] > pData[j]) {
            tmp = pData[i];
            pData[i] = pData[j];
            pData[j] = tmp;            
        }
//        showList(pData, 10);
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
        if(pData[i1]<pData[i2]) {
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
    //Copy back
    while(i<=j)
    {
        pData[i] = oData[i];
        ++i;
    }
//    showList(oData, 10);
//    showList(pData, 10);
}

void doMergeSort2(int* pData, int l, int r, int* oData)
{    
    if(l>=r) return;
    int middle = (l+r)/2;
    doMergeSort2(pData, l, middle, oData);
    doMergeSort2(pData, middle+1, r, oData);

    int i=0;
    int j=0;    

    i=l;
    j=middle+1;
    int idx = i;
    LOGE("Merge: %d <-> %d & %d <->%d \n", i, middle, j, r);
    showList(pData, 10);
    showList(oData, 10);
    while(i<=middle && j<=r) {
        if(pData[i]>pData[j]){
            oData[idx++]=pData[j];
            j++;
        }
        else {
            oData[idx++]=pData[i];
            i++;
        }
    }    
    while(i<=middle) {
        oData[idx++]=pData[i];
        i++;
    }
    while(j<=r) {
        oData[idx++]=pData[j];
        j++;
    }
    for(i=0; i<=r; i++) {
        pData[i] = oData[i];
    }    
    showList(oData, 10);
}

void doHanoi (int n, char src, char tmp, char dest)
{
    if(n<=0) {
        return;
    }
    doHanoi(n-1, src, dest, tmp);
    LOGD("%c -> %c\n", src, dest);
    doHanoi(n-1, tmp, src, dest);
}

void Test_sorting()
{
    LOGI("%s\n", __TIME__);

#if 1
    int iData [] = {72,63,42,27,79,3,32,71,88,73};
//    int iData [] = {75,98,97,12,82,78,91,21,72,70};
    int oData [10] = { 0 };
    int Num = sizeof(iData)/sizeof(iData[0]);   
    LOGI("Input Data Num: %d\n", Num);
    showList(iData, Num);

//    doInsertionSort(iData, Num);
//    doSelectionSort(iData, Num);
//    doBubbleSort(iData, Num);
//    doQuickSort(iData, 0, Num-1);
//    doQuickSort2(iData, 0, Num-1);
//    doMergeSort(iData, 0, Num-1, oData);
    doMergeSort2(iData, 0, Num-1, oData);
//    doHanoi(4, 'A', 'B', 'C');
    
    LOGI("+++Result\n");
    showList(iData, Num);
//    showList(oData, Num);
    LOGI("---Result\n");
    LOGI("Done \n");
#endif
}