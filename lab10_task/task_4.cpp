
#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int release_year;
    float rating;
};

int main() {

    struct Movie movies[100];
    int count = 0;
    int choice;
    char search_genre[30];
    int found;

    do {
        printf("\n--- Movie Management System ---");
        printf("\n1. Add New Movie");
        printf("\n2. Search Movie By Genre");
        printf("\n3. Display All Movies");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            if (count >= 100) {
                printf("\nMovie storage is full!");
                continue;
            }

            printf("\nEnter Movie Title: ");
            scanf(" %49[^\n]", movies[count].title);

            printf("Enter Genre: ");
            scanf(" %29[^\n]", movies[count].genre);

            printf("Enter Director: ");
            scanf(" %49[^\n]", movies[count].director);

            printf("Enter Release Year: ");
            scanf("%d", &movies[count].release_year);

            printf("Enter Rating: ");
            scanf("%f", &movies[count].rating);

            count++;

            printf("\nMovie added successfully!");
        }

        else if (choice == 2) {

            printf("\nEnter Genre to Search: ");
            scanf(" %29[^\n]", search_genre);

            found = 0;

            for (int i = 0; i < count; i++) {

                if (strcmp(movies[i].genre, search_genre) == 0) {

                    printf("\nMovie Title: %s", movies[i].title);
                    printf("\nGenre: %s", movies[i].genre);
                    printf("\nDirector: %s", movies[i].director);
                    printf("\nRelease Year: %d", movies[i].release_year);
                    printf("\nRating: %.1f\n", movies[i].rating);

                    found = 1;
                }
            }

            if (found == 0) {
                printf("\nNo movie found in this genre!");
            }
        }

        else if (choice == 3) {

            if (count == 0) {
                printf("\nNo movies available!");
            }

            for (int i = 0; i < count; i++) {

                printf("\n--- Movie %d ---", i + 1);
                printf("\nTitle: %s", movies[i].title);
                printf("\nGenre: %s", movies[i].genre);
                printf("\nDirector: %s", movies[i].director);
                printf("\nRelease Year: %d", movies[i].release_year);
                printf("\nRating: %.1f\n", movies[i].rating);
            }
        }

        else if (choice == 4) {
            printf("\nThank you!");
        }

        else {
            printf("\nInvalid choice!");
        }

    } while (choice != 4);

    return 0;
}
