#include"queue.h"

int main() {
    Queue q;
    initQueue(&q);
    int choice;

    do {
        printf("\n��ѡ�������\n");
        printf("1. �������\n");
        printf("2. ��Ӹ�����\n");
        printf("3. ����ַ�\n");
        printf("4. ����\n");
        printf("5. ��ʾ����\n");
        printf("6. �˳�\n");
        printf("���������ѡ��");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: { // �������  
            int value;
            printf("������Ҫ��ӵ�������");
            if (scanf_s("%d", &value) != 1) {
                printf("�������������һ��������\n");
                while (getchar() != '\n'); // ������뻺����  
                continue; // ���»ص�ѭ����ʼ��  
            }
            GenericData data = { {.intValue = value}, INT_TYPE };
            enqueue(&q, data);
            break;
        }
        case 2: { // ��Ӹ�����  
            float value;
            printf("������Ҫ��ӵĸ�������");
            if (scanf_s("%f", &value) != 1) {
                printf("�������������һ����������\n");
                while (getchar() != '\n'); // ������뻺����  
                continue; // ���»ص�ѭ����ʼ��  
            }
            GenericData data = { {.floatValue = value}, FLOAT_TYPE };
            enqueue(&q, data);
            break;
        }
        case 3: { // ����ַ�  
            char value;
            printf("������Ҫ��ӵ��ַ���");
            if (scanf_s(" %c", &value) != 1) {
                printf("�������������һ���ַ���\n");
                while (getchar() != '\n'); // ������뻺����  
                continue; // ���»ص�ѭ����ʼ��  
            }
            GenericData data = { {.charValue = value}, CHAR_TYPE };
            enqueue(&q, data);
            break;
        }
        case 4: { // ����  
            GenericData data = dequeue(&q);
            switch (data.type) {
            case INT_TYPE:
                printf("���ӵ������ǣ�%d\n", data.data.intValue);
                break;
            case FLOAT_TYPE:
                printf("���ӵĸ������ǣ�%f\n", data.data.floatValue);
                break;
            case CHAR_TYPE:
                printf("���ӵ��ַ��ǣ�%c\n", data.data.charValue);
                break;
            default:
                printf("δ֪����\n");
                break;
            }
            break;
        }
        case 5: { // ��ʾ��������  
            printf("�������ݣ�\n");
            printQueue(&q);
            break;
        }
        case 6: { // �˳�����  
            printf("�˳�����\n");
            break;
        }
        default: { // ��Ч��ѡ��  
            printf("��Ч��ѡ�����������롣\n");
            break;
        }
        }
    } while (choice != 6);

    // ��������ڴ�  
    Node* current = q.head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}