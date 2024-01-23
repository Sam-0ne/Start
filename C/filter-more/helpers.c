#include "helpers.h"
#include <math.h>
#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loops through lines of image
    for (int i = 0; i < height; i++)
    {
        // And then loops through columns of image
        for (int j = 0; j < width; j++)
        {
            // Initializes gray BYTE variable to hold the rounded average value
            BYTE gray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Assigns gray value to color channels in RGBTRIPLE
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
    // Loops through lines of image
    for (int i = 0; i < height; i++)
    {
        // And then loops through columns of image
        for (int j = 0; j < width; j++)
        {
            // Initialize variables to hold original value for 3 color channels
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Initialize variables to calculate sepia value for 3 color channels
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Pixel's RGBTRIPLE receives the minimum between result variables and 255 (max "BRG" value)
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
    // Loops through lines of image
    for (int i = 0; i < height; i++)
    {
        // And then loops through columns of image until the middle
        for (int j = 0; j < width / 2; j++)
        {
            // Initializes temp RGBTRIPLE variable to hold initial RGB values
            RGBTRIPLE temp;
            temp.rgbtBlue = image[i][j].rgbtBlue;
            temp.rgbtGreen = image[i][j].rgbtGreen;
            temp.rgbtRed = image[i][j].rgbtRed;

            // Current pixel RGBTRIPLE gets oposite pixel value
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            // Oposite pixel RGBTRIPLE value gets value from temp
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
    // initialize RGBTRIPLE struct and loop to copy image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loops through lines in image array
    for (int i = 0; i < height; i++)
    {
        // And then loops through columns in image array
        for (int j = 0; j < width; j++)
        {
            // Initialize neighbor number counter and variable to hold sum of color values
            int number_pixels = 1;
            double blue_sum = copy[i][j].rgbtBlue * 1.0;
            double green_sum = copy[i][j].rgbtGreen * 1.0;
            double red_sum = copy[i][j].rgbtRed * 1.0;

            // If not the first line, add color values of top pixel to sum. And add to counter.
            if (i > 0)
            {
                number_pixels += 1;
                blue_sum += copy[i - 1][j].rgbtBlue;
                green_sum += copy[i - 1][j].rgbtGreen;
                red_sum += copy[i - 1][j].rgbtRed;

                // And if not the top left edge, add to variables and counter.
                if (j > 0)
                {
                    number_pixels += 1;
                    blue_sum += copy[i - 1][j - 1].rgbtBlue;
                    green_sum += copy[i - 1][j - 1].rgbtGreen;
                    red_sum += copy[i - 1][j - 1].rgbtRed;
                }

                // And if not the top right edge, add to variables and counter.
                if (j < width - 1)
                {
                    number_pixels += 1;
                    blue_sum += copy[i - 1][j + 1].rgbtBlue;
                    green_sum += copy[i - 1][j + 1].rgbtGreen;
                    red_sum += copy[i - 1][j + 1].rgbtRed;
                }
            }

            // If not the last line, add color values of bottom pixel to sum. And add to counter
            if (i < height - 1)
            {
                number_pixels += 1;
                blue_sum += copy[i + 1][j].rgbtBlue;
                green_sum += copy[i + 1][j].rgbtGreen;
                red_sum += copy[i + 1][j].rgbtRed;

                // And if not the bottom left edge, add to variables and counter.
                if (j > 0)
                {
                    number_pixels += 1;
                    blue_sum += copy[i + 1][j - 1].rgbtBlue;
                    green_sum += copy[i + 1][j - 1].rgbtGreen;
                    red_sum += copy[i + 1][j - 1].rgbtRed;
                }

                // And if not the bottom right edge, add to variables and counter.
                if (j < width - 1)
                {
                    number_pixels += 1;
                    blue_sum += copy[i + 1][j + 1].rgbtBlue;
                    green_sum += copy[i + 1][j + 1].rgbtGreen;
                    red_sum += copy[i + 1][j + 1].rgbtRed;
                }
            }

            // If not the first column, add to variables and counter.
            if (j > 0)
            {
                number_pixels += 1;
                blue_sum += copy[i][j - 1].rgbtBlue;
                green_sum += copy[i][j - 1].rgbtGreen;
                red_sum += copy[i][j - 1].rgbtRed;
            }

            // If not the last column, add to variables and counter.
            if (j < width - 1)
            {
                number_pixels += 1;
                blue_sum += copy[i][j + 1].rgbtBlue;
                green_sum += copy[i][j + 1].rgbtGreen;
                red_sum += copy[i][j + 1].rgbtRed;
            }

            // Image pixel's RGBTriple gets the rounded sum divided by number of neighbor numbers
            image[i][j].rgbtBlue = round(blue_sum / number_pixels);
            image[i][j].rgbtGreen = round(green_sum / number_pixels);
            image[i][j].rgbtRed = round(red_sum / number_pixels);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // initialize RGBTRIPLE struct and loop to copy image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loops through lines in image array
    for (int i = 0; i < height; i++)
    {
        // And then loops through columns in image array
        for (int j = 0; j < width; j++)
        {
            // Initialize Gx and Gy variables for 3 color channels
            double Gx_blue = 0;
            double Gy_blue = 0;
            double Gx_green = 0;
            double Gy_green = 0;
            double Gx_red = 0;
            double Gy_red = 0;

            // If not the first line, add to Gy variables.
            if (i > 0)
            {
                // blue
                Gy_blue = Gy_blue + copy[i - 1][j].rgbtBlue * -2;

                // green
                Gy_green = Gy_green + copy[i - 1][j].rgbtGreen * -2;

                // red
                Gy_red = Gy_red + copy[i - 1][j].rgbtRed * -2;

                // And if not the top left edge, add to Gy and Gy variables.
                if (j > 0)
                {
                    // blue
                    Gx_blue = Gx_blue + copy[i - 1][j - 1].rgbtBlue * -1;
                    Gy_blue = Gy_blue + copy[i - 1][j - 1].rgbtBlue * -1;

                    // green
                    Gx_green = Gx_green + copy[i - 1][j - 1].rgbtGreen * -1;
                    Gy_green = Gy_green + copy[i - 1][j - 1].rgbtGreen * -1;

                    // red
                    Gx_red = Gx_red + copy[i - 1][j - 1].rgbtRed * -1;
                    Gy_red = Gy_red + copy[i - 1][j - 1].rgbtRed * -1;
                }

                // If not the top right edge, add to Gy and Gy variables.
                if (j < width - 1)
                {
                    // blue
                    Gx_blue = Gx_blue + copy[i - 1][j + 1].rgbtBlue * 1;
                    Gy_blue = Gy_blue + copy[i - 1][j + 1].rgbtBlue * -1;

                    // green
                    Gx_green = Gx_green + copy[i - 1][j + 1].rgbtGreen * 1;
                    Gy_green = Gy_green + copy[i - 1][j + 1].rgbtGreen * -1;

                    // red
                    Gx_red = Gx_red + copy[i - 1][j + 1].rgbtRed * 1;
                    Gy_red = Gy_red + copy[i - 1][j + 1].rgbtRed * -1;
                }
            }

            // If not the last line, add to Gy variables.
            if (i < height - 1)
            {

                // blue
                Gy_blue = Gy_blue + copy[i + 1][j].rgbtBlue * 2;

                // green
                Gy_green = Gy_green + copy[i + 1][j].rgbtGreen * 2;

                // red
                Gy_red = Gy_red + copy[i + 1][j].rgbtRed * 2;

                // If not the bottom left edge, add to Gy and Gy variables.
                if (j > 0)
                {
                    // blue
                    Gx_blue = Gx_blue + copy[i + 1][j - 1].rgbtBlue * -1;
                    Gy_blue = Gy_blue + copy[i + 1][j - 1].rgbtBlue * 1;

                    // green
                    Gx_green = Gx_green + copy[i + 1][j - 1].rgbtGreen * -1;
                    Gy_green = Gy_green + copy[i + 1][j - 1].rgbtGreen * 1;

                    // red
                    Gx_red = Gx_red + copy[i + 1][j - 1].rgbtRed * -1;
                    Gy_red = Gy_red + copy[i + 1][j - 1].rgbtRed * 1;
                }

                // If not the bottom right edge, add to Gy and Gy variables.
                if (j < width - 1)
                {
                    // blue
                    Gx_blue = Gx_blue + copy[i + 1][j + 1].rgbtBlue * 1;
                    Gy_blue = Gy_blue + copy[i + 1][j + 1].rgbtBlue * 1;

                    // green
                    Gx_green = Gx_green + copy[i + 1][j + 1].rgbtGreen * 1;
                    Gy_green = Gy_green + copy[i + 1][j + 1].rgbtGreen * 1;

                    // red
                    Gx_red = Gx_red + copy[i + 1][j + 1].rgbtRed * 1;
                    Gy_red = Gy_red + copy[i + 1][j + 1].rgbtRed * 1;
                }
            }

            // If not the first column, add to Gx variables. Gy not affected.
            if (j > 0)
            {
                // blue
                Gx_blue = Gx_blue + copy[i][j - 1].rgbtBlue * -2;

                // green
                Gx_green = Gx_green + copy[i][j - 1].rgbtGreen * -2;

                // red
                Gx_red = Gx_red + copy[i][j - 1].rgbtRed * -2;
            }

            // If not the last column, add to Gx variables. Gy not  affected.
            if (j < width - 1)
            {
                // blue
                Gx_blue = Gx_blue + copy[i][j + 1].rgbtBlue * 2;

                // green
                Gx_green = Gx_green + copy[i][j + 1].rgbtGreen * 2;

                // red
                Gx_red = Gx_red + copy[i][j + 1].rgbtRed * 2;
            }

            // Assign integer variables to hold Sobel filter algorithm calculating the square root of Gx^2 + Gy^2
            int red = round(sqrt(pow(Gx_red, 2) + pow(Gy_red, 2)));
            int green = round(sqrt(pow(Gx_green, 2) + pow(Gy_green, 2)));
            int blue = round(sqrt(pow(Gx_blue, 2) + pow(Gy_blue, 2)));

            // Pixel's RGBTRIPLE receives the minimum between result variables and 255 (max BRG value)
            image[i][j].rgbtBlue = MIN(blue, 255);
            image[i][j].rgbtGreen = MIN(green, 255);
            image[i][j].rgbtRed = MIN(red, 255);
        }
    }
    return;
}
