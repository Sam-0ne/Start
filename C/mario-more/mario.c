#include <cs50.h>
#include <stdio.h>

int getHeight(void);
void buildPyramid(int height);

// Main function
int main(void)
{
    // Get input height
    int height = getHeight();

    // Calls building Pyramid function
    buildPyramid(height);
    return 0;
}

// Function to get input of height integer
int getHeight(void)
{
    int x;
    // Loops to checks if input is higher than 1
    do
    {
        x = get_int("Height (1-80):");
    }
    while (x < 1 || x > 80);
    return x;
}

// Function to build the pyramid
void buildPyramid(int height)
{
    // Loops line print
    for (int y = 1; y <= height; y++)
    {
        // Loops initial space print
        for (int x = height - y; x > 0; x--)
        {
            printf(" ");
        }
        // Then loops print #
        for (int x = 1; x <= y; x++)
        {
            printf("#");
        }
        // Prints two spaces
        printf("  ");
        // Then loops print # again
        for (int x = 1; x <= y; x++)
        {
            printf("#");
        }
        // Prints new line
        printf("\n");
    }
}
