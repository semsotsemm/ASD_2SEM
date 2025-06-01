#include <iostream>
#include <string>

using namespace std;

void lineToInt(string line, int& input);

void bubbleSort(int*& arr, int size);

int main()
{
	int N = - 1;
	string userInput;
	setlocale(LC_CTYPE,"Russian");
	cout << "Введите N, количество товаров: ";
	while (true)
	{
		cin >> userInput;
		lineToInt(userInput, N);
		if (N != -1)
		{
			int* product = new int[N],* sortProduct = new int[N];
			cout << "Сгенерированные цены товаров: ";
			for (int i = 0; i < N; i++)
			{
				product[i] = rand() % 100 +  1;
				cout << product[i] << " ";
			}
			cout << "\n";
			bubbleSort(product, N);
			int k = 0, sum = 0, p = 0;
			cout << "Последовательность пробития товаров: ";
			for (int j = N - 1; k < j; k++, j--)
			{
				cout << product[j] << " " << product[k] << " ";
				sortProduct[p] = product[j];
				p++;
				sortProduct[p] = product[k];
				p++;
			}
			if (N % 2 == 1)
			{
				cout << product[k];
				sortProduct[N - 1] = product[k];
			}
			for (int i = 0; i < N; i++)
			{
				if (i % 2 == 0)
				{
					sum += sortProduct[i];
				}
			}
			cout << "\n";
			cout << "Максимальная сумма в чеке: "<< sum << '\n';
		}
		else
		{
			cout << "Ошибка ввода\n";
		}
	}

}

void lineToInt(string line, int& input) 
{
	int repeat = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			repeat++;
		}
	}
	if (repeat == line.length())
	{
		input = stoi(line);
	}
}

void bubbleSort(int*& arr, int size) 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}