#ifndef _CALCUTOR_H_
#define _CALCUTOR_H_

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>

#define ERROR 0
#define OK 1
#define STACK_INT_SIZE 10  /*�洢�ռ��ʼ������*/
#define STACKINCREMENT 5  /*�洢�ռ��������*/
#define M 50

typedef char ElemType; /*�����ַ���������*/
typedef double ElemType2;  /*������������������*/

/*�ַ�ջ*/
typedef struct {
    ElemType* base;
    ElemType* top;
    int stacksize;
}SqStack;

/*������ջ*/
typedef struct {
    ElemType2* base;
    ElemType2* top;
    int stacksize;
}NStack;

int InitStack(SqStack* S);   /*�����ջ*/
int push(SqStack* S, ElemType e); /*��ջ*/
int Pop(SqStack* S, ElemType* e);  /*��ջ*/
int StackEmpty(SqStack* s);  /*ջ���ж�*/
void in2post(ElemType* str, ElemType* p);  /*��׺���ʽת��׺���ʽ*/
double cal_post(char* str);  /*�����׺���ʽ*/

#endif // !_CALCUTOR_H_

