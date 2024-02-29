#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>// Standard input output library
#include <stdlib.h> 

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
void menu();

void addCar(); //1
void sellCar(); //2
void reserved(); //3
void viewCars(); //4 
void viewOne(); //5 
void reviews(); //6
//void exit(); //7




int main(){

    menu();

    //Notes for Git hub
    //I made a switch statment 
    //Something wrong with exit();

    

        
    


}


void menu(){

    int option;
    
     printf("Welcome to the Showroom");

    printf("\n\tPlease pick an option");

    printf("\n\t 1.Add a car\n\t 2.Sell a car\n\t 3.Reserve/unreserve a car\n\t 4.View cars\n\t 5.View a specific car\n\t 6.Reviews\n\t 7.Exit");
    scanf("%d", &option);

     switch(option){
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

      // case 7:
     //  exit();
       // break;

        default:

        printf("Error, pick an option\n");

        menu();

        
    }



}

void addCar(){
    printf("add");
}

void sellCar(){
    printf("sell");
}


void reserved(){
    printf("reserved");
}

void viewCars(){
    printf("view cars");
}

void viewOne(){
    printf("view one");
}

void reviews(){
    printf("reviews");
}

//void exit(){
  // printf("Hello");

  // exit(0);
//}








