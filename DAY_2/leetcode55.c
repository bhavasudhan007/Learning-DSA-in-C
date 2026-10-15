#include<stdio.h>
#include <stdbool.h>
bool canJump(int* nums, int numsSize) {
    int reach = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > reach)
            return false;

        if (i + nums[i] > reach)
            reach = i + nums[i];
    }

    return true;
}
int main()
{
    int arr[10];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    bool h=canJump(arr,n);
    printf("%s",h ? "true":"false");
    return 0;
}