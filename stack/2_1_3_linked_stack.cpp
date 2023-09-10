#include <stdio.h>
#include <stdlib.h>


//定义栈结点
typedef struct SNode{			//定义单链表结点类型
    int data;				        //每个节点存放一个数据元素
    struct SNode *next;			//指针指向下一个节点
}SNode, *LiStack;

//分配一个头结点，头节点->next = Null;
bool InitStack(LiStack &S);
// // 链表入栈不需要检查 !!!注意：这边头节点后面一个节点是最新插入的节点
bool Push(LiStack &S, int x);

bool Pop(LiStack &S, int &x);

// 栈空条件:S->next == Null
bool isStackEmpty(LiStack S);




int main(){

}
//初始化一个链栈（单链表实现，栈顶在链头）
bool InitStack(LiStack &S) {
    S = (SNode *) malloc(sizeof(SNode)); //分配一个头结点
    S->next = NULL;         //头结点之后暂时还没有节点
    return true;
}

// 入栈  头插法：头节点后面加入元素，相当于入栈
bool Push(LiStack &S, int x) {
    // 链表入栈不需要检查
    SNode *p = (SNode *)malloc(sizeof(SNode));
    if(p == NULL)
        return false;
    p->next = S->next;
    // 这边头节点后面一个节点是最新插入的节点
    p->data = x;
    S->next = p;
    return true;
}

bool Pop(LiStack &S, int &x){
    if(S->next == NULL)
        return false;
    SNode *p;   // p Pointer
    p = S->next;    // p 指向 S->next 指向 s->next指向的Node
    int x = p->data;
    S->next = p->next;
    free(p);    // free p Pointer 指向的内存区域（每一个Node都是 指针指向的 malloc出来的一片区域）
    return true;
}

//判断栈是否为空
bool isStackEmpty(LiStack S){
    if(S->next==NULL)   //头结点后面没有结点
        return true;    //返回true，表示栈为空
    else
        return false;
}


