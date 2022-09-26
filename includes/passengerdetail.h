#ifndef passengerdetail_h
#define passengerdetail_h

#include<stdio.h>
#include "busdetail.h"
/**
 * @brief gets user detail and store in struct variable capable of storing 32 datas  
 * 
 * @param passengers --> Number of travellers
 * 
 */
typedef struct details
{
    char firstname[15];
    char lastname[15];
    char email[32];
    long long int mobile_no;
    int seat;
    char status[8]; //prints status in file
}passengerdetails;

passengerdetails passenger[32]; //structure vatiable capable of storing 32 passenger detail

void name_email(int passengers);
#endif