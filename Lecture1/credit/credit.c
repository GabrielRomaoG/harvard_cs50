#include <cs50.h>
#include <stdio.h>

string validateCreditCardNumber(long long const card_number);
int power(int base, int exponent);

int main(void)
{
    long long number = 4003600000000014;
    printf("%s", validateCreditCardNumber(number));
}

string validateCreditCardNumber(long long const card_number)
{
    string validation_output = "INVALID";
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
        checksum += digit;
        card_length++;
    }
    if (checksum % 10 != 0)
    {
        return validation_output;
    }

    int first_two_digits = card_number / power(10, card_length - 2);
    int first_digit = first_two_digits / 10;

    if (first_two_digits == 34 || first_two_digits == 37 && card_length == 15)
    {
        validation_output = "AMEX";
    }
    if (51 <= first_two_digits <= 55 && card_length == 16)
    {
        validation_output = "MASTERCARD";
    }
    if (first_two_digits == 34 || first_two_digits == 37 && card_length == 15)
    {
        validation_output = "VISA";
    }
    return validation_output;
}

int power(int const base, int const exponent)
{
    if (exponent == 1)
    {
        return base;
    }
    return base * power(base, exponent - 1);
}