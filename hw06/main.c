#include<stdio.h>
#include<math.h>
#define SIZE 30

//Global Declarations
double * changes(double*);
double total_inc(double*);
double total_dec(double*);
double AvgInc(double*);
double AvgDec(double*);

int main()
{
    int i; //initialize loop count
    double price[SIZE]; //array of prices data of size 25
    double* DayChange; //array of the day to day change
    double Average_inc; //average increase
    double Average_dec; //average decrease
    int counter_I; // total increases
    int counter_D; //total decreases

    printf("Enter price data for 30 days: ");
    for(i = 0; i < SIZE; i++)
    {
        scanf("%lf", &price[i]);
    }
    printf("\n");
    DayChange = changes(price);

    counter_I = total_inc(DayChange);
    printf("Total increases: %d ", counter_I);
    Average_inc = AvgInc(DayChange);
    printf("Average increase: $ %.2f\n", Average_inc);
    counter_D = total_dec(DayChange);
    printf("Total decreases: %d ", counter_D);
    Average_dec = AvgDec(DayChange);
    printf("Average decrease: $ %.2f\n\n", Average_dec);

    printf("Price Changes for the past 30 days: \n");
    for(i = 0; i < SIZE - 1; i++)
    {
        printf("$ %+.2f ", DayChange[i]);
        // Add a newline every 5 days
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}
double * changes (double* price)
{
    int i;
    double change;
    static double DayChanges[SIZE - 1];
    for(i = 0; i < SIZE - 1; i++)
    {
        change = price[i + 1] - price[i];
        DayChanges[i] = change;
    }
    return(DayChanges);
}

double total_inc(double* DayChanges)
{
    int i;
    int counter_I = 0;
    for(i = 0; i < SIZE; i++)
    {
        if (DayChanges[i] > 0)
        {
            counter_I++;
        }
    }
    return(counter_I);
}

double total_dec(double* DayChanges)
{
    int i;
    int counter_D = 0;
    for(i = 0; i < SIZE; i++)
    {
        if (DayChanges[i] < 0)
        {
            counter_D++;
        }
    }
    return(counter_D);
}

double AvgInc(double* DayChanges)
{
    int i;
    double total = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (DayChanges[i] > 0) {
            total += DayChanges[i];
        }
    }
    return(total / total_inc(DayChanges));
}

double AvgDec(double* DayChanges)
{
    int i;
    double total = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (DayChanges[i] < 0) {
            total += DayChanges[i];
        }
    }
    // Multiplying by -1 so the output will be positive.
    return(-1 * total / total_dec(DayChanges));
}

