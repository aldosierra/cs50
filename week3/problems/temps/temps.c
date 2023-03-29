// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void selection_sort(void);
void bubble_sort(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    // bubble_sort();
    selection_sort();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void bubble_sort(void)
{
    // Add your code here
    bool swapped;
    int i = 0;
    do
    {
        swapped = false;
        for (int j = 0; j < NUM_CITIES - i - 1; j++)
        {
            if (temps[j].temp < temps[j + 1].temp)
            {
                avg_temp sortjng[1] = {temps[j]};
                temps[j] = temps[j + 1];
                temps[j + 1] = sortjng[0];
                swapped = true;
            }
        }
        i++;
    }
    while (swapped);
}

void selection_sort(void)
{
    avg_temp max[1];
    int imax;
    for (int i = 0; i < NUM_CITIES - 1; i++)
    {
        max[0] = temps[i];
        imax = i;
        for (int j = i + 1; j < NUM_CITIES; j++)
        {
            if (max[0].temp < temps[j].temp)
            {
                max[0] = temps[j];
                imax = j;
            }
        }
        if (max[0].temp != temps[i].temp)
        {
            temps[imax] = temps[i];
            temps[i] = max[0];
        }
    }
}