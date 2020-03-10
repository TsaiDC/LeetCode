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
Ref: https://www.cnblogs.com/vamei/archive/2013/03/21/2964092.html
*/

typedef struct node *position;
typedef int ElementTP;

struct node {
    int depth; 
    position parent;
    ElementTP element;
    position lchild;
    position rchild;
};

/* pointer => root node of the tree */
typedef struct node *TREE;

static position insert_value(TREE, ElementTP);
int depth(TREE);

static void insert_node_to_nonempty_tree(TREE, position);
static void update_root_depth(TREE); 
static TREE recover_avl(TREE, position);
static int depth_diff(TREE); 
static position insert_leaf(TREE, ElementTP);
static void insert_node_to_nonempty_tree(TREE, position);
static TREE left_single_rotate(TREE);
static TREE left_double_rotate(TREE);
static TREE right_single_rotate(TREE);
static TREE right_double_rotate(TREE);
#if 0
void main(void) 
{
    TREE tr;
    position np;
    ElementTP element;
    tr = NULL;
    tr = insert_value(tr, 18);
    tr = insert_value(tr, 5);
    printf("root: %d\n", tr->element);
    printf("depth: %d\n", depth(tr));
    tr = insert_value(tr, 2); 
    printf("root: %d\n", tr->element);
    printf("depth: %d\n", depth(tr));
    tr = insert_value(tr, 4);
    printf("root: %d\n", tr->element);
    printf("depth: %d\n", depth(tr));
    printf("root->lchild: %d\n", tr->lchild->element);
    tr = insert_value(tr, 3);
    printf("root: %d\n", tr->element);
    printf("depth: %d\n", depth(tr));
    printf("root->lchild: %d\n", tr->lchild->element);
    printf("root->lchild->lchild: %d\n", tr->lchild->lchild->element);
}
#endif

/*
 * insert value
 *
 */
static position insert_value(TREE tr, ElementTP value)
{
    position newNode;

    /* insert a value to a binary search tree */
    newNode = insert_leaf(tr, value);
    update_root_depth(newNode);
    if (tr == NULL) {
        tr = newNode;
    }
    else {
        tr = recover_avl(tr, newNode);
    }

    return tr;
}

/*
 * get the depth of the tree
 * use this function to access depth
 */
int depth(TREE tr) {
    if (tr == NULL) {
        return 0;
    }
    else {
        return tr->depth;
    }
}

//========================================
// static functions: for internal use

/* 
 * traverse the path from new node to root node
 * make one rotation, recover AVL and stop
 */
static TREE recover_avl(TREE tr, position np) 
{
    int myDiff;
    while (np != NULL) {
        update_root_depth(np);
        myDiff = depth_diff(np);
        if (myDiff > 1 || myDiff < -1) {
            if (myDiff > 1) {
                /* left rotate needed */ //RR Case
                if(depth_diff(np->rchild) > 0) {
                    np = left_single_rotate(np);
                }
                else {
                    //RL Case
                    np = left_double_rotate(np);
                }
            }
            if (myDiff < -1) {
                //LL Case
                if(depth_diff(np->lchild) < 0) {
                    np = right_single_rotate(np);
                }
                else {
                    //LR Case
                    np = right_double_rotate(np);
                }
            }
            /* if rotation changes root node */
            if (np->parent == NULL) tr = np;
            break;
        }
        np = np->parent;
    }
    
    return tr;
}

/*
 * difference of rchild->depth and lchild->depth
 */
static int depth_diff(TREE tr) 
{
    if (tr == NULL) {
        return 0;
    }
    else {
        return depth(tr->rchild) - depth(tr->lchild);
    }
}


/* 
 * left single rotation 
 * return the new root
 */
static TREE left_single_rotate(TREE tr) 
{
    TREE newRoot, parent;
    parent  = tr->parent;
    newRoot = tr->rchild;
    /* detach & attach */ 
    if (newRoot->lchild != NULL) newRoot->lchild->parent = tr;
    tr->rchild = newRoot->lchild;
    update_root_depth(tr);
   
    /* raise new root node */
    newRoot->lchild = tr;
    newRoot->parent = parent;
    if (parent != NULL) {
        if (parent->lchild == tr) {
        parent->lchild = newRoot;
    }
    else {
        parent->rchild = newRoot;
    }
    }
    tr->parent = newRoot;
    update_root_depth(newRoot);
    return newRoot;
}

