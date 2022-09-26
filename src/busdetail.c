#include "busdetail.h"
void partition1()
{
    int n = 0;
    while (n < 20)
    {
        printf("***");
        n++;
    }
    printf("\n");
    
}
void partition2()
{
    int n = 0;
    while (n < 10)
    {
        printf("\xcd\xcd");
        n++;
    }
    
}
/**
 * @brief prints bus routes
 * 
 */
void bus_route()
{
    partition2();
    printf("BUS ROUTE");
    partition2();
    printf("\n");
    partition1();
    for (int i = 0; i < ROW1; i++)
    {
        printf("\t[%d]. %s\n", i + 1, route[i]);
    }
    return;
}
/**
 * @brief prints buslist with depature time
 * 
 * Depature time is displayed using rand function with same seeds generated every time  
 * 
 */
void bus_list()
{
    int option;
    partition2();
    printf("BUS LIST");
    partition2();
    printf("\nBUS NO\tBUS-NAME\tDEPATURE TIME\t\tROUTE\n");
    for (int i = 0, p = 1; i < ROW1; i++, p++)
    {
        printf("|%3d--->%14s--->%2d:%2d---->%25s|\n", p, buses[i], rand() % 13 + 8, rand() % 61, route[i]);
    }
    return;
}
/**
 * @brief displays bus lists and takes bus no from user  
 * 
 */
void busnumber()
{
    int test;
    do //this loop repeats if bus no is less than 1 or greater than 6
    {
        test = 0;
        bus_list();
        partition2();
        printf("\nEnter a bus number:");
        scanf("%d", &busno);
        if (busno < 1 || busno > 6)
        {
            test = 1;
            system("cls");
            printf("\xcd\xcd\xcd\xcdINVALID BUS NO\xcd\xcd\xcd\xcd \n");
            continue;
        }
    } while (test == 1);
    return;
}