#include <stdio.h>

int prime(int max_number);

int main(void)
{
    printf("The sum is: %i", prime(100));
    
}

int prime(int max_number)
{
    int sum = 0;
    for (int i = 2; i < max_number; i++)
    {
        int flag = 0;
        for (int j = 2; j < i; j++)
        {
            if (i%j == 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            sum += i;
        }
    }
    return sum;
}
