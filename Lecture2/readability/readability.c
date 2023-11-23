#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_index(int letters, int words, int sentences);

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

int calculate_index(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    return round(0.0588 * L - 0.296 * S - 15.8);
}
