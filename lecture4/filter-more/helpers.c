#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h_id = 0; h_id < height; h_id++)
    {
        for (int w_id = 0; w_id < width; w_id++)
        {
            int rgb_average = round((image[h_id][w_id].rgbtRed + image[h_id][w_id].rgbtGreen + image[h_id][w_id].rgbtBlue) / 3.0);
            image[h_id][w_id].rgbtRed = rgb_average;
            image[h_id][w_id].rgbtGreen = rgb_average;
            image[h_id][w_id].rgbtBlue = rgb_average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int w_id = 0; w_id < width / 2; w_id++)
    {
        for(int h_id = 0; h_id < height; h_id++)
        {
            RGBTRIPLE tmp_pixel = image[h_id][w_id];
            int rev_pixel_id = width - w_id - 1;
            image[h_id][w_id] = image[h_id][rev_pixel_id];
            image[h_id][rev_pixel_id] = tmp_pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int h_id = 0; h_id < height; h_id++)
    {
        for (int w_id = 0; w_id < width; w_id++)
        {
            copy[h_id][w_id] = image[h_id][w_id];
        }
    }
    int around_pixel_permutations[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int h_id = 0; h_id < height; h_id++)
    {
        for (int w_id = 0; w_id < width; w_id++)
        {
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            int nPixels = 0;

            for (int i = 0; i < 9; i++)
            {
                int rowSum = around_pixel_permutations[i][0];
                int colSum = around_pixel_permutations[i][1];

                int around_pixel_row = h_id + rowSum;
                int around_pixel_column = w_id + colSum;

                if (around_pixel_row < 0 || around_pixel_column < 0 || around_pixel_row >= width || around_pixel_column >= height)
                {
                    continue;
                }

                RGBTRIPLE current_pixel = copy[around_pixel_row][around_pixel_column];

                redSum += current_pixel.rgbtRed;
                greenSum += current_pixel.rgbtGreen;
                blueSum += current_pixel.rgbtBlue;

                nPixels++;
            }

            image[h_id][w_id].rgbtRed = (int) round(redSum / (float) nPixels);
            image[h_id][w_id].rgbtGreen = (int) round(greenSum / (float) nPixels);
            image[h_id][w_id].rgbtBlue = (int) round(blueSum / (float) nPixels);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
