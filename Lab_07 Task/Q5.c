
#include <stdio.h>
int main() {
    int a[3][3][3];
    int i, j, k;
    int same;
    for (i = 0; i < 3; i++) {
        printf("\nEnter elements for Layer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("Enter a[%d][%d][%d]: ", i, j, k);
                scanf("%d", &a[i][j][k]);
            }
        }
    }
    printf("\nAll Layers:\n");
    for (i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%d ", a[i][j][k]);
            }
            printf("\n");
        }
    }
    printf("\nLayer Comparisons:\n");
    same = 1;
    for (j = 0; j < 3; j++) {
        for (k = 0; k < 3; k++) {
            if (a[0][j][k] != a[1][j][k]) {
                same = 0;
            }
        }
    }
    if (same == 1)
        printf("Layer 1 and Layer 2 are IDENTICAL.\n");
    else
        printf("Layer 1 and Layer 2 are DISTINCT.\n");
    same = 1;
    for (j = 0; j < 3; j++) {
        for (k = 0; k < 3; k++) {
            if (a[0][j][k] != a[2][j][k]) {
                same = 0;
            }
        }
    }
    if (same == 1)
        printf("Layer 1 and Layer 3 are IDENTICAL.\n");
    else
        printf("Layer 1 and Layer 3 are DISTINCT.\n");
    same = 1;
    for (j = 0; j < 3; j++) {
        for (k = 0; k < 3; k++) {
            if (a[1][j][k] != a[2][j][k]) {
                same = 0;
            }
        }
    }
    if (same == 1)
        printf("Layer 2 and Layer 3 are IDENTICAL.\n");
    else
        printf("Layer 2 and Layer 3 are DISTINCT.\n");
    return 0;
}
