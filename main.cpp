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
#endif

#if 0
    Test_addTwoSum();
#endif

#if 0
    Test_addTwoNumbers();    
#endif

#if 0
//#3
    Test_lengthOfLongestSubstring();
#endif

#if 0
//#4
    Test_findMedianSortedArrays();
#endif

#if 1
//#5
    Test_longestPalindrome();
#endif

#if 0
//#350
    Test_intersect();
#endif
    return 0;
}
