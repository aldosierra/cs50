#include <stdio.h>

int ask_size(char *size, int min_number);
int years_needed(int firstSize, int lastSize);

int main(void)
{
    // Prompt for start size
    int startSize = ask_size("Start size: ", 9);

    // Prompt for end size
    int endSize = ask_size("End size: ", startSize);

    // Calculate number of years until we reach threshold
    int yearsNeeded = years_needed(startSize, endSize);

    // Print number of years
    printf("Years: %d\n", yearsNeeded);

    return 0;
}

// Ask function
int ask_size(char *size, int minNumber)
{
    int numb;
    do
    {
        printf("%s", size);
        scanf("%d", &numb);
    }
    while (numb < minNumber);
    return numb;
}

// Time needed for end size function
int years_needed(int firstSize, int lastSize)
{
    // Formula: initialSize + initialSize/3 - initialSize/4 = endYearSize.
    int counterYears = 0;
    while (firstSize < lastSize)
    {
        firstSize = firstSize + (firstSize / 3) - (firstSize / 4);
        counterYears++;
    }
    return counterYears;
}