// This is C code
#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int x = get_int("Enter first number: ");
    int y = get_int("Enter second number: ");

    printf("%i + %i = %i\n", x, y, x+y);
}