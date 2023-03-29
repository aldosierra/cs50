// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You must use 1 argument\n");
        return 1;
    }
    // Convert to leetspeak
    printf("%s\n", replace(argv[1]));
    return 0;
}

string replace(string word)
{
    int wordLength = strlen(word);
    for (int i = 0; i < wordLength; i++)
    {
        char letter = tolower(word[i]);
        switch (letter)
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                break;
        }
    }
    return word;
}