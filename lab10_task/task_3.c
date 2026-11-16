
#include <stdio.h>

struct Flight {
    int flight_number;
    char departure_city[30];
    char destination_city[30];
    char date[20];
    int available_seats;
};

void displayFlight(struct Flight f) {
    printf("\n--- Flight Details ---\n");
    printf("Flight Number: %d\n", f.flight_number);
    printf("Departure City: %s\n", f.departure_city);
    printf("Destination City: %s\n", f.destination_city);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.available_seats);
}

void bookSeat(struct Flight *f) {
    if (f->available_seats > 0) {
        f->available_seats--;
        printf("\nSeat booked successfully!\n");
    } else {
        printf("\nSorry! No seats available.\n");
    }
}

int main() {
    struct Flight f1 = {
        101,
        "Karachi",
        "Lahore",
        "20-12-2026",
        50
    };

    int choice;

    do {
        printf("\n1. Display Flight Details");
        printf("\n2. Book a Seat");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayFlight(f1);
        }
        else if (choice == 2) {
            bookSeat(&f1);
        }
        else if (choice == 3) {
            printf("\nThank you!");
        }
        else {
            printf("\nInvalid choice!");
        }

    } while (choice != 3);

    return 0;
}
