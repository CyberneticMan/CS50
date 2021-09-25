// This is C code
#include <stdio.h>
#include <cs50.h>

bool checksum(unsigned long cardNumber);

void checksys(unsigned long cardNumber);

int main(void)
{
    unsigned long number = get_long("Enter a card number: ");
    if (checksum(number))
    {
        checksys(number);
    }
    else
    {
        printf("INVALID\n");
    }
}

void checksys(unsigned long cardNumber) // This function check that pay system of card
{
    unsigned long lastDigit, pre_lastDigit; // Code of pay system
    int digitCount = 0;
    while (cardNumber > 10) // Get the penultimate digit
    {
        pre_lastDigit = cardNumber % 10;
        cardNumber /= 10;
        digitCount++; // Get the length of card number (except last digit)
    }
    lastDigit = cardNumber; // Get the last digit
    digitCount++; // Get final value of number's length (involve last digit)
    if (lastDigit == 4 && (digitCount == 13 || digitCount == 16)) // Print the system
    {
        printf("VISA\n");
    }
    else
    {
        if (lastDigit == 3 && (pre_lastDigit == 4 || pre_lastDigit == 7) && digitCount == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            if (lastDigit == 5 && (pre_lastDigit == 1 || pre_lastDigit == 2 || pre_lastDigit == 3 || pre_lastDigit == 4 || pre_lastDigit == 5) && digitCount == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}

bool checksum(unsigned long cardNumber) // This function check the control sum of number
{
    unsigned long sumTwo = 0; // Amount of digit in an even position, that multiplied by 2
    unsigned long sumOne = 0; // Amount of digit in an odd position
    while (cardNumber > 0) // Counts the first and second amount
    {
        sumOne += (cardNumber % 10);
        cardNumber /= 10;
        sumTwo += (cardNumber % 10) * 2;
        cardNumber /= 10;
    }
    if ((sumOne + sumTwo) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}