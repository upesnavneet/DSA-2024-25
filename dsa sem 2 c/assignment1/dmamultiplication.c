#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int r1, c1, r2, c2;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);
    
    if (c1 != r2) 
    {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }
    
    int **A = (int **)malloc(r1 * sizeof(int *));
    int **B = (int **)malloc(r2 * sizeof(int *));
    int **C = (int **)malloc(r1 * sizeof(int *));
    
    for (int i = 0; i < r1; i++) 
    {
        A[i] = (int *)malloc(c1 * sizeof(int));
        C[i] = (int *)malloc(c2 * sizeof(int));
    }
    for (int i = 0; i < r2; i++) 
    {
        B[i] = (int *)malloc(c2 * sizeof(int));
    }
    
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    printf("Product matrix:\n");
    for (int i = 0; i < r1; i++) 
    {
        for (int j = 0; j < c2; j++) 
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < r1; i++) 
    {
        free(A[i]);
        free(C[i]);
    }
    for (int i = 0; i < r2; i++) 
    {
        free(B[i]);
    }
    free(A);
    free(B);
    free(C);
}

