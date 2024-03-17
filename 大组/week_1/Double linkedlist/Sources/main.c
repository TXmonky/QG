#include "DOUBLE.h" 

// ... 双向链表的结构和函数声明 ...  

int main() {
    int choice, pos, value;
    DuLinkedList head = NULL; // 初始化为NULL  
    int flag = 0; // 标记链表是否已初始化 
    printf("\n---------------------------\n");
    printf(">>> 1.新建一个双向链表.               \n");
    printf(">>> 2.打印链表.               \n");
    printf(">>> 3.插入节点.              \n");
    printf(">>> 4.删除节点.             \n");
    printf(">>> 5.查询节点.              \n");
    printf(">>> 6.退出.                \n");
    printf("---------------------------\n");
    

    while (1) { 
        printf("请输入你的选择：");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            if (flag) {
                printf("链表已存在，请先销毁当前链表或选择其他操作。\n");
            }
            else {
                head = CreateDuLinkedList();
                flag = 1;
                printf("双向链表已创建。\n");
            }
            break;
        case 2:
            if (flag) {
                TraverseList_DuL(head, PrintNode);
            }
            else {
                printf("链表未初始化，请先创建链表。\n");
            }
            break;
        case 3:
            if (flag) {
                printf("请输入要插入的位置和值(中间空格)：");
                scanf_s("%d %d", &pos, &value);
                InsertNode_DuL(&head, pos, value);
                printf("节点已插入。\n");
            }
            else {
                printf("链表未初始化，请先创建链表。\n");
            }
            break;
        case 4:
            if (flag) {
                printf("请输入要删除的节点值：");
                scanf_s("%d", &value);
                DeleteNode_DuL(&head, value);
                printf("节点已删除（如果存在）。\n");
            }
            else {
                printf("链表未初始化，请先创建链表。\n");
            }
            break;
        case 5:
            if (flag) {
                int value;
                printf("请输入要查询的节点值：");
                scanf_s("%d", &value);
                SearchNode_DuL(head, value);
            }
            else {
                printf("链表未初始化，请先创建链表。\n");
            }
            break;
        case 6:
            if (flag) {
                FreeDuLinkedList(&head);
                printf("双向链表已销毁。\n");
            }
            flag = 0; // 重置标记  
            printf("程序退出。\n");
            return 0;
        default:
            printf("无效的选择，请重新输入。\n");
        }
    }

    return 0;
}