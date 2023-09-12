#include <stdio.h>
#include <stdlib.h>

// Father Node index start from 1.

#define treeSize 100

typedef struct TreeNode {
    int data;       //结点中的数据元素
    bool isEmpty;   //结点是否为空
} TreeNode;


// 初始化顺序存储的二叉树，所有结点标记为"空"
void InitSqBiTree (TreeNode t[], int length);

// Traverse each TreeNode and print it out.
void visitNode(TreeNode t);

// 判断下标为 index 的结点是否为空
bool isEmpty(TreeNode t[], int length, int index);

// 找到下标为 index 的结点的左孩子，
// 并返回左孩子的下标，如果没有左孩子，则返回 -1
int getLchild(TreeNode t[], int length, int index);

// 找到下标为 index 的结点的右孩子，
// 并返回右孩子的下标，如果没有右孩子，则返回 -1
int getRchild(TreeNode t[], int length, int index);


// 找到下标为 index 的结点的父节点，
// 并返回父节点的下标，如果没有父节点，则返回 -1
int getFather(TreeNode t[], int length, int index);


//从下标为 index 的结点开始先序遍历
void PreOrderSqTree (TreeNode *t, int length, int index);

//从下标为 index 的结点开始中序遍历
void InOrderSqTree (TreeNode *t, int length, int index);

//从下标为 index 的结点开始后序遍历
void PostOrderSqTree (TreeNode *t, int length, int index);


int main(){
    TreeNode t[treeSize];        //定义一棵顺序存储的二叉树
    InitSqBiTree(t, treeSize);   //初始化为空树
    for(int i = 0; i < 99; i++) {
        t[i].data = i;
        t[i].isEmpty = false;
        // printf("treeNode[%d].data = %d\n", i, t[i].data);
    }
    if(t[99].isEmpty == true)
        printf("t[99].data = %d\n", t[99]);
        printf("true\n");
    PreOrderSqTree(t, treeSize, 1);    //从根节点1出发，进行中序遍历
}




//从下标为 index 的结点开始先序遍历
void PreOrderSqTree (TreeNode *t, int length, int index) {
    if (isEmpty(t, length, index))    //当前为空节点
        return;
    visitNode(t[index]);     //访问结点
    PreOrderSqTree(t, length, getLchild(t, length, index));       //先序遍历左子树
    PreOrderSqTree(t, length, getRchild(t, length, index));       //先序遍历右子树
}

//从下标为 index 的结点开始中序遍历
void InOrderSqTree (TreeNode *t, int length, int index) {
    if (isEmpty(t, length, index))    //当前为空节点
        return;
    InOrderSqTree(t, length, getLchild(t, length, index));       //中序遍历左子树
    visitNode(t[index]);     //访问结点
    InOrderSqTree(t, length, getRchild(t, length, index));       //中序遍历右子树
}

//从下标为 index 的结点开始后序遍历
void PostOrderSqTree (TreeNode *t, int length, int index) {
    if (isEmpty(t, length, index))    //当前为空节点
        return;
    PostOrderSqTree(t, length, getLchild(t, length, index));       //后序遍历左子树
    PostOrderSqTree(t, length, getRchild(t, length, index));       //后序遍历右子树
    visitNode(t[index]);     //访问结点
}



//初始化顺序存储的二叉树，所有结点标记为"空"
void InitSqBiTree (TreeNode t[], int length) {
    for (int i=0; i<length; i++){
        t[i].isEmpty=true;
    }
}

void visitNode(TreeNode t) {
    printf("Now visited the Node's data is: %d\n", t.data);

    return;
}

//判断下标为 index 的结点是否为空
bool isEmpty(TreeNode t[], int length, int index) {
    if (index >= length || index < 1) return true;   //下标超出合法范围
    return t[index].isEmpty;
}

//找到下标为 index 的结点的左孩子，并返回左孩子的下标，如果没有左孩子，则返回 -1
int getLchild(TreeNode t[], int length, int index) {
    int lChild = index * 2;   //如果左孩子存在，则左孩子的下标一定是 index * 2
    if (isEmpty(t, length, lChild)) return -1;  //左孩子为空
    return lChild;
}

//找到下标为 index 的结点的右孩子，并返回右孩子的下标，如果没有右孩子，则返回 -1
int getRchild(TreeNode t[], int length, int index) {
    int rChild = index * 2 + 1;                 //如果右孩子存在，则右孩子的下标一定是 index * 2 + 1
    if (isEmpty(t, length, rChild)) return -1;  //右孩子为空
    return rChild;
}

//找到下标为 index 的结点的父节点，并返回父节点的下标，如果没有父节点，则返回 -1
int getFather(TreeNode t[], int length, int index) {
    if (index == 1) return -1;          //根节点没有父节点
    int father = index / 2;             //如果父节点存在，则父节点的下标一定是 index/2，整数除法会自动向下取整
    if (isEmpty(t, length, father)) return -1;
    return father;
}



