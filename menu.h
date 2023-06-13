
#include<stdio.h>

struct Burger {
    int id;
    char name[100];
    float price;
};

void display_burger_list(struct Burger *burgers, int count) {
    printf("\t\t\t~~~~~ Burger List ~~~~~\n\n\n");
    printf("  %-10s %-20s %-10s\n", "ID", "Name", "Price");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        struct Burger burger = burgers[i];
        printf("  %-10d %-20s %-10.2f\n", burger.id, burger.name, burger.price);
        printf("-----------------------------------------\n");
    }
}


void menu (void)
{
    printf("==> 1. Burger List & Order\n");
    printf("==> 2. Admin Pannel\n");
    printf("==> 3. Exit\n");
}



void exit_program(void)
 {
     system("cls");
    printf("                ...Thank You For Using Our System...\n");
    sleep(1);
    exit(0); // Terminate the program with a status code of 0
 }

