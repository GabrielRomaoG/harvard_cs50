#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_index(int letters, int words, int sentences);
void print_grade(string text);

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

void print_grade(string text)
{
    int index = calculate_index(count_letters(text), count_words(text), count_sentences(text));

    if (index < 1)
    {
        printf("Before Grade 1");
    }
    if (index >= 1 && index < 16)
    {
        printf("Grade: %i", index);
    }
    if (index >= 16)
    {
        printf("Grade 16+");
    }
}
