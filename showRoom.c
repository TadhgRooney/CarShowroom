#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // Standard input output library
#include <string.h>
#include <stdlib.h>

struct car {  // Structure template for data part of linked list
    // char yyDxnnnn
    char plate[20];
    // make and model eg ford fiesta
    char make[20];
    // color
    char color[20];
    // no of previous owners
    int prevOwners;
    // bool reserved;
    int reserved;
    // Reserve amount
    int reserveAmount;
    // Review
    char review[20];
};

struct LinearNode {
    struct car *element;
    struct LinearNode *next;
};

// Function prototypes
void menu();
void addCar();  // 1
void sellCar();  // 2
void reserved();  // 3
void viewCars();  // 4
void viewOne();  // 5
void reviews();  // 6
void exitProgram();  // 7

// Global variables
struct LinearNode *front = NULL;  // Front of list
struct LinearNode *last = NULL;  // Pointer to last node

int main() {
    menu();
}

void menu() {
    int option;
    printf("Welcome to the Showroom");
    printf("\n\tPlease pick an option");
    do {
        printf("\n\t 1.Add a car\n\t 2.Sell a car\n\t 3.Reserve/unreserve a car\n\t 4.View cars\n\t 5.View a specific car\n\t 6.Reviews\n\t 7.Exit");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addCar();
                break;

            case 2:
                sellCar();
                break;

            case 3:
                reserved();
                break;

            case 4:
                viewCars();
                break;

            case 5:
                viewOne();
                break;

            case 6:
                reviews();
                break;
        }
    } while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6);
}

void addCar() {
    char plate[20];
    char make[20];
    char color[20];
    int prevOwners;
    int reserved;
    int reserveAmount;
    char review[20];

    struct LinearNode *aNode;
    struct car *anElement;

    // Allocate memory for a new car element
    anElement = (struct car *)malloc(sizeof(struct car));

    // Check if the front of the list is empty
    if (front == NULL) {
        // If empty, allocate memory for a new front node and set last to front
        front = (struct LinearNode *)malloc(sizeof(struct LinearNode));
        last = front;
    }
    // Check if last is empty
    else if (last == NULL) {
        // If empty, allocate memory for a new last node and set front's next pointer to last
        last = (struct LinearNode *)malloc(sizeof(struct LinearNode));
        front->next = last;
    } else {
        // If not empty, allocate memory for a new node and update last to point to the new node
        last->next = (struct LinearNode *)malloc(sizeof(struct LinearNode));
        last = last->next;
    }

    last->next = NULL;  // Ensure the next pointer of the last node points to NULL

    printf("Enter cars plate: ");
    scanf("%s", plate);  

    printf("Enter the make of the car: ");
    fgets(make,20,stdin);// Needs a space

    printf("Enter the color of the car: ");
    scanf("%s", color);

    do {
        printf("Enter the number of previous owners: ");
        scanf("%d", &prevOwners);
        if (prevOwners < 0 || prevOwners > 3) {
            printf("Error: Invalid input for the number of owners. Please enter a number between 0 and 3.\n");
        }
    } while (prevOwners < 0 || prevOwners > 3);

    if (reserved) {
        printf("Enter the reserve amount: ");
        scanf("%d", &reserveAmount);
    } else {
        reserveAmount = 0;  // Set reserve amount to 0 for unreserved cars
    }

    int maxReviews = prevOwners;
    if (maxReviews == 0) {
        printf("This car is brand new. There are no reviews");
        return;
    }

    // Loop to get reviews
    for (int i = 0; i < maxReviews; i++) {
        printf("Enter a review for the car (Review from owner %d): ", i + 1);
        scanf("%s", review);
    }



 
}

void sellCar() {  // Delete
    
    char plate[20];
    printf("Enter the registration number of the car you want to sell: ");
    scanf("%s", plate);

    // Traverse the list to find the car with the given registration number
    struct LinearNode *current = front;
    struct LinearNode *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->element->plate, plate) == 0) { // If registration number matches
            if (current->element->reserved == 1) { // If the car is reserved
                // Remove the car from the list
                if (prev == NULL) { // If the first node matches
                    if (current->next == NULL) { // If it's the only node
                        free(current->element); // Free car element memory
                        free(current); // Free node memory
                        front = NULL;
                        last = NULL;
                    } else {
                        front = current->next; // Move front to next node
                        free(current->element); // Free car element memory
                        free(current); // Free node memory
                    }
                } else {
                    prev->next = current->next; // Link the previous node to the next of current
                    if (current->next == NULL) { // If it's the last node
                        last = prev; // Update last pointer
                    }
                    free(current->element); // Free car element memory
                    free(current); // Free node memory
                }
                printf("Car with registration number %s has been sold.\n", plate);
                return; // Exit function after selling the car
            } else {
                printf("Error: The car with registration number %s is not reserved.\n", plate);
                return; // Exit function if car is not reserved
            }
        }
        prev = current; // Move prev pointer to current
        current = current->next; // Move current pointer to next node
    }
    printf("Error: Car with registration number %s not found.\n", plate); // If car not found
}



void reserved() {
    printf("reserved");
}

void viewCars() {  // Display
    printf("view cars");
}

void viewOne() {  // Display one
    printf("view one");
}

void reviews() {
    printf("reviews");
}

void exitProgram() {
    printf("This is where you exit");
}










