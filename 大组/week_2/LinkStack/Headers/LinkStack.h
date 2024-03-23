#ifndef _LINKSTACK_H_  
#define _LINKSTACK_H_  

#include <stdio.h>    
#include <stdlib.h>  
#include <string.h>  

typedef enum {
    INT,
    FLOAT,
    CHAR,
    Unknown
} DataType;

// 定义链栈节点结构体    
typedef struct StackNode {
    void* data;
    DataType type;
    struct StackNode* next;
} StackNode, * LinkStack;

// 初始化链栈  
LinkStack InitStack();

// 入栈（这里假设有一个通用的Push函数，接受void*和DataType）  
void Push(LinkStack* S, void* e, DataType type);

// 出栈（这里假设有一个通用的Pop函数，接受void*的指针来存储弹出的数据，并返回DataType）  
DataType Pop(LinkStack* S, void* e);

// 销毁链栈  
void DestroyStack(LinkStack S);

// 打印链栈  
void printStack(LinkStack S);

// 打印菜单  
void PrintfMenu();

#endif // _LINKSTACK_H_