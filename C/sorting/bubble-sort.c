#include <stdio.h>

int main(void)
{
    // Creates array
    int num[] = {7, 2, 5, 4, 1, 6, 0, 3};
    // Calculates array size
    int size = sizeof(num) / sizeof(num[0]);
    // Loops through array to print elements
    for (int k = 0; k < size; k++)
    {
        printf("%i ", num[k]);
    }
    printf(" ==> Array has %i elements.\n", size);
    // Loops through array to identify smallest
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {

            if (num[j] > num [j+1])
            {
                int temp = num [j];
                num [j] = num [j+1];
                num[j+1] = temp;
                for (int k = 0; k < size; k++)
                {
                    printf("%i ", num[k]);
                }
                printf("\n");
            }

        }
    }
    for (int k = 0; k < size; k++)
    {
        printf("%i ", num[k]);
    }
    printf("\n");
}
