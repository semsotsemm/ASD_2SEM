#include <iostream>
#include <string>
#include <chrono>

using namespace std;

void inputToInt(string line, int& userInput);
void bubbleSort(int*& B, int size);
void swap(int& firstNum, int& secondNum);
void printArr(int* arr, int size);
void insertionSort(int*& C, int size);
void insert(int i, int j, int* C);
void selectionSort(int*& D, int size);
void quickSort(int*& E, int size);
void quickSortHelper(int* E, int low, int high, int& iterations);
int partition(int* E, int low, int high);

int main() {
    int N = -1;
    setlocale(LC_CTYPE, "Russian");
    string line;
    cout << "Введите число N: ";
    while (true) {
        cin >> line;
        inputToInt(line, N);
        if (N != -1) {
            int* A = new int[N];
            cout << "Массив А: ";
            for (int i = 0; i < N; i++) {
                A[i] = rand() % 1000 + 1;
            }
            printArr(A, N);

            int* B = new int[N], * C = new int[N], * D = new int[N], * E = new int[N];
            for (int i = 0; i < N; i++) {
                B[i] = A[i];
                C[i] = A[i];
                D[i] = A[i];
                E[i] = A[i];
            }

            auto start = chrono::high_resolution_clock::now();
            bubbleSort(B, N);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Время выполнения bubbleSort: " << duration.count() << " мс" << endl << endl;
            cout << "Массив B: ";
            printArr(B, N);

            start = chrono::high_resolution_clock::now();
            insertionSort(C, N);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Время выполнения insertionSort: " << duration.count() << " мс" << endl << endl;
            cout << "Массив C: ";
            printArr(C, N);

            start = chrono::high_resolution_clock::now();
            selectionSort(D, N);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Время выполнения selectionSort: " << duration.count() << " мс" << endl << endl;
            cout << "Массив D: ";
            printArr(D, N);

            start = chrono::high_resolution_clock::now();
            quickSort(E, N);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << "Время выполнения quickSort: " << duration.count() << " мс" << endl << endl;
            cout << "Массив E: ";
            printArr(E, N);

            delete[] A;
            delete[] B;
            delete[] C;
            delete[] D;
            delete[] E;
            break;
        }
        else {
            cout << "Ошибка ввода\n";
        }
    }
    return 0;
}

void inputToInt(string line, int& userInput) {
    int repeat = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            repeat++;
        }
    }
    if (repeat == line.length()) {
        userInput = stoi(line);
    }
}

void bubbleSort(int*& B, int size) {
    int iterations = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            iterations++;
            if (B[j] < B[j - 1]) {
                swap(B[j], B[j - 1]);
            }
        }
    }
    cout << "Количество итераций bubbleSort: " << iterations << endl;
}

void swap(int& firstNum, int& secondNum) {
    int temp = secondNum;
    secondNum = firstNum;
    firstNum = temp;
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertionSort(int*& C, int size) {
    int iterations = 0;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            iterations++;
            if (C[i] < C[j]) {
                insert(i, j, C);
                break;
            }
        }
    }
    cout << "Количество итераций insertionSort: " << iterations << endl;
}

void insert(int i, int j, int* C) {
    int temp = C[i];
    for (int k = i; k > j; k--) {
        C[k] = C[k - 1];
    }
    C[j] = temp;
}

void selectionSort(int*& D, int size) {
    int iterations = 0;
    int k = 0;
    for (int i = 0; i < size; i++) {
        k = i;
        for (int j = i + 1; j < size; j++) {
            iterations++;
            if (D[k] > D[j]) {
                k = j;
            }
        }
        swap(D[i], D[k]);
    }
    cout << "Количество итераций selectionSort: " << iterations << endl;
}
// 1 2 4 6 7 8 3

void quickSortHelper(int* E, int low, int high, int& iterations) {
    if (low < high) {
        int pivotIndex = partition(E, low, high);
        iterations++;
        quickSortHelper(E, low, pivotIndex - 1, iterations);
        quickSortHelper(E, pivotIndex + 1, high, iterations);
    }
}

void quickSort(int*& E, int size) {
    int iterations = 0;
    if (size > 1) {
        quickSortHelper(E, 0, size - 1, iterations);
    }
    cout << "Количество итераций quickSort: " << iterations << endl;
}

int partition(int* E, int low, int high) {
    int pivot = E[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (E[j] <= pivot) {
            i++;
            swap(E[i], E[j]);
        }
    }
    swap(E[i + 1], E[high]);
    return i + 1;
}
