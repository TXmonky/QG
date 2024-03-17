#include "DOUBLE.h" 

// ... ˫������Ľṹ�ͺ������� ...  

int main() {
    int choice, pos, value;
    DuLinkedList head = NULL; // ��ʼ��ΪNULL  
    int flag = 0; // ��������Ƿ��ѳ�ʼ�� 
    printf("\n---------------------------\n");
    printf(">>> 1.�½�һ��˫������.               \n");
    printf(">>> 2.��ӡ����.               \n");
    printf(">>> 3.����ڵ�.              \n");
    printf(">>> 4.ɾ���ڵ�.             \n");
    printf(">>> 5.��ѯ�ڵ�.              \n");
    printf(">>> 6.�˳�.                \n");
    printf("---------------------------\n");
    

    while (1) { 
        printf("���������ѡ��");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            if (flag) {
                printf("�����Ѵ��ڣ��������ٵ�ǰ�����ѡ������������\n");
            }
            else {
                head = CreateDuLinkedList();
                flag = 1;
                printf("˫�������Ѵ�����\n");
            }
            break;
        case 2:
            if (flag) {
                TraverseList_DuL(head, PrintNode);
            }
            else {
                printf("����δ��ʼ�������ȴ�������\n");
            }
            break;
        case 3:
            if (flag) {
                printf("������Ҫ�����λ�ú�ֵ(�м�ո�)��");
                scanf_s("%d %d", &pos, &value);
                InsertNode_DuL(&head, pos, value);
                printf("�ڵ��Ѳ��롣\n");
            }
            else {
                printf("����δ��ʼ�������ȴ�������\n");
            }
            break;
        case 4:
            if (flag) {
                printf("������Ҫɾ���Ľڵ�ֵ��");
                scanf_s("%d", &value);
                DeleteNode_DuL(&head, value);
                printf("�ڵ���ɾ����������ڣ���\n");
            }
            else {
                printf("����δ��ʼ�������ȴ�������\n");
            }
            break;
        case 5:
            if (flag) {
                int value;
                printf("������Ҫ��ѯ�Ľڵ�ֵ��");
                scanf_s("%d", &value);
                SearchNode_DuL(head, value);
            }
            else {
                printf("����δ��ʼ�������ȴ�������\n");
            }
            break;
        case 6:
            if (flag) {
                FreeDuLinkedList(&head);
                printf("˫�����������١�\n");
            }
            flag = 0; // ���ñ��  
            printf("�����˳���\n");
            return 0;
        default:
            printf("��Ч��ѡ�����������롣\n");
        }
    }

    return 0;
}