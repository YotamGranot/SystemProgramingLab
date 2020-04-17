#include "numbers.h"
/*program to convert number from int to number name*/
int main(int argc, char *argv[]) {
    extern char numberName[NAME_MAX_LEN];/*variable stores number name*/
    char c;/*char from fd1*/
    char ch[1];/*char from fd1 as String*/
    char number[3];/*whole number*/
    int n;/*number as int*/
    FILE *fd1;
    FILE *fd2;/*pointers to file*/
    strcpy(number,"");/*reset number string*/
    if(argc>3){
        /*to many arguments*/
        fprintf(stderr,"Error: To Many command line arguments given\n");
        exit(0);
    }
    if(argc == 1){
        /*input and output to stdio*/
        while(scanf("%d",&n)==1)/*while possible get numbers*/ {
            convert(n);/*convert number to name string*/
            puts(numberName);/*print the name*/
        }
        exit(0);
    }
    if(argc ==2){
        fd1 = fopen(argv[1], "rt");/*open input file*/
		if(fd1 == NULL){
		    /*check if file opened properly*/
			fprintf(stderr,"Error couldn't open input file\n");
			exit(0);
		}
        fd2=stdout;/*set output file as stdout*/
    }
    else{
        fd1 = fopen(argv[1], "rt");/*open input file*/
        fd2 = fopen(argv[2], "wt");/*open output file*/
        if(fd1 == NULL){
            /*check if file opened properly*/
			fprintf(stderr,"Error: couldn't open input file\n");
			exit(0);
		}
		if(fd2 == NULL){
            /*check if file opened properly*/
			fprintf(stderr,"Error: couldn't open output file\n");
			exit(0);
		}
    }

    while(!feof(fd1)){
        /*while we in file*/
        c=fgetc(fd1);/*get char*/
        if(isdigit(c)){
            /*if it's digit append it to number*/
            ch[0]=c;
            strcat(number,ch);
            strcpy(ch,"");
        }
        if(isspace(c)){
            /*if space convert the number to it's name and print it*/
            number[2] = '\0';
            if(strlen(number)>0) {
                n = atoi(number);
                convert(n);
                fputs(numberName,fd2);
                fputs("\n",fd2);
                strcpy(number,"");
            }
        }
    }
    return 0;
}

