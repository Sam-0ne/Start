#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Declaring functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade(int letters, int words, int sentences);

// Main
int main(void)
{
    // Get input words from both players
    string text = get_string("Text: ");
    // Calls function to count letters
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = grade(letters, words, sentences);
    // Prints grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}
// Function to count letters
int count_letters(string text)
{
    // Initializing count letters variables
    int letters = 0;
    int chars = (strlen(text));
    // Loops through chars in text
    for (int i = 0; i < chars; i++)
    { // Checks if is alhpa
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    // Returns int letter count
    return letters;
}
// Function to count words
int count_words(string text)
{
    // Initializing count words variable
    int words = 0;
    int chars = (strlen(text));
    // Loops through chars in text
    for (int i = 1; i <= chars; i++)
    { // Checks if the char is a 'space' or ponctuation sign next to a alpha
        if ((isspace(text[i]) || (text[i] == '.') || (text[i] == ',') || (text[i] == ';') || (text[i] == '"') || (text[i] == '!') ||
             (text[i] == '?') || (text[i] == 0)) &&
            isalpha(text[i - 1]))
        {
            words += 1;
        }
    }
    // Returns int word count
    return words;
}
// Function to count sentences
int count_sentences(string text)
{
    // Initializing count sentences variable
    int sentences = 0;
    int chars = (strlen(text));
    // Loops through chars in text
    for (int i = 1; i <= chars; i++)
    { // Checks if the char is a 'space' or ponctuation sign next to a alpha
        if (((text[i] == '.') || (text[i] == '!') || (text[i] == '?') || (text[i] == 0)) && isalpha(text[i - 1]))
        {
            sentences += 1;
        }
    }
    // Returns int sentence count
    return sentences;
}

// Function to calculate grade
int grade(int letters, int words, int sentences)
{
    // Iitializes average number of letters and sentences per hundred words
    float lphw = (float) letters / words * 100;
    float sphw = (float) sentences / words * 100;
    // Calculates Coleman-Liau index
    float index = ((0.0588 * lphw) - (0.296 * sphw) - 15.8);
    // Returns rounded index value
    return round(index);
}
