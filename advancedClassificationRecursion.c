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

int reqArmstrong(int num, int n)
{
    if (num == 0)
        return 0;
    
    return power(num%10, n) + reqArmstrong(num/10, n);
}

int isArmstrong(int num)
{
    if(reqArmstrong(num, numberOfDigits(num)) == num)
        return 1;
    else
        return 0;
}

int reqPalindrome(char* str, char* endpointer)
{
    if (str >= endpointer)
        return 1;
        
    if (str[0] == endpointer[0])
        return reqPalindrome(str +1, endpointer -1);
    else
        return 0;
}

int isPalindrome(int num)
{
    char* str = malloc(numberOfDigits(num));
    sprintf(str, "%d", num);
    int ret = reqPalindrome(str, (char*) str +(numberOfDigits(num)-1));
    free(str);
    return ret;
}