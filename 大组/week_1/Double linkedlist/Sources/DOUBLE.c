#include "DOUBLE.h"

// 创建空的双向链表  
DuLinkedList CreateDuLinkedList() {
    DuLinkedList head = (DuLinkedList)malloc(sizeof(DuNode));
    if (!head) {
        exit(FAILURE);
    }
    head->prev = head;
    head->next = head;
    return head;
}

// 遍历双向链表并打印每个节点的值  
void TraverseList_DuL(DuLinkedList head, void (*visit)(DuNode*)) {
    DuNode* current = head->next;
    while (current != head) {
        visit(current);
        current = current->next;
    }
}
// 查询节点的函数  
void SearchNode_DuL(DuLinkedList head, int value) {
    DuNode* current = head;
    int position = 1; // 从1开始计数节点的位置  

    // 遍历链表查找节点  
    while (current != NULL) {
        if (current->data == value) {
            printf("找到值为 %d 的节点，位置为：%d\n", value, position);
            return;
        }
        current = current->next;
        position++;
    }

    // 如果遍历完整个链表都没有找到，则输出未找到的消息  
    printf("未找到值为 %d 的节点。\n", value);
}

// 插入节点到双向链表的指定位置  
void InsertNode_DuL(DuLinkedList* head, int pos, int value) {
    DuNode* newNode = (DuNode*)malloc(sizeof(DuNode));
    if (!newNode) {
        exit(FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    DuNode* current = *head;
    int count = 0;
    while (current->next != *head && count < pos - 1) {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// 删除双向链表中的指定值节点  
void DeleteNode_DuL(DuLinkedList* head, int value) {
    DuNode* current = (*head)->next;
    while (current != *head && current->data != value) {
        current = current->next;
    }
    if (current != *head) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
}

// 访问函数，用于打印节点值  
void PrintNode(DuNode* node) {
    printf("%d ", node->data);
}

// 销毁双向链表，释放所有内存  
void FreeDuLinkedList(DuLinkedList* head) {
    DuNode* current = (*head)->next;
    DuNode* temp;
    while (current != *head) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(*head);
    *head = NULL;
}