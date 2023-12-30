#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    // Reset pair count
    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Loops through candidate list to validate option and add vote
    for (int i = 0; i < candidate_count; i++)
    { // Checks if input name equals to candidate name
        if (strcasecmp(candidates[i], name) == 0)
        { // Checks if candidate was already ranked
            for (int j = 0; j < rank; j++)
            {
                if (i == ranks[j])
                {
                    return false;
                }
            }
            // Register vote
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Loops through candidates and adds to preferences array
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Loops through preferences array and adds pairs for winners and losers
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
            if (preferences[i][j] > preferences[j][i])
            {
                // Sets pairs of winners and losers
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count += 1;
            }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Performs a selection sort
    for (int i = 0; i < pair_count; i++)
    {
        // Defines i counter as the higher delta of vote difference
        int bigger_delta = i;
        for (int j = i + 1; j < pair_count; j++)
        {
            // Checks if preference for candidate j is higher than preference for canditade with bigger delta
            if (preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner] >
                preferences[pairs[bigger_delta].winner][pairs[bigger_delta].loser] -
                    preferences[pairs[bigger_delta].loser][pairs[bigger_delta].winner])
            {
                bigger_delta = j;
            }
        }
        // Creats a temporary pair struct
        pair temp;
        // Sets temp winner and loser indexes to bigger delta index
        temp.winner = pairs[bigger_delta].winner;
        temp.loser = pairs[bigger_delta].loser;
        // Swaps index i (smaller value) with bigger delta index
        pairs[bigger_delta].winner = pairs[i].winner;
        pairs[bigger_delta].loser = pairs[i].loser;
        // Swaps index i with temporary pair, wich is holdind the bigger delta index
        pairs[i].winner = temp.winner;
        pairs[i].loser = temp.loser;
    }
    return;
}

// Recursion function to check if pairs form a cycle before locking
bool check_cycle(int start, int loser)
{
    // Sets base condition
    if (locked[loser][start])
    {
        return true;
    }
    // Sets recursion assessment to check for cycles
    for (int i = 0; i < candidate_count; i++)
    { // Checks if the loser wins against i, recursively
        if (locked[loser][i] && check_cycle(start, i))
        {
            return true;
        }
    }
    // Returns false if no cycle is formed
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Loops through set pairs
    for (int i = 0; i < pair_count; i++)
    {
        // Checks for cycle only after the 2nd locked pair
        if (i > 1)
        {
            if (check_cycle(pairs[i].winner, pairs[i].loser))
            { // Continue if cycle is formed, not locking
                continue;
            }
        }
        // If not forming a cycle, lock the pair
        locked[pairs[i].winner][pairs[i].loser] = true;
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // Loops through locked pairs
    for (int i = 0; i < candidate_count; i++)
    { // Initializes 0 valued variable to count losses
        int lost = 0;
        for (int j = 0; j < candidate_count; j++)
        { // Checks if the "i" candidate loses over "j"
            if (locked[j][i])
            {
                lost++;
            }
        }
        // Checks losses counter of i candidate, if equals to 0 i is the winner
        if (lost == 0)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}
