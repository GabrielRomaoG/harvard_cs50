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
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
