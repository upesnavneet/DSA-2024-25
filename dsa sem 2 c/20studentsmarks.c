//9/1/25

#include <stdio.h>
#include <ctype.h>

void main()
{
    int n=20;
    float arr[n];

    for(int i=0; i<n; i=i+1)
    {
        printf("Enter the marks of %d student: ", i+1);
        scanf("%f", &arr[i]);
    }

    float s = 0;
    for(int i=0; i<n; i=i+1)
    {
        s = s + arr[i];
    }

    printf("Sum of array: %f", s);


}