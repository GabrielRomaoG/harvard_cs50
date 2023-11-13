#include <cs50.h>
#include <stdio.h>

int get_population_years(int start_population, int end_population);

int main(void)
{
    int start_population;
    int end_population;

    do
    {
        start_population = get_int("Start size: ");
    }
    while (start_population < 9);

    do
    {
        end_population = get_int("End size: ");
    }
    while (end_population < start_population);

    int years = get_population_years(start_population, end_population);
    printf("Years: %i\n", years);
}

int get_population_years(int start_population, int end_population)
{
    int years = 0;
    while (start_population < end_population)
    {
        start_population = start_population + (start_population / 3) - (start_population / 4);
        years++;
    }
    return years;
}
