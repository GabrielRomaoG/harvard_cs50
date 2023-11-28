#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
bool has_only_alphas(string key);
bool has_repeated_characters(string key);
void print_encrypted_cipher(string key, string plaintext);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: %s KEY", argv[0]);
        return 1;
    }

    const string key = argv[1];

    if (!is_valid_key(key))
    {
        return 1;
    }

    string plaintext = get_string("plaintext:  ");
    
    printf("ciphertext: ");
    print_encrypted_cipher(key, plaintext);
    printf("\n");
    return 0;
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.○\n");
        return false;
    }
    if (!has_only_alphas(key))
    {
        printf("Key must only contain alphabetic characters.\n");
        return false;
    }
    if (has_repeated_characters(key))
    {
        printf("Key must not contain repeated characters.\n");
        return false;
    }
    return true;
}

bool has_only_alphas(string key)
{
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
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
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char character = plaintext[i];
        if (!isalpha(character))
        {
            printf("%c", character);
        }
        if (islower(character))
        {
            printf("%c", tolower(key[character - 'a']));
        }
        if (isupper(character))
        {
            printf("%c", toupper(key[character - 'A']));
        }
    }
}