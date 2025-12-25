#ifndef SORT_H
#define SORT_H

#include "../ds/DynamicArray.h"

template <typename T>
class Sort {
private:
    // Helper to merge two halves
    // Compare function 'comp' allows us to choose the sorting criteria (price, qty, etc.)
    static void merge(DynamicArray<T>& arr, int left, int mid, int right, bool (*comp)(const T&, const T&)) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        DynamicArray<T> L, R;
        for (int i = 0; i < n1; i++) L.push_back(arr[left + i]);
        for (int j = 0; j < n2; j++) R.push_back(arr[mid + 1 + j]);

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (comp(L[i], R[j])) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

public:
    static void mergeSort(DynamicArray<T>& arr, int left, int right, bool (*comp)(const T&, const T&)) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid, comp);
            mergeSort(arr, mid + 1, right, comp);
            merge(arr, left, mid, right, comp);
        }
    }
};

#endif