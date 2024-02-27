#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>// Standard input output library
#include <stdio.h> 

struct car {

int x;

// char yyDxnnnn
char plate[20];
// make and model eg ford fiesta
char make[20];

// color
char color[20];

// no of previous owners
int prevOwners;

// boolean if reserved or not
//bool reserved;

// Reserve amount
int reserveAmount;

//Review
char review[20];
};

//function prototypes
void addCar();
void sellCar();
void reserved();
void viewCars();
void viewOne();
void reviews();
void exit();


int main(){

    int option;

    printf("Welcome to the Showroom");

    printf("\n\tPlease pick an option");

    printf("\n\t 1.Add a car\n\t 2.Sell a car\n\t 3.Reserve/unreserve a car\n\t 4.View cars\n\t 5.View a specific car\n\t 6.Reviews\n\t 7.Exit");
    scanf("%d", option);

    //if statments for each option or switch statment



}