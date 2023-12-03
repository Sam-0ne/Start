#include "cs50.h"
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Loops through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Checks if the input name string compares exactly to the candidate name in loop
        if (strcmp(candidates[i].name, name) == 0)
        {
            // If matches, add a vote to the candidate and return true
            candidates[i].votes += 1;
            return true;
        }
        // If not a match, return false
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    printf("\nWinner:\n");
    // Initialize variable to hold most voted candidate
    int most_votes = -1;
    // Loops through candidates to find the highest votecount
    for (int i = 0; i < candidate_count; i++)
    {
        if ((candidates[i].votes) > (most_votes))
        { // If biggest vote number, assign to variable
            most_votes = candidates[i].votes;
        }
    }
    // Loops throug candidates list
    for (int i = 0; i < candidate_count; i++)
    { // Checks if looped candidate votes match highest votecount
        if ((candidates[i].votes) == (most_votes))
        { // Print candidate's name
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
