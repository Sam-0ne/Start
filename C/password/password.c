#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least 8 characters and one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
    // Initializing char check boolean variables
    bool upper = false;
    bool lower = false;
    bool nmbr = false;
    bool symb = false;
    bool size = false;
    // Initializing integer string lenght variable for performance
    int len = strlen(password);
    // Loops through password chars
    for (int i = 0; i < len; i++)
    {
        // Checks lower case
        if (islower(password[i]))
        {
            lower = true;
        }
        // Checks upper case
        else if (isupper(password[i]))
        {
            upper = true;
        }
        // Checks if number
        else if (isdigit(password[i]))
        {
            nmbr = true;
        }
        // Checks if Symbol
        else if (ispunct(password[i]))
        {
            symb = true;
        }
        // Checks size
        else if ((len > 7) && (len < 32))
        {
            size = true;
        }
    }
    if ((len > 7) && (len < 32))
    {
        size = true;
    }
    // Returns boolean concatenated result
    return (lower && upper && nmbr && symb && size);
}
