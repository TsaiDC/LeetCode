//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
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

/*
https://leetcode.com/problems/linked-list-cycle-ii/
142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

To represent a cycle in the given linked list, 
we use an integer pos which represents the position (0-indexed) 
in the linked list where tail connects to. 
If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: 
There is a cycle in the linked list, 
where tail connects to the second node.

(3)->(2)->(0)->(-4)
      \_________|

Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: 
There is a cycle in the linked list, 
where tail connects to the first node.

(1)->(2)
  \___|

Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

(1)

*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return NULL;
    }
};

void Test_detectCycle()
{
    LOGD("%s\n", __TIME__);
    int ans;
//    int arr1[] = {1,3,4,2,2};
//    int arr1[] = {3,1,3,4,2};
//    int arr1[] = {1,2,2,3,4};
//    int arr1[] = {1,1,3,4};
    // int arr1[] = {2,5,9,6,9,3,8,9,7,1};
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // vector<int> numbs(arr1, arr1+n);
    Solution *solution = new Solution();
    // ans = solution->findDuplicate(numbs);
    // LOGD("Ans: %d\n",ans);
/*
    ans = solution->findDuplicate2(numbs);
    LOGD("Ans2: %d\n",ans);
    ans = solution->findDuplicate3(numbs);
    LOGD("Ans3: %d\n",ans);
*/
    // ans = solution->findDuplicate0(numbs);
    // LOGD("Ans0: %d\n",ans);    
    delete solution;
}