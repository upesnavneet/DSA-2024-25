//linear search
//date: 9/1/25
#include <stdio.h>
void main() 
{
    int n, t, i, f = 0; //loc[j] for more convenient way

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &t);

    for (i = 0; i < n; i++) 
    {
        if (arr[i] == t) 
        {
            printf("Element found at location: %d ", i+1); //less convenient way
            f = 1;
            break;
        }
    }

    /*for(i=0; i<20; i=i+1)
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
           for(i=0; i,j-1, i++)
           {
                print("element is present at location %d\n", loc[i]);
           }
    }
    }*/

    if (f==0) 
    {
        printf("Element not found in the array\n");
    }
}