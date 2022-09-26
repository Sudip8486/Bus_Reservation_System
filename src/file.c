#include "file.h"
/**
 * @brief this opens .csv file and writes the data stored in structure variable
 * 
 * @param passengers-> number of passengers 
 * @param busno -->bus no
 */
void file(int passengers, int busno)
{
    FILE *detail;
    switch (busno)
    {
    case 1:
        detail = fopen("bus1.csv", "a");
        break;
    case 2:
        detail = fopen("bus2.csv", "a");
        break;
    case 3:
        detail = fopen("bus3.csv", "a");
        break;
    case 4:
        detail = fopen("bus4.csv", "a");
        break;
    case 5:
        detail = fopen("bus5.csv", "a");
        break;
    case 6:
        detail = fopen("bus6.csv", "a");
        break;
    }
    fprintf(detail, "BUS NO,FIRST NAME,LAST NAME,E-MAIL,MOBILE NO,SEAT NO,STATUS\n");
    for (int i = 0; i < passengers; i++)
    {
        fprintf(detail, "%d,%s,%s,%s,%lld,%d,%s\n", busno, passenger[i].firstname, passenger[i].lastname, passenger[i].email, passenger[i].mobile_no, passenger[i].seat, passenger[i].status);
    }
    fclose(detail);
    return;
}