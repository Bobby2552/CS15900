#include <stdio.h>
#include <math.h>
void input();
void printDigits();

int octin = 0;
int key = 0;

int main() {
	input();
	printf("----------------------\nEncrypted value: ");
	printDigits();
	printf("\n-----------------------\n");
}

void input() {
	printf("Enter octal number: ");
	scanf("%d", &octin);
	printf("Enter octal key digit: ");
	scanf("%d", &key);
}

void printDigits() {
	int i;
	int digits = floor(log10(octin)) + 1;
	for (i = 0; i < digits; i++) {
		int digit = ((int) octin / (int) pow(10, digits - i - 1)) % 10;
		digit += key;
		if (digit >= 8) digit -= 8;
		key = digit;
		printf("%d", digit);
	}
}
