//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

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
*/

typedef struct node_t
{
    int data;
    struct node_t* left;
    struct node_t* right;
}node;

node* create()
{
    node *p;
    int x;
    printf("Enter date (-1 exist):");
    scanf("%d", &x);
    
    if(x==-1)
        return NULL;
    
    p = (node*)malloc(sizeof(node));
    p->data = x;
    printf("Left Child of %x\n", x);
    p->left = create();
    printf("Right Child of %x\n", x);
    p->right = create();
    return p;
}

void preorder(node *t)
{
    if(t == NULL)
        return;
    LOGD("%d\n", t->data);
    preorder(t->left);
    preorder(t->right);    
}

void postorder(node *t)
{
    if(t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    LOGD("%d\n", t->data);
}

void inorder(node *t)
{
    if(t == NULL)
        return;
    inorder(t->left);
    LOGD("%d\n", t->data);
    inorder(t->right);
}

void freeTree(node *t)
{
    if(t== NULL)
        return;
}

void Test_tree()
{
    LOGI("%s\n", __TIME__);
    node *root;
    root = create();
    
    LOGD("Preorder: \n");
    preorder(root);
    LOGD("Postorder: \n");
    postorder(root);
    LOGD("inorder: \n");
    inorder(root);    
}