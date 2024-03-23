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

// ������ջ�ڵ�ṹ��    
typedef struct StackNode {
    void* data;
    DataType type;
    struct StackNode* next;
} StackNode, * LinkStack;

// ��ʼ����ջ  
LinkStack InitStack();

// ��ջ�����������һ��ͨ�õ�Push����������void*��DataType��  
void Push(LinkStack* S, void* e, DataType type);

// ��ջ�����������һ��ͨ�õ�Pop����������void*��ָ�����洢���������ݣ�������DataType��  
DataType Pop(LinkStack* S, void* e);

// ������ջ  
void DestroyStack(LinkStack S);

// ��ӡ��ջ  
void printStack(LinkStack S);

// ��ӡ�˵�  
void PrintfMenu();

#endif // _LINKSTACK_H_