#include "calculator.h"

int main()
{
    char str[M];
    char post[M];
    int i;
    printf("\n输入一串中缀表达式：(好好输入，我不健壮）\n");
    gets(str);
    printf("\n对应的后缀表达式：\n");
    in2post(str, post);
    printf("%s", post);
    printf("\n\n计算后缀表达式：\n");
    printf("%f", cal_post(post));
    getchar();
    return 0;
}

