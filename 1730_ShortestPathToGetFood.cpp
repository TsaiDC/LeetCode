//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <algorithm>

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
// Unorder Map:
// https://shengyu7697.github.io/std-unordered_map/
// https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/
//

/*
https://www.cnblogs.com/cnoodle/p/15645191.html
1730. Shortest Path to Get Food

You are starving and you want to eat food as quickly as possible. You want to find the 
shortest path to arrive at any food cell.

You are given an m x n character matrix, grid, of these different types of cells:

'*' is your location. There is exactly one '*' cell.
'#' is a food cell. There may be multiple food cells.
'O' is free space, and you can travel through these cells.
'X' is an obstacle, and you cannot travel through these cells.
You can travel to any adjacent cell north, east, south, or west of your current location 
if there is not an obstacle.

Return the length of the shortest path for you to reach any food cell. 
If there is no path for you to reach food, return -1.


Example 1:

Input: grid = [["X","X","X","X","X","X"],
               ["X","*","O","O","O","X"],
               ["X","O","O","#","O","X"],
               ["X","X","X","X","X","X"]]
Output: 3
Explanation: It takes 3 steps to reach the food.

Example 2:

Input: grid = [["X","X","X","X","X"],
               ["X","*","X","O","X"],
               ["X","O","X","#","X"],
               ["X","X","X","X","X"]]
Output: -1
Explanation: It is not possible to reach the food.

Example 3:

Input: grid = [["X","X","X","X","X","X","X","X"],
               ["X","*","O","X","O","#","O","X"],
               ["X","O","O","X","O","O","X","X"],
               ["X","O","O","O","O","#","O","X"],
               ["X","X","X","X","X","X","X","X"]]
Output: 6
Explanation: There can be multiple food cells. It only takes 6 steps to reach the bottom food.

Example 4:

Input: grid = [["O","*"],
               ["#","O"]]
Output: 2

Example 5:

Input: grid = [["X","*"],
               ["#","X"]]
Output: -1

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
grid[row][col] is '*', 'X', 'O', or '#'.
The grid contains exactly one '*'.

*/


#ifdef _CVERSION_
//C
/*

*/

void Test_AM_TEST()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Ref
BFS
*/
class Solution {
#if 0
    int[][] DIRS = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };
    public int getFood(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                             if (grid[i][j] == '*') {
                    queue.offer(new int[] { i, j });
                                         break;
                }
             }
        }
        boolean[][] visited = new boolean[m][n];

        int step = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] cur = queue.poll();
                int x = cur[0];
                int y = cur[1];
                if (grid[x][y] == '#') {
                    return step;
                }
                for (int[] dir : DIRS) {
                    int r = x + dir[0];
                    int c = y + dir[1];
                    if (r >= 0 && r < m && c >= 0 
                        && c < n && grid[r][c] != 'X' && !visited[r][c]) {
                        visited[r][c] = true;
                        queue.offer(new int[] { r, c });
                    }
                }
            }
            step++;
        }
        return -1;
    }
#endif
};

void Test_AM_getFood()
{
//    vector< vector<string> > ans;
//    string arr1[] = {"eat","tea","tan","ate","nat","bat"};
//    int n1 = sizeof(arr1)/sizeof(arr1[0]);
//    vector<string> input1(arr1, arr1+n1);

    LOGD("[CPP] %s\n", __TIME__);
    Solution *solution = new Solution();
    delete solution;
}

#endif// _CPPVERSION_