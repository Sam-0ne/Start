#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Checks Score
    if (score1 > score2)
    { // Print player 1 winner
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    { // Print player 2 winner
        printf("Player 2 wins!\n");
    }
    else
    { // Print tie
        printf("Tie!\n");
    }
    return 0;
}

// Function to calculate word score
int compute_score(string word)
{
    // Initializes a score variable
    int score = 0;
    // Loops through chars in word
    for (int i = strlen(word) - 1; i >= 0; i--)
    {
        // Assigns int ASCII value of upper char
        int value = (int) toupper(word[i]);
        // Checks if alpha by ASCII index
        if (value > 64 && value < 91)
        { // Floors value and compare to points array
            value = value - 65;
            value = POINTS[value];
            // Adds to score
            score += value;
        }
    }
    // Returns total word score
    return score;
}
