#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    //declare variable float  
    float change;
    
    //prompt user for change owed and validate change  
    do
    {
        change = get_float("How much change are you owed?: ");
    }
    while (change < 0);
    
    //convert dollars to cents and round to nearest penny  
    int cents = round(change * 100);
    
    //declare and initialize a variable to hold the number of coins to be dispensed 
    int coinCount = 0;
   
    while (cents >= 25)
    {
        cents -= 25;
        coinCount++;
    }
    while (cents >= 10)
    {
        cents -= 10;
        coinCount++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        coinCount++;
    }
    while (cents >= 1)
    {
        cents -= 1;
        coinCount++;
    }
    printf("%i\n", coinCount);   
      
}
    
