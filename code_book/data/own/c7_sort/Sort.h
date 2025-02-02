#ifndef SORT_H
#define SORT_H

/**
 * Several sorting routines.
 * Arrays are rearranged with smallest item first.
 */

#include <functional>
#include <vector>
using namespace std;

/**
 * Simple insertion sort.
 * O(N^2)
 */
template <typename Comparable>
void insertionSort(vector<Comparable> &a) {
  for (int p = 1; p < a.size(); p++) {
    Comparable tmp = a[p];

    int j;
    for (j = p; j > 0 && tmp < a[j - 1]; j--) a[j] = a[j - 1];
    a[j] = tmp;
  }
}

/**
 * Shellsort, using Shell's (poor) increments.
 * O(N^2)
 */
template <typename Comparable>
void shellsort(vector<Comparable> &a) {
  for (int gap = a.size() / 2; gap > 0; gap /= 2)
    for (int i = gap; i < a.size(); i++) {
      Comparable tmp = a[i];
      int j = i;

      for (; j >= gap && tmp < a[j - gap]; j -= gap) a[j] = a[j - gap];
      a[j] = tmp;
    }
}

/**
 * Standard heapsort.
 * NLogN
 */
template <typename Comparable>
void heapsort(vector<Comparable> &a) {
  for (int i = a.size() / 2; i >= 0; i--) /* buildHeap */
    percDown(a, i, a.size());
  for (int j = a.size() - 1; j > 0; j--) {
    swap(a[0], a[j]); /* deleteMax */
    percDown(a, 0, j);
  }
}

/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int leftChild(int i) { return 2 * i + 1; }

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void percDown(vector<Comparable> &a, int i, int n) {
  int child;
  Comparable tmp;

  for (tmp = a[i]; leftChild(i) < n; i = child) {
    child = leftChild(i);
    if (child != n - 1 && a[child] < a[child + 1]) child++;
    // max heap
    if (tmp < a[child])
      a[i] = a[child];
    else
      break;
  }
  a[i] = tmp;
}

/**
 * Mergesort algorithm (driver).
 * NLogN
 */
template <typename Comparable>
void mergeSort(vector<Comparable> &a) {
  vector<Comparable> tmpArray(a.size());

  mergeSort(a, tmpArray, 0, a.size() - 1);
}

/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void mergeSort(vector<Comparable> &a, vector<Comparable> &tmpArray, int left,
               int right) {
  if (left < right) {
    int center = (left + right) / 2;
    mergeSort(a, tmpArray, left, center);
    mergeSort(a, tmpArray, center + 1, right);
    merge(a, tmpArray, left, center + 1, right);
  }
}

/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
void merge(vector<Comparable> &a, vector<Comparable> &tmpArray, int leftPos,
           int rightPos, int rightEnd) {
  int leftEnd = rightPos - 1;
  int tmpPos = leftPos;
  int numElements = rightEnd - leftPos + 1;

  // Main loop
  while (leftPos <= leftEnd && rightPos <= rightEnd)
    if (a[leftPos] <= a[rightPos])
      tmpArray[tmpPos++] = a[leftPos++];
    else
      tmpArray[tmpPos++] = a[rightPos++];

  while (leftPos <= leftEnd)  // Copy rest of first half
    tmpArray[tmpPos++] = a[leftPos++];

  while (rightPos <= rightEnd)  // Copy rest of right half
    tmpArray[tmpPos++] = a[rightPos++];

  // Copy tmpArray back
  for (int i = 0; i < numElements; i++, rightEnd--)
    a[rightEnd] = tmpArray[rightEnd];
}

/**
 * Quicksort algorithm (driver).
 * NlogN
 */
template <typename Comparable>
void quicksort(vector<Comparable> &a) {
  quicksort(a, 0, a.size() - 1);
}

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable &median3(vector<Comparable> &a, int left, int right) {
  int center = (left + right) / 2;
  if (a[center] < a[left]) swap(a[left], a[center]);
  if (a[right] < a[left]) swap(a[left], a[right]);
  if (a[right] < a[center]) swap(a[center], a[right]);

  // Place pivot at position right - 1
  swap(a[center], a[right - 1]);
  return a[right - 1];
}

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quicksort(vector<Comparable> &a, int left, int right) {
  if (left + 10 <= right) {
    Comparable pivot = median3(a, left, right);

    // Begin partitioning
    int i = left, j = right - 1;
    for (;;) {
      while (a[++i] < pivot) {
      }
      while (pivot < a[--j]) {
      }
      if (i < j)
        swap(a[i], a[j]);
      else
        break;
    }

    swap(a[i], a[right - 1]);  // Restore pivot

    quicksort(a, left, i - 1);   // Sort small elements
    quicksort(a, i + 1, right);  // Sort large elements
  } else                         // Do an insertion sort on the subarray
    insertionSort(a, left, right);
}

