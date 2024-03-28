#include <cs50.h>
#include <math.h>
#include <stdio.h>

long int power(int x, int n)
{
    long int a = 1;
    for (int i = 0; i < n; ++i)
        a = x * a;

    return (a);
}
int main(void)
{
    long x;
    int chk = 3;
    int l = 0;
    do
    {
        x = get_long("Number ");
        l = (int) log10(x) + 1;
    }
    while (l == 0);

    int sum1 = 0;
    int sum2 = 0;
    int sum = 0;

    for (int i = 1; i <= l; i = i + 2)
    {
        long div = pow(10, i);
        long div_ = pow(10, i - 1);
        int b = ((x % div) / div_);
        if (b <= 9)
        {
            sum1 = sum1 + b;
        }
        else
        {
            sum1 = sum1 + b / 10;
            sum1 = sum1 + b % 10;
        }
    }
    for (int j = 2; j <= l; j = j + 2)
    {
        long div2 = pow(10, j);
        long div2_ = pow(10, j - 1);
        int a = 2 * ((x % div2) / div2_);
        if (a <= 9)
        {
            sum2 = sum2 + a;
        }
        else
        {
            sum2 = sum2 + a / 10;
            sum2 = sum2 + a % 10;
        }
    }
    sum = sum1 + sum2;
    chk = sum % 10;
    if (chk == 0)
    {
        long int d13 = power(10, 13);
        long int d14 = power(10, 14);
        long int dd = power(10, l - 1);
        if (l == 15 && ((x / d13 == 34) || (x / d13 == 37)))
        {
            printf("AMEX\n");
        }
        else if (l == 16 && ((x / d14) == 51 || (x / d14) == 52 || (x / d14) == 53 ||
                             (x / d14) == 54 || (x / d14) == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((l == 13 || l == 16) && ((x / dd) == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}