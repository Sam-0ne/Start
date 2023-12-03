#include "cs50.h"
#include <stdio.h>
#include <time.h>
#include <ctype.h>

int yearCalc(int age)
{
    time_t systemTime = time(NULL);
    struct tm tm = *localtime(&systemTime);
    int yearBorn = tm.tm_year + 1900 - age;
    return yearBorn;
}

int main(void)
{
    string name = get_string("\nWhat is your name?\n");
    int age = get_int("\nHow old are you?\n");
    int yearBorn = yearCalc(age);
    printf("\nHello, %s!\n", name);
    char answer = 'x';
    
    while (true) {
        answer = tolower(get_char("Were you born in %i? (y/n)\n", yearBorn));
        if (answer == 'n' || answer == 'y') {
            break;
        }
    }

    if (answer =='y') {
        printf("Ok, nice to meet you, %s from %i!\nHope you've had a great birthday in %i!\n", name, yearBorn, yearBorn+age);
    }
    else if (answer=='n') {
        yearBorn = yearBorn -1;
        printf("\nOh, sorry!\nNice to meet you, %s from %i!\nHope you have a great birthday in %i!\n", name, yearBorn, yearBorn+1+age);
    }
}


