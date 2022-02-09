#include <stdio.h>
#include "stdlib.h"
#include "limits.h"
#include "math.h"


void gen_rand(int n) // generate a file vith random values
{
    FILE* input = fopen("data1.txt", "a");
    for(int i = 0; i < n; i++)
    {
        fprintf(input, "%d\n", -500 + rand()%1000);
    }
    fclose(input);
}


void gen_rev(int n) // generate a file with reverse values
{
    FILE* input = fopen("data2.txt", "a");
    for(int i = n; i > 0; i--)
    {
        fprintf(input, "%d\n", i);
    }
    fclose(input);
}


void gen_sorted(int n) // generate a file with sorted values
{
    FILE* input = fopen("data3.txt", "a");
    for(int i = 1; i <= n; i++)
    {
        fprintf(input, "%d\n", i);
    }
    fclose(input);
}


void bubble_sort(int* a, int n) // Bubble algorithm
{
    int c;
    int count_cmp = 0, count_swap = 0; // counter of swaps and comparisons
    for(int j = 0; j < n - 1; j++)
    {
        for(int i = 0; i < n - 1; i++)
        {
            count_cmp++;
            if(abs(a[i]) < abs(a[i + 1]))
            {
                count_swap++;
                c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
            }
        }
    }
    printf("Count_cmp = %d\nCount_swap = %d\n", count_cmp, count_swap);
    // print count os swaps and comparisons in console
}


void quick_sort(int* a, int n) // qsort algorithm
{
    int count_cmp = 0, count_swap = 0; // counter of swaps and comparisons
    int mid = abs(a[n / 2]), last = n - 1, c;
    for(int i = 0; i < n / 2; i++)
    {
        count_cmp++;
        if(abs(a[i]) < mid)
        {
            for(int j = last; j > n / 2; j--)
            {
                count_cmp++;
                if(abs(a[j]) > mid)
                {
                    count_swap++;
                    c = a[i];
                    a[i] = a[j];
                    a[j] = c;
                }
            }
        }
    }
    if((n / 2) > 1)
    {
        quick_sort(a + (n / 2), n / 2);
        quick_sort(a, n / 2);
    }
}


int main(void) {
    int n; // number of numbers to sort
    printf("Print n = ");
    scanf("%d", &n);
    gen_rand(n);
    gen_sorted(n);
    gen_rev(n);
    // BUBBLE SORT RANDOM VALUES
    FILE* input_1 = fopen("data1.txt", "r"); // input for random values bubble sort
    FILE* output_1_1 = fopen("output1.1.txt", "w");  // output for random values bubble sort
    int* a = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        fscanf(input_1, "%d", &a[i]);
    }
    printf("\nBubble sort random values\n");
    bubble_sort(a, n);
    for(int i = 0; i < n; i++)
    {
        fprintf(output_1_1, "%d\n", a[i]);
    }
    // QUICK SORT RANDOM VALUES
    FILE* output_1_2 = fopen("output1.2.txt", "w");  // output for random values bubble sort
    for(int i = 0; i < n; i++)
    {
        fscanf(input_1, "%d", &a[i]);
    }
    printf("Quick sort random values\n");
    quick_sort(a, n);
    for(int i = 0; i < n; i++)
    {
        fprintf(output_1_2, "%d\n", a[i]);
    }
    // BUBBLE SORT SORTED VALUES
    FILE* input_2 = fopen("data2.txt", "r");
    FILE* output_2_1 = fopen("output2.1.txt", "w");
    for(int i = 0; i < n; i++)
    {
        fscanf(input_2, "%d", &a[i]);
    }
    printf("\n\nBubble sort sorted n to 1 values\n");
    bubble_sort(a, n);
    for(int i = 0; i < n; i++)
    {
        fprintf(output_2_1, "%d\n", a[i]);
    }
    // QUICK SORT SORTED VALUES
    FILE* output_2_2 = fopen("output2.2.txt", "w");
    for(int i = 0; i < n; i++)
    {
        fscanf(input_2, "%d", &a[i]);
    }
    printf("\n\nQuick sort sorted n to 1 values\n");
    quick_sort(a, n);
    for(int i = 0; i < n; i++)
    {
        fprintf(output_2_2, "%d\n", a[i]);
    }
    // BUBBLE SORT REVERSE VALUES
    FILE* input_3 = fopen("data3.txt", "r");
    FILE* output_3_1 = fopen("output3.1.txt", "w");
    for(int i = 0; i < n; i++)
    {
        fscanf(input_3, "%d", &a[i]);
    }
    printf("\n\nBubble sort sorted 1 to n values\n");
    bubble_sort(a, n);
    for(int i = 0; i < n; i++)
    {
        fprintf(output_3_1, "%d\n", a[i]);
    }
    // QUICK SORT REVERSE VALUES
    FILE* output_3_2 = fopen("output3.2.txt", "w");
    for(int i = 0; i < n; i++)
    {
        fscanf(input_3, "%d", &a[i]);
    }
    printf("\n\nQuick sort sorted 1 to n values\n");
    quick_sort(a, n);
    for(int i = 0; i < n; i++)
    {
        fprintf(output_3_2, "%d\n", a[i]);
    }
    
    free(a);
    return 0;
}
