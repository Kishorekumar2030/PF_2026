#include <stdio.h>
#include <string.h>

int main() {
    char cities[5][50];
    int i;
    int longest = 0;

    for (i = 0; i < 5; i++) {
        printf("Enter city %d: ", i + 1);
        fgets(cities[i], 50, stdin);

        cities[i][strcspn(cities[i], "\n")] = '\0';
    }

    printf("\nCity names:\n");

    for (i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, cities[i]);
    }

    for (i = 1; i < 5; i++) {
        if (strlen(cities[i]) > strlen(cities[longest])) {
            longest = i;
        }
    }

    printf("\nLongest city name: %s\n", cities[longest]);
    printf("Length: %d\n", (int)strlen(cities[longest]));

    return 0;
}