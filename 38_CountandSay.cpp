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

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//

/*
https://leetcode.com/problems/count-and-say/
38. Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ? n ? 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".

 1.     1    one 1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
10.     13211311123113112211
*/

class Solution {
public:
    string countAndSay(int n) {
                
        vector<int> Lstr;
        vector<int> Rstr;
        vector<int> count_vec;
        Lstr.push_back(1);
        
        int count = 0;
        int num = 0;

        for(int i=1; i<n; i++)
        {
#if 0
            LOGD("%d L Array: ", i+1);
            for(int x=0;x<Lstr.size(); ++x)
                printf("%d ", Lstr[x]);
            printf(" -- ");
#endif
            //Convert to readable Array
            count_vec.clear();
            for(int j=0;j<Lstr.size(); ++j)
            {
                if(count_vec.empty()) {
                    count_vec.push_back(Lstr[j]);
                    continue;
                }
                else {
                    if(Lstr[j]==count_vec.back()) {
                        count_vec.push_back(Lstr[j]);
                    }
                    else {
                        Rstr.push_back(count_vec.size());
                        Rstr.push_back(count_vec.back());
                        count_vec.clear();
                        count_vec.push_back(Lstr[j]);
                    }
                }
            }
            Rstr.push_back(count_vec.size());
            Rstr.push_back(count_vec.back());
#if 0
            for(int x=0;x<Rstr.size(); ++x)
                printf("%d ", Rstr[x]);
            printf("\n");
#endif
            //Convert to real array
            Lstr.clear();
            Lstr.assign(Rstr.begin(), Rstr.end());
            Rstr.clear();
        }
        
        return getString(Lstr);
    }
    
    string getString(vector<int> &Lstr)
    {
        string str="";
        for(int i=0; i<Lstr.size(); i++)
        {
            switch(Lstr[i])
            {
            case 0:
                str.push_back('0');
                break;
            case 1:
                str.push_back('1');
                break;
            case 2:
                str.push_back('2');
                break;
            case 3:
                str.push_back('3');
                break;
            case 4:
                str.push_back('4');
                break;
            case 5:
                str.push_back('5');
                break;
            case 6:
                str.push_back('6');
                break;
            case 7:
                str.push_back('7');
                break;
            case 8:
                str.push_back('8');
                break;
            case 9:
                str.push_back('9');
                break;
            }            
        }
        return str;
    }
};

void Test_countAndSay()
{
    LOGD("%s\n", __TIME__);
    string str;
    int n = 5;
    Solution *solution = new Solution();
    str = solution->countAndSay(n);
    LOGD("N: %d, Ans: %s\n", n, str.c_str());
    delete solution;
}