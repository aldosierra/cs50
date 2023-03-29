#include <stdbool.h>
#include <cs50.h>
#include <stdio.h>

long ask_number(void);
bool check_sum(long cardNumber);
void check_card(long cardNumber);

int main(void)
{
    // Ask for credit card
    long creditCard = ask_number();

    // Checksum
    bool checkSum = check_sum(creditCard);
    if (checkSum == true)
    {
        check_card(creditCard);
    }
    else
    {
        printf("INVALID\n");
    }
}

long ask_number(void)
{
    long askedNumber;
    do
    {
        askedNumber = get_long("Number: ");
    }
    while (askedNumber < 0);
    return askedNumber;
}

bool check_sum(long cardNumber)
{
    int firstCounter = 0;
    int secondCounter = 0;
    int tempValue = 0;
    while (cardNumber > 0)
    {
        firstCounter += cardNumber % 10;
        cardNumber /= 10;
        if (cardNumber > 0)
        {
            tempValue = (cardNumber % 10) * 2;
            if (tempValue > 9)
            {
                secondCounter += (tempValue % 10) + 1;
            }
            else
            {
                secondCounter += tempValue;
            }
            cardNumber /= 10;
        }
    }
    firstCounter += secondCounter;
    if ((firstCounter % 10) == 0)
    {
        return true;
    }
    return false;
}

void check_card(long cardNumber)
{
    int cardLength = 0;
    int firstDigit, secondDigit;

    while (cardNumber > 0)
    {
        cardLength++;
        cardNumber /= 10;
        if (cardNumber > 9 && cardNumber < 100)
        {
            secondDigit = cardNumber % 10;
            firstDigit = cardNumber / 10;
        }
    }
    // American express
    if (cardLength == 15 && firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
    {
        printf("AMEX\n");
    }
    // MasterCard
    else if (cardLength == 16 && firstDigit == 5 && (secondDigit == 1 || secondDigit == 2 || secondDigit == 3 || secondDigit == 4
             || secondDigit == 5))
    {
        printf("MASTERCARD\n");
    }
    // VISA
    else if ((cardLength == 13 || cardLength == 16) && firstDigit == 4)
    {
        printf("VISA\n");
    }
    // Invalido
    else
    {
        printf("INVALID\n");
    }
}