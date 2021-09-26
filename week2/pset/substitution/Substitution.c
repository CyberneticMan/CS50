// This is C code
#include <cs50.h>
#include <stdio.h>

void encrypt(string text, string key);

const string ALPHABET_UP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Source alphabets
const string ALPHABET_LOW = "abcdefghijklmnopqrstuvwxyz";
const int ASCII_SHIFT = 32; // Range between 'A' & 'a', 'B' & 'b', etc.
const int TOP_EDGE = 90; // ASCII code for 'Z'
const int BOTTOM_EDGE = 65; // ASCII code for 'A'

int main(int argc, string argv[])
{
    // Check a correctness of argument input
    if (argc != 2) // Too much arguments or too lettle
    {
        printf("USAGE ./Substitution KEY\n");
        return 1;
    }
    int i;
    for (i = 0; argv[1][i] != '\0'; i++)
    {
        if (((argv[1][i] > TOP_EDGE) || (argv[1][i] < BOTTOM_EDGE))
            && ((argv[1][i] > (TOP_EDGE + ASCII_SHIFT))
                || (argv[1][i] < (BOTTOM_EDGE + ASCII_SHIFT)))) // Check for that key contain only letters
        {
            printf("USE ONLY LEETER\n");
            return 1;
        }
        for (int j = i + 1; argv[1][j] != '\0'; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("USE EACH LETTER ONLY ONECE\n"); // Cher for repeating in key
                return 1;
            }
        }
    }
    if (i != 26) // Check for count of letters in key
    {
        printf("NEEDS 26 ALPHABET\n");
        return 1;
    }

    // Ask User for input a text which will be encrypted
    string Plaintext = get_string("Plaintext: ");

    // Encrypt a text
    encrypt(Plaintext, argv[1]);

    // Output the text in encrypt form
    printf("Ciphertext: %s\n", Plaintext);
    return 0;
}

void encrypt(string text, string key)
{
    int i;
    int j;
    bool Up_Source_Text;
    bool Low_Source_Text;
    bool Is_It_Letter;
    bool Up_Key;
    bool Low_Key;
    for (i = 0; text[i] != '\0'; i++)
    {
        Up_Source_Text = (text[i] >= BOTTOM_EDGE) && (text[i] <= TOP_EDGE); // Is text[i] a letter in uppercase?
        Low_Source_Text = (text[i] >= (BOTTOM_EDGE + ASCII_SHIFT))
                          && (text[i] <= (TOP_EDGE + ASCII_SHIFT)); // Is text[i] a letter in lowercase?
        Is_It_Letter = Up_Source_Text || Low_Source_Text; // Is text[i] a letter?
        if (Is_It_Letter)
        {
            if (Up_Source_Text) // If text[i] is a letter, then it is either uppercase or lowercase
            {
                for (j = 0; (text[i] != ALPHABET_UP[j]); j++);
                Up_Key = (key[j] >= BOTTOM_EDGE) && (key[j] <= TOP_EDGE); // Is key[j] a letter in uppercase?
                Low_Key = !(Up_Key); // Key contain only letters, it's mean that if a letter not in uppercase, then that letter in lowercase...
                if (Up_Key)
                {
                    text[i] = key[j];
                }
                else
                {
                    text[i] = key[j] - ASCII_SHIFT;
                }
            }
            else
            {
                for (j = 0; (text[i] != ALPHABET_LOW[j]); j++);
                Up_Key = (key[j] >= BOTTOM_EDGE) && (key[j] <= TOP_EDGE); // ...and vice versa
                Low_Key = !(Up_Key);
                if (Low_Key)
                {
                    text[i] = key[j];
                }
                else
                {
                    text[i] = key[j] + ASCII_SHIFT;
                }
            }
        }
        else // text[i] isn't letter, let's get the next character
        {
            continue;
        }
    }
}