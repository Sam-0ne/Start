#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{ // Checks quantity of command-line arguments
    if (argc != 2)
    {
        printf("bash: Syntax error>> Usage: ./substitution key\n");
        return 1;
    }
    // Initializes key size variable
    int argLen = (strlen(argv[1]));
    // Checks if key size equals to 26
    if (argLen != 26)
    {
        printf("Key error>> encryption key must contain 26 different characters\n");
        return 1;
    }
    // Initialize variable to get key from command-line argument
    string key = (argv[1]);
    // Initializes array variable to hold integer difference value from key elements
    int difMap[26] = {};
    // Loops through key to map ASCII codes differentials
    for (int i = 0; i < 26; i++)
    { // Initializes variable to get upper of char
        char keyChar = toupper(key[i]);
        // checks if valid ASCII code
        if ((keyChar < 65) || (keyChar > 90))
        {
            printf("Key error>> encryption key must contain 26 different letter characters\n");
            return 1;
        }
        // Loops to verify doubles of upper of chars in key
        for (int j = i; j < 25; j++)
        {
            if (keyChar == toupper(key[j + 1]))
            {
                printf("Key error>> encryption key must contain 26 different characters\n");
                return 1;
            }
        }
        // If valid key, maps array of integer difference between cipher key chars and ASCII 0 indexed
        difMap[i] = keyChar - (i + 65);
    }
    // Get input plaintext
    string input = get_string("plaintext: ");
    // Initialize variables to get text lenght
    int textLen = (strlen(input));
    // Initialize output variable to get copy of input
    string output = input;
    // Loops through input text, checks for alphabetic chars
    for (int i = 0; i < textLen; i++)
    {
        if (isalpha(input[i]))
        { // Calculates ciphered char from differential array, changing value
            int x = difMap[(toupper(input[i]) - 65)];
            output[i] = (input[i]) + x;
        }
    }
    // Prints ciphertext output
    printf("ciphertext: %s\n", output);
    return 0;
}
