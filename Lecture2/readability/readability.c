#include <cs50.h>
#include <stdio.h>

int count_letters(string text);

int main(void)
{
    int letters = count_letters("AloHa  Zi!!!...");
}

int count_letters(string text)
{
    int count = 0;
    for (int letter_pos = 0; text[letter_pos] != '\0'; letter_pos++)
    {
        char character = text[letter_pos];
        if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122))
        {
            count++;
        }
    }
    return count;
}