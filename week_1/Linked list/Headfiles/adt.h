#ifndef ADT_H  
#define ADT_H 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Linklist {
    Node* head;
} Linklist;
// 创建空链表 
Linklist* createLinklist();
// 向链表末尾添加节点
void append(Linklist* list, int data);
// 删除整个链表  
void DeleteLinklist(Linklist* list);
//删除某个结点
void deleteNode(Linklist* list, int data);
//奇偶互换
//Node* oddEvenList(Node* head);
//找到链表的中点
Node* findMiddle(Linklist* list);
// 打印菜单  
void printMenu();

#endif // LINKLIST_H
