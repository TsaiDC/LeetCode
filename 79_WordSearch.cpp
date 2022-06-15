//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#define _CPPVERSION_

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

/*
https://leetcode.com/problems/word-search/
79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:

["A","B","C","E"]
["S","F","C","S"]
["A","D","E","E"]


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

["A","B","C","E"],
["S","F","C","S"],
["A","D","E","E"]

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true


Example 3:

["A","B","C","E"],
["S","F","C","S"],
["A","D","E","E"]

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

*/


#ifdef _CVERSION_
//C
/*

*/

bool exist(char** board, int boardSize, int* boardColSize, char * word){

}

void Test_AM_exist()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/

class Solution {
public:
    bool exist(vector< vector<char> >& board, string word) {
        return false;
    }
};


void Test_AM_exist()
{
    LOGD("[CPP] %s\n", __TIME__);

    string word = "ABCCED";
    int n;

    char arr1[] = {'A','B','C','E'};
    n = sizeof(arr1)/sizeof(arr1[0]);
    vector<char> num1(arr1, arr1+n);

    char arr2[] = {'S','F','C','S'};
    n = sizeof(arr2)/sizeof(arr2[0]);
    vector<char> num2(arr2, arr2+n);

    char arr3[] = {'A','D','E','E'};
    n = sizeof(arr3)/sizeof(arr3[0]);
    vector<char> num3(arr3, arr3+n);

    vector< vector<char> >board;
    board.push_back(num1);
    board.push_back(num2);
    board.push_back(num3);
    
    Solution *solution = new Solution();    
    bool b = solution->exist(board, word);    
    delete solution;
    LOGD("Ans: %d\n", b);
}

#endif// _CPPVERSION_