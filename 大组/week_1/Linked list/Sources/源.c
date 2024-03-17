#include <stdio.h>
#include <stdlib.h>
#include "adt.h"  
int main() {
    int a = 0;
    Linklist* list = NULL; // 用于保存链表指针  
    int data;
    printMenu();
    while (1) {
        printf("请输入对应数字(1-7):");
        scanf_s("%d", &a);
        getchar(); // 清除输入缓冲区中的换行符  
        switch (a) {
        case 1:
            if (list == NULL) {
                list = createLinklist();
                printf("空链表创建成功\n");
            }
            else {
                printf("链表已存在\n");
            }
            break;
        case 2:
            if (list != NULL) {
                printf("请输入要插入的数据：");
                scanf_s("%d", &data);
                append(list, data);
            }
            else {
                printf("请先创建链表\n");
            }
            break;
        case 3:
            if (list != NULL) {
                printf("链表内容为：\n");
                Node* tempNode = list->head;
                while (tempNode != NULL) {
                    printf("%d ", tempNode->data);
                    tempNode = tempNode->next;
                }
                printf("\n");
            }
            else {
                printf("链表为空\n");
            }
            break;
        case 4:
            if (list != NULL) {
                DeleteLinklist(list);
                printf("链表已删除\n");
                list = NULL; // 释放链表后，将指针设为NULL  
            }
            else {
                printf("链表为空，无需删除\n");
            }
            break;
        case 5: // 删除节点  
            if (list != NULL) {
                printf("请输入要删除的节点的数据值: ");
                scanf_s("%d", &data);
                deleteNode(list, data);
            }
            else {
                printf("请先创建链表\n");
            }
            break;
        case 6: // 找到链表的中点  
            if (list != NULL) {
                Node* middle = findMiddle(list);
                if (middle != NULL) {
                    printf("链表的中点数据值: %d\n", middle->data);
                }
                else {
                    printf("链表为空或只有一个节点\n");
                }
            }
            else {
                printf("请先创建链表\n");
            }
            break;
        case 7:
            if (list != NULL) {
                DeleteLinklist(list);
                list = NULL; // 退出前确保释放链表内存  
            }
            printf("程序退出\n");
            return 0;
        default:
            printf("无效的选择，请重新输入\n");
        }
    }
    return 0;
}