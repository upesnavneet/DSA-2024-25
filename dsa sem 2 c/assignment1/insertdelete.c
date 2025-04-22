#include <stdio.h>

int main() 
{
    int n, i, j, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n + 1];
    
    printf("Enter %d elements: ", n);
    for (int k = 0; k < n; k++) 
    {
        scanf("%d", &arr[k]);
    }
    
    printf("Enter position to insert and value: ");
    scanf("%d %d", &i, &value);
    for (int k = n; k > i; k--) 
    {
        arr[k] = arr[k - 1];
    }
    arr[i] = value;
    n++;
    
    printf("Enter position to delete: ");
    scanf("%d", &j);
    for (int k = j; k < n - 1; k++) 
    {
        arr[k] = arr[k + 1];
    }
    n--;
    
    printf("Final array: ");
    for (int k = 0; k < n; k++) 
    {
        printf("%d ", arr[k]);
    }
    printf("\n");
    
    return 0;
}