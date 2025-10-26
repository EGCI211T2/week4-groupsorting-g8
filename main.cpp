#include <iostream>
#include <cstring>
#include <cstdlib>
#include <chrono> 
using namespace std;
using namespace std::chrono;
#include "sorting.h"

int main(int argc, char * argv[]) {
    int n = argc - 2;
    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        a[i] = atoi(argv[i + 2]);
    }

    if (strcmp(argv[1], "bubble") == 0) {
        bubbleSort(a, n);
    }
    else if (strcmp(argv[1], "selection") == 0) {
        selectionSort(a, n);
    }
    else if (strcmp(argv[1], "insertion") == 0) {
        insertionSort(a, n);
    }
    else if (strcmp(argv[1], "quick") == 0) {
        quickSort(a, n);
    }
    else {
        cout << "Error! Unknown Sorting Algorithm\n";
    }
    

    display(a, n);

    delete[] a;



  return 0;
  }