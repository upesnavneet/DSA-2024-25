#include <stdio.h>

int sumArray(int arr[], int n) 
{
    if (n <= 0)
        return 0;
    else
        return arr[n - 1] + sumArray(arr, n - 1);
}

void main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    int sum = sumArray(arr, n);
    printf("Sum of array elements: %d\n", sum);
}