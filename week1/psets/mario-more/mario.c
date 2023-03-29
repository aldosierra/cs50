#include <cs50.h>
#include <stdio.h>

int get_height(void);
void make_pyramids(int heightSize);

int main(void)
{
    // Get height value
    int pyramidSize = get_height();

    // Make the pyramid
    make_pyramids(pyramidSize);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void make_pyramids(int heightSize)
{
    for (int i = 1; i <= heightSize; i++)
    {
        for (int j = 0; j < (heightSize - i); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}