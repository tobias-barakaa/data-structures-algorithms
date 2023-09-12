// The question
// Design, implement, and test a function that performs matrix multi-
// plication. What is its complexity?

#include <stdio.h>
#include <stdlib.h>

// Function to perform matrix multiplication
int** matrixMultiply(int** A, int** B, int numRowsA, int numColsA, int numColsB) {
    int** result = (int**)malloc(numRowsA * sizeof(int*));

    for (int i = 0; i < numRowsA; i++) {
        result[i] = (int*)malloc(numColsB * sizeof(int));
    }

    for (int i = 0; i < numRowsA; i++) {
        for (int j = 0; j < numColsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < numColsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(int** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example matrices
    int numRowsA = 2, numColsA = 3, numRowsB = 3, numColsB = 2;

    int** A = (int**)malloc(numRowsA * sizeof(int*));
    for (int i = 0; i < numRowsA; i++) {
        A[i] = (int*)malloc(numColsA * sizeof(int));
    }

    int** B = (int**)malloc(numRowsB * sizeof(int*));
    for (int i = 0; i < numRowsB; i++) {
        B[i] = (int*)malloc(numColsB * sizeof(int));
    }

    // Initialize matrices A and B

    // Call the matrixMultiply function
    int** result = matrixMultiply(A, B, numRowsA, numColsA, numColsB);

    // Print the result matrix
    printMatrix(result, numRowsA, numColsB);

    // Free allocated memory
    for (int i = 0; i < numRowsA; i++) {
        free(A[i]);
    }
    free(A);

    for (int i = 0; i < numRowsB; i++) {
        free(B[i]);
    }
    free(B);

    for (int i = 0; i < numRowsA; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
