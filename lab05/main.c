#include <stdio.h>
#include <math.h>
void input();
void printDigits();
void inputOctin();
void inputKey();
int checkOctal(int number);

int octin = -1;
int key = -1;

int main() {
    inputOctin();
    inputKey();
    printDigits();
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
}

void inputKey()
{
    do {
        printf("Enter octal key digit: ");
        scanf("%d", &key);
        if (key < 0 || key > 7) {
            printf("\nError! Invalid octal digit value!!\n\n");
        }
    } while (key < 0 || key > 7);
}

//return a 0 or 1 if number is invalid or valid, respectively.
int checkOctal(int number)
{
    int i;
    int digits = floor(log10(octin)) + 1;
    for (i = 0; i < digits; i++) {
        int digit = (octin / (int) pow(10, digits - i - 1)) % 10;
        if (digit >= 8) {
            return 0;
        }
    }
    //If all of the numbers are valid octal digits, we return that the number was OK.
    return 1;

}

void printDigits() {
    printf("----------------------\nEncrypted value: ");
    int i;
    int digits = floor(log10(octin)) + 1;
    for (i = 0; i < digits; i++) {
        int digit = (octin / (int) pow(10, digits - i - 1)) % 10;
        digit += key;
        if (digit >= 8)
            digit -= 8;
        key = digit;
        printf("%d", digit);
    }
    printf("\n----------------------\n");
}
