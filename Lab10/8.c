#include <stdio.h>
#include <string.h>

int main() {
    char s[100], t[100];
    int i = 0, j = 0;

    printf("Enter first string: ");
    scanf("%99s", s);

    printf("Enter second string: ");
    scanf("%99s", t);

    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    if (s[i] == '\0') {
        printf("It is a subsequence.\n");
    }
    else {
        printf("It is not a subsequence.\n");
    }

    return 0;
}