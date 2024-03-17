#ifndef DOUBLE_H
#define DOUBLE_H
#include <stdio.h>  
#include <stdlib.h>  

// ����˫������ڵ�Ľṹ��  
typedef struct DuNode {
    int data;          // �ڵ��е�����  
    struct DuNode* prev; // ָ��ǰһ���ڵ��ָ��  
    struct DuNode* next; // ָ����һ���ڵ��ָ��  
} DuNode, * DuLinkedList;

// ����ɹ���ʧ�ܵĺ�  
#define SUCCESS 1  
#define FAILURE 0  

// ����˫������Ĳ�������  
DuLinkedList CreateDuLinkedList();
void TraverseList_DuL(DuLinkedList head, void (*visit)(DuNode*));
void InsertNode_DuL(DuLinkedList* head, int pos, int value);
void DeleteNode_DuL(DuLinkedList* head, int value);
void SearchNode_DuL(DuLinkedList head, int value);
void PrintNode(DuNode* node);
void FreeDuLinkedList(DuLinkedList* head); 
#endif // 