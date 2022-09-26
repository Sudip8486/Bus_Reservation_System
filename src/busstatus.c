#include "busstatus.h"

/**
 * @brief This displays the seat status for different buses
 * 
 * @param a -->2D-array
 */
void printstatus(char a[][COLUMN2])
{
    for (int i = 0; i < LOOP; i = i + 4)
    {
    printf("|%2d.%8s   %2d.%8s\t", i + 1, a[i], i + 2,a[i + 1]); 
    printf("\t%2d.%8s   %2d.%8s|\n", i + 3, a[i + 2], i + 4, a[i + 3]);
    }
}
/**
 * @brief prints on board status for entered bus 
 * 
 * @param busno 
 */
void busstatus(int busno)
{
    switch (busno)
    {
    case 1:
        book=fopen("bus1.txt","a");  //creating a file
        fclose(book);
        book=fopen("bus1.txt","r+"); 
        fread(busstatus_1,sizeof(busstatus_1),1,book);//reading from the created file and storing it in array
        fclose(book);
        printstatus(busstatus_1);  
        break;
    case 2:
        book=fopen("bus2.txt","a");
        fclose(book);
        book=fopen("bus2.txt","a+");  
        fread(busstatus_2,sizeof(busstatus_2),1,book);
        fclose(book);
        printstatus(busstatus_2);
        break;
    case 3:
        book=fopen("bus3.txt","a");
        fclose(book);
        book=fopen("bus3.txt","a+");
        fread(busstatus_3,sizeof(busstatus_3),1,book);
        fclose(book);
        printstatus(busstatus_3);
        break;
    case 4:
        book=fopen("bus4.txt","a");
        fclose(book);
        book=fopen("bus4.txt","a+");
        fread(busstatus_4,sizeof(busstatus_4),1,book);
        fclose(book);
        printstatus(busstatus_4);
        break;
    case 5:
        book=fopen("bus5.txt","a");
        fclose(book);
        book=fopen("bus5.txt","a+");
        fread(busstatus_5,sizeof(busstatus_5),1,book);
        fclose(book);
        printstatus(busstatus_5);
        break;
    case 6:
        book=fopen("bus6.txt","a");
        fclose(book);
        book=fopen("bus6.txt","a+");
        fread(busstatus_6,sizeof(busstatus_6),1,book);
        fclose(book);
        printstatus(busstatus_6);
        break;
    }
    return;
}
/**
 * @brief Stores seat number for each passenger in structure
 * 
 * @param status -->2D array which stores bus status
 * @param trv -->number of travellers
 * @param busno 
 */
void changestatus1(char status[][COLUMN2],int trv,int busno)
{
        again:
        busstatus(busno);
        partition2();
        printf("\n");
        for (int i = 0; i < trv; i++)
        {
            printf("Seat number for %s %s:", passenger[i].firstname, passenger[i].lastname);
            scanf("%d", &passenger[i].seat);
            if (strcmp(status[passenger[i].seat-1],"Empty")==0) //this checks if the entered seat is empty or not
            {
                strcpy(status[passenger[i].seat - 1], "Reserved"); //changes seat status to reserved
                strcpy(passenger[i].status, "RESERVED"); //this is used to print seat status resresved in file
            }
            else
            {
                printf("\xcd\xcd\xcd\xcd ALREADY RESERVED\xcd\xcd\xcd\xcd\n");
                goto again;
            }
        }
    
}
/**
 * @brief this function ask user seat for each passengers and opens file to wite status in a file
 * @param travellers -->no of travellers
 * @param busno 
 */

void reserveseats(int travellers, int busno)
{
    partition1();
    switch (busno)
    {
    case 1:
        changestatus1(busstatus_1,travellers,busno);
        book=fopen("bus1.txt","w");  //destorys older file if exist
        fwrite(busstatus_1,sizeof(busstatus_1),1,book); //writes a block of line (status) in a file
        fclose(book);
        break;
    case 2:
        changestatus1(busstatus_2,travellers,busno);
        book=fopen("bus2.txt","w");
        fwrite(busstatus_2,sizeof(busstatus_2),1,book);
        fclose(book);
        break;
    case 3:
        changestatus1(busstatus_3,travellers,busno);
        book=fopen("bus3.txt","w");
        fwrite(busstatus_3,sizeof(busstatus_3),1,book);
        fclose(book);
        break;
    case 4:
        changestatus1(busstatus_4,travellers,busno);
        book=fopen("bus4.txt","w");
        fwrite(busstatus_4,sizeof(busstatus_4),1,book);
        fclose(book);
        break;
    case 5:
        changestatus1(busstatus_5,travellers,busno);
        book=fopen("bus5.txt","w");
        fwrite(busstatus_5,sizeof(busstatus_5),1,book);
        fclose(book);
        break;
    case 6:
        changestatus1(busstatus_6,travellers,busno);
        book=fopen("bus6.txt","w");
        fwrite(busstatus_6,sizeof(busstatus_6),1,book);
        fclose(book);
        break;
    }
    partition1();
    return;
}
/**
 * @brief asks user the seat he/she wants to cancel and stores in strcuture and
 * changes seats to empty
 * 
 * @param travellers 
 * @param status -->seat stauts
 */
void changestatus2(int travellers,char status[][COLUMN2])
{
    for (int i = 0; i < travellers; i++)
        {
            printf("Seat number of %s %s:", passenger[i].firstname, passenger[i].lastname);
            scanf("%d", &passenger[i].seat);
            if (strcmp(status[passenger[i].seat - 1], "Reserved") == 0) //this checks if the entered seat is reserved or not
            {
                strcpy(status[passenger[i].seat - 1], "Empty"); //changes seat status to Empty
                strcpy(passenger[i].status, "CANCELLED");            //this is used to print seat status cancelled in file
                
            }
            else
            {
                printf("\xcd\xcd\xcdTHE ENTERED SEATS IS ALREADY EMPTY\xcd\xcd\xcd\n");
            }
        }

}
/**
 * @brief this asks user the reserved seat and opens file to write the seat status
 * 
 * @param travellers ->no of travellers
 * @param busno 
 */
void cancelseats(int travellers, int busno)
{
    partition2();
    printf("\n");
    switch (busno)
    {
    case 1:
        changestatus2(travellers,busstatus_1);
        book=fopen("bus1.txt","w");  //destroys older file if exist
        fwrite(busstatus_1,sizeof(busstatus_1),1,book);  //writes bus status in a file
        fclose(book);
        break;
    case 2:
        changestatus2(travellers,busstatus_2);
        book=fopen("bus2.txt","w");
        fwrite(busstatus_2,sizeof(busstatus_2),1,book);
        fclose(book);
        break;
    case 3:
        changestatus2(travellers,busstatus_3);
        book=fopen("bus3.txt","w");
        fwrite(busstatus_3,sizeof(busstatus_3),1,book);
        fclose(book);
        break;
    case 4:
        changestatus2(travellers,busstatus_4);
        book=fopen("bus4.txt","w");
        fwrite(busstatus_4,sizeof(busstatus_4),1,book);
        fclose(book);
        break;
    case 5:
        changestatus2(travellers,busstatus_5);;
        book=fopen("bus5.txt","w");
        fwrite(busstatus_5,sizeof(busstatus_5),1,book);
        fclose(book);
        break;
    case 6:
        changestatus2(travellers,busstatus_6);
        book=fopen("bus6.txt","w");
        fwrite(busstatus_6,sizeof(busstatus_6),1,book);
        fclose(book);
        break;
    }

    partition1();
    return;
}
