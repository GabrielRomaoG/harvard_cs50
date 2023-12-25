#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h_id = 0; h_id < height; h_id++)
    {
        for (int w_id = 0; w_id < width; w_id++)
        {
            if (image[h_id][w_id].rgbtRed == 0x00 && image[h_id][w_id].rgbtGreen == 0x00 && image[h_id][w_id].rgbtBlue == 0x00)
            {
                image[h_id][w_id].rgbtBlue = 0xff;
            }
        }
    }
}
