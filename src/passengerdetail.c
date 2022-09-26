#include "passengerdetail.h"
void name_email(int passengers)
{

    for (int i = 0; i < passengers; i++) //this loop is repeated till the number of passenger is greater tham zero
    {
        partition2();
        printf("\nEnter the detail of %d passenger:\n", i + 1);
        printf("Name:");
        scanf("%s %s", passenger[i].firstname, passenger[i].lastname);
        printf("Email:");
        scanf("%s", passenger[i].email);
        printf("Number:");
        scanf("%lld", &passenger[i].mobile_no);
    }
    return;
}
