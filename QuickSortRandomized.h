// "Copyright [2017], Gavan Adrian-George, 324CA"
#include<iostream>

using namespace std;

template<typename Type>
void swapRandomized(Type *a, Type *b) {
    Type temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Functia ia un element random din vector ca si pivot, pune pivotul in pozitia
  corecta din vectorul sortat, plaseaza toate elementele mai mici decat pivotul
  la stanga acestuia si toate elementele mai mari la dreapta. */
template<typename Type>
int partionRandomized(Type* array, int left, int right) {
     // Se genereaza un numar random pentru pivot;
    int pivotIndex = left + rand() % (right - left + 1);
    Type pivot;
    int i = left - 1;
    int j = 0;
    pivot = array[pivotIndex];

    swapRandomized(&array[pivotIndex], &array[right]);

    for (j = left; j < right; j++) {
        if (array[j] < pivot) {
            i++;
            swapRandomized(&array[i], &array[j]);
        }
    }

    swapRandomized(&array[i+1], &array[right]);
    return i + 1;
}

/* Functia care implementeaza Quick Sort.*/
template<typename Type>
void quickSortRandomized(Type* array, int left, int right) {
    int part_index = 0;

    if (left < right) {
      /* Elementul de la pozitia part_index se va afla in pozitia
        corecta din vectorul sortat */
        part_index = partionRandomized(array, left, right);

        /* Se sorteaza elementele de dinainte de part_index si de dupa. */
        quickSortRandomized(array, left, part_index - 1);
        quickSortRandomized(array, part_index + 1, right);
    }
}
