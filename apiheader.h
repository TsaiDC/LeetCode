#ifndef __API_HEADER__
#define __API_HEADER__

using namespace std;

#define LOGD(...) {printf("[D] %s(%d): ", __FUNCTION__, __LINE__);printf( __VA_ARGS__);}

void Test_addTwoSum();
void Test_addTwoNumbers();
void Test_lengthOfLongestSubstring();
void Test_findMedianSortedArrays();
void Test_longestPalindrome();
void Test_intersect();
#endif