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

void Test_Amazon()
{
    LOGD("%s\n", __TIME__);    
    Solution *solution = new Solution();
    solution->test();
    delete solution;
}