#include "DOUBLE.h"

// �����յ�˫������  
DuLinkedList CreateDuLinkedList() {
    DuLinkedList head = (DuLinkedList)malloc(sizeof(DuNode));
    if (!head) {
        exit(FAILURE);
    }
    head->prev = head;
    head->next = head;
    return head;
}

// ����˫��������ӡÿ���ڵ��ֵ  
void TraverseList_DuL(DuLinkedList head, void (*visit)(DuNode*)) {
    DuNode* current = head->next;
    while (current != head) {
        visit(current);
        current = current->next;
    }
}
// ��ѯ�ڵ�ĺ���  
void SearchNode_DuL(DuLinkedList head, int value) {
    DuNode* current = head;
    int position = 1; // ��1��ʼ�����ڵ��λ��  

    // ����������ҽڵ�  
    while (current != NULL) {
        if (current->data == value) {
            printf("�ҵ�ֵΪ %d �Ľڵ㣬λ��Ϊ��%d\n", value, position);
            return;
        }
        current = current->next;
        position++;
    }

    // �����������������û���ҵ��������δ�ҵ�����Ϣ  
    printf("δ�ҵ�ֵΪ %d �Ľڵ㡣\n", value);
}

// ����ڵ㵽˫�������ָ��λ��  
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

// ɾ��˫�������е�ָ��ֵ�ڵ�  
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

// ���ʺ��������ڴ�ӡ�ڵ�ֵ  
void PrintNode(DuNode* node) {
    printf("%d ", node->data);
}

// ����˫�������ͷ������ڴ�  
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