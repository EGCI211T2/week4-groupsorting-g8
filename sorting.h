#include <iostream>
using namespace std;

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertion(int a[], int n) {
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
        display(a, n);
    }
}

void bubbleSort(int a[], int n) {
    int i, j;
    bool sorted;
    for (j = 0; j < n - 1; j++) {
        sorted = true;
        for (i = 0; i < n - j - 1; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                sorted = false;
            }
        }
        display(a, n);
        if (sorted) break;
    }
}

void selectionSort(int data[], int length) {
    int i, j, minIndex;
    for (i = 0; i < length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < length; j++) {
            if (data[j] < data[minIndex])
                minIndex = j;
        }
        swap(data[i], data[minIndex]);
        display(data, length);
    }
}