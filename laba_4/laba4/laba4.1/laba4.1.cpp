#include <iostream>
#include <string>

using namespace std;

void lineToInt(string line, int& input);

void bubbleSort(int*& arr, int size);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int N = -1, sum = 0;
	string userInput;
	cout << "Введите N, количество участников олимпиады: ";
	while (true)
	{
		cin >> userInput;
		lineToInt(userInput, N);
		if (N != -1)
		{
			int* participants = new int[N];
			cout << "Сгенерированные оценки участников олимпиады: ";
			for (int i = 0; i < N; i++)
			{
				participants[i] = rand() % 100 + 1;
				cout << participants[i] << " ";
			}
			bubbleSort(participants, N);
			for (int i = 0; i < N; i++)
			{
				if (participants[i] == participants[0] || participants[i] == participants[1] || participants[i] == participants[2])
				{
					sum++;
				}
			}
			cout << "\nЧисло призеров: " << sum << '\n';
			cout << "Призеры – это участники, набравшие ";
			if (participants[0] == participants[1] && participants[1] == participants[2])
			{
				cout << participants[0];
			}
			else
			{
				cout << "Призеры – это участники, набравшие " << participants[0] << ", " << participants[1] << " или " << participants[2];
			}
			cout << " баллов\n";

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
			if (arr[j - 1] < arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}