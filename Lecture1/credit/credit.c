#include <cs50.h>
#include <stdio.h>

void validateCreditCardNumber(long long const card_number);
int power(int base, int exponent);

int main(void)
{

    long long number = 6176292929;
    // long long divided = number / 10;
    validateCreditCardNumber(number);
}

void validateCreditCardNumber(long long const card_number)
{
    long long end_number_test = card_number;
    int sum = 0;

    for (int position = 0; end_number_test != 0; position++)
    {
        int digit = end_number_test % 10;
        end_number_test /= 10;
        
        if (position % 2 == 1)
        {
            digit *= 2;
        }

        sum += digit;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID");
    }
}

int power(int const base, int const exponent)
{
    if (exponent == 1)
    {
        return base;
    }
    return base * power(base, exponent - 1);
}