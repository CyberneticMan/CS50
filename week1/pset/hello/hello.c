// This is C code
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask username
    string username = get_string("What's your name?\n");

    // Prompt %username%
    printf("Hello, %s\n", username);
}