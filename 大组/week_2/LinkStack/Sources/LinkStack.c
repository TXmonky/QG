#include "LinkStack.h"  
#include <stdlib.h>  

// ��ջ��ʼ��    
LinkStack InitStack() {
    // ����һ����ջ����ͷ�ڵ�ΪNULL  
    return NULL;
}

// ��ջ����    
void Push(LinkStack* S, void* e, DataType type) {
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    if (!p) {
        perror("Memory allocation failed for Push");
        exit(EXIT_FAILURE);
    }
    p->data = e;
    p->type = type;
    p->next = *S; // ���½ڵ���뵽ջ��  
    *S = p;
}

// ��ջ����    
int Pop(LinkStack* S, void** e, DataType* type) {
    if (*S == NULL) {
        return -1; // ջ��    
    }
    StackNode* p = *S;
    *e = p->data;
    *type = p->type;
    *S = p->next; // ����ջ��ָ��  
    free(p); // �ͷŵ�ǰ�ڵ�    
    return 0; // �ɹ���ջ  
}

// ������ջ    
void DestroyStack(LinkStack* S) {
    StackNode* p;
    while (*S) {
        p = *S;
        *S = (*S)->next;
        free(p); // �ͷŵ�ǰ�ڵ�    
    }
}

void printStack(LinkStack S) {
    if (S == NULL) {
        printf("ջΪ��\n");
        return;
    }
    StackNode* temp = S; // ����S����ջ�ĵ�һ���洢���ݵĽڵ�  
    printf("��ջ����Ϊ:\n");
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

// ��ӡ�˵�  
void PrintfMenu() {
    printf("��ѡ�������\n");
    printf("1. ��ʼ����ջ\n");
    printf("2. ��ջ\n");
    printf("3. ��ջ\n");
    printf("4. ��ӡջ\n");
    printf("5. ����ջ\n");
    printf("6. �˳�\n");
}