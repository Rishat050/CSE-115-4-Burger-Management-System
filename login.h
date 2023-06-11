#include<stdio.h>

void login(void)
{

    char username[50],password[25],userfile[50],passwordfile[25];

    FILE *log;
    log=fopen("login.txt","r");

    printf("\t\t\t\t.......................................\n");
    printf("\t\t\t\t.......................................\n");
    printf("\t\t\t\t..........  Login Panel  ..............\n");
    printf("\t\t\t\t.......................................\n");
    printf("\t\t\t\t.......................................\n\n\n");

        //storing the username and password from file
        fscanf(log,"%s%s", userfile,passwordfile);

        while(1)
        {
          printf("Enter user name\n");
          fflush(stdin);
          fgets(username,sizeof(username),stdin);
        username[strlen(username)-1]='\0'; //remove the new line charecter


        printf("Enter password\n");
        fflush(stdin);
        fgets(password,sizeof(password),stdin);
        password[strlen(password)-1]='\0';


       //matching password and username
        if((strcmp(userfile,username)==0 )&& (strcmp(passwordfile,password)==0))

         {
             system("cls");
            printf("\t\t\t\t\.........Login Successful..........\n\n\n\n\n\n");
            printf("Enter any key to Continue\n");
            getchar();
            break;

         }
        else
         {
            printf("\t\t\t\t..............!!!!!!!!Login Unsuccessful!!!!!!!!!!!............\n\n\n");
            printf("......Try Again......\n\n\n");
         }
        }

    }

