#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute(string s)
{
    int count = 0;
    int Points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        {
            count += Points[(int) (s[i] - 'a') + 0];
        }
        if (isupper(s[i]))
        {
            count += Points[(int) (s[i] - 'A') + 0];
        }
    }
    return count;
}

int main(void)
{
    string s1 = get_string("Player 1: ");
    string s2 = get_string("Player 2: ");
    int scr1 = compute(s1);
    int scr2 = compute(s2);

    if (scr1 > scr2)
    {
        printf("Player 1 wins!");
    }
    else if (scr1 < scr2)
    {
        printf("Player 2 wins!");
    }
    else if (scr1 == scr2)
    {
        printf("Tie!");
    }
    else
    {
        return 1;
    }
    printf("\n");
}