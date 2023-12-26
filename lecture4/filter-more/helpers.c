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
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
