#include <cs50.h>
#include <stdio.h>

void print_pyramid(int height);

int main(void) 
{
    int height;
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);
    print_pyramid(height);
}

void print_pyramid(int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        for (int brick = 0; brick < row + 1; brick++)
        {
            printf("#");       
        }

        printf("  ");

        for (int brick = 0; brick < row + 1; brick++)
        {
            printf("#");       
        }

        printf("\n");
    }
}