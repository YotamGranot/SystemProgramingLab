

#include "complex.h"

int main(){
    char command[MAX_LEN];
    int analysis;
    comp * A, *B, *C, *D, *E, *F;
    comp *ptrs[6];
    /*create memory space for complex variables*/
    A=create_comp();
    B=create_comp();
    C=create_comp();
    D=create_comp();
    E=create_comp();
    F=create_comp();
    /*reset all complex variables*/
    read_comp(A,0,0);
    read_comp(B,0,0);
    read_comp(C,0,0);
    read_comp(D,0,0);
    read_comp(E,0,0);
    read_comp(F,0,0);
    /*set each variable to his location in array*/
    ptrs[0]=A;
    ptrs[1]=B;
    ptrs[2]=C;
    ptrs[3]=D;
    ptrs[4]=E;
    ptrs[5]=F;

    while(TRUE){
        puts("\nplease enter command");
        fgets(command,MAX_LEN,stdin);
        puts(command);
        analysis =analysis_command(command);
        switch (analysis){
            case 1:
                continue;
            case 2:
                puts("To Many parameters.");
                break;
            case 3:
                puts("undefined command.");
                break;
            case 4:
                puts("undefined complex.");
                break;
            case 5:
                puts("missing parameter.");
                break;
            case 6:
                puts("missing comma.");
                break;
            case 7:
                puts("Illegal comma.");
                break;
            case 8:
                puts("multiple consecutive comma.");
                break;
            case 9:
                puts("extra text");
                break;
            case 10:
                puts("invalid parameter, not a complex.");
                break;
            case 11:
                puts("invalid parameter, not a number.");
                break;
            default:
                call_func(ptrs);
        }
    }
}
