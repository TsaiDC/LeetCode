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
https://leetcode.com/problems/sort-characters-by-frequency/
451. Sort Characters By Frequency

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

typedef struct node_s{
    char c;
    int num;
    struct node_s* pL;
    struct node_s* pR;
}node_t;

void insert_a_node(node_t* root, node_t* node)
{
    if(root->num > node->num) {
        if(root->pL == NULL) {
            root->pL = node;
        }
        else {
            insert_a_node(root->pL, node);
        }
    }
    else {
        if(root->pR == NULL) {
            root->pR = node;
        }
        else {
            insert_a_node(root->pR, node);
        }
    }
}

node_t* insertNode(node_t* root, char c, int num)
{
    LOGD("Char: %c, Num: %d\n", c, num);
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->c = c;
    node->num = num;
    node->pL = NULL;
    node->pR = NULL;

    if(root==NULL) {
        root = node;
    }
    else {
        insert_a_node(root, node);
    }
    return root;
}

static void revert_inorder(node_t* root, string* str)
{
    if(root==NULL) return;
    revert_inorder(root->pR, str);
    LOGD("%c(%d)\n", root->c, root->num);
    for(int i=0; i<root->num; ++i)
    {
        str->push_back(root->c);
    }
    revert_inorder(root->pL, str);
}

string frequencySort(string s) {
    map<char, int> mapStr;
    map<char, int>::iterator iter;
    
    for(int i=0; i<s.length(); ++i)
    {
        iter = mapStr.find(s.at(i));
        if(iter != mapStr.end()) {
            iter->second+=1;
        }
        else {
            mapStr[s.at(i)] = 1;
        }        
    }
    
    node_t *pRoot = NULL;
    for(iter = mapStr.begin(); iter != mapStr.end(); iter++)
    {
//        cout<<iter->first<<" "<<iter->second<<endl;
        pRoot = insertNode(pRoot, iter->first, iter->second);
    }

    string result;
    revert_inorder(pRoot, &result);
    LOGD("Result: %s\n", result.c_str());
    return result;    
}

void Test_SortCharactersByFrequency()
{
    LOGD("%s\n", __TIME__);
    string str="aabbbbccc";
    frequencySort(str);
}