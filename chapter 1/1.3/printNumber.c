#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void printDigit(char inte){
    if(inte == '.')
        printf(".");
    else
        printf("%d", inte);
}

void printNumber(float num){
    int i;
    int max_decimal_digit = 6,decimal_digit = 0;
    int integer = (int)floor(num);
    float decimal = num - integer;
    printf("%f\n", integer + decimal);
    
    //print integer
    int digit =  (int)ceil(log(integer)/log(10)),cnt = 0 ;
    if(digit>0){
        char *stack = (char*)malloc(sizeof(char) * digit);
        memset(stack,0,sizeof(char)*digit);

        while(integer>0){
            int remainder = integer%10;
            stack[cnt++] = (char)remainder;
            integer = (integer-remainder)/10;
        }

        for(i = digit-1;i >= 0;--i){
            printDigit(stack[i]);
        }
    }else {
        printDigit(0);
    }

    //print decimal
    if(0 == decimal){
        return;
    }

    printDigit('.');

    while(fabs(0 - decimal)>1e-6 && decimal_digit<max_decimal_digit){
        decimal *= 10;
        ++decimal_digit;
        printDigit((char)floor(decimal));
        decimal = decimal - floor(decimal);
    }

    printf("\n");
}

int main(int argc,char* argv[]){
    srand(time(NULL));
    float tar = rand()/1e6f;
    printNumber(tar);
    return 0;
}