#include <stdio.h>

void f(int **pp)
{
    *pp = (int*)0xFFFFFFFF;
}

int main(void)
{
    int i = 9;
    int *p = &i;
    printf("%p\n", p);
    f(&p); 
    printf("%p\n", p);

}