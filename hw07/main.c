#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
void calculateCard(int counter, long long num);
void input();
void printResults();
void findMax();
void countOccs();

long long cards [50][2];
int occ [64];
int maxs [64];
char dataSet[1000000];
int max;
int j;
int i;
int maxVal = 0;
int multiple = -1;

int main()
{
    input();
    countOccs();
    findMax();
    printResults();
}

void printResults()
{
    if (multiple == 0) {
        for (i = 0; i < 64; i++) {
            if (maxs[i] == maxVal) {
                break;
            }
        }
        printf("Most frequently occurring cardinality in data set: %d\n", i);
    } else {
        int maxNum = 0;
        int maxCard = 0;
        for (i = 0; i < 64; i++) {
            if (maxs[i] > 0) {
                for (j = 0; j < max; j++) {
                    if (cards[j][1] == i && cards[j][0] > maxNum) {
                        maxNum = cards[j][0];
                        maxCard = cards[j][1];
                    }
                }
            }
        }
        printf("Multiple cardinality value occur most frequently!\nCardinality value %d with a maximum decimal value of %d\n", maxCard, maxNum);
    }
}

void findMax()
{
    //find max
    for (i = 0; i < 64; i++) {
        if (maxVal < occ[i]) {
            maxVal = occ[i];
        }
    }
    //a boolean
    for (i = 0; i < 64; i++) {
        if (occ[i] == maxVal) {
            maxs[i] = occ[i];
            multiple++;
        }
    }
}

void countOccs()
{
    //long long has a max of 64 binary digits
    for (i = 0; i < 64; i++) {
        int occs = 0;
        for (j = 0; j < max; j++) {
            if (cards[j][1] == i) {
                occs++;
            }
        }
        occ[i] = occs;
    }
}

void input()
{
    char* tok;
    printf("Enter data set now: ");
    fgets(dataSet, 1000000, stdin);
    printf("\n");
    tok = strtok(dataSet, " ");
    while (tok != NULL)
    {
        long long num = atoi(tok);
        if (num < 0) {
            break;
        }
        calculateCard(i, num);
        i++;
        tok = strtok(NULL, " ");
    }
    max = i;
}

void calculateCard(int counter, long long num)
{
    cards[counter][0] = num;
    int i;
    int card = 0;
    for (i = 0; num != 0; i++) {
        if (num % 2 == 1) {
            card++;
        }
        num /= 2;
    }
    cards[counter][1] = card;
}
