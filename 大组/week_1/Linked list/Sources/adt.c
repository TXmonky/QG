#include <stdio.h>
#include <stdlib.h>
#include "adt.h"


// 创建空链表  
Linklist* createLinklist() {
    Linklist* list = (Linklist*)malloc(sizeof(Linklist));
    if (list) {
        list->head = NULL;
    }
    else
    {
        printf("链表创建失败！");
        exit(EXIT_FAILURE);
    }
    return list;
}

// 向链表末尾添加节点  
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

// 删除整个链表  
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
// 删除链表中值为data的节点  
void deleteNode(Linklist* list, int data) {
    Node* current = list->head;
    Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev == NULL) { // 要删除的节点是头节点  
            list->head = current->next;
        }
        else {
            prev->next = current->next;
        }
        free(current);
        printf("节点已成功删除。\n");
    }
    else {
        printf("链表中不存在值为%d的节点。\n", data);
    }
}
// 找到链表的中点  
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
        // 空链表或只有一个节点的链表，无需反转  
        return list;
    }

    Node* prev = NULL;  // 用于指向前一个节点的指针  
    Node* cur = list->head; // 当前节点  

    while (cur != NULL) {
        Node* nextTemp = cur->next; // 保存下一个节点  
        cur->next = prev; // 反转当前节点的next指针  
        prev = cur; // 将prev向前移动一步  
        cur = nextTemp; // 将cur向前移动一步  
    }

    // 反转完成后，prev会指向新的头节点  
    list->head = prev;

    return list;
}


// 打印菜单  
void printMenu() {
    printf("请输入对应数字\n");
    printf("1.创建一个空链表\n");
    printf("2.插入结点\n");
    printf("3.打印链表\n");
    printf("4.删除该链表\n");
    printf("5.删除某个节点\n");
    printf("6.找到链表中点\n");
    printf("7.奇偶互换（还不太行）\n");
    printf("8.反转链表\n");
    printf("9.退出\n");
}
