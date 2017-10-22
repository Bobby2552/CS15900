#include <stdio.h>
int main() {
	//Creating variables for the 3 numbers to be inputed
	int first, second, third;
	int digitone, digittwo, digitthree;
	//Creating variable to store the choice of place
	char place;

	printf("I - Ones place\nX - Tens place\nC - Hundreds place\nM - Thousands place\nEnter character for place selection: ");
	scanf("%c", &place);
	printf("Enter 4-digit integer #1: ");
	scanf("%d", &first);
	printf("Enter 4-digit integer #2: ");
	scanf("%d", &second);
	printf("Enter 4-digit integer #3: ");
	scanf("%d", &third);

	switch(place) {
		case('I') :
			digitone = first % 10;
			digittwo = second % 10;
			digitthree = third % 10;
		break;
		case('X') :
			digitone = first / 10 % 10;
			digittwo = second / 10 % 10;
			digitthree = third / 10 % 10;
		break;
		case('C') :
			digitone = first / 100 % 10;
			digittwo = second / 100 % 10;
			digitthree = third / 100 % 10;
		break;
		case('M') :
			digitone = first / 1000 % 10;
			digittwo = second / 1000 % 10;
			digitthree = third / 1000 % 10;
		break;
	}

		char* bin = malloc(sizeof(char) * 12);
		bin += //TODO Add stuff here;
}
