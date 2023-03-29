#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check_key(int length, string key);
string get_cipher(string key, string text);

int main(int argc, string argv[])
{
    // Verify single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int keyLength = strlen(argv[1]);
    string key = argv[1];

    if (check_key(keyLength, key) == false)
    {
        printf("Key must contain 26 non-repeated alphabetic characters.\n");
        return 1;
    }

    string plainText = get_string("plaintext: ");
    string cipherText = get_cipher(key, plainText);

    printf("ciphertext: %s\n", cipherText);

    return 0;
}

bool check_key(int length, string key)
{
    if (length != 26)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]))
        {
            for (int j = i + 1; j < length; j++)
            {
                if (key[i] == key[j])
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}
string get_cipher(string key, string text)
{
    int textLength = strlen(text);
    for (int i = 0; i < textLength; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = toupper(key[(toupper(text[i]) - 65)]);
            }
            else
            {
                text[i] = tolower(key[(toupper(text[i]) - 65)]);
            }
        }
        else
        {
            continue;
        }
    }
    return text;
}