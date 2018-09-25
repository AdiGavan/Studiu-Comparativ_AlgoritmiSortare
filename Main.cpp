// "Copyright [2017], Gavan Adrian-George, 324CA"
#include <iostream>
#include <chrono>
#include <fstream>
#include "StructCustom.h"
#include "QuickSortPrim.h"
#include "QuickSortMiddle.h"
#include "QuickSortRandomized.h"
#include "MergeSort.h"
#include "HeapSort.h"

using namespace std;

// Functie pentru testarea programului in functie de algoritm;
template<typename Type>
void function (Type* array, int n, int nr_algoritm) {
  if (nr_algoritm == 1) {
    auto start = std::chrono::system_clock::now();
    quickSortRandomized(array, 0, n-1);
    auto end = std::chrono::system_clock::now();

    auto elapsed =
    std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Timpul pentru sortarea elementelor in microsecunde: "
              << elapsed.count() << '\n';
  } else if(nr_algoritm == 2) {
    auto start = std::chrono::system_clock::now();
    quickSortMiddle(array, 0, n-1);
    auto end = std::chrono::system_clock::now();

    auto elapsed =
    std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Timpul pentru sortarea elementelor in microsecunde: "
              << elapsed.count() << '\n';
  } else if (nr_algoritm == 3) {
    auto start = std::chrono::system_clock::now();
    quickSortPrim(array, 0, n-1);
    auto end = std::chrono::system_clock::now();

    auto elapsed =
    std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Timpul pentru sortarea elementelor in microsecunde: "
              << elapsed.count() << '\n';
  } else if (nr_algoritm == 4) {
    auto start = std::chrono::system_clock::now();
    mergeSort(array, 0, n-1);
    auto end = std::chrono::system_clock::now();

    auto elapsed =
    std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Timpul pentru sortarea elementelor in microsecunde: "
              << elapsed.count() << '\n';
  } else if (nr_algoritm == 5) {
    auto start = std::chrono::system_clock::now();
    heapSort(array, n);
    auto end = std::chrono::system_clock::now();

    auto elapsed =
    std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Timpul pentru sortarea elementelor in microsecunde: "
              << elapsed.count() << '\n';
  }
}


int main(int argc, char* argv[]) {
  string fisier_input;
  string fisier_output;

  // Deschidere fisier input;
  cout << "Introduceti va rog numele fisierului de input: ";
  cin >> fisier_input;
  cout << endl;
  ifstream infile(fisier_input);
  if (!infile.is_open()){
    cout << "Eroare! Fisier input incorect!" << endl;
    return -1;
  }

  // Deschidere fisier output;
  cout << "Introduceti va rog numele fisierului de output: ";
  cin >> fisier_output;
  cout << endl;
  ofstream outfile(fisier_output);

  int n = 0;
  infile >> n;
  string tipdate;
  infile >> tipdate;
  cout << "Ce algoritm doriti sa testati? Alegeti va rog un numar: " << endl;
  cout << "1. QuickSortRandomized" << endl;
  cout << "2. QuickSortMiddle" << endl;
  cout << "3. QuickSortPrim" << endl;
  cout << "4. MergeSort" << endl;
  cout << "5. HeapSort" <<endl;
  cout << "Numarul algoritmului: ";
  int nr_algoritm;
  cin >> nr_algoritm;
  cout << endl;

  while (nr_algoritm > 5 || nr_algoritm < 1) {
    cout << "Numarul dat este invalid. Va rog sa dati unul din numerele din lista." << endl;
    cout << "Numarul algoritmului: ";
    cin >> nr_algoritm;
    cout << endl;
  }

  int* array1 = new int[n];
  string* array2 = new string[n];
  StructCustom* array3 = new StructCustom[n];

  // Fisiere cu date de tip int;
  if (tipdate == "int") {
    for (int i = 0; i < n; i++){
      infile >> array1[i];
    }
    function(array1, n, nr_algoritm);

    // Fisiere cu date de tip string;
  } else if (tipdate == "string") {
    for (int i = 0; i < n; i++){
      infile >> array2[i];
    }
    function(array2, n, nr_algoritm);

    // Fisiere cu date de tip StructCustom;
  } else if (tipdate == "StructCustom") {
    for (int i = 0; i < n; i++){
      int aux1;
      string aux2;
      infile >> aux1;
      infile >> aux2;
      array3[i].setNumar(aux1);
      array3[i].setText(aux2);
    }
    function(array3, n, nr_algoritm);
  }

  outfile << "Elementele sortate: " << endl;

  if (tipdate == "int") {
      // Scriere date sortate in fisier pentru testare cu "int" sau "string".
      for (int i = 0; i < n; i++) {
        outfile << array1[i];
        outfile << endl;
      }
  } else if (tipdate == "string") {
    for (int i = 0; i < n; i++) {
      outfile << array2[i];
      outfile << endl;
    }

    // Scriere date sortate in fisier pentru testare cu StructCustom.
  } else if (tipdate == "StructCustom") {
    for (int i = 0; i < n; i++) {
      outfile << array3[i].getNumar() << " " << array3[i].getText();
      outfile << endl;
    }
  }

  delete[] array1;
  delete[] array2;
  delete[] array3;

  infile.close();
  outfile.close();

  return 0;
}
