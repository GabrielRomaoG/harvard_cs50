#include <cs50.h>
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

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    if (score1 == score2)
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int score = 0;

    for (int letter_pos = 0; word[letter_pos] != '\0'; letter_pos++)
    {
        char letter = word[letter_pos];
        int upper_letter_id = word[letter_pos];
        if (islower(word[letter_pos]))
        {
            upper_letter_id = toupper(word[letter_pos]);
        }
        if (upper_letter_id < 65 || upper_letter_id > 90)
        {
            continue;
        }
        score += POINTS[upper_letter_id - 65];
    }
    return score;
}
