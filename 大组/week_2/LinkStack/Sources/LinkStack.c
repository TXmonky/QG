#include "LinkStack.h"  
#include <stdlib.h>  

// 链栈初始化    
LinkStack InitStack() {
    // 返回一个空栈，即头节点为NULL  
    return NULL;
}

// 入栈操作    
void Push(LinkStack* S, void* e, DataType type) {
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    if (!p) {
        perror("Memory allocation failed for Push");
        exit(EXIT_FAILURE);
    }
    p->data = e;
    p->type = type;
    p->next = *S; // 将新节点插入到栈顶  
    *S = p;
}

// 出栈操作    
int Pop(LinkStack* S, void** e, DataType* type) {
    if (*S == NULL) {
        return -1; // 栈空    
    }
    StackNode* p = *S;
    *e = p->data;
    *type = p->type;
    *S = p->next; // 更新栈顶指针  
    free(p); // 释放当前节点    
    return 0; // 成功出栈  
}

// 销毁链栈    
void DestroyStack(LinkStack* S) {
    StackNode* p;
    while (*S) {
        p = *S;
        *S = (*S)->next;
        free(p); // 释放当前节点    
    }
}

void printStack(LinkStack S) {
    if (S == NULL) {
        printf("栈为空\n");
        return;
    }
    StackNode* temp = S; // 假设S是链栈的第一个存储数据的节点  
    printf("链栈内容为:\n");
    while (temp != NULL) {
        switch (temp->type) {
        case INT:
            printf("int: %d\n", *((int*)temp->data));
            break;
        case FLOAT:
            printf("float: %f\n", *((float*)temp->data));
            break;
        case CHAR:
            printf("char: %c\n", *((char*)temp->data));
            break;
        default:
            printf("Unknown type\n");
            break;
        }
        temp = temp->next;
    }
}

// 打印菜单  
void PrintfMenu() {
    printf("请选择操作：\n");
    printf("1. 初始化链栈\n");
    printf("2. 入栈\n");
    printf("3. 出栈\n");
    printf("4. 打印栈\n");
    printf("5. 销毁栈\n");
    printf("6. 退出\n");
}