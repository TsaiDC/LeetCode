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
#if DEBUG
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#define LOGE(...)
#endif

/*
https://leetcode.com/problems/search-a-2d-matrix-ii/
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

//(sx,  sy  )    (mx,  sy  )|(mx+1,sy  )    (ex,  sy  )
//                          |
//(sx,  my  )    (mx,  my  )|(mx+1,my  )    (ex,  my  )
//--------------------------+-------------------------
//(sx,  my+1)    (mx,  my+1)|(mx+1,my+1)    (ex,  my+1)
//                          |  
//(sx,  ey  )    (mx,  ey  )|(mx+1,ey  )    (ex,  ey  )
void search2D(vector< vector<int> >& matrix,int matrix_w, int matrix_h, int target, int sx, int sy, int ex, int ey, bool &isFound) {
    if(isFound) return;
    
    int mx = (ex+sx)/2;
    int my = (ey+sy)/2;
    if(sx>=matrix_w || sy>=matrix_h) return;    
    if(ex>=matrix_w || ey>=matrix_h) return;
    if(mx>=matrix_w || my>=matrix_h) return;       
    if(sx > ex || sy>ey) return;
    if(target < matrix[sy][sx] || target > matrix[ey][ex]) return;
    LOGD("Middle (%d, %d)(%d)->(%d, %d)(%d) : (%d, %d), Val: %d\n", sx, sy, matrix[sy][sx], ex, ey, matrix[ey][ex], mx, my, matrix[my][mx]);    

    if(matrix[my][mx] == target){ 
        LOGE("HIT Middle (%d, %d), Val: %d\n", mx, my, matrix[my][mx]);
        isFound = true;
        return;
    }
    if(sx == ex && sy==ey) return;
    
    
    //Left-Up    
//    LOGD("LU: (%d, %d)<->(%d, %d)\n", sx, sy, mx, my);
    search2D(matrix, matrix_w, matrix_h, target, sx,sy, mx, my, isFound);
    
    
    //Left-Down    
//    LOGD("LU: (%d, %d)<->(%d, %d)\n", sx,my+1, mx, ey);
    search2D(matrix, matrix_w, matrix_h, target, sx,my+1, mx, ey, isFound);
    
    //Right-Up
//    LOGD("LU: (%d, %d)<->(%d, %d)\n", mx+1,sy, ex, my);
    search2D(matrix, matrix_w, matrix_h, target, mx+1,sy, ex, my, isFound);
    
    //Right-Down
//    LOGD("LU: (%d, %d)<->(%d, %d)\n", mx+1,my+1, ex, ey);
    search2D(matrix, matrix_w, matrix_h, target, mx+1,my+1, ex, ey, isFound);    
}

#if 0
bool searchMatrix(vector< vector<int> >& matrix, int target) {
    bool isFound = false;
    int h = matrix.size();
    if(h==0) return isFound;
    int w = matrix[0].size();
    if(w==0) return isFound;
    
    search2D(matrix, w, h, target, 0,0, matrix[0].size()-1, matrix.size()-1, isFound);

    return isFound;    
}
#endif

#if 1
bool searchMatrix(vector< vector<int> >& matrix, int target) {
    
    if(matrix.size()<=0 || matrix[0].size() <= 0){return false;}
    int i = matrix.size()-1;
    int j = 0;
    while(i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size()){
        LOGD("(%d, %d)\n", j, i);
        if(matrix[i][j] == target){
            return true;
        }
        else if(matrix[i][j] > target){
            i--;
        }
        else if(matrix[i][j] < target){
            j++;
        }
    }
            
    return false;
}  
#endif

void Test_search2dMatrixii()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {1,   4,  7, 11, 15};
    int arr2[] = {2,   5,  8, 12, 19};
    int arr3[] = {3,   6,  9, 16, 22};
    int arr4[] = {10, 13, 14, 17, 24};
    int arr5[] = {18, 21, 23, 26, 30};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> input1(arr1, arr1+n);
    vector<int> input2(arr2, arr2+n);                               
    vector<int> input3(arr3, arr3+n);
    vector<int> input4(arr4, arr4+n);
    vector<int> input5(arr5, arr5+n);
    vector< vector<int> > input;

    input.push_back(input1);
    input.push_back(input2);
    input.push_back(input3);
    input.push_back(input4);
    input.push_back(input5);

    bool b = searchMatrix(input, 12);
    LOGD("Result: %d\n", b);
}