#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int stringLength = strlen(input) - 1;
    int answer = 0;
    int i = 1;

    while (stringLength >= 0)
    {
        answer += ((input[stringLength] - 48) * i);
        i *= 10;
        stringLength--;
    }

    return answer;
}