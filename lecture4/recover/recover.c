#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: recover file_path\n");
        return 1;
    }
    FILE *rawFile = fopen(argv[1], "r");

    if (rawFile == NULL)
    {
        printf("The programm couldn't open the file, please check the file path.");
        return 1;
    }
}