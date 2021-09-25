//This is C code
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char x = get_char("Did you agree? ");

    if (x == 'y' || x == 'Y')
    {
        printf("Agree\n");
    }
    else if (x == 'n' || x == 'N')
    {
        printf("Disagree\n");
    }
    else printf("Error\n");
}