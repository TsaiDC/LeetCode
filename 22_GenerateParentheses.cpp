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
https://leetcode.com/problems/generate-parentheses/
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0) return ans;
        ans.push_back("()");
        if(n==1) return ans;

        string str;
        while(!ans.empty())
        {
            str = ans.back();
            ans.pop_back();
            LOGD("Str (%d): %s(%d)\n", ans.size(), str.c_str(), str.length());
            string tmp;
            tmp+="_";
            for(int i=0; i<str.length(); ++i)
            {
                tmp+=str.at(i);
                tmp+="_";                
            }
            LOGD("Tmp: %s(%d)\n", tmp.c_str(), tmp.length());
            size_t ptr = tmp.find_first_of("_");
            if(ptr != string::npos) {                
                tmp.replace(ptr, 1, "_(_");
                LOGD("Tmp: %s(%d), ptr: %d\n", tmp.c_str(), tmp.length(), ptr);
            }
        }
                
        return ans;
    }
    
    bool isGood(string str)
    {
        vector<char> stack;
        for(int i=0; i<str.length(); ++i)
        {
            if(str.at(i) == '(') {
                stack.push_back('(');
            }
            else {
                if(stack.empty()) {
                    return false;
                }
                else {
                    stack.pop_back();
                }
            }
        }
        return stack.empty();
    }
};
void Test_generateParenthesis()
{
    LOGD("%s\n", __TIME__);
    Solution *solution = new Solution();
#if 0
    string str;
    str = "(())";
    LOGD("Test %s: %d\n", str.c_str(), solution->isGood(str));
    str = "()()";
    LOGD("Test %s: %d\n", str.c_str(), solution->isGood(str));
    str = "())";
    LOGD("Test %s: %d\n", str.c_str(), solution->isGood(str));
#endif

    vector<string> ans = solution->generateParenthesis(3);    
    for(int i=0; i<ans.size(); ++i)
    {
        LOGD("%s\n", ans[i].c_str());
    }
    
    delete solution;
}