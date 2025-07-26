#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int grade_number(string sentence);

int main(void)
{
    string sentence = get_string("Text: ");
    int grade_num = grade_number(sentence);
    if (grade_num < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_num >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_number(sentence));
    }
}

int grade_number(string sentence)
{
    int i = 0;
    int word_count = 1;
    int total_length = 0;
    int sentence_count = 0;

    while (sentence[i] != 0)
    {
        char c = sentence[i];
        i++;
        if (isalpha(c))
        {
            total_length++;
        }
        else if (c == ' ')
        {
            word_count++;
        }
        else if (c == '?' || c == '.' || c == '!')
        {
            sentence_count++;
        }
    }
    double L = (double) total_length / word_count * 100;
    double S = (double) sentence_count / word_count * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;

    return (int) round(index);
}
