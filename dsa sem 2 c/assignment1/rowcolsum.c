#include <stdio.h>

void main() 
{
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int matrix[rows][cols];
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("Row sums:\n");
    for (int i = 0; i < rows; i++) 
    {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) 
        {
            rowSum += matrix[i][j];
        }
        printf("Row %d sum: %d\n", i + 1, rowSum);
    }
    
    printf("Column sums:\n");
    for (int j = 0; j < cols; j++) 
    {
        int colSum = 0;
        for (int i = 0; i < rows; i++) 
        {
            colSum += matrix[i][j];
        }
        printf("Column %d sum: %d\n", j + 1, colSum);
    }
}