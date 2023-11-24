#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

void print_encrypted_cipher(string key, string plaintext);

int main(int argc, string argv[])
{
    string test = encrypt_cipher("aaaaaa");
    return 0;
}

void print_encrypted_cipher(string key, string plaintext)
{
    char upper_key[26];
    for (int i = 0; key[i] != '\0'; i++)
    {
        upper_key[i] = toupper(key[i]);
    }
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char character = plaintext[i];
        if (!isalpha(character))
        {
            printf("%c", character);
        }
        char upper_letter = toupper(character);
        char encrypted_char = upper_key[upper_letter - 'A'];

        if (islower(character))
        {
            printf("%c", tolower(encrypted_char));
        }
        if (isupper(character))
        {
            printf("%c", encrypted_char);
        }
    }
}