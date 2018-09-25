"Copyright [2017], Gavan Adrian-George, 324CA"

Nume, Prenume: Gavan, Adrian-George

Grupa, Serie: 324CA

Tema Analiza Algoritmilor - Etapa finala
========================================

Continutul arhivei:

1. Sortare_GavanAdrianGeorge_324CA.pdf - Lucrarea in format PDF
2. Sortare_GavanAdrianGeorge_324CA.docx - Lucrarea in forma docx (sursa)
3. GraficeSiTabele.xlsx - Excel-ul folosit la generarea graficelor si tabelelor
4. Fisiere implementare algoritmi:
   Algoritmii au fost implementati in fisiere header sub forma de functii.
   - QuickSortPrim.h - algoritmul QuickSort ce alege ca pivot primul element
   - QuickSortMiddle.h - algoritmul QuickSort ce alege ca pivot elementul din mijloc
   - QuickSortRandomized.h - algoritmul QuickSort ce alege ca pivot un element random din vector
   - MergeSort.h - algoritmul MergeSort
   - HeapSort.h - algoritmul HeapSort
   - StructCustom.h - structura de date custom ("int" + "string")
5. Codul folosit pentru testare:
   - Main.cpp - functia main cere utilizatorului sa introduca fisierul input si fisierul de output,
		daca fisierul de input este corect se cere alegerea algoritmului ce se vrea a fi
		testat (pe ecran apare o lista, fiecarui algoritm corespunzandu-i un numar);
   - Makefile - Contine 3 reguli:
		build - compileaza fisierul Main.cpp si creeaza fisierele Main.o si executabilul Main
		run - ruleaza executabilul o singura data
		clean - sterge fisierele obiect *.o, executabilul Main si fisierele *.out (daca se doreste
		  ca regula clean sa stearga si fisierele de output, acestea trebuie sa aiba extensia .out)
6. Folderul Teste:
   Pentru testarea algoritmilor s-au utilizat 60 de fisiere de test. Arhiva contine doar 24 dintre acestea
   (cu dimensiuni de 2.000 si 20.000 de elemente) pentru ca dimensiunile testelor erau foarte mari,
   respectiv 200.000, 2.000.000 si 20.000.000 de intrari (fisiere disponibile la cerere).
   Prima linie din orice fisier de testare contine numarul total de linii de intrare si tipul datelor.
   Exemplu: 20000 StructCustom, 2000000 int, 2000 string
   Detalierea fisierelor de intrare:
   - NrDubleRandom1.txt/NrDubleRandom2.txt - 2.000/20.000 de elemente de tip int, duplicate, ordonate aleator
   - NrUnicCrescator1.txt/NrUnicCrescator2.txt - 2.000/20.000 de elemente de tip int, unice, ordonate crescator
   - NrUnicDescrescator1.txt/NrUnicDescrescator2.txt - 2.000/20.000 de elemente de tip int, unice, ordonate descrescator
   - NrUnicRandom1.txt/NrUnicRandom2.txt - 2.000/20.000 de elemente de tip int, unice, ordonate aleator
   - SetDubleRandom1.txt/SetDubleRandom2.txt - 2.000/20.000 de elemente de tip StructCustom, duplicate, ordonate aleator
   - SetUnicCrescator1.txt/SetUnicCrescator2.txt - 2.000/20.000 de elemente de tip StructCustom, unice, ordonate crescator
   - SetUnicDescrescator1.txt/SetUnicDescrescator2.txt - 2.000/20.000 de elemente de tip StructCustom, unice, ordonate descrescator
   - SetUnicRandom1.txt/SetUnicRandom2.txt - 2.000/20.000 de elemente de tip StructCustom, unice, ordonate aleator
   - TextDubleRandom1.txt/TextDubleRandom2.txt - 2.000/20.000 de elemente de tip string, duplicate, ordonate aleator
   - TextUnicCrescator1.txt/TextUnicCrescator2.txt - 2.000/20.000 de elemente de tip string, unice, ordonate crescator
   - TextUnicDescrescator1.txt/TextUnicDescrescator2.txt - 2.000/20.000 de elemente de tip string, unice, ordonate descrescator
   - TextUnicRandom1.txt/TextUnicRandom2.txt - 2.000/20.000 de elemente de tip string, unice, ordonate aleator
   Observatie: string-urile au dimensiune variabila si contin caractere alfanumerice sau nume de persoane (Set-uri si duplicate);
7. Generator fisiere de test:
   - spawner.exe - aplicatie Windows pentru generare de date. Programul ruleaza fara a fi instalat.
   Observatie: datele din fisiere au fost editate cu ajutorul Microsoft Excel si Microsoft Access.
   Pentru a putea fi vizualizate si editata prima linie, s-a folosit aplicatia EditPad Lite 7 pentru Windows.
