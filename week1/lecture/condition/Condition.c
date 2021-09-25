//This is C code
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("Enter first value: ");
    int y = get_int("Enter second value: ");

    if (x > y)
    {
        printf("%i greater than %i\n", x, y);
    }
    else if (x < y)
    {
        printf("%i less than %i\n", x, y);
    }
    else printf("%i equal to %i\n", x, y);
}