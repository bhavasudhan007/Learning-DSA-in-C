#include<stdio.h>

int n=0;
int main()
{
    n++;
    if(n==5)
    {
        return 0;
    }
    printf("%d\n",n);
    

    main();
    return 0;

}