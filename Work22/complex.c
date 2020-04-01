#include "complex.h"

void stop() {
    exit(0);
}

void print_comp(comp *complex) {
    if(complex->img<0){
        printf("%.10g-(%.10g)i", complex->real, fabs(complex->img));
        return;
    }
    printf("%.10g+(%.10g)i", complex->real, complex->img);
    return;
}

void abs_comp(comp *complex) {
    printf("%.10g", sqrt(pow(complex->real, 2) + pow(complex->img, 2)));
    return;
}

void add_comp(comp *c1, comp *c2) {
    comp *temp = create_comp();
    read_comp(temp, c1->real + c2->real, c1->img + c2->img);
    print_comp(temp);
    return;
}

void sub_comp(comp *c1, comp *c2) {
    comp *temp = create_comp();
    read_comp(temp, c1->real - c2->real, c1->img - c2->img);
    print_comp(temp);
    return;
}

void mult_comp_comp(comp *c1, comp *c2) {
    comp *temp = create_comp();
    read_comp(temp, (c1->real * +c2->real) - (c1->img * c2->img), (c1->real * c2->img) + (c1->img * c2->real));
    print_comp(temp);
    return;
}

void mult_comp_img(comp *c1, double i) {
    comp *temp = create_comp();
    read_comp(temp, ((-1) * i * c1->img), i * c1->real);
    print_comp(temp);
    return;
}

void mult_comp_real(comp *c1, double r) {
    comp *temp = create_comp();
    read_comp(temp, c1->real * r, c1->img * r);
    print_comp(temp);
    return;
}

void read_comp(comp *c1, double real, double img) {
    c1->real = real;
    c1->img = img;
    return;
}

comp *create_comp() {
    void *ptr = malloc(sizeof(comp));
    comp *temp = ptr ? ptr : create_comp();
    return temp;
}
