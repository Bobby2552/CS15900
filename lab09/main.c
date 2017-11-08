#include <stdio.h>
#include <math.h>
void inputOctin();
int checkOctal(int number);
int moveDigit(int num);
void iterator(int num);
int octToDec(int oct);
char largestHex(int dec);

int octin;
//Initial number of digits
int digits;

int main()
{
    inputOctin();
    iterator(octin);
}

void iterator(int num)
{
    int i;
    int digits = floor(log10(octin)) + 1;
    for (i = 0; i < digits; i++)
    {
        printf("Octal Value: %0*d Max Hex Digit: %c\n", digits, num, largestHex(octToDec(num)));
        num = moveDigit(num);
    }
}


int octToDec(int oct)
{
    int i = 0;
    int dec = 0;
    while (oct != 0)
    {
        dec = dec +(oct % 10)* pow(8, i++);
        oct = oct / 10;
    }
    return dec;
}

char largestHex(int dec)
{
    char largest = '0';

    while(dec != 0)
    {
        //Temporary variables to store remainder and the represantative hex char
        int temp = 0;
        char tempChar;
        //Storing remainder in temp variable.
        temp = dec % 16;
        //Convert the decimal representation of the hex value to a hex char
        if(temp < 10)
        {
            tempChar = temp + 48;
        }
        else
        {
            tempChar = temp + 55;
        }
        dec /= 16;
        if (tempChar > largest)
        {
            largest = tempChar;
        }
    }
    return largest;
}

void inputOctin()
{
    do {
        printf("Enter octal number: ");
        scanf("%d", &octin);
        if (octin < 0) {
            printf("\nError! Negative numbers are invalid!!\n\n");
        } else if (checkOctal(octin) == 0) {
            //An octal error will only be flagged if octin < 0 by putting it in an else if.
            printf("\nError! Input contains invalid digit!!\n\n");
        }
    } while (octin < 0 || checkOctal(octin) == 0);
    digits = floor(log10(octin)) + 1;
	printf("\n");
}

//This function will move the leftmost digit to the rightmost position.
int moveDigit(int num)
{
    int actualDigits = floor(log10(num)) + 1;
    //Find first (most important) digit
    int firstDigit = (num / (int) pow(10, digits - 1)) % 10;
    if (actualDigits < digits)
    {
        firstDigit = 0;
    }
    //Remove digit from number
    num -= firstDigit * pow(10, digits - 1);
    //Add it back in at the beginning
    num *= 10;
    num += firstDigit;
    return num;
}

//return a 0 or 1 if number is invalid or valid, respectively.
int checkOctal(int number)
{
    int i;
    for (i = 0; i < digits; i++) {
        int digit = (octin / (int) pow(10, digits - i - 1)) % 10;
        if (digit >= 8) {
            return 0;
        }
    }
    //If all of the numbers are valid octal digits, we return that the number was OK.
    return 1;

}
