#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
// int get_redabilty(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float averageLetters = ((float) letters / words) * 100;
    float averageSentences = ((float) sentences / words) * 100;

    int index = round(0.0588 * averageLetters - 0.296 * averageSentences - 15.8);

    printf("Letters: %d\nWords: %d\nSentences: %d\n", letters, words, sentences);
    printf("Letters per 100 words: %f\nSentences per 100 words: %f\n", averageLetters, averageSentences);

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
        printf("Grade %d\n", index);
    }

    return 0;
}

int count_letters(string text)
{
    int letters = 0;
    int stringLength = strlen(text);
    for (int i = 0; i < stringLength; i++)
    {
        if (isalnum(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    int stringLength = strlen(text);
    char pastLetter = ' ';
    for (int i = 0; i < stringLength; i++)
    {
        if (pastLetter == ' ' && text[i] == ' ')
        {
            continue;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        pastLetter = text[i];
    }
    if (pastLetter == ' ')
    {
        return words;
    }
    return ++words;
}

int count_sentences(string text)
{
    int stringLength = strlen(text);
    int sentences = 0;
    for (int i = 0; i < stringLength; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}