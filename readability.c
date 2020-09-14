#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int letter;
int word;
int sentence;

int main(void)
{
    // prompt the user with the question

    string read = get_string("Text: ");

// set the length of article

    int n = strlen(read);

// add +1 if the article starts with alphanumeric letter

    if (isalnum(read[0]))
    {
        word = 1;
    }

// count words

    for (int i = 0; i < n;  i++)
    {
        // count letters

        if (isalnum(read[i]))
        {
            letter++;
        }

        // count words

        if (i < n - 1 && isspace(read[i]) && isalnum(read[i + 1]))
        {
            word++;
        }

        // count sentences

        if (i > 0 && (read[i] == '!' || read[i] == '?' || read[i] == '.') && isalnum(read[i - 1]))
        {
            sentence++;
        }
}

// calculate Coleman-Liau index

    int grade = round(0.0588 * (100 * letter / word) - 0.296 * (100 * sentence / word) - 15.8);

// debugger

     // printf("Letters: %i\n Words: %i\n Sentences: %i\n", letter, word, sentence);

// print result
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade-1);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
