#include <stdio.h>
#include <stdlib.h>
#include "adt.h"  
int main() {
    int a = 0;
    Linklist* list = NULL; // ���ڱ�������ָ��  
    int data;
    printMenu();
    while (1) {
        printf("�������Ӧ����(1-7):");
        scanf_s("%d", &a);
        getchar(); // ������뻺�����еĻ��з�  
        switch (a) {
        case 1:
            if (list == NULL) {
                list = createLinklist();
                printf("���������ɹ�\n");
            }
            else {
                printf("�����Ѵ���\n");
            }
            break;
        case 2:
            if (list != NULL) {
                printf("������Ҫ��������ݣ�");
                scanf_s("%d", &data);
                append(list, data);
            }
            else {
                printf("���ȴ�������\n");
            }
            break;
        case 3:
            if (list != NULL) {
                printf("��������Ϊ��\n");
                Node* tempNode = list->head;
                while (tempNode != NULL) {
                    printf("%d ", tempNode->data);
                    tempNode = tempNode->next;
                }
                printf("\n");
            }
            else {
                printf("����Ϊ��\n");
            }
            break;
        case 4:
            if (list != NULL) {
                DeleteLinklist(list);
                printf("������ɾ��\n");
                list = NULL; // �ͷ�����󣬽�ָ����ΪNULL  
            }
            else {
                printf("����Ϊ�գ�����ɾ��\n");
            }
            break;
        case 5: // ɾ���ڵ�  
            if (list != NULL) {
                printf("������Ҫɾ���Ľڵ������ֵ: ");
                scanf_s("%d", &data);
                deleteNode(list, data);
            }
            else {
                printf("���ȴ�������\n");
            }
            break;
        case 6: // �ҵ�������е�  
            if (list != NULL) {
                Node* middle = findMiddle(list);
                if (middle != NULL) {
                    printf("������е�����ֵ: %d\n", middle->data);
                }
                else {
                    printf("����Ϊ�ջ�ֻ��һ���ڵ�\n");
                }
            }
            else {
                printf("���ȴ�������\n");
            }
            break;
        case 7:
            if (list != NULL) {
                DeleteLinklist(list);
                list = NULL; // �˳�ǰȷ���ͷ������ڴ�  
            }
            printf("�����˳�\n");
            return 0;
        default:
            printf("��Ч��ѡ������������\n");
        }
    }
    return 0;
}