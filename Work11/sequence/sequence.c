#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
#define MAX_LEN 101 /*the max length is 100+1*/
void f_sequence(char []);
int main()
{
    char str1[MAX_LEN];
    printf("please enter a string\n");
    scanf("%s", str1);
    f_sequence(str1);
    return 0;
}
void f_sequence(char string[])
{
    int increasing, decreasing, equal;/*flags for inc, dec, equal transition*/
    char curr=string[0], prev;
    int i;
    printf("the string %s is ", string);

    increasing=false;
    decreasing=false;
    equal=false;       /*defult value is false*/

    if(curr=='\0'||strlen(string)==1){
        puts(" strictly increasing");
        /*if the string is empty or 1 char long*/
        return;
    }

    for(i=1;string[i]!='\0'&&!(increasing==true&&decreasing==true);i++)
    {
        prev=curr;
        curr=string[i];
        if(curr>prev){
        /*if inc transition*/
            increasing=true;
        }
        else if(prev>curr){
            /*if dec transition*/
            decreasing=true;
        }
        else if(prev==curr){
            /*if equal transition*/
            equal=true;
        }

    }
    if(increasing==true&&decreasing==true){
        /*if there were both inc and dec transitions there is no order*/
        puts(" not ordered");
        return;
    }
    else if(increasing==true&&equal==true){
        /*if there were both inc and equal transitions there is it's increasing*/
        puts(" incresing");
        return;
    }
    else if(decreasing==true&&equal==true){
         /*if there were both dec and equal transitions there it's decreasing*/
        puts( " decreasing");
        return;
    }
    else if(increasing==true){         
        /*if there were both inc and not equal transitions there it's strictly increasing*/
        puts(" strictly increasing");
        return;
    }
    else if(decreasing==true){        
        /*if there were both dec and not equal transitions there it's strictly decreasing*/
        puts(" strictly decreasing");
        return;
    }
    else{ 
        /*not anything else so equal => inc*/
        puts("increasing");
        return;
    }
    
}
