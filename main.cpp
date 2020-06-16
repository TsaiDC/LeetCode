#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <time.h>
#include "apiheader.h"

using namespace std;

// <https://drive.google.com/open?dac=1&id=1UG4lMpbPY5wggiV7alUx88tlwRPnwxbMs4vrinqAgT0>

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

void revertStr(char *str)
{
    char c = *str;
    if(c=='\0'){        
        return;
    }
    revertStr(++str);
    printf("%c", c);
}

void localTest()
{
    const char *str = "abcdefg";
    printf("[DBG] %s(%d) %s : str: %s\n", __FUNCTION__, __LINE__, __TIME__, str);    
    revertStr((char*)str);
}

int main()
{
    double START,END;
    START = clock();

#if 0
    localTest();
#endif

#if 0
    int m=5, n=3;
    vector<int> list;
    c_recur(0, n, m, list, true);
#endif

//A00
#if 0
    Test_sorting();
#endif

#if 0
    Test_sortingList();
#endif

#if 0
    Test_maxArea();
#endif

//A01
#if 0
    Test_tree();
#endif

#if 0
    Test_avltree();
#endif

#if 0
    Test_splaytree();
#endif

//A02
#if 0
//    Test_Recursive();
    Test_RecursiveCombi();
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
//#12
    Test_intToRoman();
#endif

#if 0
//#15
    Test_threeSum();
#endif

#if 0
//#16
    Test_threeSumClosest();
#endif

#if 0
//#17
    Test_letterCombinations();
#endif

#if 0
//#18
    Test_fourSum();
#endif

#if 0
//#19
    Test_removeNthFromEnd();
#endif

#if 0
//#31
    Test_nextPermutation();
#endif

#if 0
//#33
    Test_SearchInRotatedSortedArray();
#endif

#if 0
//#34
    Test_searchRange();
#endif

#if 0
//#38
    Test_countAndSay();
#endif

#if 0
//#46
    Test_permute();
#endif

#if 0
//#47
    Test_permuteUnique();
#endif

#if 0
//#61
    Test_rotateRight();
#endif

#if 0
//#62
    Test_uniquePaths();
#endif

#if 0
//#64
    Test_minPathSum();
#endif

#if 0
//#72
    Test_minDistance();
#endif

#if 0
//#78
    Test_Subsets();
#endif

#if 0
//#86
    Test_partition();
#endif

#if 0
//#96
    Test_numTrees();
#endif

#if 0
//#98
    Test_isValidBST();
#endif

#if 0
//#114
    Test_flatten();
#endif

#if 0
//#138
    Test_copyRandomList();
#endif

#if 1
//#198
    Test_rob();
#endif

#if 0
//#200
    Test_NumIslands();
#endif

#if 0
//#230
    Test_KthSmallestElement();
#endif

#if 0
//#240
    Test_search2dMatrixii();
#endif

#if 0
//#300
    Test_lengthOfLIS();
#endif

#if 0
//#321
    Test_maxNumber();
#endif

#if 0
//#338
    Test_countBits();
#endif

#if 0
//#350
    Test_IntersectionOfTwoArrays();
#endif

#if 0
//#380
    Test_InsertDeleteGetRandom();
#endif

#if 0
//#402
    Test_removeKdigits();
#endif

#if 0
//#451
    Test_SortCharactersByFrequency();
#endif

#if 0
//#474
    Test_OnesAndZeros();
#endif

#if 0
//#477
    Test_totalHammingDistance();
#endif

#if 0
//#503
    Test_NextGreaterElmentII();
#endif

#if 0
//#621
    Test_TaskScheduler();
#endif

#if 0
//#1091
    Test_shortestPathBinaryMatrix();
#endif

    END = clock();
	cout << endl << "Used Time: " << (END - START) / CLOCKS_PER_SEC << " S" << endl;
    return 0;
}
