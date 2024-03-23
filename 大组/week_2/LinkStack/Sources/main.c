#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include "LinkStack.h"  

// ������  
int main() {
    LinkStack stack = NULL; // ��ʼ��һ����ջ  
    DataType type;
    void* data;
    int choice;
    int value;
    float fvalue;
    char cvalue;

    do {
        PrintfMenu();
        printf("���������ѡ��: ");
        scanf_s("%d", &choice);
        getchar(); // ������뻺�����еĻ��з�  

        switch (choice) {
        case 1:
            // ��ʼ����ջ  
            stack = InitStack();
            printf("��ջ�ѳ�ʼ��\n");
            break;

        case 2:
            // ��ջ����  
            printf("��������������(INT/FLOAT/CHAR): ");
            char typeStr[10];
            fgets(typeStr, sizeof(typeStr), stdin); // ʹ��fgets��ȡһ������  
            typeStr[strcspn(typeStr, "\n")] = 0; // ȥ�����з�  

            if (strcmp(typeStr, "INT") == 0) {
                type = INT;
                printf("������һ������: ");
                scanf_s("%d", &value);
                getchar(); // ������뻺�����еĻ��з�  
                Push(&stack, &value, INT);
            }
            else if (strcmp(typeStr, "FLOAT") == 0) {
                type = FLOAT;
                printf("������һ��������: ");
                scanf_s("%f", &fvalue);
                getchar(); // ������뻺�����еĻ��з�  
                Push(&stack, &fvalue, FLOAT);
            }
            else if (strcmp(typeStr, "CHAR") == 0) {
                type = CHAR;
                printf("������һ���ַ�: ");
                scanf_s(" %c", &cvalue);
                Push(&stack, &cvalue, CHAR);
            }
            else {
                printf("��Ч���������ͣ�������INT/FLOAT/CHAR\n");
            }
            break;

        case 3:
            // ��ջ����  
            if (Pop(&stack, &data, &type) == 0) {
                switch (type) {
                case INT:
                    printf("��ջ������: %d\n", *((int*)data));
                    break;
                case FLOAT:
                    printf("��ջ�ĸ�����: %f\n", *((float*)data));
                    break;
                case CHAR:
                    printf("��ջ���ַ�: %c\n", *((char*)data));
                    break;
                default:
                    printf("δ֪����������\n");
                    break;
                }
            }
            else {
                printf("ջΪ�գ��޷���ջ\n");
            }
            break;

        case 4:
            // ��ӡջ����  
            printStack(stack);
            break;

        case 5:
            // ������ջ  
            DestroyStack(&stack);
            printf("��ջ������\n");
            break;

        case 6:
            // �˳�����  
            printf("�������˳�\n");
            break;

        default:
            printf("��Ч��ѡ������������\n");
            break;
        }
    } while (choice != 6);

    return 0;
}