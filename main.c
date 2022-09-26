/**
 * @file busreservation.c
 * 
 * @author Sudip Bhattarai
 * 
 * @brief program to reserve and cancel bus seats
 * 
 * @date 2021-08-16
 * 
 */

#include <stdio.h>  //header file for input output
#include <conio.h>  //header file for getch()
#include <stdlib.h> //header file for exit
#include "reservation.h"
extern int busno;
void feedback();

int main()
{

    int option;
    do //the loop will conitnue  till user doesn't exit
    {
        system("cls");
        partition1();
        printf("\t\tWELCOME TO BUS RESERVATION SYSTEM\n");
        partition1();
        partition2();
        printf("MENU");
        partition2();
        printf("\n\t1. Bus routes\n");
        printf("\t2. Bus lists\n");
        printf("\t3. Reseravtion\n");
        printf("\t4. Bus status \n");
        printf("\t5. Cancellation\n");
        printf("\t6. Feedback\n");
        printf("\t7. Exit\n");
        partition2();
        printf("\nChoose an option:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("cls");
            bus_route();  //function defined in busdetail.c
            break;
        case 2:
            system("cls");
            bus_list();  //function deined in busdetail.c
            break;
        case 3:
            system("cls");
            bus_reservation();  //function defined in reservation.c
            break;
        case 4:
            system("cls");
            busnumber();  //funtion deifned in busdetail.c
            busstatus(busno);
            break;
        case 5:
            system("cls");
            cancellation();  //function defined in cancelltaion.c
            break;
        case 6:
            system("cls");
            feedback();
            break;
        default:
            if (option != 7)
            {
                printf("\tInvalid option!!\n");
            }
        }
        printf("PRESS ANY KEY");
        getch();
    } while (option != 7);
    system("cls");
    partition1();
    printf("\tTHANK YOU FOR UISNG OUR SERVICE\n");
    partition1();
    return 0;
}

/**
 * @brief this function gets character unless it encounters new line character
 * 
 */
void feedback()
{
    FILE *review;
    char fristname[15], lastname[15];
    char *reviews = malloc(1000 * sizeof(char)); //allocates memory for 1000 character
    partition2();
    printf("FEEDBACK");
    partition2();
    review = fopen("feedback.txt", "a"); //opening file named feedback.txt to write in a file
    printf("\nEnter your name:");
    scanf("%s %s", fristname, lastname);
    getchar();
    fprintf(review, "NAME:%s %s\n", fristname, lastname);
    printf("\xcd\xcd\xcd\xcd\xcdPlease Write your suggestion for us.\xcd\xcd\xcd\xcd\xcd\n");
    fgets(reviews, 1000, stdin); //gets character
    fprintf(review, "%s\n", reviews);   //writes in a file
    free(reviews);   //deallocates free memory
    fclose(review);
    return;
}