#include <stdio.h>
int readInput(int numbers[]);
int parseDigit(int place, int number);
void convertDigitToBinary(int digit, int startingChar, char bin[]);

int main() {
    //Creating variable to store the choice of place.
    int place;
    //Creating array for the inputed numbers.
    int numbers[3];
    //Creating an array for the three digits parsed out of the inputed numbers.
    int digits[3];
    //A string to put binary digits in.
    char bin[12] = "";

    place = readInput(numbers);
    int i = 0;
    digits[i] = parseDigit(place, numbers[i]);
    i++;
    digits[i] = parseDigit(place, numbers[i]);
    i++;
    digits[i] = parseDigit(place, numbers[i]);

    i = 0;
    convertDigitToBinary(digits[i], i * 4, bin);
    i++;
    convertDigitToBinary(digits[i], i * 4, bin);
    i++;
    convertDigitToBinary(digits[i], i * 4, bin);

    //strtol will convert a string (str) of base (n) to decimal. It is in the C standard library. strtol(str, NULL, n)
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\nConcatenated binary number: %s\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\nConversion of concatenated binary: %d\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n", bin, strtol(bin, NULL, 2));
}

int readInput(int numbers[])
{
    //Creating variable to store the choice of place.
    int place;
    printf("I - Ones place\nX - Tens place\nC - Hundreds place\nM - Thousands place\nEnter character for place selection: ");
    scanf("%c", &place);
    printf("\nEnter 4-digit integer #1: ");
    scanf("%d", &numbers[0]);
    printf("Enter 4-digit integer #2: ");
    scanf("%d", &numbers[1]);
    printf("Enter 4-digit integer #3: ");
    scanf("%d", &numbers[2]);

    return place;
}

int parseDigit(int place, int number)
{
    int digit = 0;
    switch(place) {
    case('I') :
        digit = number % 10;
        break;
    case('X') :
        digit = number / 10 % 10;
        break;
    case('C') :
        digit = number / 100 % 10;
        break;
    case('M') :
        digit = number / 1000 % 10;
        break;
    }

    return digit;
}

void convertDigitToBinary(int digit, int startingChar, char bin[])
{
    //Find binary digits for digitone

    //Check if the digit is above the binary place you are trying to find (8, then 4, 2, 1).
    //Relational operators (==, !=, >, <, >=, <=) will return 1 or 0 depending on if it evaluates to true, or false, respectively.
    //Add this to the ASCII value of 0. e.g. 0 + '0' = '0', 1 + '0' = '1'.
    bin[startingChar] = (digit >= 8) + '0';
    //If the digit was above the binary place, subtract it, as we have accounted for it already.
    if (digit >= 8) digit -= 8;
    //Repeat.
    bin[startingChar + 1] = (digit >= 4) + '0';
    if (digit >= 4) digit -= 4;
    bin[startingChar + 2] = (digit >= 2) + '0';
    if (digit >= 2) digit -= 2;
    bin[startingChar + 3] = (digit >= 1) + '0';
    if (digit >= 1) digit -= 1;
}
