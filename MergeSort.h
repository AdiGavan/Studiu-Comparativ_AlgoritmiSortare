// "Copyright [2017], Gavan Adrian-George, 324CA"
#include<iostream>

using namespace std;

// Se interclaseaza cei 2 subvectori.
template<typename Type>
void merge(Type* array, int left, int middle, int right) {
    int i = 0, j = 0, k = 0;
    int n1 = middle - left + 1;
    int n2 =  right - middle;

    // Se creeaza 2 array-uri auxiliare si se pun datele in ele
    Type* HalfL = new Type[n1];
    Type* HalfR = new Type[n2];


    for (i = 0; i < n1; i++) {
        HalfL[i] = array[left + i];
    }
    for (j = 0; j < n2; j++) {
        HalfR[j] = array[middle + 1+ j];
    }

    // Se pun elementele din cele 2 array-uri inapoi in vector.
    i = 0; // Indexul pentru primul subvector (HalfL).
    j = 0; // Indexul pentru al doilea subvector (HalfR).
    k = left; // Indexul pentru vectorul interclasat.
    while (i < n1 && j < n2) {
        if (HalfL[i] <= HalfR[j]) {
            array[k] = HalfL[i];
            i++;
        } else {
            array[k] = HalfR[j];
            j++;
        }
        k++;
    }

    // Se copiaza elementele ramase din HalfL (daca mai sunt).
    while (i < n1) {
        array[k] = HalfL[i];
        i++;
        k++;
    }

    // Se copiaza elementele ramase din HalfR (daca mai sunt).
    while (j < n2) {
        array[k] = HalfR[j];
        j++;
        k++;
    }
    delete[] HalfL;
    delete[] HalfR;
}

/* left si right sunt idecsii pentru subvectorii
    vectorului ce trebuie sortat */
template<typename Type>
void mergeSort(Type* array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Se sorteaza cele 2 jumatari.
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}
