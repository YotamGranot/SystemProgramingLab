

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_LEN 100

typedef struct {
    /*complex type have real and imaginary parts*/
    double real;
    double img;
} comp;
typedef enum commands {
    /*commands sorted by number of parameters and type of parameters*/
    eror = 0, stopp, print, absC, add, sub, multCC, multCR, multCI, read
}commands;

/*functions in complex.c*/



void stop(); /* exit from program*/

void print_comp(comp *);/*print complex number*/

void abs_comp(comp *);/*print absolute value of complex number*/

void read_comp(comp *, double, double);/*read values from user into complex number*/

void add_comp(comp *, comp *);/*print sum of two complex numbers*/

void sub_comp(comp *, comp *);/*print difference of two complex numbers*/

void mult_comp_comp(comp *, comp *);/* print multiplication of two complex numbers*/

void mult_comp_real(comp *, double);/* print multiplication of complex number and real number*/

void mult_comp_img(comp *, double);/* print multiplication of complex number and imaginary number**/

comp *create_comp();/*create new complex in memory*/


/*functions in analysis.c*/
int analysis_command(char []);/*full analysis of command, return 0 if  no errors and specific number for each error if exists*/

void analysis_command_name(char []);/*analysis of command name*/

int count_commas(char []);/*count commas in command*/

int count_args(char []);/*count arguments in command*/

void analysis_first_parameter(char []);/*analysis of first argument*/

void analysis_second_parameter_comp(char []);/*analysis of second argument if it's complex*/

double analysis_second_parameter_real(char []);/*analysis of second argument if it's real*/

double analysis_third_parameter_real(char []);/*analysis of third argument if it's real**/

int check_commas(char []);/*check commas error*/

void call_func(comp *[]);/*call the correct function*/
