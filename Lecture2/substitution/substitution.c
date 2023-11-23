#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

string encrypt_cipher(string key);

int main(int argc, string argv[])
{
    string test = encrypt_cipher("aaaaaa");
    return 0;
}

string encrypt_cipher(string key)
{
    string upper_key;
    for (int character = 0; key[character] != '\0'; character++)
    {
        upper_key[character] = toupper(key[character]);
    }
    return upper_key;
}