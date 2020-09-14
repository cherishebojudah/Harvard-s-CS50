#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // prompt user for height
    do 
    {
        n = get_int("Height: ");
    }
    //check if number is valid
    while (n < 1 || n > 8);
    
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n - 1 - i; j++)
        { 
            printf(" ");
        }
        for (int j = 0; j < 1 + i; j++)
        {
            printf("#");
        }
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 1 + i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
          
}
