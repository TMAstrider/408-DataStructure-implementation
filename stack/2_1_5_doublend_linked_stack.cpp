#include <stdio.h>
#include <stdlib.h>



//定义栈结点
typedef struct DbSNode{			    //定义双链表结点类型
    int data;				        //每个节点存放一个数据元素
    struct DbSNode *last,*next;	    //指向前后两个结点
}DbSNode;

typedef struct DbLiStack{	        //双链表实现的栈（栈顶在链尾）
    struct DbSNode *head, *rear;    //两个指针，分别指向链头、链尾
}DbLiStack, *DbStack;


// Main Funcs that you need to implement:
// bool InitStack(DbSNode &S);
// bool Push(DbSNode &S, int x);
// bool Pop(DbSNode &S, int &x);
// bool isStackEmpty(DbSNode S);

bool InitStack(DbSNode &S);

bool Push(DbSNode &S, int x);

bool Pop(DbSNode &S, int &x);

bool isStackEmpty(DbSNode S);

int main() {


    return 0;
}

bool InitStack(DbSNode &S) {
    DbSNode *S = (DbSNode *)malloc(sizeof(DbSNode));

    return false;
}
