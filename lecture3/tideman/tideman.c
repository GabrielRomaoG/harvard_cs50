#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
void merge(pair pairs[], pair aux[], int left,int middle, int right);
void mergesort(pair pairs[], pair aux[], int left, int right);

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
    // TODO
    for (int cand_id = 0; cand_id < candidate_count; cand_id++)
    {
        if (strcmp(name, candidates[cand_id]) == 0)
        {
            ranks[cand_id] = rank;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int cand1_id = 0; cand1_id < candidate_count; cand1_id++)
    {
        int cand1_rank = ranks[cand1_id];
        for (int cand2_id = cand1_id + 1; cand2_id < candidate_count; cand2_id++)
        {
            int cand2_rank = ranks[cand2_id];
            if (cand1_rank < cand2_rank)
            {
                preferences[cand1_id][cand2_id]++;
            }
            if (cand1_rank > cand2_rank)
            {
                preferences[cand2_id][cand1_id]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int cand1_id = 0; cand1_id < candidate_count; cand1_id++)
    {
        for (int cand2_id = cand1_id + 1; cand2_id < candidate_count; cand2_id++)
        {
            int pref_cand1_over_cand2 = preferences[cand1_id][cand2_id];
            int pref_cand2_over_cand1 = preferences[cand2_id][cand1_id];

            if (pref_cand1_over_cand2 > pref_cand2_over_cand1)
            {
                pairs[pair_count].winner = cand1_id;
                pairs[pair_count].loser = cand2_id;
                pair_count++;
            }
            if (pref_cand1_over_cand2 < pref_cand2_over_cand1)
            {
                pairs[pair_count].winner = cand2_id;
                pairs[pair_count].loser = cand1_id;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair aux[MAX * (MAX - 1) / 2] = {0};
    mergesort(pairs,  aux, 0, pair_count - 1);
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

void merge(pair pairs[], pair aux[], int left,int middle, int right)
{
    for (int k = left; k <= right; k++)
    {
        aux[k] = pairs[k];
    }
    int i = left;
    int j = middle + 1;

    for (int k = left; k <= right; k++)
    {
        int j_victor_strenght = preferences[aux[j].winner][aux[j].loser];
        int i_victor_strenght = preferences[aux[i].winner][aux[i].loser];
        if (i > middle)
        {
            pairs[k] = aux[j];
            j++;
        }
        else if (j > right)
        {
            pairs[k] = aux[i];
            i++;
        }
        else if (j_victor_strenght > i_victor_strenght)
        {
            pairs[k] = aux[j];
            j++;
        }
        else 
        {
            pairs[k] = aux[i];
            i++;
        }
    }

}

void mergesort(pair pairs[], pair aux[], int left, int right)
{
    if (right <= left)
    {
        return;
    }
    int middle = (left + right) / 2;

    mergesort(pairs, aux, left, middle);

    mergesort(pairs, aux, middle + 1, right);

    merge(pairs, aux, left, middle, right);
}