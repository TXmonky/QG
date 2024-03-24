#ifndef _QUEUE_H_
#define _QUEUE_H_


#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

typedef enum {
    INT_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE,
    UNKNOWN_TYPE
} DataType;

typedef struct {
    union {
        int intValue;
        float floatValue;
        char charValue;
    } data;
    DataType type;
} GenericData;

typedef struct Node {
    GenericData data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} Queue; 
void initQueue(Queue* q);
void enqueue(Queue* q, GenericData data);
GenericData dequeue(Queue* q);
void printQueue(Queue* q);








#endif