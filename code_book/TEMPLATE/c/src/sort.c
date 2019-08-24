#include <stdio.h>
#include "utils.h"

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
    int gap, i, j, temp;
    
    for (gap = n/2; gap > 0; gap /=2)
        for (i = gap; i < n; i++)
            for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

void quicksort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left; 
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    quicksort(v, left, last - 1);
    quicksort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main() {
    int a[] = {5,2,3,8,10,21,32,55,14};
    int l = sizeof(a)/sizeof(a[0]);
    printf("array length a: %d\n", l);
    quicksort(a, 0, l);
    print_array(a, l);
}