/*
============================================================================
Name        : Matrix Operations in C
Description : This program performs addition, subtraction, and transpose 
              operations on two user-input matrices of the same dimensions.

Functional Requirements:
----------------------------------------------------------------------------
1. Input:
   - Number of rows and columns.
   - Elements of Matrix A and Matrix B.

2. Operations:
   - Matrix Addition: A + B
   - Matrix Subtraction: A - B
   - Transpose of Matrix A and B

3. Output:
   - Resultant matrix after each operation.

Constraints:
----------------------------------------------------------------------------
- Maximum matrix size: 100 x 100 (controlled via #define MAX 100)
- Matrices must have the same dimensions for addition and subtraction.

Author      : Roshan Singh
============================================================================
*/

#include <stdio.h>

#define MAX 100 // Maximum allowed matrix dimensions

// Function to take matrix input from the user
void inputMatrix(int mat[MAX][MAX], int row, int col) {
    printf("Enter elements (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
}

// Function to print matrix
void printMatrix(int mat[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res[i][j] = a[i][j] + b[i][j];
}

// Function to subtract two matrices
void subtractMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res[i][j] = a[i][j] - b[i][j];
}

// Function to compute transpose of a matrix
void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            trans[j][i] = mat[i][j];
}

int main() {
    int row, col;
    int a[MAX][MAX], b[MAX][MAX], res[MAX][MAX], trans[MAX][MAX];

    // Input dimensions
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    // Input matrices
    printf("\nMatrix A:\n");
    inputMatrix(a, row, col);

    printf("\nMatrix B:\n");
    inputMatrix(b, row, col);

    // Matrix Addition
    addMatrix(a, b, res, row, col);
    printf("\nAddition of matrices (A + B):\n");
    printMatrix(res, row, col);

    // Matrix Subtraction
    subtractMatrix(a, b, res, row, col);
    printf("\nSubtraction of matrices (A - B):\n");
    printMatrix(res, row, col);

    // Transpose of Matrix A
    transposeMatrix(a, trans, row, col);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(trans, col, row);

    // Transpose of Matrix B
    transposeMatrix(b, trans, row, col);
    printf("\nTranspose of Matrix B:\n");
    printMatrix(trans, col, row);

    return 0;
}
