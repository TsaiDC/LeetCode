#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <fstream>
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

void testCopyFile()
{
    printf("[DBG] %s(%d) %s \n", __FUNCTION__, __LINE__, __TIME__);
    char *from = "E:\\test\\aaa.txt";
    char *to = "E:\\test\\bbb.txt";
    std::ifstream src(from, std::ios::binary);
    std::ofstream dst(to, std::ios::binary);
    dst<<src.rdbuf();
    printf("Done\n");
}

int main()
{
    double START,END;
    START = clock();

//    testCopyFile();
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
//#0
    Test_Amazon();
#endif

#if 0
//#1
    Test_AM_twoSum();
#endif

#if 0
//#4
    Test_AM_findMedianSortedArrays();
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
//#13
    Test_AM_romanToInt();
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
//#20
    Test_isValid();
#endif

#if 0
//#22
    Test_generateParenthesis();
#endif

#if 0
//#24
    Test_swapPairs();
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
//#35
    Test_searchInsert();
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
//#49
    Test_AM_groupAnagrams();
#endif

#if 0
//#56
    Test_merge();
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

#if 1
//#68
    Test_GG_fullJustify();
#endif

#if 0
//#69
    Test_mySqrt();
#endif

#if 0
//#72
    Test_minDistance();
#endif

#if 0
//#76
    Test_minWindow();
#endif

#if 0
//#77
    Test_combine();
#endif

#if 0
//#78
    Test_Subsets();
#endif

#if 0
//#79
    Test_AM_exist();
#endif

#if 0
//#86
    Test_partition();
#endif

#if 0
//#88
    Test_merge88();
#endif

#if 0
//#94
    Test_inorderTraversal();
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
//#100
    Test_isSameTree();
#endif

#if 0
//#102
    Test_levelOrdere();
#endif

#if 0
//#114
    Test_flatten();
#endif

#if 0
//#137
    Test_singleNumber();
#endif

#if 0
//#138
    Test_copyRandomList();
#endif

#if 0
//#142
    Test_detectCycle();
#endif

#if 0
//#146
    Test_AM_LRUCache();
#endif

#if 0
//#149
    Test_sortList();
#endif

#if 0
//#150
    Test_GG_evalRPN();
#endif

#if 0
//#158
    Test_GG_read();
#endif

#if 0
//#162
    Test_findPeakElement();
#endif

#if 0
//#167
    Test_twoSum();
#endif

#if 0
//#198
    Test_rob();
#endif

#if 0
//#200
    Test_NumIslands();
#endif

#if 0
//#207
    Test_canFinish();
#endif

#if 0
//#210
    Test_findOrder();
#endif

#if 0
//#215
    Test_findKthLargest();
#endif

#if 0
//#226
    Test_invertTree();
#endif

#if 0
//#230
    Test_KthSmallestElement();
#endif

#if 0
//#232
    Test_MyQueue();
#endif

#if 0
//#240
    Test_search2dMatrixii();
#endif

#if 0
//#249
    Test_FB_groupStrings();
#endif

#if 0
//#253
    Test_AM_minMeetingRooms();
#endif

#if 0
//#279
    Test_numSquares();
#endif

#if 0
//#282
    Test_GG_addOperators();
#endif

#if 0
//#287
    Test_findDuplicate();
#endif

#if 0
//#299
    Test_GG_getHint();
#endif

#if 0
//#300
    Test_lengthOfLIS();
#endif

#if 0
//#302
    Test_GG_minArea();
#endif

#if 0
//#314
    Test_FB_verticalOrder();
#endif

#if 0
//#321
    Test_maxNumber();
#endif

#if 0
//#329
    Test_GG_longestIncreasingPath();
#endif

#if 0
//#338
    Test_countBits();
#endif

#if 0
//#339
    Test_FB_depthSum();
#endif

#if 0
//#346
    Test_FB_MovingAverage();
#endif

#if 0
//#347
    Test_topKFrequent();
#endif

#if 0
//#350
    Test_IntersectionOfTwoArrays();
#endif

#if 0
//#359
    Test_GG_shouldPrintMessage();
#endif

#if 0
//#366
    Test_GG_findLeaves();
#endif

#if 0
//#370
    Test_AM_getModifiedArray();
#endif

#if 0
//#378
    Test_kthSmallest();
#endif

#if 0
//#380
    Test_InsertDeleteGetRandom();
#endif

#if 0
//#394
    Test_GG_decodeString();
#endif

#if 0
//#402
    Test_removeKdigits();
#endif

#if 0
//#418
    Test_GG_wordsTyping();
#endif

#if 0
//#426
    Test_FB_treeToDoublyList();
#endif

#if 0
//#435
    Test_eraseOverlapIntervals();
#endif

#if 0
//#447
    Test_GG_numberOfBoomerangs();
#endif

#if 0
//#451
    Test_SortCharactersByFrequency();
#endif

#if 0
//#454
    Test_fourSumCount();
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
//#528
    Test_GG_pickIndex();
#endif

#if 0
//#539
    Test_GG_findMinDifference();
#endif

#if 0
//#545
    Test_AM_boundaryOfBinaryTree();
#endif

#if 0
//#605
    Test_canPlaceFlowers();
#endif

#if 0
//#621
    Test_TaskScheduler();
#endif

#if 0
//#652
    Test_GG_findDuplicateSubtrees();
#endif

#if 0
//#695
    Test_maxAreaOfIsland();
#endif

#if 0
//#708
    Test_FB_insert();
#endif

#if 0
//#735
    Test_AM_asteroidCollision();
#endif

#if 0
//#767
    Test_AM_reorganizeString();
#endif

#if 0
//#777
    Test_GG_canTransform();
#endif

#if 0
//#792
    Test_GG_numMatchingSubseq();
#endif

#if 0
//#833
    Test_GG_findReplaceString();
#endif

#if 0
//#863
    Test_AM_distanceK();
#endif

#if 0
//#907
    Test_AM_sumSubarrayMins();
#endif

#if 0
//#926
    Test_AM_minFlipsMonoIncr();
#endif

#if 0
//#934
    Test_shortestBridge();
#endif

#if 0
//#939
    Test_GG_minAreaRect();
#endif

#if 0
//#973
    Test_AM_kClosest();
#endif

#if 0
//#994
    Test_AM_orangesRotting();
#endif

#if 0
//#1048
    Test_GG_longestStrChain();
#endif

#if 0
//#1091
    Test_shortestPathBinaryMatrix();
#endif

#if 0
//#1146
    Test_GG_SnapshotArray();
#endif

#if 0
//#1152
    Test_AM_mostVisitedPattern();
#endif

#if 0
//#1218
    Test_GG_longestSubsequence();
#endif

#if 0
//#1268
    Test_AM_suggestedProducts();
#endif

#if 0
//#1291
    Test_AM_sequentialDigits();
#endif

#if 0
//#1423
    Test_GG_maxScore();
#endif

#if 0
//#1492
    Test_AM_kthFactor();
#endif

#if 0
//#1554
    Test_GG_differByOne();
#endif

#if 0
//#1567
    Test_AM_getMaxLen();
#endif

#if 0
//#1570
    Test_FB_dotProduct();
#endif

#ifdef _1648_
    Test_AM_maxProfit();
#endif

#if 0
//#1650
    Test_FB_lowestCommonAncestor();
#endif

#if 0
//#1730
    Test_AM_getFood();
#endif

#if 0
//#1762
    Test_FB_findBuildings();
#endif

#if 0
//#1834
    Test_GG_getOrder();
#endif

#if 0
//#1891
    Test_FB_maxLength();
#endif

#if 0
//#1937
    Test_GG_maxPoints();
#endif

#if 0
//#2007
    Test_GG_findOriginalArray();
#endif

#if 0
//#2034
    Test_GG_StockPrice();
#endif

#if 0
//#2096
    Test_GG_getDirections();
#endif

#if 0
//#2104
    Test_AM_subArrayRanges();
#endif

#if 0
//#2115
    Test_GG_findAllRecipes();
#endif

#if 0
//#2128
    Test_GG_removeOnes();
#endif

#if 0
//#2135
    Test_GG_wordCount();
#endif

    END = clock();
	cout << endl << "Used Time: " << (END - START) / CLOCKS_PER_SEC << " S" << endl;
    return 0;
}
