#include <stdio.h>

struct Flight {
    int flightNumber;
    char departure[50];
    char destination[50];
    char date[20];
    int availableSeats;
};

void copyString(char dest[], char src[]){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void displayFlight(struct Flight f){
    printf("\nFlight Number: %d\n", f.flightNumber);
    printf("Departure: %s\n", f.departure);
    printf("Destination: %s\n", f.destination);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.availableSeats);
}

void bookSeat(struct Flight *f){
    if(f->availableSeats > 0){
        f->availableSeats--;
        printf("\nSeat booked successfully!\n");
    } else {
        printf("\nNo seats available!\n");
    }
}

int main(){
    struct Flight f;

    f.flightNumber = 1023;

    copyString(f.departure, "Karachi");
    copyString(f.destination, "Islamabad");
    copyString(f.date, "12-12-2025");

    f.availableSeats = 5;

    int choice;

    while(1){
        printf("\n1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            displayFlight(f);
        }
        else if(choice == 2){
            bookSeat(&f);
        }
        else if(choice == 3){
            break;
        }
        else{
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

