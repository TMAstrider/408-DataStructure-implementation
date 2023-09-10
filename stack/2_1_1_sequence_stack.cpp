#include <stdio.h>

#define MaxSize 5


// Squence Stack 顺序栈
typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

// 初始化 SqStack：初始时设置s.top = -1
// 栈顶元素 s.data[s.top]
bool InitStack(SqStack &s);
// 栈不满时，栈顶指针先加 1，再送值到栈顶元素
bool Push(SqStack &s, int x);
// 栈非空时，先取栈顶元素值，再将栈顶指针减1
bool Pop(SqStack &s, int &x);
// 栈满条件:s.top==MaxSize-1;
bool isStackFull(SqStack s);
// 栈空条件:s.top==-1;
bool isStackEmpty(SqStack s);

void PrintStack(SqStack S);


// Literally test unit.
// 字面意义上的测试单元 lol
void testUnit() {
    SqStack s;
    InitStack(s);
    int x = 0;
    if(Push(s, x))
        printf("push success!\n");
    else printf("push fail!\n");
    PrintStack(s);
    x = 1;
    if(Push(s, x))
        printf("push success!\n");
    else printf("push fail!\n");
    PrintStack(s);
    x = 2;
    if (Pop(s, x))
        printf("Pop success!\n");
    else printf("Pop failed!\n");
    PrintStack(s);
    printf("Pop element x = %d.\n", x);


}
    





int main() {
    printf("hello world! \n");
    printf("1 \n");
    testUnit();


    return 0;
    
}



bool InitStack(SqStack &s) {
    s.top = -1;
    return true;
}


bool Push(SqStack &s, int x) {
    if(isStackFull(s))
        return false;
    s.top++;
    s.data[s.top] = x;
    return true;
}

bool Pop(SqStack &s, int &x) {
    if(isStackEmpty(s))
        return false;
    x = s.data[s.top--];
    return true;
}

bool isStackFull(SqStack s) {
    if(s.top==MaxSize-1)
        return true;
    return false;
}

bool isStackEmpty(SqStack s) {
    if(s.top == -1)
        return true;
    return false;
}


void PrintStack(SqStack S) {
    printf("从栈顶元素开始，栈如下：\n");
    while (S.top >= 0) {//注意判空的条件
        printf("S[%d]=%d\n", S.top, S.data[S.top]);
        S.top--;
    }
    printf("栈打印完毕\n");
}