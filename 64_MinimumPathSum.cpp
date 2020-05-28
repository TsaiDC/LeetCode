//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
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

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//

/*
https://leetcode.com/problems/minimum-path-sum/
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes 
the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]

Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
        int width = grid[0].size();
        int hight = grid.size();
        
        for(int y=0; y<hight; ++y)
        {
            for(int x=0; x<width;++x)
            {
                //Left-Top Corner
                if((x==0) && (y==0)) {
                    continue;
                }
                //Top Row
                else if((y == 0) && (x>0)) {
                    grid[y][x] = grid[y][x] + grid[y][x-1];                
                }
                //Left Column
                else if((y>0) && (x==0)) {
                    grid[y][x] = grid[y][x] + grid[y-1][x];
                }
                else {            
                    grid[y][x]= (grid[y-1][x]) < (grid[y][x-1]) ? (grid[y][x]+grid[y-1][x]) : (grid[y][x]+grid[y][x-1]);
                }
            }
        }
        return grid[hight-1][width-1];
    }
#if 0
    int minPathSum(vector< vector<int> >& grid) {
        int width = grid[0].size();
        int hight = grid.size();
        vector<bool> row(width, false);
        vector< vector<bool> > map (hight, row);
        vector<int> vrow(width, false);
        vector< vector<int> > vmap (hight, vrow);
        queue< pair<int,int> >nodeQ;
        pair <int, int> node;        
        node = make_pair(0,0);
        nodeQ.push(node);
        
        while(!nodeQ.empty())
        {           
            node = nodeQ.front();
            nodeQ.pop();

            //map[y][x]
            int y = node.first;
            int x = node.second;
            if(y>=hight || x>=width || map[y][x]) {
                continue;
            }

            //Left-Top Corner
            if((x-1)<0 && (y-1)<0) {
                vmap[y][x] = grid[y][x];               
            }
            //Top Row
            else if((y == 0) && (x>0)) {
                vmap[y][x] = grid[y][x] + vmap[y][x-1];                
            }
            //Left Column
            else if((y>0) && (x==0)) {
                vmap[y][x] = grid[y][x] + vmap[y-1][x];
            }
            else {            
                vmap[y][x]= (vmap[y-1][x]) < (vmap[y][x-1]) ? (grid[y][x]+vmap[y-1][x]) : (grid[y][x]+vmap[y][x-1]);
            }
            map[y][x] = true;

            //Right Node
            node = make_pair(y,x+1);
            nodeQ.push(node);

            //Down Node
            node = make_pair(y+1,x);
            nodeQ.push(node);
        }
        return vmap[hight-1][width-1];
    }
#endif
};

void Test_minPathSum()
{
    LOGD("%s\n", __TIME__);
    int arr1[] = {1, 3, 1};
    int arr2[] = {1, 5, 1};
    int arr3[] = {4, 2, 1};
    
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> input1(arr1, arr1+n1);
    vector<int> input2(arr2, arr2+n2);
    vector<int> input3(arr3, arr3+n3);

    vector< vector<int> > map;
    map.push_back(input1);
    map.push_back(input2);
    map.push_back(input3);

    Solution *solution = new Solution();
    int n = solution->minPathSum(map);
    LOGD("n: %d\n", n);
    delete solution;
}