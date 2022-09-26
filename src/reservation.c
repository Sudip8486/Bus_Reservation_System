#include "reservation.h"
/**
 * @brief This asks passenger details and writes in .csv file
 * 
 */
void bus_reservation()
{
    int  test1;
    partition2();
    printf("RESERVATION");
    partition2();
    printf("\n");
    partition1();
    busnumber();
    do // this loop repeats if number of passenger is greater than 32
    {
        printf("\xcd\xcd\xcd\xcdMAXIMUM CAPACITY OF BUS IS 32\xcd\xcd\xcd\xcd");
        test1 = 0;
        printf("\nNo of travellers:");
        scanf("%d", &passengers);
        if (passengers > 32) //this checks if the entered number of passengers is less than the capacity of bus
        {
            test1 = 1;
            system("cls");
        }
    } while (test1 == 1);
    name_email(passengers);
    reserveseats(passengers, busno);
    file(passengers, busno);
    printf("\tRESERVATION COMPLETED\n");
    partition1();
    return;
}