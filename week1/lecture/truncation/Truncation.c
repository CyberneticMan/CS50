//This is C code
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("Enter first number: ");
    int y = get_int("Enter second number: ");

    float z = (float)x / (float)y;

    printf("%i / %i = %f\n", x, y, z);
}