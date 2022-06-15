//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
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
//No Good
typedef struct xpair_t{
    int i;
    int j;
    int ptr;
    xpair_t(int a, int b, int c):i(a),j(b), ptr(c){}
}xpair;

class Solution {
public:
    bool exist(vector< vector<char> >& board, string word) {
        queue<xpair>TraceQueue;
        
        int RecordMap[3][4] = {0};
        int ptr = 0;
        
        for(int i=0; i<board.size(); ++i) {
            for(int j=0;j<board[i].size(); ++j) {
                if(board[i][j] == word.at(0)) {
//                    LOGD("%d, %d\n", i, j);
                    xpair node(i,j, ptr);
                    TraceQueue.push(node);
                    
                    while(!TraceQueue.empty()) {
                        node = TraceQueue.front();
                        TraceQueue.pop();
                        ptr = node.ptr;
                        if(ptr == word.length()-1) {
                            return true;
                        }
                        RecordMap[node.i][node.j] = 1;
                        
                        
                        
                        
                        for(int ii=node.i-1; ii<node.i+2; ++ii) {
                            for(int jj = node.j-1; jj<node.j+2; ++jj) {
                                if(ii<0 || ii>board.size()-1) continue;
                                if(jj<0 || jj>board[0].size()-1) continue;
                                if(ii == node.i-1 && jj == node.j-1) continue; //left-up
                                if(ii == node.i-1 && jj == node.j+1) continue; //left-down
                                if(ii == node.i+1 && jj == node.j-1) continue; //right-up
                                if(ii == node.i+1 && jj == node.j+1) continue; //right-down
                                
                                if(board[ii][jj] == word.at(ptr+1) && 
                                   RecordMap[ii][jj] != 1) {
                                   xpair node1(ii, jj, ptr+1);
                                   TraceQueue.push(node1);
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};


void Test_AM_exist()
{
    LOGD("[CPP] %s\n", __TIME__);

#if 1
//    string word = "ABCCED";
//    string word = "SEE";
    string word = "ABCB";
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
#endif    

#if 0
//[["a","b"],["c","d"]]
//"abcd"    

    string word = "abcd";
    int n;

    char arr1[] = {'a','b'};
    n = sizeof(arr1)/sizeof(arr1[0]);
    vector<char> num1(arr1, arr1+n);

    char arr2[] = {'c','d'};
    n = sizeof(arr2)/sizeof(arr2[0]);
    vector<char> num2(arr2, arr2+n);

    vector< vector<char> >board;
    board.push_back(num1);
    board.push_back(num2);
#endif

#if 0
//["A","B","C","E"],
//["S","F","E","S"],
//["A","D","E","E"]
//"ABCESEEEFS"

#endif    
    Solution *solution = new Solution();    
    bool b = solution->exist(board, word);    
    delete solution;
    LOGD("Ans: %d\n", b);
}

#endif// _CPPVERSION_