//5. Write a program to multiply two matrices. Before multiplication, verify whether the given matrices are compatible.
#include <stdio.h>

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check whether matrices are compatible
    if (c1 != r2) { 
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++) // Loop through rows of first matrix
        for (j = 0; j < c1; j++)  // Loop through columns of first matrix
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++)  // Loop through rows of second matrix
        for (j = 0; j < c2; j++)  // Loop through columns of second matrix
            scanf("%d", &b[i][j]);

    // Multiply matrices
    for (i = 0; i < r1; i++) {  // Loop through rows of first matrix
        for (j = 0; j < c2; j++) {  // Loop through columns of second matrix
            result[i][j] = 0;

            for (k = 0; k < c1; k++) {  // Loop through columns of first matrix (or rows of second matrix)
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");
    for (i = 0; i < r1; i++) {  // Loop through rows of resultant matrix
        for (j = 0; j < c2; j++)  //    Loop through columns of resultant matrix
            printf("%d ", result[i][j]); 
        printf("\n");
    }

    return 0;
}