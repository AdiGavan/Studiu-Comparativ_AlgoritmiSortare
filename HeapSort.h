// "Copyright [2017], Gavan Adrian-George, 324CA"
#include<iostream>

using namespace std;

// Functia de reordonare a heap-ului.
template<typename Type>
void heapify(Type* array, int n, int i) {
    int largest = i;  // Largest va fi root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2

    // Cazul cand copilul stang este mai mare ca root.
    if (left < n && array[left] > array[largest]) {
        largest = left;
    }

    // Cazul cand copilul drept este mai mare ca root.
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(array[i], array[largest]);

        // Se apeleaza recursiv heapify pentru subtree.
        heapify(array, n, largest);
    }
}

// Functia pentru Heap Sort.
template<typename Type>
void heapSort(Type* array, int n) {
    // Se construieste heap-ul.
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }

    // Se extrag elementele unul cate unu si se rearanjeaza heap-ul.
    for (int i = n - 1; i >= 0; i--) {
        // Se muta roo-ul la final.
        swap(array[0], array[i]);

        heapify(array, i, 0);
    }
}
