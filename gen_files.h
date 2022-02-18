#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "math.h"
#include "time.h"


void gen_rand(int n) // generate a file vith random values from -n to n
{
    srand(time(NULL));
    FILE* input = fopen("data/data1.txt", "a");
    for(int i = 0; i < n; i++)
    {
        fprintf(input, "%d\n", (-1) * n + rand()%(2 * n + 1));
    }
    fclose(input);
}


void gen_rev(int n) // generate a file with sorted n to 1 values
{
    FILE* input = fopen("data/data2.txt", "a");
    for(int i = n; i > 0; i--)
    {
        fprintf(input, "%d\n", i);
    }
    fclose(input);
}


void gen_sorted(int n) // generate a file with sorted 1 to n values
{
    FILE* input = fopen("data/data3.txt", "a");
    for(int i = 1; i <= n; i++)
    {
        fprintf(input, "%d\n", i);
    }
    fclose(input);
}
