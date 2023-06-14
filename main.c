#include <stdio.h>
#include <stdlib.h>
#include"splash.h"
#include"login.h"
#include"menu.h"


struct order
{
    char name [50];
    int item;
    int id;
    double price;
};



int main()
{

    splash();
    system("cls");
    login();

         FILE *bill;


    struct order ord[100];
    char user[100];
    char card[20];
    char pas[15];
    char srch[1000];
    int ch,payment;
    int i=1;
    char n;
    char inv="";
    double sum =0;
    struct Burger burgers[100];
    int count = 0;

    // Add burgers to the list
    struct Burger burger1 = {1, "Cheeseburger", 5.99};
    struct Burger burger2 = {2, "Hamburger", 4.99};
    struct Burger burger3 = {3, "Bacon Burger", 6.99};
    struct Burger burger4 = {4, "Bean Burger", 3.65};
    struct Burger burger5 = {5, "Mutton Burger", 4.50};
    struct Burger burger6 = {6, "Beef Burger", 7.50};
    struct Burger burger7 = {7, "Wild Salmon Burger", 8.29};


    burgers[count++] = burger1;
    burgers[count++] = burger2;
    burgers[count++] = burger3;
    burgers[count++] = burger4;
    burgers[count++] = burger5;
    burgers[count++] = burger6;
    burgers[count++] = burger7;


    ord[1].price=5.99;
    ord[2].price=4.99;
    ord[3].price=6.99;
    ord[4].price=3.65;
    ord[5].price=4.50;
    ord[6].price=7.50;
    ord[7].price=8.29;


    while (1){  //loop for keep stay menubar till type 3

        system("cls");
        menu();

        printf("Enter Your Choise>>\n");
        fflush(stdin);
        scanf("%d",&ch);

        if(ch==1){
        // Display the burger list
        system("cls");
        display_burger_list(burgers, count);
         printf("\n");

         i=1;
         sum=0;

        fflush(stdin);
        printf("Enter customer name\n");
        fgets(user,100,stdin);

    do{
       system("cls");
       display_burger_list(burgers, count);

       printf("Enter Burger Id\n");
       scanf("%d",&ord[i].id);

       printf("Enter Burger Quantity\n");
       scanf("%d",&ord[i].item);

       //matching id and calculate money for burger
        if (ord[i].id==1){
        sum=sum + (ord[i].price*ord[i].item);
        strcpy(ord[i].name,"Cheeseburger");
     }
     else if(ord[i].id==2){
        sum=sum + (ord[i].price*ord[i].item);
        strcpy(ord[i].name,"Hamburger");
     }
     else if(ord[i].id==3){
        sum=sum + (ord[i].price*ord[i].item);
        strcpy(ord[i].name,"Bacon Burger");
     }
     else if(ord[i].id==4){
        sum=sum + (ord[i].price*ord[i].item);
        strcpy(ord[i].name,"Bean Burger");
     }
     else if(ord[i].id==5){
        sum=sum + (ord[i].price*ord[i].item);
        strcpy(ord[i].name,"Mutton Burger");
     }
     else if(ord[i].id==6){
        sum=sum + (ord[i].price*ord[i].item);
        strcpy(ord[i].name,"Beef Burger");
     }
     else if(ord[i].id==7){
        sum=sum + (ord[i].price*ord[i].item);
        strcpy(ord[i].name,"Wild Salmon Burger");
     }
     else {
        printf("Wrong keyword\n");
        sleep(1);

     }


     system("cls");
     printf(" \n\n\t\t\t     Total Payable Amount is = %f\n",sum);
     printf("For Order more or not..Type y/n\n");
     fflush(stdin);
     scanf(" %c",&n);
     i++;
    }while(n!='n'); //conitune order untill type n


    system("cls");
    printf("\t\t\t\t\t............Payment Getway.........\n\n\n");
    printf("==>1.Pay Cash\n");
    printf("==>2.Credit Card\n\n");
    printf("\tEnter your choice>>\n");


    scanf("%d",&payment);

    if(payment==1){
            system("cls");
        printf(".......Successfully paid!!!!!!!!\n");
        printf("Do you want to save invoice(y/n)\n");
        scanf(" %c",&inv);

         if(inv=='y'){ //Saving Bill IN file

          bill=fopen("bill.txt","a+");
          fprintf(bill,"%51s\n","B&G Invoice Information");
          fprintf(bill,"%51s\n","=======================");
          fprintf(bill,"\n\n");
          fprintf(bill," Customar Name: %s",user);
          fprintf(bill," Payment Type :Cash\n\n");
          fprintf(bill,"--------------------------------------------------------------------------------\n");
          fprintf(bill," %-10s %-20s %-10s\t %s\t%s  \n","ID","Name","Quantity","Unit Price","Total");
          fprintf(bill,"--------------------------------------------------------------------------------\n");

          for(int j=1;j<i;j++){
          fprintf(bill," %-10d %-20s %-10d\t %.2f\t\t%.2f\n",ord[j].id,ord[j].name,ord[j].item,ord[j].price,(ord[j].price*ord[j].item));

          }

          fprintf(bill,"--------------------------------------------------------------------------------\n");
          fprintf(bill,"\t\t\t\t\t\t\tGrand Total=%.2f Tk",sum);
          fprintf(bill,"\n\n");
          printf("\t\t\t..........Successfully Saved Bill..............\n");
          sleep(1);
          fclose(bill);


        }

        system("cls");
                printf(">>... Main Menu Loading\n");
        sleep(1);

        }



    else if(payment==2){
            system("cls");

        printf("Enter Card Number:\n");
        scanf("%s",card);
        system("cls");

        printf("Enter passwod:\n");
        scanf("%s",pas);
        system("cls");

        printf("\t\t\t............payment Successful!!!!!!\n\n\n");
        printf("Do you want to save invoice(y/n)\n");
        fflush(stdin);

        scanf(" %c",&inv);

         if(inv=='y'){ //bill save for option 2

                bill=fopen("bill.txt","a+");
          fprintf(bill,"%51s\n","B&G Invoice Information");
          fprintf(bill,"%51s\n","=======================");
          fprintf(bill,"\n\n");
          fprintf(bill," Customar Name: %s",user);
          fprintf(bill," Payment Type :Card\n\n");
          fprintf(bill,"--------------------------------------------------------------------------------\n");
          fprintf(bill," %-10s %-20s %-10s\t %s\t%s  \n","ID","Name","Quantity","Unit Price","Total");
          fprintf(bill,"--------------------------------------------------------------------------------\n");

          for(int j=1;j<i;j++){
          fprintf(bill," %-10d %-20s %-10d\t %.2f\t\t%.2f\n",ord[j].id,ord[j].name,ord[j].item,ord[j].price,(ord[j].price*ord[j].item));

          }

          fprintf(bill,"--------------------------------------------------------------------------------\n");
          fprintf(bill,"\t\t\t\t\t\t\tGrand Total=%.2f Tk",sum);
          fprintf(bill,"\n\n");
          printf("\t\t\t..........Successfully Saved Bill..............\n");
          sleep(1);
          fclose(bill);

    }
            else {
                printf(">>... Main Menu Loading\n");
        sleep(1);

        }



           }
           else {
            printf("!!!!!Wrong keyword\n");
            printf("Main menu Loading\n");
            sleep(1);
           }


    }



    else if(ch==2) //Showing bill
    {

         system("cls");
         bill=fopen("bill.txt","r");

         if(bill==NULL){
            printf("==>!!Invoice Deleted\n");
            fclose(bill);
            sleep(2);
         }


       else {

          printf("==>Loading Invoice...\n");
          sleep(2);
          system("cls");


          while(!feof(bill)){ //printing bill from file

            fgets(srch,sizeof(srch),bill);
            printf("%s",srch);

          }

          fclose(bill);
          printf("\n\n\n\n>>>>>>Enter any key to Return Main Menu>>>>>>>>\n");
          fflush(stdin);
          getchar();

         }
    }


     else if(ch==3){ //delet all bill or file

            system("cls");
            remove("bill.txt");
                printf("==> All Invoice Deleted Successfully!!\n");
            sleep(2);

         }




      else if (ch==4){
        exit_program();
         }



        else if(ch!=1||ch!=2||ch!=3||ch!=4){

        system("cls");
        printf("\n");
        printf("Invalid keyword\n\n");
        sleep(1);
       }
    }

    return 0;
}
