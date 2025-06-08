/*
============================================================================
Name        : Matrix Multiplication in C
Description : This program performs matrix multiplication for two user-input 
              matrices. It checks compatibility and multiplies two matrices 
              using the standard triple nested loop approach.

Functional Requirements:
----------------------------------------------------------------------------
1. Input:
   - Rows and columns of both matrices.
   - Elements of both matrices.

2. Validation:
   - Ensures matrix multiplication is possible:
     (columns in Matrix A == rows in Matrix B).

3. Computation:
   - Multiplies matrices A[row1][column1] and B[row2][column2]
   - Stores result in matrix C[row1][column2]

4. Output:
   - Displays the resultant matrix after multiplication.

Mathematical Insight:
----------------------------------------------------------------------------
Matrix multiplication is defined only if:
    Columns of A == Rows of B

Formula:
    C[i][j] = Σ (A[i][k] * B[k][j])  for k = 0 to column1 - 1

Time Complexity:
----------------------------------------------------------------------------
- O(row1 × column2 × column1) — standard triple loop algorithm.

Space Complexity:
----------------------------------------------------------------------------
- O(row1 × column1 + row2 × column2 + row1 × column2)

Limitations:
----------------------------------------------------------------------------
- Input size limited by stack memory (use heap for larger matrices).

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

int main()
{
    int row1, column1, row2, column2;

    // Input matrix dimensions
    printf("Rows in first matrix: ");
    scanf("%d", &row1);
    printf("Columns in first matrix: ");
    scanf("%d", &column1);
    printf("Rows in second matrix: ");
    scanf("%d", &row2);
    printf("Columns in second matrix: ");
    scanf("%d", &column2);

    // Validate matrix multiplication rule
    if (column1 != row2)
    {
        printf("Matrix multiplication not possible: Columns of first matrix != Rows of second matrix\n");
    }
    else
    {
        // Declare matrices using VLA (C99+)
        int a[row1][column1], b[row2][column2], c[row1][column2];

        // Input first matrix
        printf("\nEnter elements of First Matrix (%dx%d):\n", row1, column1);
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column1; j++)
            {
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
            }
        }

        // Input second matrix
        printf("\nEnter elements of Second Matrix (%dx%d):\n", row2, column2);
        for (int i = 0; i < row2; i++)
        {
            for (int j = 0; j < column2; j++)
            {
                printf("B[%d][%d]: ", i, j);
                scanf("%d", &b[i][j]);
            }
        }

        // Initialize and multiply
        printf("\nResultant Matrix (%dx%d):\n", row1, column2);
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column2; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < column1; k++) // column1 == row2
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
