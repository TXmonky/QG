#include <stdio.h>
#include <stdlib.h>
#include "adt.h"


// ����������  
Linklist* createLinklist() {
    Linklist* list = (Linklist*)malloc(sizeof(Linklist));
    if (list) {
        list->head = NULL;
    }
    else
    {
        printf("������ʧ�ܣ�");
        exit(EXIT_FAILURE);
    }
    return list;
}

// ������ĩβ��ӽڵ�  
void append(Linklist* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;

        if (list->head == NULL) {
            list->head = newNode;
        }
        else {
            Node* temp = list->head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// ɾ����������  
void DeleteLinklist(Linklist* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}
// ɾ��������ֵΪdata�Ľڵ�  
void deleteNode(Linklist* list, int data) {
    Node* current = list->head;
    Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev == NULL) { // Ҫɾ���Ľڵ���ͷ�ڵ�  
            list->head = current->next;
        }
        else {
            prev->next = current->next;
        }
        free(current);
        printf("�ڵ��ѳɹ�ɾ����\n");
    }
    else {
        printf("�����в�����ֵΪ%d�Ľڵ㡣\n", data);
    }
}
// �ҵ�������е�  
Node* findMiddle(Linklist* list) {
    Node* slow = list->head;
    Node* fast = list->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Linklist* reversal(Linklist* list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        // �������ֻ��һ���ڵ���������跴ת  
        return list;
    }

    Node* prev = NULL;  // ����ָ��ǰһ���ڵ��ָ��  
    Node* cur = list->head; // ��ǰ�ڵ�  

    while (cur != NULL) {
        Node* nextTemp = cur->next; // ������һ���ڵ�  
        cur->next = prev; // ��ת��ǰ�ڵ��nextָ��  
        prev = cur; // ��prev��ǰ�ƶ�һ��  
        cur = nextTemp; // ��cur��ǰ�ƶ�һ��  
    }

    // ��ת��ɺ�prev��ָ���µ�ͷ�ڵ�  
    list->head = prev;

    return list;
}


// ��ӡ�˵�  
void printMenu() {
    printf("�������Ӧ����\n");
    printf("1.����һ��������\n");
    printf("2.������\n");
    printf("3.��ӡ����\n");
    printf("4.ɾ��������\n");
    printf("5.ɾ��ĳ���ڵ�\n");
    printf("6.�ҵ������е�\n");
    printf("7.��ż����������̫�У�\n");
    printf("8.��ת����\n");
    printf("9.�˳�\n");
}
