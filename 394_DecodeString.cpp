//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <math.h>
#include <time.h>
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

/*
https://leetcode.com/problems/decode-string/
394. Decode String

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being 
repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, 
square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are 
only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

*/

#ifdef _CVERSION_
//C
/*

*/

char * decodeString(char * s){

}

void Test_GG_decodeString()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/

#if 1
/*
Approach 1

Approach 1: Using Stack

Intuition

We have to decode the result in a particular pattern. We know that the input is always valid. 
The pattern begins with a number k, followed by opening braces [, followed by string. Post that, 
there could be one of the following cases :

There is another nested pattern k[string k[string]]
There is a closing bracket k[string]
Since we have to start decoding the innermost pattern first, continue iterating over the string s, 
pushing each character to the stack until it is not a closing bracket ]. Once we encounter the 
closing bracket ], we must start decoding the pattern.

As we know that stack follows the Last In First Out (LIFO) Principle, the top of the stack would 
have the data we must decode.


Algorithm

The input can contain an alphabet (a-z), digit (0-9), opening braces [ or closing braces ]. 
Start traversing string s and process each character based on the following rules:

Case 1) Current character is not a closing bracket ].
Push the current character to stack.

Case 2) Current character is a closing bracket ].
Start decoding the last traversed string by popping the string decodedString and number k from the 
top of the stack.

Pop from the stack while the next character is not an opening bracket [ and append each character 
(a-z) to the decodedString.
Pop opening bracket [ from the stack.
Pop from the stack while the next character is a digit (0-9) and build the number k.
Now that we have k and decodedString , decode the pattern k[decodedString] by pushing 
the decodedString to stack k times.

Once the entire string is traversed, pop the result from stack and return.


Complexity Analysis

Time Complexity: O(maxK^countK * n), where maxK is the maximum value of k, countK is the count of 
nested k values and n is the maximum length of encoded string. Example, for s = 20[a10[bc]], 
maxK is 20, countK is 2 as there are 2 nested k values (20 and 10) . Also, there are 2 encoded 
strings a and bc with maximum length of encoded string ,n as 2

The worst case scenario would be when there are multiple nested patterns. Let's assume that all the 
k values (maxK) are 10 and all encoded string(n) are of size 2.

For, s = 10[ab10[cd]]10[ef], time complexity would be roughly equivalent to 10* cd * 10* ab +10*2 
= 10^2*2

Hence, for an encoded pattern of form maxK[nmaxK[n]], the time complexity to decode the pattern can 
be given as, O(maxK^countK * n).

Space Complexity: O(sum(maxK^countK * n)), where maxK is the maximum value of k, countK is the count
of nested k values and n is the maximum length of encoded string.
The maximum stack size would be equivalent to the sum of all the decoded strings in the form 
maxK[nmaxK[n]]

*/

class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                string decodedString = "";
                // get the encoded string
                while (stack.top() != '[') {
                    decodedString += stack.top();
                    stack.pop();
                }
                // pop [ from stack
                stack.pop();
                int base = 1;
                int k = 0;
                // get the number k
                while (!stack.empty() && isdigit(stack.top())) {
                    k = k + (stack.top() - '0') * base;
                    stack.pop();
                    base *= 10;
                }
                int currentLen = decodedString.size();
                // decode k[decodedString], by pushing decodedString k times into stack
                while (k != 0) {
                    for (int j = decodedString.size() - 1; j >= 0; j--) {
                        stack.push(decodedString[j]);
                    }
                    k--;
                }
            }
            // push the current character to stack
            else {
                stack.push(s[i]);
            }
        }
        // get the result from stack
        string result;
        for (int i = stack.size() - 1; i >= 0; i--) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};

#endif

#if 0
/*
Approach 2: Using 2 Stack

Intuition

In the previous approach, we used a single character stack to store the digits(0-9) as well as 
letters (a-z). We could instead maintain 2 separate stacks.

countStack: The stack would store all the integer k.
stringStack: The stack would store all the decoded strings.

Also, instead of pushing the decoded string to the stack character by character, we could improve 
our algorithm by appending all the characters into the string first and then push the entire string 
into the stringStack. Let's look at the algorithm in detail.


Algorithm

Iterate over the string s and process each character as follows:

Case 1) If the current character is a digit (0-9), append it to the number k.

Case 2) If the current character is a letter (a-z), append it to the currentString.

Case 3) If current character is a opening bracket [, push k and currentString intocountStack and 
stringStack respectively.

Case 4) Closing bracket ]: We must begin the decoding process,

We must decode the currentString. Pop currentK from the countStack and decode the pattern 
currentK[currentString]

As the stringStack contains the previously decoded string, pop the decodedString from the 
stringStack. Update the decodedString = decodedString + currentK[currentString]


Complexity Analysis

Assume, n is the length of the string s.

Time Complexity: O(maxK*n), where maxK is the maximum value of k and n is the length of a given 
string s. We traverse a string of size n and iterate k times to decode each pattern of form 
k[string]. This gives us worst case time complexity as O(maxK*n).

Space Complexity: O(m+n), where m is the number of letters(a-z) and n is the number of digits(0-9) 
in string s. In worst case, the maximum size of stringStack and countStack could be m and n
respectively.
*/

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString;
        int k = 0;
        for (auto ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + ch - '0';
            } else if (ch == '[') {
                // push the number k to countStack
                countStack.push(k);
                // push the currentString to stringStack
                stringStack.push(currentString);
                // reset currentString and k
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();
                // decode currentK[currentString] by appending currentString k times
                for (int currentK = countStack.top(); currentK > 0; currentK--) {
                    decodedString = decodedString + currentString;
                }
                countStack.pop();
                currentString = decodedString;
            } else {
                currentString = currentString + ch;
            }
        }
        return currentString;
    }
};

#endif

#if 0
/*
Recursive
Complexity Analysis

Assume, n is the length of the string s.

Time Complexity: O(maxK*n) as in Approach 2

Space Complexity: O(n). 
This is the space used to store the internal call stack used for recursion. 
As we are recursively decoding each nested pattern, 
the maximum depth of recursive call stack would not be more than n
*/
class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return decodeString(s, index);
    }
    string decodeString(const string& s, int& index) {
        string result;
        while (index < s.length() && s[index] != ']') {
            if (!isdigit(s[index]))
                result += s[index++];
            else {
                int k = 0;
                // build k while next character is a digit
                while (index < s.length() && isdigit(s[index]))
                    k = k * 10 + s[index++] - '0';  
                // ignore the opening bracket '['    
                index++;
                string decodedString = decodeString(s, index);
                // ignore the closing bracket ']'
                index++;        
                while (k-- > 0)
                    result += decodedString;
            }
        }
        return result;
    }
};
#endif

void Test_GG_decodeString()
{
    LOGD("[CPP] %s\n", __TIME__);
    string s = "3[a]2[bc]";
    Solution *solution = new Solution();
    string ans = solution->decodeString(s);
    LOGD("Ans: %s\n", ans.c_str());
    delete solution;    
}

#endif //_CPPVERSION_