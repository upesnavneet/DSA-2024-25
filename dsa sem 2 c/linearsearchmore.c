//linear search
//date: 9/1/25
#include <stdio.h>

int main() 
{
    int n =20, t, i, j = 0, loc[20];
    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &t);

    for(i=0; i<20; i=i+1)
      {
        if (arr[i] == t)
        {
        loc[j]=i+1;
        j++;
        }
      }
    if(j==0)
    printf("Element not present");
    else
    {
           for(i=0; i<j-1;i++)
           {
                printf("element is present at location %d\n", loc[i]);
           }
    }
}