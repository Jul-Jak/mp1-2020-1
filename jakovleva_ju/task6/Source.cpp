#include <iostream>
#include <string>
#include <locale>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class NumberGenerator
{
private:
	int Digit;
public:
	NumberGenerator(int digit)
	{
		Digit = digit;
	}
	void CreateNumber(char* Arr)
	{
		srand(time(0));
		for (int i = 0; i < Digit; i++)
		{
			Arr[i] = rand() % 9;

			for (int j = 0; j < i; j++)
			{
				while ((Arr[j] == Arr[i]) || (Arr[0] == 0))
				{
					Arr[i]++;
					break;
				}
			}
		}

	}
};

class Counter
{
private:
	int Digit;
	char* Correct_Number;
public:
	Counter(int digit, char* correct_number)
	{
		Digit = digit;
		Correct_Number = correct_number;
	}

	void CountBullsAndCows(char* player_number, int* bulls, int* cows)
	{
		for (int i = 0; i < Digit; i++)
		{
			if (Correct_Number[i] == player_number[i] - '0')
			{
				(*bulls)++;
			}

			for (int j = 0; j < Digit; j++)
			{
				if (Correct_Number[i] == player_number[j] - '0')
					(*cows)++;
			}
		}
	}
};

class Game
{
private:
	int Digit;
public:
	Game(int digit)
	{
		Digit = digit;
	}

	void Start()
	{
		int yes = 0;
		NumberGenerator NG(Digit);
		char* Arr = new char[Digit];
		NG.CreateNumber(Arr);
		Counter counter(Digit, Arr);
		char* My = new char[Digit];
		while (yes != 1)
		{
			int bulls = 0;
			int cows = 0;
			cout << "��� �������:\n";
			cin >> My;
			counter.CountBullsAndCows(My, &bulls, &cows);
			if (bulls == Digit)
			{
				cout << endl;
				cout << "����������, �� ��������!";
				cout << endl;
				yes = 1;
			}
			else {
				cout << bulls << " ���, " << cows - bulls << " ������!" << endl;
				bulls = 0;
				cows = 0;
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	int k = 1;
	int choice;
	int rules;
	int n;
	while (k == 1)
	{
		cout << "����� ���������� � ���� \"���� � ������!\"" << endl;
		cout << "�������� ���������� ��������:" << endl;
		cout << "1 - ������" << endl;
		cout << "2 - ����� �� ���������" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			cout << "1 - ������ ������� ����" << endl;
			cout << "2 - � ���� ������� ����" << endl;
			cout << "��� �����:" << endl;
			cin >> rules;
			system("cls");
			switch (rules)
			{
			case 1:
			{
				cout << "������ ��� ������ (������� � ���������)" << endl;
				cout << "����� �������� ����� ������������� ����� � n." << endl;
				cout << "��������� ����������� n - ������� ����� � ���������������� �������." << endl;
				cout << "����� ������ ������� �������� ����� � ������ n - ������� ����� � ���������������� �������." << endl;
				cout << "��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����(�� ���� ���������� �����) � ������� ������� ������ �� ������� � ���������� �����(�� ���� ���������� �����)." << endl;
				cout << "����� ������ �������, ���� �� �������� ��� ������������������." << endl;
				cout << "������ ��� �����!" << endl << endl;
				cout << "������� ����� ������������� �����: ";
				cin >> n;
				Game game(n);
				game.Start();
				cout << "������� �� ����!";
				_getch();
				system("cls");
				break;
			}
			case 2:
			{
				int n;
				cout << "������� ����� ������������� �����: ";
				cin >> n;
				Game game(n);
				game.Start();
				cout << "������� �� ����!";
				_getch();
				system("cls");
				break;
			}
			}
		}
		case 2:
		{
			cout << "�� ��������!";
			exit(0);
			system("cls");
		}
		}
	}
}