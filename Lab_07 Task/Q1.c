#include <stdio.h>
int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    if (rows != cols || rows < 1 || rows > 3) {
        printf("Please enter a square matrix of size 1 to 3.\n");
        return 0;
    }
    int matrix[rows][cols];
    int cofactor_matrix[rows][cols];
    int adjoint[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // 1. Transpose
    printf("The transpose of the matrix is:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
    // 2. Determinant
    int det = 0;
    if (rows == 1) {
        det = matrix[0][0];
    }
    else if (rows == 2) {
        det = matrix[0][0] * matrix[1][1]
            - matrix[0][1] * matrix[1][0];
    }
    else if (rows == 3) {
        det = matrix[0][0] *
             (matrix[1][1] * matrix[2][2]
            - matrix[1][2] * matrix[2][1])
            - matrix[0][1] *
             (matrix[1][0] * matrix[2][2]
            - matrix[1][2] * matrix[2][0])
            + matrix[0][2] *
             (matrix[1][0] * matrix[2][1]
            - matrix[1][1] * matrix[2][0]);
    }
    printf("The determinant of the matrix is: %d\n", det);
    // 3. Cofactor matrix
    int minor, cofactor;
    if (rows == 1) {
        cofactor_matrix[0][0] = 1;
    } else if (rows == 2) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                minor = matrix[1 - i][1 - j];
                cofactor = ((i + j) % 2 == 0) ? minor : -minor;
                cofactor_matrix[i][j] = cofactor;
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int sub[4], k = 0;
                for (int r = 0; r < 3; r++) {
                    if (r == i) continue;
                    for (int c = 0; c < 3; c++) {
                        if (c == j) continue;
                        sub[k++] = matrix[r][c];
                    }
                }
                minor = sub[0] * sub[3] - sub[1] * sub[2];
                cofactor = ((i + j) % 2 == 0) ? minor : -minor;
                cofactor_matrix[i][j] = cofactor;
            }
        }
    }
    printf("The cofactor matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", cofactor_matrix[i][j]);
        }
        printf("\n");
    }
    // 4. Adjoint = transpose of cofactor matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            adjoint[i][j] = cofactor_matrix[j][i];
        }
    }
    printf("The adjoint of the matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", adjoint[i][j]);
        }
        printf("\n");
    }
    // 5. Inverse = adjoint / determinant
    if (det == 0) {
        printf("Inverse does not exist (determinant is 0).\n");
    } else {
        printf("The inverse of the matrix is:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%.2f ", adjoint[i][j] / (float)det);
            }
            printf("\n");
        }
    }
    return 0;
}