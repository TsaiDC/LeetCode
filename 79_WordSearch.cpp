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

class Solution1 {
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

/*
Time Limit Exceeded
*/
class Solution {
public:
/*
    string dump(vector< vector<char> >& board, int i, int j) {
//        LOGD("+++++++++++ (%d, %d)\n", i, j);
        string udlr;
        //up
        if(i-1>=0) {
//            LOGD("up: %c\n", board[i-1][j]);
            udlr += board[i-1][j];
        }
        else {
//            LOGD("up: @\n");
            udlr += "@";
        }            
        //down
        if(i+1<board.size()) {
//            LOGD("down: %c\n", board[i+1][j]);
            udlr += board[i+1][j];
        }
        else {
            udlr += "@";
        }

        //left
        if(j-1>=0) {
//            LOGD("left: %c\n", board[i][j-1]);
            udlr += board[i][j-1];
        }
        else {
//            LOGD("left: @\n");
            udlr += "@";
        }

        //right
        if(j+1<board[i].size()) {
//            LOGD("right: %c\n", board[i][j+1]);
            udlr += board[i][j+1];
        }
        else {
//            LOGD("right: @\n");
            udlr += "@";
        }
//        LOGD("-------\n");
        return udlr;
    }
*/
    void dfs(vector< vector<char> >& board, int i, int j, int idx, string word, bool &hit) {
        if(hit){ LOGD("\n"); return;}
        if(i<0 || j<0) { LOGD("\n"); return; }
        if(i>=board.size() || j>=board[i].size()){ LOGD("\n");  return;}
                
        if(idx == word.length()){
            LOGD("Hit\n");
            hit = true; 
            return;
        }
//        LOGD("dfs - (%d, %d), IDX: %d (%c), udlr: %s\n", i, j, idx, word.at(idx), dump(board, i,j).c_str());
        LOGD("dfs - (%d, %d), IDX: %d (%c)\n", i, j, idx, word.at(idx));
        vector< vector<char> >newBoard =  board;
        
        //up
        if(i-1 >=0 && board[i-1][j] == word.at(idx)) {
            LOGD("(%d, %d), idx: %d (%c), up\n", i, j, idx, word.at(idx));
            newBoard[i-1][j] = '#';
            dfs(newBoard, i-1, j, idx+1, word, hit);
            newBoard[i-1][j] = board[i-1][j];
        }
        //down
        if(i+1 < board.size() && board[i+1][j] == word.at(idx)) {
            LOGD("(%d, %d), idx: %d (%c), down\n", i, j, idx, word.at(idx));
            newBoard[i+1][j] = '#';
            dfs(newBoard, i+1, j, idx+1, word, hit);
            newBoard[i+1][j] = board[i+1][j];
        }
        //left
        if(j-1 >=0 && board[i][j-1] == word.at(idx)) {
            LOGD("(%d, %d)->(%d, %d), idx: %d (%c), left\n", i, j, i, j-1, idx, word.at(idx));            
            newBoard[i][j-1] = '#';
            dfs(newBoard, i, j-1, idx+1, word, hit);
            newBoard[i][j-1] = board[i][j-1];
        }
        //right
        if(j+1 < board[i].size() && board[i][j+1] == word.at(idx)) {
            LOGD("(%d, %d), idx: %d (%c), right\n", i, j, idx, word.at(idx));
            newBoard[i][j+1] = '#';
            dfs(newBoard, i, j+1, idx+1, word, hit);
            newBoard[i][j+1] = board[i][j+1];
        }
    }
    bool exist(vector< vector<char> >& board, string word) {
        LOGD("String: %s\n", word.c_str());
        bool ret = false;        
        for(int i=0; i<board.size(); ++i) {
            for(int j=0; j<board[i].size(); ++j) {
                if(board[i][j] == word.at(0)) {                    
                    board[i][j] = '#';
                    dfs(board, i, j, 1, word, ret);
                    board[i][j] = word.at(0);
                }
                if(ret) return ret;
            }
        }
        return false;
    }    
};


void Test_AM_exist()
{
    LOGD("[CPP] %s\n", __TIME__);

#if 0
    string word = "ABCCED"; //true
//    string word = "SEE"; //true
//    string word = "ABCB"; //false
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

    string word = "ABCESEEEFS"; //true
    int n;

    char arr1[] = {'A','B','C','E'};
    n = sizeof(arr1)/sizeof(arr1[0]);
    vector<char> num1(arr1, arr1+n);

    char arr2[] = {'S','F','E','S'};
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
//[["a","a"]]
//"aaa"

    string word = "aaa"; //true
    int n;

    char arr1[] = {'a','a'};
    n = sizeof(arr1)/sizeof(arr1[0]);
    vector<char> num1(arr1, arr1+n);

    vector< vector<char> >board;
    board.push_back(num1);
#endif

#if 1
//["A","A","A","A","A","A"],
//["A","A","A","A","A","A"],
//["A","A","A","A","A","A"],
//["A","A","A","A","A","A"],
//["A","A","A","A","A","A"],
//["A","A","A","A","A","A"]]
//"AAAAAAAAAAAAAAB"

    string word = "AAAAAAAAAAAAAAB"; //true
    int n;

    char arr1[] = {'A','A','A','A','A','A'};
    n = sizeof(arr1)/sizeof(arr1[0]);
    vector<char> num1(arr1, arr1+n);

    char arr2[] = {'A','A','A','A','A','A'};
    n = sizeof(arr2)/sizeof(arr2[0]);
    vector<char> num2(arr2, arr2+n);

    char arr3[] = {'A','A','A','A','A','A'};
    n = sizeof(arr3)/sizeof(arr3[0]);
    vector<char> num3(arr3, arr3+n);


    char arr4[] = {'A','A','A','A','A','A'};
    n = sizeof(arr4)/sizeof(arr4[0]);
    vector<char> num4(arr4, arr4+n);


    char arr5[] = {'A','A','A','A','A','A'};
    n = sizeof(arr5)/sizeof(arr5[0]);
    vector<char> num5(arr5, arr5+n);

    char arr6[] = {'A','A','A','A','A','A'};
    n = sizeof(arr6)/sizeof(arr6[0]);
    vector<char> num6(arr6, arr6+n);

    vector< vector<char> >board;
    board.push_back(num1);
    board.push_back(num2);
    board.push_back(num3);
    board.push_back(num4);
    board.push_back(num5);
    board.push_back(num6);
#endif

    Solution *solution = new Solution();    
    bool b = solution->exist(board, word);    
    delete solution;
    LOGD("Ans: %d\n", b);
}

#endif// _CPPVERSION_