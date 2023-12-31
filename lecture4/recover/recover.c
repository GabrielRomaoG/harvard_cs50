#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

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

    unsigned char buffer[BLOCK_SIZE];
    int fileId = 0;
    FILE *imageFile = NULL;
    char fileName[8];

    while (fread(buffer, 1, BLOCK_SIZE, rawFile) == BLOCK_SIZE)
    {
        bool isJpgStart =  buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
        if (isJpgStart)
        {
            if (fileId > 0)
            {
                fclose(imageFile);
            }
            sprintf(fileName, "%03i.jpg", fileId);

            imageFile = fopen(fileName, "w");

            fwrite(buffer, 1, BLOCK_SIZE, imageFile);

            fileId++;
        }
        else if (!isJpgStart && fileId > 0)
        {
            fwrite(buffer, 1, BLOCK_SIZE, imageFile);
        }
    }
    fclose(imageFile);
    fclose(rawFile);

    return 0;
}

