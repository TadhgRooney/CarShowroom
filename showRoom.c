  #define true 1
  #define false 0
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
void reserveCar();
void unreserveCar();
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

            case 7:
                exitProgram();
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

   

    do { printf("Enter cars plate: ");
    scanf("%s", plate);  

    if (strlen(plate) != 8 || (plate[2] != 'D') || (plate[3] != '1' && plate[3] != '2')) {
            printf("Error: Wrong registration plate format. Please enter in the format yyDxnnnn (15D21234).\n");
        }
    } while(strlen(plate) != 8 || (plate[2] != 'D') || (plate[3] != '1' && plate[3] != '2'));


    fflush(stdin); // Clear input buffer
    printf("Enter the make of the car: ");
    fgets(make,20,stdin);// Needs a space

    printf("Enter the color of the car: ");
    scanf("%s", color);

    do {
        printf("Enter the number of previous owners: ");
        scanf("%d", &prevOwners);
        if (prevOwners < 0 || prevOwners > 3) {
            printf("Error: Wrong input for the number of owners. Enter a number between 0 and 3.\n");
        }
    } while (prevOwners < 0 || prevOwners > 3);

    printf("Is the car reserved? (1 for yes 0 for no): ");
    scanf("%d", &reserved);

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

     printf("Car added successfully!\n");

     // Free memory for the new car element
    free(anElement);

    // Free memory for the new node
    if (last != front) { // Check if last is not the same as front
        free(last);
    }

    // After adding the car, ask user if they want to go back to the menu
    char choice;
    printf("Do you want to go back to the menu? (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        menu(); // Go back to the menu
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

      char choice;
    printf("Do you want to go back to the menu? (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        menu(); // Go back to the menu
    }
}



void reserved() {
    
    int choice;
    printf("Reserve/Unreserve a Car\n");
    printf("1. Reserve a car\n");
    printf("2. Unreserve a car\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            reserveCar();
            break;
        case 2:
            unreserveCar();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    } 

      
    
}

void reserveCar() {
    char plate[20];
    int depositAmount;

    printf("Enter the car registration number you want to reserve: ");
    scanf("%s", plate);

    // Search for the car
    struct LinearNode *current = front;
    while (current != NULL) {
        if (strcmp(current->element->plate, plate) == 0) {
            // Car found
            if (current->element->reserved) {
                printf("Error: The car is already reserved.\n");
                return;
            } else {
                // Car not reserved, reserve it
                printf("Enter the deposit amount (between 500 and 1500): ");
                scanf("%d", &depositAmount);
                if (depositAmount < 500 || depositAmount > 1500) {
                    printf("Error: Deposit amount must be between 500 and 1500.\n");
                    return;
                } else {
                    current->element->reserved = true;
                    current->element->reserveAmount = depositAmount;
                    printf("Car with registration number %s reserved successfully.\n", plate);
                    return;
                }
            }
        }
        current = current->next;
    }
    printf("Error: Car with registration number %s not found.\n", plate);

      char choice;
    printf("Do you want to go back to the menu? (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        menu(); // Go back to the menu
    }
}

