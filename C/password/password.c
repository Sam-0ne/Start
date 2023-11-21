// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library
#include <cs50.h>
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
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
    // Initializing char check boolean variables
    bool upper = false;
    bool lower = false;
    bool nmbr = false;
    bool symb = false;
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
    }
    // Returns boolean concatenated result
    return (lower && upper && nmbr && symb);
}
