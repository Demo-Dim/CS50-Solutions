#include <cs50.h>
#include <stdio.h>

int word_score(string word, const int letter_scores[]);
int letter_position(char character);

int main(void)
{
    const int letter_scores[27] = {1, 3, 3,  2, 1, 4, 2, 4, 1, 8, 5, 1,  3, 1,
                                   1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};
    string p1_input = get_string("Player 1: ");
    string p2_input = get_string("Player 2: ");
    int p1_score = word_score(p1_input, letter_scores);
    int p2_score = word_score(p2_input, letter_scores);

    if (p1_score > p2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1_score < p2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int word_score(string word, const int letter_scores[])
{
    int i = 0;
    int final_score = 0;
    while (word[i] != 0)
    {
        char letter = word[i];
        int letter_pos = letter_position(letter);
        final_score += letter_scores[letter_pos];
        i++;
    }
    return final_score;
}

int letter_position(char character)
{
    // zero_score represents the last digit in letter_scores
    static const int zero_score = 26;
    if (character >= 'A' && character <= 'Z')
        return character - 'A';
    else if (character >= 'a' && character <= 'z')
        return character - 'a';
    else
        return zero_score;
}
