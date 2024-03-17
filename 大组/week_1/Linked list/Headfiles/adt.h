#ifndef ADT_H  
#define ADT_H 
#include <stdio.h>
#include <stdlib.h>
//����һ�����
typedef struct Node {
    int data;
    struct Node* next;
} Node;
//����һ������
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
//Linklist* oddevenswap(Linklist* list);
//��ת����
Linklist* reversal(Linklist* list);
//�ҵ�������е�
Node* findMiddle(Linklist* list);
// ��ӡ�˵�  
void printMenu();

#endif // LINKLIST_H
