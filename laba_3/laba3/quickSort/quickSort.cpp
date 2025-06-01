#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <windows.h>

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void quicksort(int* mas, int first, int last, int N) {     //функция сортировки

    int mid, count, midI;
    int f = first, l = last;
    mid = mas[(f + l) / 2];   //вычисление опорного элемента
    midI = (f + l) / 2;

    for (int i = 0; i < N; ++i)
    {
        if (i == f || i == l)
        {
            cout << mas[i] << " ";
        }
        else if (i == midI)
        {
            cout << mas[i] << " ";
        }
        else
            cout << mas[i] << " ";
    }
    cout << " -> f - [" << f << "] = (" << mas[f] << ") | l - [" << l << "] = (" << mas[l] << ")\n\n";

    do
    {
        while (mas[f] < mid)
        {
            for (int i = 0; i < N; ++i)
            {
                if (i == f || i == l)
                {
                    setColor(12);
                    cout << mas[i] << " ";
                    setColor(7);
                }
                else if (i == midI)
                {
                    setColor(8);
                    cout << mas[i] << " ";
                    setColor(7);
                }
                else
                    cout << mas[i] << " ";
            }
            cout << " -> сдвигаем f вправо\n";
            f++;
        }
        while (mas[l] > mid)
        {
            for (int i = 0; i < N; ++i)
            {
                if (i == f || i == l)
                {
                    setColor(12);
                    cout << mas[i] << " ";
                    setColor(7);
                }
                else if (i == midI)
                {
                    setColor(8);
                    cout << mas[i] << " ";
                    setColor(7);
                }
                else
                    cout << mas[i] << " ";
            }
            cout << " -> сдвигаем l влево\n";
            l--;
        }
        cout << "\n";
        if (f <= l)     //перестановка элементов
        {
            for (int i = 0; i < N; ++i)
            {
                if (i == f || i == l)
                {
                    setColor(10);
                    cout << mas[i] << " ";
                    setColor(7);
                }
                else if (i == midI)
                {
                    setColor(8);
                    cout << mas[i] << " ";
                    setColor(7);
                }
                else
                    cout << mas[i] << " ";
            }
            cout << "\n";
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
            for (int i = 0; i < N; ++i)
            {
                if (i == f - 1 || i == l + 1)
                {
                    setColor(10);
                    cout << mas[i] << " ";
                    setColor(7);
                }
                else if (i == midI)
                {
                    setColor(8);
                    cout << mas[i] << " ";
                    setColor(7);
                }
                else
                    cout << mas[i] << " ";
            }
            cout << " -> после swapa\n\n";
        }
        else
        {
            cout << "- не меняем -\n\n";
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l, N);
    if (f < last) quicksort(mas, f, last, N);
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int N = 9;
    vector<int> A = { 45, 81, 4, 25, 15, 2, 96, 85, 3 };
    cout << "Исходный массив: ";
    for (int num : A) cout << num << " ";
    cout << endl;
    vector<int> B = A;
    clock_t start = clock();
    quicksort(B.data(), 0, N - 1, N);
    setColor(8);
    cout << "Быстрая сортировка: ";
    setColor(7);
    for (int num : B) cout << num << " ";
    setColor(12);
    cout << "\n" << (double)(clock() - start) / CLOCKS_PER_SEC * 1000 << " милисекунд" << endl;
    setColor(7);

    return 0;
}