
#include <stdio.h>
int main() {
    int A[3][3], B[3][3], result[3][3];
    int r1, c1, r2, c2;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);
    if (r1 < 1 || r1 > 3 || c1 < 1 || c1 > 3 ||
        r2 < 1 || r2 > 3 || c2 < 1 || c2 > 3) {
        printf("Invalid dimensions! Maximum size is 3x3.\n");
        return 0;
    }
    if (c1 != r2) {
        printf("Matrix multiplication is not possible!\n");
        return 0;
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
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("First Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("Second Matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("Result Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
