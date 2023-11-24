#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void print_encrypted_cipher(string key, string plaintext);

int main(int argc, string argv[])
{
    string key =  argv[1];

    if (argc != 2)
    {
        printf("Usage: %s KEY", argv[0]);
        return 1;
    }

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.");
            return 1;
        }
        for (int seg_char = 0; seg_char < i; seg_char ++)
        {
            if (key[i] == key[seg_char])
            {
                printf("Key must not contain repeated characters.");
                return 1;
            }
        }
    }
    string plaintext = get_string("plaintext:  ");
    
    printf("ciphertext: ");
    print_encrypted_cipher(key, plaintext);
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

        char encrypted_char = upper_key[toupper(character) - 'A'];

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