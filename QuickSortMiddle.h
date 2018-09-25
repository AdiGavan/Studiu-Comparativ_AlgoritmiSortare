// "Copyright [2017], Gavan Adrian-George, 324CA"
#include<iostream>

using namespace std;

/* Functia ia elementul din mijloc ca si pivot, pune pivotul in pozitia corecta
  din vectorul sortat, plaseaza toate elementele mai mici decat pivotul
  la stanga acestuia si toate elementele mai mari la dreapta. */
template<typename Type>
int partitionMiddle (Type* array, int low, int high) {
    Type pivot = array[low + (high - low) / 2];
    low--;
    high++;
    while(low <= high) {
        low++;
        while(array[low] < pivot) {
          low++;
        }
        high--;
        while(array[high] > pivot) {
          high--;
        }
        if(low >= high) {
          break;
        }
        swap(array[low], array[high]);
    }
    return high;
}

/* Functia care implementeaza Quick Sort.*/
template<typename Type>
void quickSortMiddle(Type* array, int left, int right) {
    if (left < right) {
        /* Elementul de la pozitia part_index se va afla in pozitia
          corecta din vectorul sortat */
        int part_index = partitionMiddle(array, left, right);

        /* Se sorteaza elementele de dinainte de part_index si de dupa. */
        quickSortMiddle(array, left, part_index);
        quickSortMiddle(array, part_index + 1, right);
    }
}
