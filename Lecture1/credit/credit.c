#include <cs50.h>
#include <stdio.h>

string validateCreditCardNumber(long long const card_number);
long long power(int base, int exponent);

int main(void)
{
    long long number = get_long_long("Number: ");
    printf("%s\n", validateCreditCardNumber(number));
}

string validateCreditCardNumber(long long const card_number)
{
    // Luhn's validation
    int checksum = 0;
    int card_length = 0;

    for (long long end_number_test = card_number; end_number_test != 0; end_number_test /= 10)
    {
        int digit = end_number_test % 10;
        if (card_length % 2 == 1)
        {
            digit *= 2;
        }
        checksum += digit / 10 + digit % 10;
        card_length++;
    }
    if (checksum % 10 != 0)
    {
        return "INVALID";
    }

    int first_two_digits = card_number / power(10, card_length - 2);
    int first_digit = first_two_digits / 10;

    if ((first_two_digits == 34 || first_two_digits == 37) && card_length == 15)
    {
        return "AMEX";
    }
    if (51 <= first_two_digits && first_two_digits <= 55 && card_length == 16)
    {
        return "MASTERCARD";
    }
    if (first_digit == 4 && (card_length == 13 || card_length == 16))
    {
        return "VISA";
    }
    return "INVALID";
}

long long power(int const base, int const exponent)
{
    if (exponent == 1)
    {
        return base;
    }
    return base * power(base, exponent - 1);
}
