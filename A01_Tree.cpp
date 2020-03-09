//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue> 

using namespace std; 
#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define GREEN "\033[0;32;32m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#if DEBUG
#define LOGI(...) {printf(GREEN "[I] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGI(...)
#define LOGD(...)
#define LOGE(...)
#endif


/*
Tree:
practice 
Ref: https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/
https://www.itread01.com/articles/1476616127.html
http://www.csie.ntnu.edu.tw/~u91029/Order.html
*/

typedef struct node_s
{
    int data;
    struct node_s* left;
    struct node_s* right;
}node_t;

node_t* newNode(int key)
{   
    LOGI("Key: %d\n", key);
    node_t* t = (node_t*)malloc(sizeof(node_t));
    t->data = key;
    t->left = t->right = NULL;
    return t;
}

void insert(node_t *root, int key)
{
    if(!root) {
        root = newNode(key);
        return;
    }

    queue<node_t*> q;
    q.push(root);
    
    while(!q.empty()) {
        node_t* tmp = q.front();
        q.pop();
        
        if(!tmp->left) {
            tmp->left = newNode(key);
            break;
        }
        else {
            q.push(tmp->left);
        }
        
        if(!tmp->right) {
            tmp->right = newNode(key);
            break;
        }
        else {
            q.push(tmp->right);
        }
    }
}

void preorder(node_t *t)
{
    if(t == NULL)
        return;
    LOGD("%d\n", t->data);
    preorder(t->left);
    preorder(t->right);
}

void postorder(node_t *t)
{
    if(t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    LOGD("%d\n", t->data);
}

void inorder(node_t *t)
{
    if(t == NULL)
        return;
    inorder(t->left);
    LOGD("%d\n", t->data);
    inorder(t->right);
}

void freeTree(node_t *t)
{
}

void Test_tree()
{
    LOGI("%s\n", __TIME__);

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    node_t *root = newNode(arr[0]);
    
    for(int i=1; i<n; ++i)
    {
        insert(root, arr[i]);
    }
    
    

//    LOGD("Preorder: \n");
//    preorder(root);

//    LOGD("Postorder: \n");
//    postorder(root);
    LOGD("inorder: \n");
    inorder(root);

}