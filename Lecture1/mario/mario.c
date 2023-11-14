#include <cs50.h>
#include <stdio.h>

void print_pyramid(int height);

int main(void) 
{
    int height;
    do
    {
        height = get_int("Height: ");
        print_pyramid(height);
    } while (height < 1);
}

void print_pyramid(int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        for (int i = 0; i < row + 1; i++)
        {
            printf("#");       
        }

        printf(" ");

        for (int i = 0; i < row + 1; i++)
        {
            printf("#");       
        }

        printf("\n");
    }
}