#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char name[50];
    int i, count = 0;

    fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("Enter 3 student names:\n");

    for (i = 0; i < 3; i++) {
        scanf("%49s", name);
        fprintf(fp, "%s\n", name);
    }

    fclose(fp);

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("\nNames from file:\n");

    while (fgets(name, 50, fp) != NULL) {
        name[strcspn(name, "\n")] = '\0';

        count++;
        printf("%d. %s\n", count, name);
    }

    fclose(fp);

    printf("Total students: %d\n", count);

    return 0;
}