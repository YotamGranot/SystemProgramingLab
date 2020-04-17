/*
Created by Yotam Granot on 03/04/2020.
*/
#include "numbers.h"

char tens[10][NAME_MAX_LEN] = {"", "", "twenty", "thirty", "forty", "fifty", "Sixty", "seventy", "eighty", "ninety"};/*array that stores the tens names*/
char digits[10][NAME_MAX_LEN] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};/*array that stores the tens names*/
char unusual[10][NAME_MAX_LEN] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",/*array that stores numbers from 10-19 names*/
                                  "eighteen", "nineteen"};
char numberName[NAME_MAX_LEN];

void convert(int n) {
    /*function to convert number to it's name*/
    int digit, ten;
    strcpy(numberName,"");    /*reset name*/
    digit = n % 10;/*extract the digit*/
    ten = n / 10;/*extract the tens digit*/
    if(n==0){
        strcpy(numberName, "zero");
        return;
    }
    if (n < 10) {
        /*if number is smaller than ten its only digit*/
        strcat(numberName, digits[n]);
    } else if (n < 20) {
        /*if the number is smaller than 20 it's not the usual structure so extract his name from array*/
        strcat(numberName, unusual[digit]);
    } else {
        /*append to the name the tens and digits*/
        strcat(numberName, tens[ten]);
        strcat(numberName," ");
        strcat(numberName, digits[digit]);
    }
    return;
}

