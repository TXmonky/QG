#include"queue.h"

void initQueue(Queue* q) {
    q->head = q->tail = NULL;
    q->size = 0;
}

void enqueue(Queue* q, GenericData data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (q->tail) {
        q->tail->next = newNode;
    }
    else {
        q->head = newNode;
    }
    q->tail = newNode;
    q->size++;
}

GenericData dequeue(Queue* q) {
    if (q->head == NULL) {
        GenericData emptyData = { {0}, UNKNOWN_TYPE };
        return emptyData;
    }

    Node* temp = q->head;
    GenericData data = temp->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    q->size--;
    return data;
}
void printQueue(Queue* q) {
    Node* current = q->head;
    while (current) {
        switch (current->data.type) {
        case INT_TYPE:
            printf("%d ", current->data.data.intValue);
            break;
        case FLOAT_TYPE:
            printf("%f ", current->data.data.floatValue);
            break;
        case CHAR_TYPE:
            printf("%c ", current->data.data.charValue);
            break;
        default:
            printf("Unknown type\n");
            break;
        }
        current = current->next;
    }
    printf("\n");
}