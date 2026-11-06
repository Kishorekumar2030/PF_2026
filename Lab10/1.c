#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char copiedName[100];

    printf("Enter your name: ");
    fgets(name, 100, stdin);

    name[strcspn(name, "\n")] = '\0';

    int length = strlen(name);
    printf("Your name has %d characters.\n", length);

    strcpy(copiedName, name);

    printf("Your copied name is: %s\n", copiedName);

    printf("Length of name: %d\n", strlen(name));
    printf("Size of name array: %d bytes\n", (int)sizeof(name));

    return 0;
}