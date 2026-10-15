#include<stdio.h>
int main()
{
    int arr[10];
    int n;
    scanf("%d",&n);
    int h;
    scanf("%d",&h);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int low =0;
    int high =n-1;
    int target=h;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (arr[mid] == target) {
            return mid; 
        }
        
        if (arr[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return -1;
}