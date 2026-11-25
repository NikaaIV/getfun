
#include <stdio.h>
#include <stdlib.h>
#include "getfun.h"

int main(void)
{
    char letter = store_char("type a letter: ");
    int number = store_int("type a number: ");
    long numberbig = store_long("type a big number: ");
    float decimal = store_float("type a number with a decimal: ");
    double precise = store_double("type a number with a lot of decimals: ");
    string phrase = store_string("type a long string: ");

    printf("\n--- summary ---\n");
    printf("Char: %c\n", letter);
    printf("Int: %d\n", number);
    printf("Long: %ld\n", numberbig);
    printf("Float: %f\n", decimal);
    printf("Double: %.10lf\n", precise);
    printf("String: %s\n", phrase);

    free(phrase); 
}
