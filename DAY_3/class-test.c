#include<stdio.h>
int main()
{
    int r,c;
    scanf("%d%d",&r,&c);

    int matrix[r][c];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("before 90 turn\n ");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nAfter 90 deg turn\n");
    for(int i=0;i<c;i++)
    {
        for(int j=r-1;j>=0;j--)
        {
            printf("%d ",matrix[j][i]);
        }
        printf("\n");
    }
    return 0;

}