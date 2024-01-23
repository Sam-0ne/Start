#include "helpers.h"
#include <math.h>
#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            image[i][j].rgbtBlue = MIN(sepiaBlue, 255);
            image[i][j].rgbtGreen = MIN(sepiaGreen, 255);
            image[i][j].rgbtRed = MIN(sepiaRed, 255);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp;
            temp.rgbtBlue = image[i][j].rgbtBlue;
            temp.rgbtGreen = image[i][j].rgbtGreen;
            temp.rgbtRed = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp.rgbtBlue;
            image[i][width - j - 1].rgbtGreen = temp.rgbtGreen;
            image[i][width - j - 1].rgbtRed = temp.rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int number_pixels = 1;
            double blue_sum = copy[i][j].rgbtBlue * 1.0;
            double green_sum = copy[i][j].rgbtGreen * 1.0;
            double red_sum = copy[i][j].rgbtRed * 1.0;

            if (i > 0)
            {
                number_pixels += 1;
                blue_sum += copy[i - 1][j].rgbtBlue;
                green_sum += copy[i - 1][j].rgbtGreen;
                red_sum += copy[i - 1][j].rgbtRed;
            }

            if (j > 0)
            {
                number_pixels += 1;
                blue_sum += copy[i][j - 1].rgbtBlue;
                green_sum += copy[i][j - 1].rgbtGreen;
                red_sum += copy[i][j - 1].rgbtRed;
            }

            if (i > 0 && j > 0)
            {
                number_pixels += 1;
                blue_sum += copy[i - 1][j - 1].rgbtBlue;
                green_sum += copy[i - 1][j - 1].rgbtGreen;
                red_sum += copy[i - 1][j - 1].rgbtRed;
            }

            if (i > 0 && j < width - 1)
            {
                number_pixels += 1;
                blue_sum += copy[i - 1][j + 1].rgbtBlue;
                green_sum += copy[i - 1][j + 1].rgbtGreen;
                red_sum += copy[i - 1][j + 1].rgbtRed;
            }

            if (i < height - 1)
            {
                number_pixels += 1;
                blue_sum += copy[i + 1][j].rgbtBlue;
                green_sum += copy[i + 1][j].rgbtGreen;
                red_sum += copy[i + 1][j].rgbtRed;
            }

            if (j < width - 1)
            {
                number_pixels += 1;
                blue_sum += copy[i][j + 1].rgbtBlue;
                green_sum += copy[i][j + 1].rgbtGreen;
                red_sum += copy[i][j + 1].rgbtRed;
            }

            if (i < height - 1 && j > 0)
            {
                number_pixels += 1;
                blue_sum += copy[i + 1][j - 1].rgbtBlue;
                green_sum += copy[i + 1][j - 1].rgbtGreen;
                red_sum += copy[i + 1][j - 1].rgbtRed;
            }

            if (i < height - 1 && j < width - 1)
            {
                number_pixels += 1;
                blue_sum += copy[i + 1][j + 1].rgbtBlue;
                green_sum += copy[i + 1][j + 1].rgbtGreen;
                red_sum += copy[i + 1][j + 1].rgbtRed;
            }

            image[i][j].rgbtBlue = round(blue_sum / number_pixels);
            image[i][j].rgbtGreen = round(green_sum / number_pixels);
            image[i][j].rgbtRed = round(red_sum / number_pixels);
        }
    }
    return;
}
