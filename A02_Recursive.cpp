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
hannoi:
least steps: (2^n) -1
*/

void hannoi(string target, string temp, string dest, int n)
{
    if(n==0) return;
    hannoi(target, dest, temp, n-1);
    LOGD("%s -> %s\n", target.c_str(), dest.c_str());
    hannoi(temp, target, dest, n-1);
}

#if 0
void hannoi(string target, string temp, string dest, int n)
{
    if(n==1) {
        LOGD("%s -> %s\n", target.c_str(), dest.c_str());
        return;
    }
    if(n==2) {
        LOGD("%s -> %s\n", target.c_str(), temp.c_str());
        LOGD("%s -> %s\n", target.c_str(), dest.c_str());
        LOGD("%s -> %s\n", temp.c_str(), dest.c_str());
        return;
    }
    
    hannoi (target, dest, temp, n-1);
    hannoi (target, temp, dest, n-2);
    hannoi (temp, target, dest, n-1);
}
#endif
void Test_Recursive()
{
    LOGI("%s\n", __TIME__);
    hannoi ("A", "B", "C", 4);
}