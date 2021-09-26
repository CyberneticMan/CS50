//This is C code
#include <cs50.h>
#include <stdio.h>

unsigned int letters_counter(string input);

unsigned int words_counter(string input);

unsigned int sentence_counter(string input);

float Coleman_Liau_index(unsigned int letters, unsigned int words, unsigned int sentence);

int main(void)
{
    string text = get_string("Text: ");
    float grade = Coleman_Liau_index(letters_counter(text), words_counter(text), sentence_counter(text));
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        if (grade >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %.0f\n", grade);
        }
    }
}

unsigned int letters_counter(string input) //This function count a letters number in text
{
    unsigned int lettersCount = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
        {
            lettersCount++;
        }
    }
    return lettersCount;
}

unsigned int words_counter(string input) //This function count a words number in text
{
    unsigned int wordsCount = 1;
    for (int i = 1; input[i] != '\0'; i++)
    {
        if (input[i - 1] == ' ' && input[i] != ' ')
        {
            wordsCount++;
        }
    }
    return wordsCount;
}

unsigned int sentence_counter(string input) //This function count a sentencies number in text
{
    unsigned int sentenceCount = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}

float Coleman_Liau_index(unsigned int letters, unsigned int words, unsigned int sentence) //This function compute the index of text
{
    float average_letters = letters * 100.0 / words; //Average letters per 100 words
    float average_sentence = sentence * 100.0 / words; //[...] sentencies per 100 [...]
    float index = 0.0588 * average_letters - 0.296 * average_sentence - 15.8;
    return index;
}