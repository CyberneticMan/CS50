// This is C code
#include <cs50.h>
#include <stdio.h>

int get_number(void);

void pyramid_builder(int pyramidArgument);

int main(void)
{
    pyramid_builder(get_number());
}

int get_number(void) // This function ask user for a number in [1, 8] range
{
    int number;
    int topEdge = 8;
    int bottomEdge = 1;
    do
    {
        number = get_int("Enter the piramid's hight(1-8): ");
    }
    while (!((number <= topEdge) && (number >= bottomEdge)));
    return number;
}

void pyramid_builder(int pyramidArgument) // This function build pyramid with like in Mario
{
    int foundation = pyramidArgument;
    int hight = pyramidArgument;

    for (int stage = 1; stage <= hight; stage++, foundation--)
    {
        for (int shift = foundation - 1; shift > 0; shift--)
        {
            printf(" "); // Make shift between screen edge and left part of pyramid
        }
        for (int block = stage; block > 0; block--)
        {
            printf("#"); // Build left part of pyramid
        }
        printf("  "); // Make shit between left and right parts of pyramid
        for (int block = stage; block > 0; block--)
        {
            printf("#"); // Build right part of pyramid
        }
        printf("\n");
    }
}