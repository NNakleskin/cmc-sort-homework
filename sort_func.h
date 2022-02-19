#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "limits.h"


void bubble_sort(long long* a, int n, int* count) // Bubble algorithm (read README file)
{
    long long c;
    long long count_cmp = 0, count_swap = 0; // counter of swaps and comparisons
    for(int j = 0; j < n - 1; j++)
    {
        for(int i = 0; i < n - 1; i++)
        {
            count_cmp++; // count of comparisons ++
            if(abs(a[i]) < abs(a[i + 1]))
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


void qsort_alg(long long* a, int first, int last, int count[2]) // qsort algorithm (read README file)
{
    if(last > first)
    {
        long long count_cmp = 0, count_swap = 0; // counter of swaps and comparisons
        int left = first, right = last;
        int mid = abs(a[(left + right) / 2]);
        while(left < right)
        {
            while(abs(a[left]) > mid)
            {
                count_cmp++;
                left++;
            }
            while(abs(a[right]) < mid)
            {
                count_cmp++;
                right--;
            }
            if(left < right)
            {
                count_swap++;
                long long c = a[left];
                a[left] = a[right];
                a[right] = c;
                left++;
                right--;
            }
            else
            {
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
