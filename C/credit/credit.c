#include <cs50.h>
#include <stdio.h>

long getCard();
int getLongLenght(long value);
int checkCard(long cardNumber);
string getCardType(long cardNumber);

int len;

int main(void)
{
    // Gets card and saves in creditCard variable
    long creditCard = getCard();
    // Calls checkCard Function to validate checksum
    if (checkCard(creditCard) != 0)
    { // If last digit in checksum is not 0
        printf("INVALID\n");
    }
    else
    { // Obtains card type
        string cardType = getCardType(creditCard);
        // Prints string result
        printf("%s\n", cardType);
    }
}

// Function to get input of credit card long
long getCard()
{
    long x;
    // Loops to check if input fits initial criterea
    do
    {
        x = get_long("Number:");
        len = getLongLenght(x);
    }
    while (x < 1);
    return x;
}

// Function that validates card number checksum
int checkCard(long cardNumber)
{
    // Sets checksum to 0 initially
    int checksum = 0;
    // Variable to alternate odd and even digits sum
    bool isEven = false;
    // Loops through card digits
    for (int i = len; i > 0; i--)
    {
        int digit = cardNumber % 10;
        // If even digit multiplies by 2
        if (isEven)
        {
            digit *= 2;
            // Adds products digits
            if (digit > 9)
            {
                digit = digit % 10 + 1;
            }
        }
        // Adds digit result to checksum
        checksum += digit;
        // change isEven value to alternate odds and even digits
        isEven = !isEven;
        // Divide to go to next digit
        cardNumber /= 10;
    }
    return checksum % 10; // Returns checksum result
}

// Function to get card type (VISA, AMEX or Mastercard)
string getCardType(long cardNumber)
{
    cardNumber = cardNumber / 1000000000000; // Gets digits after 12nd position
    if ((len == 13) && (cardNumber == 4))    // VISA card with 13 digits
    {
        return "VISA";
    }
    else if ((len == 16) && (cardNumber / 1000 == 4)) // VISA card with 16 digits
    {
        return "VISA";
    }
    else if ((len == 15) && ((cardNumber / 10 == 34) || (cardNumber / 10 == 37))) // American Express
    {
        return "AMEX";
    }
    else if ((len == 16) && (((cardNumber / 100 > 50) && (cardNumber / 100 < 56)) || (cardNumber / 100 == 22))) // Mastercard
    {
        return "MASTERCARD";
    }
    // Else it is invalid
    return "INVALID";
}

// Function to obtain long input lenght
int getLongLenght(long value)
{
    int l = 0;
    while (value > 0)
    {
        value /= 10;
        l++;
    }
    return l; // Returns long's lenght value
}
