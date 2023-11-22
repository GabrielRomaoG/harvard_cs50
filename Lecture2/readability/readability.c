#include <cs50.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int letters = count_letters("AloHa  Zi!!!...");
}

int count_letters(string text)
{
    int count = 0;
    for (int character_pos = 0; text[character_pos] != '\0'; character_pos++)
    {
        char character = text[character_pos];
        if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int character_pos = 0; text[character_pos] != '\0'; character_pos++)
    {
        char character = text[character_pos];
        if (character == 32)
        {
            count++;
        }
    }
    return count + 1;    
}

int count_sentences(string text)
{
    int count = 0;
    for (int character_pos = 0; text[character_pos] != '\0'; character_pos++)
    {
        char character = text[character_pos];
        if (character == 33 || character == 46 || character == 63)
        {
            count++;
        }
    }
    return count;    
}