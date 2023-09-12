#include <stdio.h>
#include <stdlib.h>


#define treeSize 100


// 双亲表示法
typedef struct {
    int data;
    int parent;
}PTnode;

typedef struct {
    PTnode nodes[treeSize];
    int n;
}PTree;



// 孩子兄弟表示法
typedef struct {
    int data;
    struct CSNode *firstchild, *nextsbling;
}CSNode, *CSTree;


// 孩子表示法
//Child表示下一个孩子的信息
typedef struct Child{
    int index;             //孩子编号
    struct Child * next;   //下一个孩子
} Child;

//TreeNode用于保存结点信息
typedef struct TreeNode {
    char data;             //结点信息
    Child * firstChild;    //指向第一个孩子
} TreeNode;

TreeNode tree[10];   //定义一棵拥有10个结点的树（孩子表示法）
