#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "apiheader.h"

using namespace std;

void c_recur(int k, int n, int m, vector<int> list, bool isInit)
{
    if(k-1 >=0) {
        printf("[DBG] %s(%d) %s : idx: %d\n", __FUNCTION__, __LINE__, __TIME__, k-1);
        list.push_back(k-1);
    }
    
    for (int i=k; i<=(m-n) && n>0; ++i)
    {
        printf("[DBG] %s(%d) %s : i: %d\n", __FUNCTION__, __LINE__, __TIME__, i);
        c_recur(i+1, n-1, m, list, false);
    }
    
    if (n==0 && !isInit) {
        for(int i=0; i<list.size(); ++i)
        {
            cout<<list[i]<<'\t';
        }
        cout<<endl;
    }
}
int main()
{
#if 0
    int m=5, n=3;
    vector<int> list;
    c_recur(0, n, m, list, true);
#else
    vector<int> input{2, 7, 11,15};
    vector<int> output;
    output = twoSum (input, 22);
    printf("[DBG] %s(%d) %s : size: %d\n", __FUNCTION__, __LINE__, __TIME__, output.size());
    for (int i=0; i<output.size(); ++i)
    {
        printf("[DBG] %s(%d) %s : idx: %d\n", __FUNCTION__, __LINE__, __TIME__, output[i]);
    }
#endif
    return 0;
}