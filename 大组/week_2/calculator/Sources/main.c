#include "calculator.h"

int main()
{
    char str[M];
    char post[M];
    int i;
    printf("\n����һ����׺���ʽ��(�ú����룬�Ҳ���׳��\n");
    gets(str);
    printf("\n��Ӧ�ĺ�׺���ʽ��\n");
    in2post(str, post);
    printf("%s", post);
    printf("\n\n�����׺���ʽ��\n");
    printf("%f", cal_post(post));
    getchar();
    return 0;
}

