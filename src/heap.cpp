#include <iostream>
using namespace std;

void maxHeap(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeap(arr, n, largest);
    }
}

void heapSortDescending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeap(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeap(arr, i, 0);
    }

    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];

    int n;
    cout << "Masukkan jumlah elemen (maks 100): ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "Melebihi batas maksimum!" << endl;
        return 1;
    }

    cout << "Masukkan " << n << " angka: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Isi array sebelum sorting: ";
    printArray(arr, n);

    heapSortDescending(arr, n);

    cout << "Max Heap Sort: ";
    printArray(arr, n);

    return 0;
}
