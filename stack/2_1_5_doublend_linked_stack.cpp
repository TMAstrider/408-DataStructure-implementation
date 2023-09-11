#include <stdio.h>
#include <stdlib.h>



//定义栈结点
typedef struct DbSNode{			    //定义双链表结点类型
    int data;				        //每个节点存放一个数据元素
    struct DbSNode *last,*next;	    //指向前后两个结点
}DbSNode;
// 双链表实现的栈（栈顶在链尾）
// 两个指针，分别指向链头 *head、链尾*rear
typedef struct DbLiStack{	        
    struct DbSNode *head, *rear;    
}DbLiStack, *DbStack;


// Main Funcs that you need to implement:
// bool InitStack(DbSNode &S);
// bool Push(DbSNode &S, int x);
// bool Pop(DbSNode &S, int &x);
// bool isStackEmpty(DbSNode S);

bool InitStack(DbStack &S);

bool Push(DbStack &S, int x);

bool Pop(DbStack &S, int &x);

bool isStackEmpty(DbStack S);

int main() {


    return 0;
}

bool InitStack(DbStack &S) {
    S = (DbLiStack *)malloc(sizeof(DbLiStack));
    // 分配一个链栈（双链表实现，栈顶在链尾）
    DbSNode *p = (DbSNode *)malloc(sizeof(DbSNode));
    // 新建一个头节点
    p->next = NULL;
    p->last = NULL;

    S->head = p;
    S->rear = p;

    return true;
}

bool Push(DbStack &S, int x) {
    DbSNode *p = (DbSNode *) malloc(sizeof(DbSNode));
    p->data = x;
    p->next = NULL;
    p->last = S->rear;
    S->rear->next = p;
    S->rear = p;
    return true;
}

bool Pop(DbStack &S, int &x) {
    if(isStackEmpty(S))
        return false;
    DbSNode *p = S->rear;
    S->rear = p->last;
    S->rear->next = NULL;
    free(p);
    

    return true;
}


bool Pop(DbStack &S, int &x) {
    if(isStackEmpty(S))
        return false;
    DbSNode *p = S->rear;
    
    S->rear = S->rear->last;
    free(S->rear->next);
    S->rear->next =NULL;

    return true;
}


bool isStackEmpty(DbStack S) {
    if(S->head == S->rear)
        return true;
    return false;
}
