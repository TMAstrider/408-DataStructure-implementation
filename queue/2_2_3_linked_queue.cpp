#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;


void InitQueue(LinkQueue &Q);//初始化

bool EnQueue(LinkQueue &Q, int x);//入队操作

// 判断是否空队，然后出队
bool DeQueue(LinkQueue &Q, int &x);

bool GetHead(LinkQueue Q, int &x);//获取头元素

bool QueueEmpty(LinkQueue Q);//判空


int main() {
    LinkQueue Queue1;

    return 0;
}

void InitQueue(LinkQueue &Q) {
    Q.front = (LinkNode *) malloc(sizeof(LinkNode));
    Q.rear = Q.front;
    Q.front->next = NULL;
}

bool EnQueue(LinkQueue &Q, int x) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}

bool DeQueue(LinkQueue &Q, int &x) {
    if(QueueEmpty(Q))
        return true;
    LinkNode *p = Q.front->next;
    Q.front = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}

bool GetHead(LinkQueue Q, int &x) {
    if(QueueEmpty(Q))
        return false;
    x = Q.front->next->data;
    return true;
}

bool QueueEmpty(LinkQueue Q) {
    if(Q.front == NULL && Q.rear == NULL)
        return true;
    return false;
}
