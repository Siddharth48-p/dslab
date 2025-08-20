/*Implement a C program to read, display, and find the product of two matrices using
functions with appropriate parameters.
• The matrices must be created using dynamic memory allocation (malloc or
calloc).
• Access matrix elements using array dereferencing (i.e., *(*(mat + i) + j)
style).*/
#include <stdio.h>
#include <stdlib.h>
// Function prototypes
int** allocateMatrix(int rows, int cols);
void freeMatrix(int** mat, int rows);
void readMatrix(int** mat, int rows, int cols);
void displayMatrix(int** mat, int rows, int cols);
int** multiplyMatrices(int** mat1, int r1, int c1, int** mat2, int r2, int c2);

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible. Columns of first must be equal to rows of second.\n");
        return 1;
    }

    // Allocate matrices
    int **mat1 = allocateMatrix(r1, c1);
    int **mat2 = allocateMatrix(r2, c2);

    // Read matrices
    printf("Enter elements of first matrix:\n");
    readMatrix(mat1, r1, c1);

    printf("Enter elements of second matrix:\n");
    readMatrix(mat2, r2, c2);

    // Display matrices
    printf("First matrix:\n");
    displayMatrix(mat1, r1, c1);

    printf("Second matrix:\n");
    displayMatrix(mat2, r2, c2);

    // Multiply matrices
    int **product = multiplyMatrices(mat1, r1, c1, mat2, r2, c2);

    printf("Product matrix:\n");
    displayMatrix(product, r1, c2);

    // Free memory
    freeMatrix(mat1, r1);
    freeMatrix(mat2, r2);
    freeMatrix(product, r1);

    return 0;
}

// Function to dynamically allocate a matrix of size rows x cols
int** allocateMatrix(int rows, int cols) {
    int **mat = (int**)malloc(rows * sizeof(int*));
    if (mat == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        *(mat + i) = (int*)malloc(cols * sizeof(int));
        if (*(mat + i) == NULL) {
            printf("Memory allocation failed\n");
            // Free previously allocated rows
            for (int j = 0; j < i; j++)
                free(*(mat + j));
            free(mat);
            exit(EXIT_FAILURE);
        }
    }
    return mat;
}

// Function to free allocated matrix memory
void freeMatrix(int** mat, int rows) {
    for (int i = 0; i < rows; i++) {
        free(*(mat + i));
    }
    free(mat);
}

// Function to read matrix elements
void readMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", (*(mat + i) + j));
        }
    }
}

// Function to display matrix elements
void displayMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

// Function to multiply two matrices and return the product matrix
int** multiplyMatrices(int** mat1, int r1, int c1, int** mat2, int r2, int c2) {
    int **result = allocateMatrix(r1, c2);

    // Initialize result matrix elements to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(*(result + i) + j) = 0;
        }
    }

    // Multiply matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                *(*(result + i) + j) += (*(*(mat1 + i) + k)) * (*(*(mat2 + k) + j));
            }
        }
    }

    return result;
}

