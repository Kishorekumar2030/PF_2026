#include <stdio.h>
#include <string.h>

int main() {
    char first[50];
    char last[50];
    char full[120] = "";

    printf("Enter first name: ");
    scanf("%49s", first);

    printf("Enter last name: ");
    scanf("%49s", last);

    strcat(full, first);
    strcat(full, " ");
    strcat(full, last);

    printf("Full name: %s\n", full);

    return 0;
}