
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = matrixColSize[0];
    int *res = malloc(m * n * sizeof(int));
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int k = 0;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            res[k++] = matrix[top][j];
        top++;

        for (int i = top; i <= bottom; i++)
            res[k++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                res[k++] = matrix[bottom][j];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                res[k++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = k;
    return res;
}
int main()
{
    int row;
    int col;
    scanf("%d",&row);
    scanf("%d",&col);

    int martix[row][col];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&martix[i][j]);
        }
    }
    int *size[100][100];
    size = spiralOrder(martix,row,col,row*col);
    for(int i=0;i<row*col;i++)
    {
        printf("%d",size[i]);
    }
    return 0;
}