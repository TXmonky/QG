#ifndef ADT_H  
#define ADT_H 
#include <stdio.h>
#include <stdlib.h>
//定义一个结点
typedef struct Node {
    int data;
    struct Node* next;
} Node;
//定义一个链表
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
//Linklist* oddevenswap(Linklist* list);
//反转链表
Linklist* reversal(Linklist* list);
//找到链表的中点
Node* findMiddle(Linklist* list);
// 打印菜单  
void printMenu();

#endif // LINKLIST_H
