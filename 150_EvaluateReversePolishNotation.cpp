//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define _CVERSION_

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
https://leetcode.com/problems/evaluate-reverse-polish-notation/
150. Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Note that division between two integers should truncate toward zero.
It is guaranteed that the given RPN expression is always valid. 
That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/
#ifdef _CVERSION_
//C
/*
Runtime: 4 ms, faster than 97.83% of C online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 7.7 MB, less than 16.30% of C online submissions for Evaluate Reverse Polish Notation.
*/
int evalRPN(char ** tokens, int tokensSize){
    int *ans = (int*)malloc(sizeof(int)*tokensSize);
    int idx = 0;
    int val;
    for(int i=0; i<tokensSize; ++i)
    {
        if(strcmp(tokens[i],"+") == 0) {
            --idx;
            LOGD("%d / %d\n", ans[idx-1], ans[idx]);
            val = ans[idx-1] + ans[idx];            
            ans[idx-1] = val;
        }
        else if(strcmp(tokens[i],"-") == 0) {
            --idx;
            val = ans[idx-1] - ans[idx];
            ans[idx-1] = val;
        }
        else if(strcmp(tokens[i],"*") == 0) {
            --idx;
            val = ans[idx-1] * ans[idx];            
            ans[idx-1] = val;
        }
        else if(strcmp(tokens[i],"/") == 0) {
            --idx;
            LOGD("%d / %d\n", ans[idx-1], ans[idx]);
            val = ans[idx-1] / ans[idx];            
            ans[idx-1] = val;
        }
        else {            
            ans[idx] = atoi(tokens[i]);
            ++idx;            
        }
    }
    val = ans[idx-1];
    free(ans);
    return val;
}
void Test_GG_evalRPN()
{
    LOGD("[C] %s\n", __TIME__);
//    char* str[] = {"4","13","5","/","+"};
    char* str[] = {"2","1","+","3","*"};
    
    int tokenSize = sizeof(str)/sizeof(str[0]);
    LOGD("Size: %d\n", tokenSize);
    int ans = evalRPN(str, tokenSize);
    LOGD("Ans: %d\n", ans);
}
#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Runtime: 11 ms, faster than 76.48% of C++ online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 12 MB, less than 60.71% of C++ online submissions for Evaluate Reverse Polish Notation.
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>ans;
        int val;
        for(int i=0; i<tokens.size(); ++i)
        {
            if(tokens[i] == "+") {
                if(ans.size() < 2) return -1;
                val = ans.top();
                ans.pop();
                val = ans.top() + val;                
                ans.pop();                
                ans.push(val);
            }

            else if(tokens[i] == "-") {
                if(ans.size() < 2) return -1;
                val = ans.top();
                ans.pop();
                val = ans.top() - val;
                ans.pop();                
                ans.push(val);
            }
            else if(tokens[i] == "*") {
                if(ans.size() < 2) return -1;
                val = ans.top();
                ans.pop();
                val = ans.top() * val;
                ans.pop();                
                ans.push(val);
            }
            else if(tokens[i] == "/") {
                if(ans.size() < 2) return -1;
                val = ans.top();
                ans.pop();
                val = ans.top() / val;
                ans.pop();
                ans.push(val);
            }
            else {
                ans.push(atoi(tokens[i].c_str()));
            }
        }
        return ans.top();
    }
};

void Test_GG_evalRPN()
{
    LOGD("[CPP] %s\n", __TIME__);

//    string str[] = {"2","1","+","3","*"};
    string str[] = {"4","13","5","/","+"};
    int n = sizeof(str)/sizeof(str[0]);
    vector<string> input1(str, str+n);
    Solution *solution = new Solution();
    int ans = solution->evalRPN(input1);
    LOGD("Ans: %d\n", ans);
    delete solution;
}

#endif //_CPPVERSION_