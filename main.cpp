#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <time.h>
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
    double START,END;
    START = clock();
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

#if 0
//#5
    Test_longestPalindrome();
#endif

#if 0
//#6
    Test_convert();
#endif

#if 0
//#7
    Test_reverse();
#endif

#if 0
//#8
    Test_myAtoi();
#endif

#if 0
//#9
    Test_isPalindrome();
#endif

#if 0
//#10
    Test_isMatch();
#endif

#if 0
    Test_sorting();
#endif

#if 0
    Test_sortingList();
#endif

#if 1
    Test_maxArea();
#endif

#if 0
//#350
    Test_intersect();
#endif
    END = clock();
	cout << endl << "Used Time: " << (END - START) / CLOCKS_PER_SEC << " S" << endl;
    return 0;
}
