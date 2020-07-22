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
https://leetcode.com/problems/course-schedule-ii/
210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, 
for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

*/
#if 0 //My Solution
class Solution {
public:
    vector<int> findOrder(int numCourses, vector< vector<int> >& prerequisites) {
        return findOrder_My(numCourses, prerequisites);
    }

    vector<int> findOrder_My(int numCourses, vector< vector<int> >& prerequisites) {
        LOGD("N: %d, Size: %d\n", numCourses, prerequisites.size());
        vector<int> ans;
        int *checked = new int[numCourses];
        vector< vector<int> >map(numCourses);
        for(int i=0; i<numCourses; ++i)
            checked[i]=0;

        int x, y;
        for(int i=0; i<prerequisites.size(); ++i)
        {
            x = prerequisites[i][0];
            y = prerequisites[i][1];
            LOGD("[%d, %d]\n", x, y);                        
            map[x].push_back(y);
        }
#if 0
        printf("Map:\n");
        for(int i=0; i<map.size(); ++i)
        {
            printf("%d: ", i);
            for(int j=0; j<map[i].size(); ++j)
            {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
#endif
        for(int i=0; i<map.size(); ++i)
        {
            if(map[i].empty()) {
                ans.push_back(i);
                checked[i] = 1;
                LOGD("Push: %d\n", i);
            }
        }
        
        bool isContinue, isHit;
        int idx = 0;
        vector<int>row;
        do{
            isContinue = false;
            for(int i=0; i<map.size(); ++i)
            {                
                if(checked[i] == 1) continue;
                
                row = map[i];
                isHit = true;
                for(int j=0; j<row.size(); ++j)
                {
                    idx = row[j];
                    LOGD("i: %d, idx: %d \n", i, idx);
                    if(checked[idx]==0) {
                        isHit = false;
                        break;
                    }
                }
                LOGD("Check: %d, isHit: %d\n", i, isHit);
                if(isHit) {
                    ans.push_back(i);
                    checked[i] = 1;
                    isContinue = true;
                    LOGD("Push: %d\n", i);
                }
            }
        }while(isContinue);        
        delete [] checked;
        if(ans.size() != numCourses) ans.clear();
        return ans;
    }
};
#endif

//BFS
#if 1
class Solution {
public:
    vector<int> findOrder(int numCourses, vector< vector<int> >& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        vector<int> order;
        vector<int> row;
        int v;
        
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    order.push_back(j);
                    break;
                }
            }
            if (j == numCourses) {
                return {};
            }
            degrees[j]--;
            row = g[j];
            for(int x=0; x<row.size(); ++x)
            {
                v = row[x];
                degrees[v]--;
            }
        }        
        return order;
    }
private:
    typedef vector< vector<int> > graph;
    
    graph buildGraph(int numCourses, vector< vector<int> >& prerequisites) {
        graph g(numCourses);
        int first, second;
        for(int i=0; i<prerequisites.size(); ++i)
        {
            first = prerequisites[i][0];
            second = prerequisites[i][1];
            g[second].push_back(first);
        }        
#if 1
        printf("Graph: \n");
        for(int i=0; i<g.size(); ++i)
        {
            printf("%d: ", i);
            for(int j=0; j<g[i].size(); ++j)
            {
                printf("%d ", g[i][j]);
            }
            printf("\n");
        }
        printf("\n");
#endif
        return g;
    }
    
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        vector<int> adj;
        int v;

        for(int i=0; i<g.size(); ++i)
        {
            adj = g[i];
            for(int j=0; j<adj.size(); ++j) {
                v = adj[j];
                degrees[v]++;
            }
        }
#if 1
        printf("Degrees: \n");
        for(int i=0; i<degrees.size(); ++i)
        {
            printf("%d ", degrees[i]);
        }
        printf("\n");
#endif
        return degrees;
    }
};
#endif //BFS

#if 0 //DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector< pair<int, int> >& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> order;
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i, order)) {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
private:
    typedef vector< vector<int> > graph;
    
    graph buildGraph(int numCourses, vector< pair<int, int> >& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node, vector<int>& order) {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int neigh : g[node]) {
            if (!acyclic(g, todo, done, neigh, order)) {
                return false;
            }
        }
        order.push_back(node);
        todo[node] = false;
        return true;
    }
};
#endif //DFS

void Test_findOrder()
{
    // int arr1[] = {1,0};
    // int arr2[] = {2,0};
    // int arr3[] = {3,1};
    // int arr4[] = {3,2};
    // int k = 4;
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // vector<int> num1(arr1, arr1+n);
    // vector<int> num2(arr2, arr2+n);
    // vector<int> num3(arr3, arr3+n);
    // vector<int> num4(arr4, arr4+n);
    // vector< vector<int> >prerequisites;
    // prerequisites.push_back(num1);
    // prerequisites.push_back(num2);
    // prerequisites.push_back(num3);
    // prerequisites.push_back(num4);

    int arr1[] = {0,1};
    int arr2[] = {0,2};
    int arr3[] = {1,2};
    int k = 3;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    vector<int> num1(arr1, arr1+n);
    vector<int> num2(arr2, arr2+n);
    vector<int> num3(arr3, arr3+n);
    vector< vector<int> >prerequisites;
    prerequisites.push_back(num1);
    prerequisites.push_back(num2);
    prerequisites.push_back(num3);

    LOGD("%s\n", __TIME__);
    
#if 1
    LOGD("Map:\n");
    for(int i=0; i<prerequisites.size(); ++i)
    {
        printf("%d: ", i);
        for(int j=0; j<prerequisites[i].size(); ++j)
        {
            printf("%d ", prerequisites[i][j]);
        }
        printf("\n");
    }
    printf("\n");
#endif
    Solution *solution = new Solution();
    vector<int> ans = solution->findOrder(k, prerequisites);
    
    LOGD("Ans Size: %d\n", ans.size());
    for(int i=0; i<ans.size(); ++i)
    {
        LOGD("Ans: %d\n", ans[i]);
    }

    delete solution;
}