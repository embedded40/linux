#include<stdio.h>
#include<string.h>

int main()
{
    char strg1[50], strg2[50];

    printf("Enter first string: ");
    gets(strg1);

    printf("Enter second string: ");
    gets(strg2);

    if(strcmp(strg1, strg2)==0)
    {
        printf("\nYou entered the same string two times");
    }

    else
    {
        printf("\nEntered strings are not same!");
    }

    // signal to operating system program ran fine
    return 0;
}
