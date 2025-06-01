#include <iostream>

using namespace std;

bool checkNumber(string userInput, int& number) 
{
	number = 0;
	int j = 0;
	for (int i = userInput.length() - 1; i >= 0; i--)
	{
		if (userInput[i] >= '0' && userInput[i] <= '9')
		{
			number += (userInput[i] - '0') * pow(10, j);
			j++;
		}
	}
	return userInput.length() == j;
}

int main()
{
	int number, input = 0, limit[2];
	string userInput;
	setlocale(LC_CTYPE, "Russian");
	while (true)
	{
		cout << "Загадайте число и введите верхний придел N: ";
		cin >> userInput;
		if (checkNumber(userInput, number))
		{
			limit[0] = 1;
			limit[1] = number;
			input = 0;
			while (input != 1)
			{
				cout << "Ваше число: " << (limit[1] + limit[0]) / 2 << "?\n";
				cout << "1 - Угадал\n";
				cout << "2 - Мое число меньше\n";
				cout << "3 - Мое число больше\n";
				cin >> userInput;
				if (checkNumber(userInput, input))
				{
					switch (input)
					{
					case 2:
						limit[1] = (limit[1] + limit[0]) / 2;
						break;
					case 3:
						limit[0] = (limit[1] + limit[0]) / 2;
						break;
					case 1:
					{
						int i = 0;
						while (pow(2, i) < number)
						{
							i++;
						}
						cout << "Максимальное количество шагов, для того, чтобы угадать ваше число: " << i << "\n";
						for (int i = number; i > 0; i /= 2)
						{
							cout << i <<"\n";
							if (i * 5 % 10 == 5 && i != 1)
							{
								i++;
							}
						}
						break;
					}
					default:
						cout << "Ошибка ввода\n";
						break;
					}
				}
				else
				{
					cout << "Ошибка ввода\n";
				}
			}
		}
		else
		{
			cout << "Ошибка ввода\n";
		}
	}
}