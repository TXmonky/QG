#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include "LinkStack.h"  

// 主函数  
int main() {
    LinkStack stack = NULL; // 初始化一个空栈  
    DataType type;
    void* data;
    int choice;
    int value;
    float fvalue;
    char cvalue;

    do {
        PrintfMenu();
        printf("请输入操作选项: ");
        scanf_s("%d", &choice);
        getchar(); // 清除输入缓冲区中的换行符  

        switch (choice) {
        case 1:
            // 初始化链栈  
            stack = InitStack();
            printf("链栈已初始化\n");
            break;

        case 2:
            // 入栈操作  
            printf("请输入数据类型(INT/FLOAT/CHAR): ");
            char typeStr[10];
            fgets(typeStr, sizeof(typeStr), stdin); // 使用fgets读取一行输入  
            typeStr[strcspn(typeStr, "\n")] = 0; // 去除换行符  

            if (strcmp(typeStr, "INT") == 0) {
                type = INT;
                printf("请输入一个整数: ");
                scanf_s("%d", &value);
                getchar(); // 清除输入缓冲区中的换行符  
                Push(&stack, &value, INT);
            }
            else if (strcmp(typeStr, "FLOAT") == 0) {
                type = FLOAT;
                printf("请输入一个浮点数: ");
                scanf_s("%f", &fvalue);
                getchar(); // 清除输入缓冲区中的换行符  
                Push(&stack, &fvalue, FLOAT);
            }
            else if (strcmp(typeStr, "CHAR") == 0) {
                type = CHAR;
                printf("请输入一个字符: ");
                scanf_s(" %c", &cvalue);
                Push(&stack, &cvalue, CHAR);
            }
            else {
                printf("无效的数据类型，请输入INT/FLOAT/CHAR\n");
            }
            break;

        case 3:
            // 出栈操作  
            if (Pop(&stack, &data, &type) == 0) {
                switch (type) {
                case INT:
                    printf("出栈的整数: %d\n", *((int*)data));
                    break;
                case FLOAT:
                    printf("出栈的浮点数: %f\n", *((float*)data));
                    break;
                case CHAR:
                    printf("出栈的字符: %c\n", *((char*)data));
                    break;
                default:
                    printf("未知的数据类型\n");
                    break;
                }
            }
            else {
                printf("栈为空，无法出栈\n");
            }
            break;

        case 4:
            // 打印栈内容  
            printStack(stack);
            break;

        case 5:
            // 销毁链栈  
            DestroyStack(&stack);
            printf("链栈已销毁\n");
            break;

        case 6:
            // 退出程序  
            printf("程序已退出\n");
            break;

        default:
            printf("无效的选择，请重新输入\n");
            break;
        }
    } while (choice != 6);

    return 0;
}