void unreserveCar() {
    char plate[20];

    printf("Enter the car registration number you want to unreserve: ");
    scanf("%s", plate);

    // Search for the car
    struct LinearNode *current = front;
    while (current != NULL) {
        if (strcmp(current->element->plate, plate) == 0) {
            // Car found
            if (current->element->reserved) {
                // Car reserved, unreserve it
                current->element->reserved =  0;
                current->element->reserveAmount = 0;
                printf("Car with registration number %s unreserved successfully.\n", plate);
                return;
            } else {
                printf("Error: The car is not currently reserved.\n");
                return;
            }
        }
        current = current->next;
    }
    printf("Error: Car with registration number %s not found.\n", plate);

      char choice;
    printf("Do you want to go back to the menu? (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        menu(); // Go back to the menu
    }
}


    
  void viewCars() {
    int option;
    printf("How would you like to view the cars?\n");
    printf("1. View all cars\n");
    printf("2. View cars based on specific conditions\n");
    scanf("%d", &option);

    char make[20]; // Declare make variable
    char color[20]; // Declare color variable

    switch (option) {
        case 1:
            // View all cars
            printf("All cars in the showroom:\n");
            struct LinearNode *currentAll = front; // Change the variable name
            while (currentAll != NULL) {
                printf("Plate: %s, Make: %s, Color: %s\n", currentAll->element->plate, currentAll->element->make, currentAll->element->color);
                currentAll = currentAll->next;
            }
            break;

        case 2:
            // View cars based on specific conditions
            printf("Choose a condition to view cars:\n");
            printf("1. View non-reserved cars\n");
            printf("2. View cars of a certain make\n");
            printf("3. View cars with a specific color\n");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    // View non-reserved cars
                    printf("Non-reserved cars:\n");
                    struct LinearNode *currentNonReserved = front; // Change the variable name
                    while (currentNonReserved != NULL) {
                        if (!currentNonReserved->element->reserved) {
                            printf("Plate: %s, Make: %s, Color: %s\n", currentNonReserved->element->plate, currentNonReserved->element->make, currentNonReserved->element->color);
                        }
                        currentNonReserved = currentNonReserved->next;
                    }
                    break;

                case 2:
                    // View cars of a certain make
                    printf("Enter the make of the cars you want to view: ");
                    scanf("%s", make); // Use make variable
                    printf("Cars of make %s:\n", make);
                    struct LinearNode *currentMake = front; // Change the variable name
                    while (currentMake != NULL) {
                        if (strcmp(currentMake->element->make, make) == 0) {
                            printf("Plate: %s, Make: %s, Color: %s\n", currentMake->element->plate, currentMake->element->make, currentMake->element->color);
                        }
                        currentMake = currentMake->next;
                    }
                    break;

                case 3:
                    // View cars with a specific color
                    printf("Enter the color of the cars you want to view: ");
                    scanf("%s", color); // Use color variable
                    printf("Cars with color %s:\n", color);
                    struct LinearNode *currentColor = front; // Change the variable name
                    while (currentColor != NULL) {
                        if (strcmp(currentColor->element->color, color) == 0) {
                            printf("Plate: %s, Make: %s, Color: %s\n", currentColor->element->plate, currentColor->element->make, currentColor->element->color);
                        }
                        currentColor = currentColor->next;
                    }
                    break;

                default:
                    printf("Invalid option.\n");
            }
            break;

        
    }

  char choice;
    printf("Do you want to go back to the menu? (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        menu(); // Go back to the menu
    }
}





void viewOne() {
    char plate[20];

    printf("Enter the registration number of the car you want to view: ");
    scanf("%s", plate);

    // Traverse the list to find the car with the given registration number
    struct LinearNode *current = front;
    while (current != NULL) {
        if (strcmp(current->element->plate, plate) == 0) {
            // Car found, display its details
            printf("\nCar details:\n");
            printf("Registration Plate: %s\n", current->element->plate);
            printf("Make: %s\n", current->element->make);
            printf("Color: %s\n", current->element->color);
            printf("Number of Previous Owners: %d\n", current->element->prevOwners);
            printf("Reserved: %s\n", current->element->reserved ? "Yes" : "No");
            if (current->element->reserved) {
                printf("Reserve Amount: %d\n", current->element->reserveAmount);
            }
            // Display reviews if available
            if (current->element->prevOwners > 0) {
                printf("Reviews:\n");
                for (int i = 0; i < current->element->prevOwners; i++) {
                    printf("Owner %d: %s\n", i + 1, current->element->review);
                }
            } else {
                printf("No reviews available.\n");
            }
            return; // Exit function after displaying details
        }
        current = current->next;
    }
    // Car not found
    printf("Error: Car with registration number %s not found.\n", plate);

      char choice;
    printf("Do you want to go back to the menu? (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        menu(); // Go back to the menu
    }
}


void reviews() {
    
//Show reviews based on make of car

    char make[20];
    printf("Enter the make of the car you want to view reviews for: ");
    scanf("%s", make);

    // Traverse the list to find the car with the given make
    struct LinearNode *current = front;
    while (current != NULL) {
        if (strcmp(current->element->make, make) == 0) {
            // Car found, display its reviews
            printf("Reviews for cars of make %s:\n", make);
            if (current->element->prevOwners > 0) {
                for (int i = 0; i < current->element->prevOwners; i++) {
                    printf("Owner %d: %s\n", i + 1, current->element->review);
                }
            } else {
                printf("No reviews available.\n");
            }
            return; // Exit function after displaying reviews
        }
        current = current->next;
    }
    // Car not found
    printf("Error: No cars found with make %s.\n", make);

      char choice;
    printf("Do you want to go back to the menu? (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        menu(); // Go back to the menu
    }
}

void exitProgram() {
    printf("You have exited");
}

