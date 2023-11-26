#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool has_repeated_characters(string key);
void print_encrypted_cipher(string key, string plaintext);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: %s KEY", argv[0]);
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.○\n");
        return 1;
    }
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    if (has_repeated_characters(key))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    string plaintext = get_string("plaintext:  ");
    
    printf("ciphertext: ");
    print_encrypted_cipher(key, plaintext);
    printf("\n");
    return 0;
}

bool has_repeated_characters(string key)
{
    bool repeated_chars_test[26] = {};
    for (int i = 0; key[i] != '\0'; i++)
    {
        int bool_index = tolower(key[i]) - 'a';

        if (repeated_chars_test[bool_index] == true)
        {
            return true;
        }

        repeated_chars_test[bool_index] = true;
    }
    return false;
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
        if (islower(character))
        {
            printf("%c", tolower(upper_key[character - 'a']));
        }
        if (isupper(character))
        {
            printf("%c", upper_key[character - 'A']);
        }
    }
}