#include <stdio.h>

typedef struct s_s
{
    int a;
    int b;
}   t_s;

int main(void)
{
    t_s s1, s2, s3;

    s1.a = 1;
    s1.b = 2;

    s2 = s1;
    printf("%d %d\n", s2.a, s2.b);

    s3 = (t_s){3, 4};
    printf("%d %d\n", s3.a, s3.b);
}