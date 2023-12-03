#include <stdio.h>


int main(void)
{
    int num[] = {5,2,7,4,1,6,3,0};
    int size = sizeof(num)/sizeof(num[0]);
    for (int k = 0; k < size; k++)
        {
            printf("%i ",num[k]);
        }
    printf(" ==> Array has %i elements.\n",size);
    //for i in
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (num[i] > num [j])
            {
                int temp = num [i];
                num [i] = num [j];
                num[j] = temp;
                for (int k = 0; k < size; k++)
                {
                    printf("%i ",num[k]);
                }
                printf("\n");
            }
        }

    }


}
