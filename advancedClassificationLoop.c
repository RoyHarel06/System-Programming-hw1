#include <stdio.h>
#include <stdlib.h>

int power(int num, int n)
{
    if (n == 0)
        return 1;
    else
        return num*power(num, n-1);
}

int numberOfDigits(int num)
{
    int count = 0;
    while(num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int isArmstrong(int num)
{
    int number_of_digits = numberOfDigits(num);
    int sum = 0;
    int temp = num;

    while(temp)
    {
        sum += power(temp % 10, number_of_digits);
        temp /= 10;
    }
    
    if(sum == num)
        return 1;
    else
        return 0;
}

int isPalindrome(int num)
{
    char* str = malloc(numberOfDigits(num));
    sprintf(str, "%d", num);

    for(int i = 0; i < (int)numberOfDigits(num)/2; i++)
    {
        char* end = str +numberOfDigits(num)-1 -i;
        if ((int)str[i] != (int)end[0])
            return 0;
    }

    return 1;
}