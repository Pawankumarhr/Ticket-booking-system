#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 5
#define MAX_SEATS 50

// Structure to hold movie details
typedef struct {
    char name[50];
    char timings[3][10];
    int price;
    int seats[MAX_SEATS];
} Movie;

Movie movies[MAX_MOVIES] = {
    {"Avengers: Endgame", {"10:00AM", "2:00PM", "6:00PM"}, 300, {0}},
    {"Inception", {"11:00AM", "3:00PM", "7:00PM"}, 250, {0}},
    {"Titanic", {"12:00PM", "4:00PM", "8:00PM"}, 200, {0}},
    {"Joker", {"1:00PM", "5:00PM", "9:00PM"}, 220, {0}},
    {"Interstellar", {"10:30AM", "2:30PM", "6:30PM"}, 280, {0}}
};

void displayMovies() {
    printf("\nAvailable Movies:\n");
    for (int i = 0; i < MAX_MOVIES; i++) {
        printf("%d. %s (Rs.%d)\n", i + 1, movies[i].name, movies[i].price);
    }
}

void bookTicket() {
    int movieChoice, timeChoice, seatCount, seatNum;
    char name[50], phone[15];
    
    displayMovies();
    printf("\nEnter the movie number: ");
    scanf("%d", &movieChoice);
    if (movieChoice < 1 || movieChoice > MAX_MOVIES) {
        printf("Invalid choice!\n");
        return;
    }
    movieChoice--;

    printf("\nAvailable Timings:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, movies[movieChoice].timings[i]);
    }
    printf("Enter your preferred timing: ");
    scanf("%d", &timeChoice);
    if (timeChoice < 1 || timeChoice > 3) {
        printf("Invalid choice!\n");
        return;
    }
    
    printf("\nEnter the number of seats: ");
    scanf("%d", &seatCount);
    if (seatCount < 1 || seatCount > MAX_SEATS) {
        printf("Invalid seat count!\n");
        return;
    }
    
    printf("\nEnter seat numbers (1-50):\n");
    for (int i = 0; i < seatCount; i++) {
        scanf("%d", &seatNum);
        if (seatNum < 1 || seatNum > MAX_SEATS || movies[movieChoice].seats[seatNum - 1] == 1) {
            printf("Invalid or already booked seat! Try again.\n");
            i--;
        } else {
            movies[movieChoice].seats[seatNum - 1] = 1;
        }
    }

    printf("\nEnter your name: ");
    scanf("%s", name);
    printf("Enter your phone number: ");
    scanf("%s", phone);
    
    int totalCost = seatCount * movies[movieChoice].price;
    printf("\nBooking Confirmed!\n");
    printf("Movie: %s\nTime: %s\nSeats: %d\nTotal Price: Rs.%d\nName: %s\nPhone: %s\n", 
           movies[movieChoice].name, movies[movieChoice].timings[timeChoice - 1], seatCount, totalCost, name, phone);
}

void adminPanel() {
    int choice;
    printf("\nAdmin Panel:\n1. Change movie price\n2. Exit Admin Panel\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        int movieChoice, newPrice;
        displayMovies();
        printf("Enter the movie number to change price: ");
        scanf("%d", &movieChoice);
        if (movieChoice < 1 || movieChoice > MAX_MOVIES) {
            printf("Invalid choice!\n");
            return;
        }
        printf("Enter new price: ");
        scanf("%d", &newPrice);
        movies[movieChoice - 1].price = newPrice;
        printf("Price updated successfully!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMovie Ticket Booking System\n");
        printf("1. View Movies\n2. Book Ticket\n3. Admin Panel\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayMovies();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                adminPanel();
                break;
            case 4:
                printf("Thank you for using the system!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
