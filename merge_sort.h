#ifndef merge_sort_h
#define merge_sort_h

#include <cassert>
#include <functional>
#include <algorithm>
#include "utils.h"


// top-down mergesort

template <typename T>

class merge_sort {
public:
 static void sort(T* arr, size_t n, const comparator<T>& comp=fwd_comparator<T>()) {
   T* aux;
   aux = new T[std::size(arr)];
   sort(arr, 0, std::size(arr) - 1);
 }


private:
 static const int CUTOFF = 7;

 static void sort(T* arr, T* aux, size_t low, size_t high, const comparator<T>& comp) {
   if (high <= low) return;
   int mid = low + (high - low) / 2;
   sort(arr, low, mid);
   sort(arr, mid + 1, high);
   merge(arr, aux, low, mid, high, comp);
 }

 static void merge(T* arr, T* aux, size_t low, size_t mid, size_t high, const comparator<T>& comp) {
   int i = low, j = mid + 1;

   for(int k = low; k <= high; k++) {
     aux[k] = arr[k];
    }

   for(int k = low; k <= high; k++) {
     if      (i > mid)             arr[k] = aux[j++];
     else if (j > high)            arr[k] = aux[i++];
     else if (less(aux[j],aux[i])) arr[k] = aux[j++];
     else                          arr[k] = aux[i++];
    }

 }
};





// bottom-up mergesort

template <typename T>

class merge_bu_sort {
public:
// merge_bu_sort() = delete;
 static void sort(T* arr, size_t n, const comparator<T>& comp=fwd_comparator<T>()) {
   size_t N = std::size(arr);
   T* aux;
   aux = new T[N];
   for (size_t sz = 1; sz < N; sz = sz + sz) {
     for (size_t low = 0; low < N - sz; low += sz + sz) {
       merge(arr, low, low + sz - 1, std::min(low + sz - 1, N - 1));
     }
   }
 }

private:
 static void merge(T* arr, T* aux, size_t low, size_t mid, size_t high, const comparator<T>& comp) {
   int i = low, j = mid + 1;

   for(int k = low; k <= high; k++) aux[k] = arr[k];

   for(int k = low; k <= high; k++) {
     if      (i > mid)             arr[k] = aux[j++];
     else if (j > high)            arr[k] = aux[i++];
     else if (less(aux[j],aux[i])) arr[k] = aux[j++];
     else                          arr[k] = aux[i++];
    }
  }
};


#endif
