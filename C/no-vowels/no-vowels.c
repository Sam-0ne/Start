// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string text);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error 1704: Must input 1 command-line argument.\n");
        return 1;
    }
    string vowelless = replace(argv[1]);
    printf("%s\n", vowelless);
}

string replace(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        switch (tolower(text[i]))
        {

            case 'a':
                text[i] = '6';
                break;
            case 'e':
                text[i] = '3';
                break;
            case 'i':
                text[i] = '1';
                break;
            case 'o':
                text[i] = '0';
                break;
        }
    }
    return text;
}
