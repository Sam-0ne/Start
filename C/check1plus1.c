#include <stdio.h>
#include <cs50.h>

int main(void)
{
    while(true) {
        int answer = get_int("What is 1+1?\n");
        if (answer == 2) {
            break;
        }
    }
    printf("Yeah!\n");
}
