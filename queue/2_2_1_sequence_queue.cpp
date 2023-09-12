#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front, rear;//对头指针和队尾指针
} SqQueue;

// 初始化队列，构造一个空队列 Q
void InitQueue(SqQueue &Q);//初始化

// 判队列空，若队列Q为空返回 true，否则返回 
bool QueueEmpty(SqQueue Q);//判空

// 入队，若队列未满，将x加入，使之成为新的队尾
bool EnQueue(SqQueue &Q, int t);//入队操作

// 出队，若队列非空，删除队头元素，并用x返回
bool DeQueue(SqQueue &Q, int &x);//出队操作

// 读队头元素，若队列o非空，则将队头元素赋值给 x
bool GetHead(SqQueue Q, int &x);//获取队头元素,用x返回

// 判满条件(Q.rear + 1) % MaxSize == Q.front
bool QueueFull(SqQueue Q);


int main() {
    return 0;
}

void InitQueue(SqQueue &Q) {
    Q.rear = 0;
    Q.front = 0;
}

bool QueueEmpty(SqQueue Q) {
    if(Q.rear == Q.front)
        return true;
    return false;
}

bool EnQueue(SqQueue &Q, int t) {
    if(QueueFull(Q))
        return false ;
    Q.data[Q.rear] = t;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, int &x) {
    if(QueueEmpty(Q))
        return true;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue Q, int &x) {
    if(QueueEmpty(Q))
        return false;
    x = Q.data[Q.front];

    return true;
}

bool QueueFull(SqQueue Q) {
    if((Q.rear + 1) % MaxSize == Q.front)
    return false;
}


