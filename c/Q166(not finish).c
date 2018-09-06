#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fractionToDecimal(long long int numerator, long long int denominator)
{
    char *result = (char *)malloc(10000 * sizeof(char));
    char *DecimalPart = (char *)malloc(10000 * sizeof(char));
    bool negative = (float)numerator / denominator >= 0;
    if (numerator == 0)
        return "0";
    else if (numerator < 0)
    {
        numerator = -numerator;
    }
    if (denominator == 0)
        return "0";
    else if (denominator < 0)
    {
        denominator = -denominator;
    }

    long long int Integer = numerator / denominator;
    long long int Decimal = numerator % denominator;

    bool *remaind;
    if (denominator > 0)
        remaind = (bool *)malloc(denominator * sizeof(bool));

    if (Integer > 0)
    {
        if (!negative)
            sprintf(result, "-%lld", Integer);
        else
            sprintf(result, "%lld", Integer);
    }
    else
    {
        if (!negative)
            sprintf(result, "-0.");
        else
            sprintf(result, "0.");
    }

    long long int i = 0;
    while (Decimal != 0)
    {
        Decimal *= 10;
        Integer = Decimal / denominator;
        Decimal = Decimal % denominator;
        if (remaind[Decimal] != 1)
            remaind[Decimal] = 1;
        else
            break;
        if (Integer > 0)
        {
            DecimalPart[i] = Integer + 48;
            i++;
        }
        else
        {
            DecimalPart[i] = '0';
        }
    }
    if (Decimal == 0)
    {
        strcat(result, DecimalPart);
        return result;
    }
    strcat(result, "(");
    strcat(result, DecimalPart);
    strcat(result, ")");
    printf("%s\n", result);
    return result;
}
int main()
{
    char *a = (char *)malloc(10 * sizeof(char));
    a = fractionToDecimal(-1, 6);
    printf("%s\n", a);
    return 0;
}
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fractionToDecimal(long long int numerator, long long int denominator)
{
    char *result = (char *)malloc(10000 * sizeof(char));
    char *DecimalPart = (char *)malloc(10000 * sizeof(char));
    bool negative = (float)numerator / denominator >= 0;
    if (numerator == 0)
        return "0";
    else if (numerator < 0)
    {
        numerator = -numerator;
    }
    if (denominator == 0)
        return "0";
    else if (denominator < 0)
    {
        denominator = -denominator;
    }

    long long int Integer = numerator / denominator;
    long long int Decimal = numerator % denominator;

    bool *remaind;
    if (denominator > 0)
        remaind = (bool *)malloc(denominator * sizeof(bool));

    if (Integer > 0)
    {
        if (!negative)
            sprintf(result, "-%lld", Integer);
        else
            sprintf(result, "%lld", Integer);
    }
    else
    {
        if (!negative)
            sprintf(result, "-0.");
        else
            sprintf(result, "0.");
    }

    long long int i = 0;
    while (Decimal != 0)
    {
        Decimal *= 10;
        Integer = Decimal / denominator;
        Decimal = Decimal % denominator;
        if (remaind[Decimal] != 1)
            remaind[Decimal] = 1;
        else
            break;
        if (Integer > 0)
        {
            DecimalPart[i] = Integer + 48;
            i++;
        }
        else
        {
            DecimalPart[i] = '0';
        }
    }
    if (Decimal == 0)
    {
        strcat(result, DecimalPart);
        return result;
    }
    strcat(result, "(");
    strcat(result, DecimalPart);
    strcat(result, ")");
    printf("%s\n", result);
    return result;
}
int main()
{
    char *a = (char *)malloc(10 * sizeof(char));
