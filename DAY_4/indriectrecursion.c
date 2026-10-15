#include<stdio.h>
void b(int n);
void a(int n)
{
    if(n>10){
    return;
    }
    printf("%d",n);
    b(n+1);

}

void b(int n)
{
    if(n>10)
    {
        return;
    }
    printf("%d",n);
    a(n+1);

}

int main()
{
    b(0);

    return 0;
}