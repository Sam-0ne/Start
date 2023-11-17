#include <cs50.h>
#include <stdio.h>

int getSize(string sizeCategory, int floor);
int calcYears(int start, int end);

int main(void)
{
    int startSize = getSize("Start", 9);
    int endSize = getSize("End", startSize);
    int years = calcYears(startSize, endSize);
    printf("Years: %i\n", years);
}

// Function to prompt for size
int getSize(string sizeCategory, int floor)
{
    int x;
    // Checks if input is lower than 1 or lower than floor argument
    do
    {
        x = get_int("%s size:", sizeCategory);
    }
    while (x < 1 || x < floor);
    return x;
}

// Function to Calculate number of years until threshold
int calcYears(int start, int end)
{
    int y = 0;
    while (start < end)
    {
        start = start + (int) (start / 3) - (int) (start / 4);
        y++;
    }
    return y;
}
