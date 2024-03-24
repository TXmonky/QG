#include"queue.h"

int main() {
    Queue q;
    initQueue(&q);
    int choice;

    do {
        printf("\n请选择操作：\n");
        printf("1. 入队整数\n");
        printf("2. 入队浮点数\n");
        printf("3. 入队字符\n");
        printf("4. 出队\n");
        printf("5. 显示队列\n");
        printf("6. 退出\n");
        printf("请输入你的选择：");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: { // 入队整数  
            int value;
            printf("请输入要入队的整数：");
            if (scanf_s("%d", &value) != 1) {
                printf("输入错误，请输入一个整数。\n");
                while (getchar() != '\n'); // 清除输入缓冲区  
                continue; // 重新回到循环开始处  
            }
            GenericData data = { {.intValue = value}, INT_TYPE };
            enqueue(&q, data);
            break;
        }
        case 2: { // 入队浮点数  
            float value;
            printf("请输入要入队的浮点数：");
            if (scanf_s("%f", &value) != 1) {
                printf("输入错误，请输入一个浮点数。\n");
                while (getchar() != '\n'); // 清除输入缓冲区  
                continue; // 重新回到循环开始处  
            }
            GenericData data = { {.floatValue = value}, FLOAT_TYPE };
            enqueue(&q, data);
            break;
        }
        case 3: { // 入队字符  
            char value;
            printf("请输入要入队的字符：");
            if (scanf_s(" %c", &value) != 1) {
                printf("输入错误，请输入一个字符。\n");
                while (getchar() != '\n'); // 清除输入缓冲区  
                continue; // 重新回到循环开始处  
            }
            GenericData data = { {.charValue = value}, CHAR_TYPE };
            enqueue(&q, data);
            break;
        }
        case 4: { // 出队  
            GenericData data = dequeue(&q);
            switch (data.type) {
            case INT_TYPE:
                printf("出队的整数是：%d\n", data.data.intValue);
                break;
            case FLOAT_TYPE:
                printf("出队的浮点数是：%f\n", data.data.floatValue);
                break;
            case CHAR_TYPE:
                printf("出队的字符是：%c\n", data.data.charValue);
                break;
            default:
                printf("未知类型\n");
                break;
            }
            break;
        }
        case 5: { // 显示队列内容  
            printf("队列内容：\n");
            printQueue(&q);
            break;
        }
        case 6: { // 退出程序  
            printf("退出程序。\n");
            break;
        }
        default: { // 无效的选择  
            printf("无效的选择，请重新输入。\n");
            break;
        }
        }
    } while (choice != 6);

    // 清理队列内存  
    Node* current = q.head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}