#include "calculator.h"
/*�ַ�ջ��ʼ��*/
int InitStack(SqStack* S) {
    S->base = (ElemType*)malloc(STACK_INT_SIZE * sizeof(ElemType));
    if (!S->base)
        return ERROR;  //����ʧ��
    S->top = S->base;
    S->stacksize = STACK_INT_SIZE;
    return OK;
}/*InitStack*/

/*������ջ��ʼ��*/
int InitStack_N(NStack* S) {
    S->base = (ElemType2*)malloc(STACK_INT_SIZE * sizeof(ElemType2));
    if (!S->base)
        return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INT_SIZE;
    return OK;
}

/*�ַ�ջ��ջ*/
int Push(SqStack* S, ElemType e) {
    //�ж�ջ��
    if (S->top - S->base >= S->stacksize) {
        S->base = (ElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (NULL == S->base)  //����ʧ��
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize = S->stacksize + STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
    return OK;
}

/*������ջ��ջ*/
int Push_N(NStack* S, ElemType2 e) {
    if (S->top - S->base >= S->stacksize) {
        S->base = (ElemType2*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType2));
        if (NULL == S->base)
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize = S->stacksize + STACKINCREMENT;
    }
    *S->top = e;
    S->top++;
    return OK;
}

/*�ַ�ջ��ջ*/
int Pop(SqStack* S, ElemType* e) {
    //�ж�ջ��
    if (S->top == S->base)
        return ERROR;
    S->top--;
    *e = *S->top;
    return OK;
}/*Pop*/

/*������ջ��ջ*/
int Pop_N(NStack* S, ElemType2* e) {
    if (S->top == S->base)
        return ERROR;
    S->top--;
    *e = *S->top;
    return OK;
}

/*�ж�ջ��*/
int StackEmpty(SqStack* s) {
    if (s->top == s->base)
        return OK;
    return ERROR;
}/*StackEmpty*/

//strΪ��ת������׺���ʽ�ַ���,pΪת����ĺ�׺���ʽ�ַ���
void in2post(ElemType* str, ElemType* p) {   /*infix to postfix*/
    //��ʼ��һ����ջ
    SqStack s;
    InitStack(&s);
    ElemType e;

    int i;
    int j = 0;
    for (i = 0; i < strlen(str); i++)  //������׺���ʽ
    {
        if ('-' == str[i])    //��������ж�
        {
            //���ʽ��λ��'-',��һ������Ϊ��������
            if (0 == i)
                p[j++] = str[i++];
            //'-'ǰ����'(',��һ������Ϊ��������
            else if ('(' == str[i - 1])
                p[j++] = str[i++];
        }


        //�������ֺ�С����ֱ�����
        while (isdigit(str[i]) || '.' == str[i])
        {
            p[j++] = str[i++];
            if (!isdigit(str[i]) && '.' != str[i])
                p[j++] = ' ';   //һ���������������ʹ�ÿո�����������������ַָ���
        }

        //����������ֱ����ջ
        if ('(' == str[i])
            Push(&s, str[i]);

        //����������ֱ�ӳ�ջ��ֱ�������ų�ջ(�����Ų����)
        if (')' == str[i])
        {
            while ('(' != *(s.top - 1))
            {
                Pop(&s, &e);
                p[j++] = e;
                p[j++] = ' ';
            }
            Pop(&s, &e);  //�����ų�ջ�������
        }

        //����+��
        //1.ջ��/ջ��Ϊ������:ֱ����ջ
        //2.����һֱ��ջ,ֱ��ջ��/ջ��Ϊ������,����ջ
        if ('+' == str[i] || '-' == str[i])
        {
            while (!StackEmpty(&s) && '(' != *(s.top - 1))  //ջ�ǿ� �� ջ����������
            {
                Pop(&s, &e);
                p[j++] = e;
                p[j++] = ' ';
            }
            Push(&s, str[i]);
        }

        //����*��/
        //1.ջ��/ջ��Ϊ������/ջ��������Ϊ+ or -:ֱ����ջ
        //2.����һֱ��ջ,ֱ������1,����ջ
        if ('*' == str[i] || '/' == str[i] || '%' == str[i])
        {
            while (!StackEmpty(&s) && '(' != *(s.top - 1) && '+' != *(s.top - 1) && '-' != *(s.top - 1))
            {
                Pop(&s, &e);
                p[j++] = e;
                p[j++] = ' ';
            }
            Push(&s, str[i]);
        }
    }
    //��׺���ʽ�������,������ջ���Ƿ���δ����ַ�
    //�ж�ջ��,�ǿ���ֱ�ӳ�ջ�����(�����Ų������)
    while (!StackEmpty(&s)) {
        Pop(&s, &e);
        if ('(' != e)
        {
            p[j++] = e;
            p[j++] = ' ';
        }
    }
    p[--j] = '\0';
}


//strΪ������ĺ�׺���ʽ,����ֵΪ������
double cal_post(char* str) {
    ElemType2 e, a, b;
    char d[M];
    //��ʼ��һ��������ջ����������
    NStack n;
    InitStack_N(&n);
    int i = 0;
    int j = 0;
    while (str[i])  //������׺���ʽ
    {
        switch (str[i])
        {
        case '-':
            if (isdigit(str[i + 1]))  //�ж�'-'����Ϊ��������or�����
            {
                d[j++] = str[i++];  //�����ż����������ַ���
                d[j] = '\0';
                break;  //ע:�����breakֻ������switchѭ��
            }
            else
            {
                Pop_N(&n, &b);
                Pop_N(&n, &a);
                Push_N(&n, a - b);
                i++;
                break;
            }
        case '+':
            Pop_N(&n, &b);
            Pop_N(&n, &a);
            Push_N(&n, a + b);
            i++;
            break;
        case '*':
            Pop_N(&n, &b);
            Pop_N(&n, &a);
            Push_N(&n, a * b);
            i++;
            break;
        case '/':
            Pop_N(&n, &b);
            Pop_N(&n, &a);
            Push_N(&n, a / b);
            i++;
            break;
        case ' ':i++;
        }

        //����������ֱ����ջ(��ת��double����)
        //d�����׺���ʽ�е��ַ�����ʽ��������
        //ʹ��atof���ַ���ת��Ϊdouble����
        while (isdigit(str[i]) || '.' == str[i])
        {
            d[j++] = str[i++];
            d[j] = '\0';
            if (' ' == str[i])
            {
                e = atof(d);  //��ʱ�������ľ���������������
                Push_N(&n, e);
                i++;
                j = 0;
            }
        }
    }
    Pop_N(&n, &e);
    return e;
}