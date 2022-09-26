#include "cancellation.h"
/**
 * @brief cancels bus seat and changes status to canceled
 * 
 */
void cancellation()
{
    int tickets;
    partition2(); //function defined busdetail.c
    printf("CANCELLATION");
    partition2();
    printf("\n");
    partition1();  //function defined in busdetail.c
    busnumber();   //function defined in busdetail.c
    partition2();
    printf("\nHow many tickets you want to cancel:");
    scanf("%d", &tickets);
    name_email(tickets);  //function defined passenger detail.c
    cancelseats(tickets, busno);  //function defined in busstatus.c
    file(tickets, busno); //function defined in file.c
    printf("\tCANCELLATION COMPLETED\n");
    partition1();
    return;
}