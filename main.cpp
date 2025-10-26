#include <iostream>
#include <cstring>   
#include <cstdlib>   
#include <chrono>    
#include "sorting.h"
using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Usage: ./sort <algorithm> <numbers...>" << endl;
        cout << "Example: ./sort insertion 20 50 10 60 5 1 2" << endl;
        return 1;
    }

    string algo = argv[1];            
    int n = argc - 2;                 
    int *a = new int[n];              

    // convert input numbers from argv
    for (int i = 0; i < n; i++) {
        a[i] = atoi(argv[i + 2]);
    }

    cout << "Original array:" << endl;
    display(a, n);

    // start timer
    auto start = high_resolution_clock::now();

    // choose algorithm
    if (algo == "bubble") {
        cout << "Running Bubble Sort..." << endl;
        bubbleSort(a, n);
    } 
    else if (algo == "insertion" || algo == "insert") {
        cout << "Running Insertion Sort..." << endl;
        insertion(a, n);
    } 
    else if (algo == "selection") {
        cout << "Running Selection Sort..." << endl;
        selectionSort(a, n);
    } 
    else {
        cout << "Unknown algorithm: " << algo << endl;
        cout << "Use one of: bubble, insertion, selection" << endl;
        delete[] a;
        return 1;
    }

    // stop timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array:" << endl;
    display(a, n);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    delete[] a;
    return 0;
}