/* 
 * right single rotation 
 * return the new root
 */
static TREE right_single_rotate(TREE tr) 
{
    TREE newRoot, parent;
    parent  = tr->parent;
    newRoot = tr->lchild;

    /* detach & attach */
    if (newRoot->rchild != NULL) newRoot->rchild->parent = tr;
    tr->lchild = newRoot->rchild;
    update_root_depth(tr);
  
    /* raise new root node */
    newRoot->rchild = tr;
    newRoot->parent = parent;
    if (parent != NULL) {
        if (parent->lchild == tr) {
        parent->lchild = newRoot;
    }
    else {
        parent->rchild = newRoot;
    }
    }
    tr->parent = newRoot;
    update_root_depth(newRoot);
    return newRoot;
}

/*
 * left double rotation
 * return
 */
static TREE left_double_rotate(TREE tr) 
{
    right_single_rotate(tr->rchild);
    return left_single_rotate(tr);
}

/*
 * right double rotation
 * return
 */
static TREE right_double_rotate(TREE tr) 
{
    left_single_rotate(tr->lchild);
    return right_single_rotate(tr);
}

/*
 * update tr->depth
 * assume lchild->depth and rchild->depth are correct
 */
static void update_root_depth(TREE tr) 
{
    int maxChildDepth; 
    int depLChild, depRChild;
    if (tr==NULL) return;
    else {
        depLChild = depth(tr->lchild);
        depRChild = depth(tr->rchild);
        maxChildDepth = depLChild > depRChild ? depLChild : depRChild;
        tr->depth = maxChildDepth + 1;
    }
}

/* 
 * insert a new value into the tree as a leaf
 * return address of the new node
 */
static position insert_leaf(TREE tr, ElementTP value) 
{
    position np;
    /* prepare the node */
    np = (position) malloc(sizeof(struct node));
    np->element = value;
    np->parent  = NULL;
    np->lchild  = NULL;
    np->rchild  = NULL;
 
    if (tr != NULL) {
        insert_node_to_nonempty_tree(tr, np);
    }
    return np;
}

/*
 * insert a node to a non-empty tree
 * called by insert_value()
 */
static void insert_node_to_nonempty_tree(TREE tr, position np)
{
    /* insert the node */
    if(np->element <= tr->element) {
        if (tr->lchild == NULL) {
            /* then tr->lchild is the proper place */
            tr->lchild = np;
            np->parent = tr;
            return;
        }
        else {
            insert_node_to_nonempty_tree(tr->lchild, np);
        }
    }
    else if(np->element > tr->element) {
        if (tr->rchild == NULL) {
            tr->rchild = np;
            np->parent = tr;
            return;
        }
        else {
            insert_node_to_nonempty_tree(tr->rchild, np);
        }
    }
}

void avltree_inorder(TREE t)
{
    if(t == NULL)
        return;
    avltree_inorder(t->lchild);
    LOGD("%d\n", t->element);
    avltree_inorder(t->rchild);
}

void Test_avltree()
{
    LOGI("%s\n", __TIME__);
#if 1
    TREE tr;
    position np;
    ElementTP element;
    tr = NULL;
    tr = insert_value(tr, 18);
    tr = insert_value(tr, 5);
    printf("root: %d\n", tr->element);
    printf("depth: %d\n", depth(tr));
    tr = insert_value(tr, 2); 
    printf("root: %d\n", tr->element);
    printf("depth: %d\n", depth(tr));
    tr = insert_value(tr, 4);
    printf("root: %d\n", tr->element);
    printf("depth: %d\n", depth(tr));
    printf("root->lchild: %d\n", tr->lchild->element);
    tr = insert_value(tr, 3);
    printf("root: %d\n", tr->element);
    printf("depth: %d\n", depth(tr));
    printf("root->lchild: %d\n", tr->lchild->element);
    printf("root->lchild->lchild: %d\n", tr->lchild->lchild->element);
#endif
    avltree_inorder(tr);
}