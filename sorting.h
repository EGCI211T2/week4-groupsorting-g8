// selection sort function module in C

/*void display(int a[],int n){

    int i;

    for(i=0;i<n;i++)
        printf("%5d",a[i]);
    printf("\n");
  
}

void selectionSort(int data[], int length) 
{ 
	int i, j, m, mi; 
	
     display(data,length);
     
	
} 



void insertion(int a[],int n){


}



void bubbleSort(int a[],int n){

int i,j;
int sorted;
// how may pair to compare?
for(j=1;j<=n-1;j++){
 
  display(a,n);
 }
  
}
*/

void display(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int *a,int *b){
 int temp;
  temp=*a;
  *a=*b;
  *b=temp;
  
}

void bubbleSort(int *a, int n) {
    int moves = 0;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]); 
                moves++;
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Moves:" << moves << endl << "Execution time: " << duration.count() << " nanoseconds" << endl << "Using Bubble Sort:" << endl;
}

void selectionSort(int *a, int n) {
    int moves = 0;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&a[i], &a[minIndex]);
            moves++;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Moves:" << moves << endl << "Execution time: " << duration.count() << " nanoseconds" << endl << "Using Selection Sort:" << endl;
}

void insertionSort(int *a, int n) {
    int moves = 0;
    auto start = high_resolution_clock::now();

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            moves++;
        }
        a[j + 1] = key;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Moves:" << moves << endl << "Execution time: " << duration.count() << " nanoseconds" << endl << "Using Insertion Sort:" << endl;
}
int movesQuick = 0;

int partitionQuick(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
            movesQuick++; // swap move
        }
    }
    swap(a[i + 1], a[high]);
    movesQuick++; // final pivot swap
    return (i + 1);
}

void quickSortAlgo(int a[], int low, int high) {
    if (low < high) {
        int pi = partitionQuick(a, low, high);
        quickSortAlgo(a, low, pi - 1);
        quickSortAlgo(a, pi + 1, high);
    }
}

void quickSort(int a[], int n) {
    movesQuick = 0;
    auto start = high_resolution_clock::now();

    quickSortAlgo(a, 0, n - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "Quick Sort Completed.\n";
    cout << "Moves: " << movesQuick << endl;
    cout << "Time: " << duration << " microseconds\n";
}