#include <stdio.h>
#include <cs50.h>

void print_card_brand(long long ccn); 
bool checksum(long long ccn, int len);
bool checklength(int len);
int length(long long n);
void check_validity(long long ccn);

int main()
{
    //prompt user to input credit card number
    long long credit_card;
    do
    {
         // printf("Number: ");
        credit_card = get_long_long("Number: ");
    }
    while(credit_card < 0);
    
     // checks length and checksum to determine validity
     check_validity(credit_card);
}


void check_validity(long long ccn)
{
    int len = length(ccn);
    if (!(checklength(len) && checksum(ccn, len)) )
    {
        //  printf("INVALID\n");
        print_card_brand(ccn);
         // return;
    }
 // after checking if the card is legit we will print out the brand of card used 
      // print_card_brand(ccn);
      else return;
}

int length(long long n)
{
    int len = 0;
    while (n > 0)
    {
        len ++;
         n /= 10;
    }
    return len;
}

bool checklength(int len)
{
    if (len == 13 || len == 15 || len == 16)
        return true;
    return false;
}

bool checksum(long long ccn, int len)
{
    int sum = 0;
    //loop through the ccn length
    for (int i = 0; i < len; i++)
    {
    //case when i is even 
      if (i % 2 == 0)
      {
        //simply accumulate
        sum += (ccn % 10);
      }
    //case when i is odd
     else
     {
         //"carefully" accumulate for ex.(18 / 10 = 1)+(18 % 10 = 8)
         int digit = (2*(ccn % 10));
         sum += (digit/10 + digit % 10);
         
     }
        
}
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}
        
void print_card_brand(long long ccn)
 {
     if (ccn >= 340000000000000 && ccn <= 350000000000000)
     {
         printf("AMEX\n");
     }
     else if (ccn >= 5100000000000000 && ccn < 5600000000000000)
     {
         printf("MASTERCARD\n");
     }
     else if ((ccn >= 40000000000000 && ccn < 50000000000000) || (ccn >= 4000000000000000 && ccn < 5000000000000000))
     {
         printf("VISA\n");
     }
     else
         printf("INVALID\n");
 }
