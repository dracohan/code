#include <stdio.h>
#include "../common_header/utils.h"

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
    quicksort(a, 0, l);
    print_array(a);
}