/**
 * Internal insertion sort routine for subarrays
 * that is used by quicksort.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void insertionSort(vector<Comparable> &a, int left, int right) {
  for (int p = left + 1; p <= right; p++) {
    Comparable tmp = a[p];
    int j;

    for (j = p; j > left && tmp < a[j - 1]; j--) a[j] = a[j - 1];
    a[j] = tmp;
  }
}

/**
 * Quick selection algorithm.
 * Places the kth smallest item in a[k-1].
 * a is an array of Comparable items.
 * k is the desired rank (1 is minimum) in the entire array.
 */
template <typename Comparable>
void quickSelect(vector<Comparable> &a, int k) {
  quickSelect(a, 0, a.size() - 1, k);
}

/**
 * Internal selection method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * Places the kth smallest item in a[k-1].
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 * k is the desired rank (1 is minimum) in the entire array.
 */
template <typename Comparable>
void quickSelect(vector<Comparable> &a, int left, int right, int k) {
  if (left + 10 <= right) {
    Comparable pivot = median3(a, left, right);

    // Begin partitioning
    int i = left, j = right - 1;
    for (;;) {
      while (a[++i] < pivot) {
      }
      while (pivot < a[--j]) {
      }
      if (i < j)
        swap(a[i], a[j]);
      else
        break;
    }

    swap(a[i], a[right - 1]);  // Restore pivot

    // Recurse; only this part changes
    if (k <= i)
      quickSelect(a, left, i - 1, k);
    else if (k > i + 1)
      quickSelect(a, i + 1, right, k);
  } else  // Do an insertion sort on the subarray
    insertionSort(a, left, right);
}

/**
 * Class that wraps a pointer variable.
 */
template <typename Comparable>
class Pointer {
 public:
  Pointer(Comparable *rhs = NULL) : pointee(rhs) {}

  bool operator<(const Pointer &rhs) const { return *pointee < *rhs.pointee; }

  operator Comparable *() const { return pointee; }

 private:
  Comparable *pointee;
};

/**
 * Sort objects -- even large ones --
 * with only N + ln N Comparable moves on average.
 */
template <typename Comparable>
void largeObjectSort(vector<Comparable> &a) {
  vector<Pointer<Comparable> > p(a.size());
  int i, j, nextj;

  for (i = 0; i < a.size(); i++) p[i] = &a[i];

  quicksort(p);

  // Shuffle items in place
  for (i = 0; i < a.size(); i++)
    if (p[i] != &a[i]) {
      Comparable tmp = a[i];
      for (j = i; p[j] != &a[i]; j = nextj) {
        nextj = p[j] - &a[0];
        a[j] = *p[j];
        p[j] = &a[j];
      }
      a[j] = tmp;
      p[j] = &a[j];
    }
}

/*
 * This is the guts of the generic insertion sort routine.
 * It is logically a private routine.
 * It requires a beginning and ending iterator,
 * a comparison function object,
 * and a dummy parameter that is used to establish
 * the type of objects that are in the container.
 */
template <typename RandomIterator, typename Comparator, typename Object>
void insertionSort(const RandomIterator &begin, const RandomIterator &end,
                   Comparator lessThan, const Object &obj) {
  RandomIterator j;

  for (RandomIterator p = begin + 1; p != end; ++p) {
    Object tmp = *p;
    for (j = p; j != begin && lessThan(tmp, *(j - 1)); --j) *j = *(j - 1);
    *j = tmp;
  }
}

/*
 * This is the more public version of insertion sort.
 * It requires a pair of iterators and a comparison
 * function object. It calls the four parameter version
 * by sending *begin as the additional parameter.
 * The template expansion will allow the routine
 * above to then deduce Object, on the basis of *begin.\
 */
template <typename RandomIterator, typename Comparator>
void insertionSort(const RandomIterator &begin, const RandomIterator &end,
                   Comparator lessThan) {
  if (begin != end) insertionSort(begin, end, lessThan, *begin);
}

/*
 * The two-parameter version logically would call
 * the three parameter version, and send in a
 * default function object. The function object
 * would be less<Object>, but what is Object?
 * We don't know, so we pass *begin to another
 * version of insertionSort to deduce it.
 */
template <typename RandomIterator>
void insertionSort(const RandomIterator &begin, const RandomIterator &end) {
  if (begin != end) insertionSortHelp(begin, end, *begin);
}

/*
 * The three-parameter helper
 * uses Object to construct less<Object>, and
 * calls the three-parameter version of insertionSort.
 */
template <typename RandomIterator, typename Object>
void insertionSortHelp(const RandomIterator &begin, const RandomIterator &end,
                       const Object &obj) {
  insertionSort(begin, end, less<Object>());
}

#endif
