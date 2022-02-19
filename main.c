#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "math.h"
#include "time.h"
#include "gen_files.h"
#include "sort_func.h"


int main(void) {
    FILE* res = fopen("data/results.txt", "a");
    int* count = calloc(2, sizeof(int));
    int n; // number of numbers to sort
    printf("Print n = ");
    scanf("%d", &n);
    gen_rand(n); // generate files
    gen_sorted(n);
    gen_rev(n);
    // BUBBLE SORT RANDOM VALUES
    FILE* input_1_1 = fopen("data/data1.txt", "r"); // input random values from the file
    FILE* output_1_1 = fopen("data/output1.1.txt", "w");  // output file for bubble sort random input
    long long* a = (long long*) malloc(n * sizeof(long long));
    for(int i = 0; i < n; i++)  // scan data from input file
    {
        fscanf(input_1_1, "%lld", &a[i]);
    }
    fprintf(res, "\nBubble sort random values\n");
    bubble_sort(a, n, count);
    fprintf(res, "Count_cmp = %d\nCount_swap = %d\n", count[0], count[1]);// Print count of swaps and comparisons to res.txt
    count[0] = 0; // zeroing the counters
    count[1] = 0; //
    for(int i = 0; i < n; i++) // print data to output file
    {
        fprintf(output_1_1, "%lld\n", a[i]);
    }
    fclose(input_1_1);
    fclose(output_1_1);
    // QUICK SORT RANDOM VALUES
    FILE* input_1_2 = fopen("data/data1.txt", "r"); // input random values from the file
    FILE* output_1_2 = fopen("data/output1.2.txt", "w");  // output file for qsort sort random input
    for(int i = 0; i < n; i++)  // scan data from input file
    {
        fscanf(input_1_2, "%lld", &a[i]);
    }
    fprintf(res, "\n\nQuick sort random values\n");
    qsort_alg(a, 0, n, count);
    fprintf(res, "Count_cmp = %d\nCount_swap = %d\n", count[0], count[1]); // Print count of swaps and comparisons to res.txt
    count[0] = 0; // zeroing the counters
    count[1] = 0; //
    for(int i = 0; i < n; i++)
    {
        fprintf(output_1_2, "%lld\n", a[i]);
    }
    fclose(input_1_2);
    fclose(output_1_2);
    // BUBBLE SORT SORTED VALUES
    FILE* input_2_1 = fopen("data/data2.txt", "r"); // input sorted n to 1 file
    FILE* output_2_1 = fopen("data/output2.1.txt", "w"); // output for sorted file
    for(int i = 0; i < n; i++)  // scan data from input file
    {
        fscanf(input_2_1, "%lld", &a[i]);
    }
    fprintf(res, "\n\nBubble sort sorted n to 1 values\n");
    bubble_sort(a, n, count);
    fprintf(res, "Count_cmp = %d\nCount_swap = %d\n", count[0], count[1]);// Print count of swaps and comparisons to res.txt
    count[0] = 0; // zeroing the counters
    count[1] = 0; //
    for(int i = 0; i < n; i++)
    {
        fprintf(output_2_1, "%lld\n", a[i]);
    }
    fclose(input_2_1);
    fclose(output_2_1);
    // QUICK SORT SORTED VALUES
    FILE* input_2_2 = fopen("data/data2.txt", "r");
    FILE* output_2_2 = fopen("data/output2.2.txt", "w");
    for(int i = 0; i < n; i++)  // scan data from input file
    {
        fscanf(input_2_2, "%lld", &a[i]);
    }
    fprintf(res, "\n\nQuick sort sorted n to 1 values\n");
    qsort_alg(a, 0, n, count);
    fprintf(res, "Count_cmp = %d\nCount_swap = %d\n", count[0], count[1]);// Print count of swaps and comparisons to res.txt
    count[0] = 0; // zeroing the counters
    count[1] = 0; //
    for(int i = 0; i < n; i++)
    {
        fprintf(output_2_2, "%lld\n", a[i]);
    }
    fclose(input_2_2);
    fclose(output_2_2);
    // BUBBLE SORT REVERSE VALUES
    FILE* input_3_1 = fopen("data/data3.txt", "r");
    FILE* output_3_1 = fopen("data/output3.1.txt", "w");
    for(int i = 0; i < n; i++)  // scan data from input file
    {
        fscanf(input_3_1, "%lld", &a[i]);
    }
    fprintf(res, "\n\nBubble sort sorted 1 to n values\n");
    bubble_sort(a, n, count);
    fprintf(res, "Count_cmp = %d\nCount_swap = %d\n", count[0], count[1]);// Print count of swaps and comparisons to res.txt
    count[0] = 0; // zeroing the counters
    count[1] = 0; //
    for(int i = 0; i < n; i++)
    {
        fprintf(output_3_1, "%lld\n", a[i]);
    }
    fclose(input_3_1);
    fclose(output_3_1);
    // QUICK SORT REVERSE VALUES
    FILE* input_3_2 = fopen("data/data3.txt", "r");
    FILE* output_3_2 = fopen("data/output3.2.txt", "w");
    for(int i = 0; i < n; i++)  // scan data from input file
    {
        fscanf(input_3_2, "%lld", &a[i]);
    }
    fprintf(res, "\n\nQuick sort sorted 1 to n values\n");
    qsort_alg(a, 0, n, count);
    fprintf(res, "Count_cmp = %d\nCount_swap = %d\n", count[0], count[1]);
    count[0] = 0; // zeroing the counters
    count[1] = 0; //
    for(int i = 0; i < n; i++)
    {
        fprintf(output_3_2, "%lld\n", a[i]);
    }
    fclose(input_3_2);
    fclose(output_3_2);
    fclose(res);
    free(a);
    free(count);
    return 0;
}
