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
// ���������� 
Linklist* createLinklist();
// ������ĩβ��ӽڵ�
void append(Linklist* list, int data);
// ɾ����������  
void DeleteLinklist(Linklist* list);
//ɾ��ĳ�����
void deleteNode(Linklist* list, int data);
//��ż����
//Node* oddEvenList(Node* head);
//�ҵ�������е�
Node* findMiddle(Linklist* list);
// ��ӡ�˵�  
void printMenu();

#endif // LINKLIST_H
