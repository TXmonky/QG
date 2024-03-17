#ifndef DOUBLE_H
#define DOUBLE_H
#include <stdio.h>  
#include <stdlib.h>  

// 定义双向链表节点的结构体  
typedef struct DuNode {
    int data;          // 节点中的数据  
    struct DuNode* prev; // 指向前一个节点的指针  
    struct DuNode* next; // 指向下一个节点的指针  
} DuNode, * DuLinkedList;

// 定义成功和失败的宏  
#define SUCCESS 1  
#define FAILURE 0  

// 声明双向链表的操作函数  
DuLinkedList CreateDuLinkedList();
void TraverseList_DuL(DuLinkedList head, void (*visit)(DuNode*));
void InsertNode_DuL(DuLinkedList* head, int pos, int value);
void DeleteNode_DuL(DuLinkedList* head, int value);
void SearchNode_DuL(DuLinkedList head, int value);
void PrintNode(DuNode* node);
void FreeDuLinkedList(DuLinkedList* head); 
#endif // 