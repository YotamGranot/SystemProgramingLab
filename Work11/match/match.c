#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
#define MAX_LEN 101 /*max length of the text and pattern string*/


int bestMatch(char [], char []); /* function that find the best position*/
int diff(char [], char [], int);/* Auxiliary function to find between the pattern and position*/
void printPos(char [], int, int);/*Auxiliary function to print position*/
int main()
{
    int bestPos;
    char pattern[MAX_LEN];
    char text[MAX_LEN];
    int length;
    printf("please enter pattern string\n");
    fgets(pattern,MAX_LEN,stdin);/*scan for pattern*/
    printf("please enter text string\n");
    fgets(text,MAX_LEN,stdin);/*scan for text*/
    printf("the pattern is: %s\n",pattern);/*print pattern*/
    printf("the text string is: %s\n",text);/*print text*/
    bestPos = bestMatch(text,pattern);
    printf("the best position is %d and it is: ", bestPos);
    length = strlen(pattern);
    printPos(text,length-1,bestPos);
    printf("\n");
    return 0;
}
int bestMatch(char text[], char pattern[])
{
int i;
    int diffrance;
    int best = strlen(pattern);/*the worst possible diffrance is length of pattern*/
    int indexBest = 0;
    if(strlen(text)==0){
        /*Extreme case that text length is 0 the best position is the first empty position, 0*/
        return 0;
    }
    
    for(i=0;i<strlen(text)-strlen(pattern)+1;i++){
        diffrance = diff(text,pattern,i);/*find diffrance in specific position*/
        if(diffrance<best){
            indexBest = i;
            best = diffrance;
        }
    }
    return indexBest;
}
int diff(char text[], char pattern[], int index)
{
    int i;
    int count = 0;
    int j=index;

    for(i=0;i<strlen(pattern);i++,j++){

        if(text[j]!=pattern[i]){
            count++;
        }
    }
    return  count;

}
void printPos(char string[], int length, int pos)
{
    int c=0;
    char sub[MAX_LEN];
    while(c<length)
    {
        sub[c]=string[pos];
        c++;
        pos++;
    }
    sub[c] = '\0';
    printf("%s", sub);
}
