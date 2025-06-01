#include <iostream>

using namespace std;

void timer(int timeNow[])
{
	time_t t = time(nullptr);
	tm now;
	localtime_s(&now, &t);
	timeNow[0] = now.tm_sec;
	timeNow[1] = now.tm_min;
}

bool checkInt(string userInput) 
{
	for (int i = 0; i < userInput.length(); i++)
	{
		if (!(userInput[i] >= '0' && userInput[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}

void calculateNumber(long long counter,int subsequence[])
{
	int sum = subsequence[0] + subsequence[1];
	subsequence[0] = subsequence[1];
	subsequence[1] = sum;
	counter--;
	if (counter == 0)
	{
		cout << "Число под номером N в последовательности Фибоначчи: " << subsequence[1] << "\n";
		return;
	}
	else
	{
		calculateNumber(counter, subsequence);
	}
};

int main()
{
	string userInput;
	int subsequence[2] = {0,1};
	long long N;
	int timeBefore[2];
	int timeAfter[2];
	setlocale(LC_CTYPE, "Russian");
	while (true)
	{
		cout << "Введите число N: ";
		cin >> userInput;
		if (checkInt(userInput))
		{
			N = atoi(userInput.c_str());
			if (N >= 0 && N <= 2)
			{
				cout << "Ошибка ввода: 1 и 2 числа последовательности Фибоначчи известны";
			}
			else
			{
				cout << "Выполняются вычисления...\n";
				timer(timeBefore);
				calculateNumber(N - 2, subsequence);
				timer(timeAfter);
				subsequence[0] = 0;
				subsequence[1] = 1;
				cout << "Вычисления выполнялись: " << timeAfter[1] - timeBefore[1] << " минут, " << timeAfter[0] - timeBefore[0] << " секунд\n";
			}
		}
		else
		{
			cout << "Ошибка ввода: введено не целое или отрицательное число\n";
		}
	}


}