#ifndef busdetail_h
#define busdetail_h

#include <stdio.h>
#include <stdlib.h>
#define ROW1 6
#define COLUMN1 30
/**
 * @brief arrays for bus route and bus name
 * 
 */
char route[ROW1][COLUMN1] = {"KATHMANDU-JHAPA-TAPLEJUNG", "TAPLEJUNG-JHAPA-KATHMANDU", "KATHMANDU-POKHARA", "POKHARA-KATHMANDU", "KATHMANDU-DELHI", "DELHI-KATHMANDU"}; //array for routes
char buses[ROW1][COLUMN1] = {"Python Express", "Java Express", "C Express", "CSS Express", "HTML Express", "C-Plus Express"};

int busno;  //golblly decalred variable for bus number;

void partition1();
void partition2();
void bus_route();
void bus_list();
void busnumber();

#endif