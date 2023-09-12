#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;       //结点中的数据元素
    bool isEmpty;   //结点是否为空
} TreeNode;

//初始化顺序存储的二叉树，所有结点标记为"空"
void InitSqBiTree (TreeNode t[], int length) {
    for (int i=0; i<length; i++){
        t[i].isEmpty=true;
    }
}

int main(){
    TreeNode t[100];        //定义一棵顺序存储的二叉树
    InitSqBiTree(t, 100);   //初始化为空树
    
}
