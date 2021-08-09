// This is a simple Yoyo made using windows library of C++.
// You can set the number of throws it would make and also adjust the speed of the yoyo.
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main()
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	int again = 1;
	do
	{
		// clear the screen
		system("cls");
		SetConsoleTextAttribute(screen, 3);
		cout << "\t\t\t\t\t\t\t\t--------" << endl;
		cout << "\t\t\t\t\t\t\t\t| YOYO |" << endl;
		cout << "\t\t\t\t\t\t\t\t--------" << endl;
		SetConsoleTextAttribute(screen, 14);

		// Number of Throws
		cout << "> Enter the number of throws it should make : ";
		int throws;
		cin >> throws;
		cout << endl;

		// Speed of the Yoyo
		cout << "> Note: 10 is the Fastest Speed and 250 is the Slowest!!!" << endl;
		cout << "> Enter the Speed (Range: 20-250) : ";
		int speed;
		cin >> speed;
		if (speed < 20 || speed > 250 )
		{
			cout << "Enter the Speed again" << endl;
			cout << "> Enter the Speed (Range: 10-250) : ";
			cin >> speed;
		}

		// Coordinates from where the yoyo will start spinning
		COORD pas = {40, 8};
		SetConsoleCursorPosition(screen, pas);
		cout << "OO" << endl;
		Sleep(500);

		for (int tossit = 1; tossit <= throws; tossit++)
		{
			while (pas.Y <= 20)
			{
				SetConsoleCursorPosition(screen, pas);
				cout << "||" << endl;
				pas.Y++;
				SetConsoleCursorPosition(screen, pas);
				cout << "OO" << endl;
				Sleep(speed);
			}
			while (pas.Y > 8)
			{
				SetConsoleCursorPosition(screen, pas);
				cout << "  " << endl;
				pas.Y--;
				SetConsoleCursorPosition(screen, pas);
				cout << "OO" << endl;
				Sleep(speed);
			}
		}

		cout << "> If you want to Spin the Yoyo again press 1." << endl;
		cout << "> If you want to exit the program press 0." << endl;
		cout << "> ";
		cin >> again;
	} while (again != 0);

	SetConsoleTextAttribute(screen, 7);

	return 0;
}