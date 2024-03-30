#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
bool notduplicate(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    string key = argv[1];

    if (notduplicate(argv[1]) == 0)
    {
        printf("Key must not contain duplicated characters.\n");
        return 1;
    }

    for (int t = 0; t < 26; t++)
    {
        if (isalpha(argv[1][t]) == 0)
        {
            printf("Key must contain alphabetical characters.\n");
            return 1;
        }
    }

    // main code
    string text = get_string("plaintext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {

        if (isupper(text[i]))
        {                                  // suppose char is 'H'
            int c = (text[i] - 65);        // we will find nth position of 'H' in key
            text[i] = toupper(argv[1][c]); // go to nth position and replace
        }
        if (islower(text[i]))
        {                                  // suppose char is 'h'
            int c = (text[i] - 97);        // we will find nth position of 'h' in key
            text[i] = tolower(argv[1][c]); // go to nth position and replace
        }
    }
    printf("ciphertext: %s\n", text);
}