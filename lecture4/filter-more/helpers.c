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
    RGBTRIPLE copy[height][width];
    for (int h_id = 0; h_id < height; h_id++)
    {
        for (int w_id = 0; w_id < width; w_id++)
        {
            copy[h_id][w_id] = image[h_id][w_id];
        }
    }
    int pixel_3by3_permutations[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int h_id = 0; h_id < height; h_id++)
    {
        for (int w_id = 0; w_id < width; w_id++)
        {
            int gxRedSum = 0;
            int gxGreenSum = 0;
            int gxBlueSum = 0;
            int gyRedSum = 0;
            int gyGreenSum = 0;
            int gyBlueSum = 0;

            for (int i = 0; i < 9; i++)
            {
                int rowPermutation = pixel_3by3_permutations[i][0];
                int colPermutation = pixel_3by3_permutations[i][1];

                int around_pixel_row = h_id + rowPermutation;
                int around_pixel_column = w_id + colPermutation;

                if (around_pixel_row < 0 || around_pixel_column < 0 || around_pixel_row >= height || around_pixel_column >= width)
                {
                    continue;
                }
                
                RGBTRIPLE current_pixel = copy[around_pixel_row][around_pixel_column];

                int gxMultiplier = 1;
                if (rowPermutation == 0)
                {
                    gxMultiplier = 2;
                }

                gxRedSum += current_pixel.rgbtRed * colPermutation * gxMultiplier;
                gxGreenSum += current_pixel.rgbtGreen * colPermutation * gxMultiplier;
                gxBlueSum += current_pixel.rgbtBlue * colPermutation * gxMultiplier;                  

                int gyMultiplier = 1;
                if (colPermutation == 0)
                {
                    gyMultiplier = 2;
                }

                gyRedSum += current_pixel.rgbtRed * rowPermutation * gyMultiplier;
                gyGreenSum += current_pixel.rgbtGreen * rowPermutation * gyMultiplier;
                gyBlueSum += current_pixel.rgbtBlue * rowPermutation * gyMultiplier;                  
            }
            int edgeRed = (int) round(sqrt(pow(gxRedSum, 2) + pow(gyRedSum, 2)));
            if (edgeRed > 255)
            {
                edgeRed = 255;
            }

            int edgeGreen = (int) round(sqrt(pow(gxGreenSum, 2) + pow(gyGreenSum, 2)));
            if (edgeGreen > 255)
            {
                edgeGreen = 255;
            }

            int edgeBlue = (int) round(sqrt(pow(gxBlueSum, 2) + pow(gyBlueSum, 2)));
            if (edgeBlue > 255)
            {
                edgeBlue = 255;
            }

            image[h_id][w_id].rgbtRed = edgeRed;
            image[h_id][w_id].rgbtGreen = edgeGreen;
            image[h_id][w_id].rgbtBlue = edgeBlue;
        }
    }
    return;
}
