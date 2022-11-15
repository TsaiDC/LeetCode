//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
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

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//


class Solution {
public:
    void test() {
        LOGD("Test Only\n");
        
        int b[10] = {0};
        int length = sizeof(b)/sizeof(b[0]);
        
        LOGD("Leng: %d\n", length);
        
        int cc = 0x82;
        int idx = 0;
        while(cc>0) {
            if(cc&0x1) {
                LOGD("IDX: %d\n", idx);
            }
            cc >>=1;
            ++idx;
        }
        
        
        int a = 0xAB;
        for(int i=0; i<8; i++)
        {
            LOGD("i:%d 0x%x\n", i, a<<i);
        }
        
        
/////////////////////////////////////////        
        LOGD("================================\n");

        int inputDataLength = 9;
//        int inputDataValues[] = {0x82, 0x1, 0x2, 0x3, 0x4, 0x0, 0x0, 0x0, 0xAB};
        int inputDataValues[] = {0x02, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00};
        
        int outputDataValues[33] = { 0 };
        
        uint8_t header = inputDataValues[0];
//        uint8_t header = 0x80;
        uint8_t numberOfValid = 0;
        int newIdx = 0;
        int newVal = 0;
        
        for(int i=0; header > 0; i++) {
            LOGD("Header: 0x%x\n", header);
            if(header&0x1) {
                LOGD("Hit: Header: 0x%x, idx: %d\n", header, i);

                numberOfValid++;
                newVal = 0;
                
                if(i>inputDataLength-1) {
                    printf("[E] STATUS_BAD_ARRAY_LENGTH Mask Idx: %d, ValidDataNum: %d\n", i, (int)inputDataLength-1);
                    return;
                }

                newIdx = i*4+1;
                newVal = inputDataValues[i+1] << i;
                LOGD("IDX: %d, Val: 0x%x, NewIdx: %d, NewVal: 0x%x\n", i, inputDataValues[i], newIdx, newVal);

                while(newVal) {
                    outputDataValues[newIdx] = newVal & 0xFF;
                    newVal >>=8;
                    LOGD("OutIdx: %d, Val: 0x%x, Left: 0x%x\n", newIdx, outputDataValues[newIdx], newVal);
                    newIdx++;
                }
            }
            header >>=1;
        }
        outputDataValues[0] = numberOfValid;
        LOGD("Valid: %d\n", outputDataValues[0]);
        
    }
};

//typedef struct __attribute__((__packed__)) Test {
typedef struct __attribute__((packed)) Test {
//    uint16_t count;
    uint32_t count;
    uint32_t ID;
}Test_t;

//1. 4 Alignment
//2. swap order for little-endian

void Test_Amazon()
{
    LOGD("%s\n", __TIME__);    
//    Solution *solution = new Solution();
//    solution->test();
//    delete solution;
    unsigned char* pVal = (unsigned char*) malloc(sizeof(unsigned char)*20);
    for(int i=0; i<20; ++i) {
        pVal[i] = 0x0;
    }
    LOGD("%d, %d\n", sizeof(uint16_t), sizeof(Test_t));
//    0x1, 0x0, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7
    pVal[0] = 0x1;
    
    pVal[2] = 0x2;
    pVal[3] = 0x3;
    pVal[4] = 0x4;
    pVal[5] = 0x5;
    pVal[6] = 0x6;
    pVal[7] = 0x7;
    
    for(int i=0; i<6; ++i) {
        LOGD("%d \n", pVal[i]);
    }
    Test_t *pT = (Test_t*)pVal;
    LOGD("Count: 0x%x, ID: 0x%x\n", pT->count, __builtin_bswap32(pT->ID));
    LOGD("Count: 0x%x, ID: 0x%x\n", pT->count, pT->ID);
    uint16_t *pCount = (uint16_t*) pVal;
    uint32_t *pID = (uint32_t*)(pVal+sizeof(uint16_t));
    LOGD("Count: 0x%x, ID: 0x%x\n", *pCount, *pID);
    free(pVal);
}