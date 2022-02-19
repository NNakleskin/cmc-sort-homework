#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "limits.h"

/* This solves the issue of using the standard abs() function
 * This function is described here:
    https://stackoverflow.com/questions/22268815/absolute-value-of-int-min
 */
unsigned int absu(int value) {
    return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
}


void bubble_sort(int* a, int n, int* count) // Bubble algorithm (read README file)
{
    int c;
    int count_cmp = 0, count_swap = 0; // counter of swaps and comparisons
    for(int j = 0; j < n - 1; j++)
    {
        for(int i = 0; i < n - 1; i++)
        {
            count_cmp++; // count of comparisons ++
            if(absu(a[i]) < absu(a[i + 1]))
            {
                count_swap++; // count of swaps ++
                c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
            }
        }
    }
    count[0] = count_cmp; // save the number of comparisons
    count[1] = count_swap; // save the nubber of swaps
}


void qsort_alg(int* a, int first, int last, int count[2]) // qsort algorithm (read README file)
{
    if(last > first)
    {
        int count_cmp = 0, count_swap = 0; // counter of swaps and comparisons
        int left = first, right = last;
        int mid = absu(a[(left + right) / 2]);
        while(left < right)
        {
            while(absu(a[left]) > mid)
            {
                count_cmp++;
                left++;
            }
            while(absu(a[right]) < mid)
            {
                count_cmp++;
                right--;
            }
            if(left <= right)
            {
                count_swap++;
                int c = a[left];
                a[left] = a[right];
                a[right] = c;
                left++;
                right--;
            }
        }
        count[0] += count_cmp;
        count[1] += count_swap;
        qsort_alg(a, first, right, count);
        qsort_alg(a, left, last, count);
    }
}
