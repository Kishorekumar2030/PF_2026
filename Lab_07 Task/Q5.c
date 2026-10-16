#include <stdio.h>
int main() {
    int a[3][3][3];
    int overall_sum = 0;
    int overall_min, overall_max;
    int total_elements = 27; 
    printf("=== Enter Elements for the 3x3x3 3D Array ===\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("Enter value for a[%d][%d][%d]: ", i, j, k);
                scanf("%d", &a[i][j][k]);
            }
        }
    }
    overall_min = a[0][0][0];
    overall_max = a[0][0][0];
    printf("\n=== Layer-wise Analysis and Display ===\n");

    for (int i = 0; i < 3; i++) {
        int layer_sum = 0;
        int layer_min = a[i][0][0];
        int layer_max = a[i][0][0];

        printf("\n-- Layer %d Matrix --\n", i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int val = a[i][j][k];
                printf("%5d", val);
                layer_sum += val;
                if (val < layer_min) layer_min = val;
                if (val > layer_max) layer_max = val;
                overall_sum += val;
                if (val < overall_min) overall_min = val;
                if (val > overall_max) overall_max = val;
            }
            printf("\n");
        }
        printf("--------------------------------\n");
        printf("Layer %d Total Sum     : %d\n", i, layer_sum);
        printf("Layer %d Average       : %.2f\n", i, (float)layer_sum / 9.0);
        printf("Layer %d Minimum Value : %d\n", i, layer_min);
        printf("Layer %d Maximum Value : %d\n", i, layer_max);
    }
    printf("\n========================================\n");
    printf("         OVERALL DATA INSIGHTS          \n");
    printf("========================================\n");
    printf("Total Elements Processed : %d\n", total_elements);
    printf("Grand Total Sum          : %d\n", overall_sum);
    printf("Overall Average          : %.2f\n", (float)overall_sum / total_elements);
    printf("Overall Minimum Value    : %d\n", overall_min);
    printf("Overall Maximum Value    : %d\n", overall_max);
    printf("========================================\n");

    return 0;
}