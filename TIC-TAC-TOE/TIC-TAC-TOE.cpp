// TIC-TAC-TOE (Mini Project)
#include<bits/stdc++.h>
// this library is added due to use of different colors and transitions in the game.
#include<windows.h>
using namespace std;


// Function to choose the choice of the user either 'X' or 'O'
void userschoice(char &user1, char &user2)
{
	cin >> user1;
	if (user1 == 'X' || user1 == 'x')
	{
		user1 = 'X';
		user2 = 'O';
	}
	if (user1 == 'O' || user1 == 'o')
	{
		user1 = 'O';
		user2 = 'X';
	}
	return;
}


// This function displays the choice of the users before the start of the game
void printchoice(char user1, char user2)
{
	cout << "Player 1 chose: " << user1 << endl;
	cout << "Player 2 chose: " << user2 << endl;
	return;
}


// Function to show the tic-tac-toe table
void showtable(char a[])
{
	cout << "\t\t\t" << " " << a[0] << " | " << a[1] << " | " << a[2] << endl;
	cout << "\t\t\t" << "___|___|___ " << endl;
	cout << "\t\t\t" << "   |   |    " << endl;
	cout << "\t\t\t" << " " << a[3] << " | " << a[4] << " | " << a[5] << endl;
	cout << "\t\t\t" << "___|___|___ " << endl;
	cout << "\t\t\t" << "   |   |    " << endl;
	cout << "\t\t\t" << " " << a[6] << " | " << a[7] << " | " << a[8] << endl;
	return;
}


// This function is used to check if any player has already marked that place or not
bool placemark(char a[], int x)
{
	if (a[x - 1] == 'X' || a[x - 1] == 'O')
	{
		cout << "This block has been marked" << endl;
		cout << "Try Again!!" << endl;
		return true;
	}
	return false;
}


// This function determines if either any user has won or the game is set drawn
bool checktowin(char a[], char user)
{
	if (a[0] == a[1] && a[1] == a[2] && a[1] == user)
	{
		return true;
	}
	else if (a[0] == a[3] && a[3] == a[6] && a[3] == user)
	{
		return true;
	}
	else if (a[0] == a[4] && a[4] == a[8] && a[4] == user)
	{
		return true;
	}
	else if (a[2] == a[4] && a[4] == a[6] && a[4] == user)
	{
		return true;
	}
	else if (a[2] == a[5] && a[5] == a[8] && a[5] == user)
	{
		return true;
	}
	else if (a[1] == a[4] && a[4] == a[7] && a[4] == user)
	{
		return true;
	}
	else if (a[3] == a[4] && a[4] == a[5] && a[4] == user)
	{
		return true;
	}
	else if (a[6] == a[7] && a[7] == a[8] && a[7] == user)
	{
		return true;
	}
	return false;
}


// This shows the basic information at the start of the game
void introduction(char user1, char user2, char a[])
{
	cout << "\t\t\t\t\t\t\t--------------------------" << endl;
	cout << "\t\t\t\t\t\t\t| Welcome to TIC-TAC-TOE |" << endl;
	cout << "\t\t\t\t\t\t\t--------------------------" << endl;
	cout << endl << endl << endl;
	Sleep(250);
	printchoice(user1, user2);
	cout << endl;
	Sleep(250);
	showtable(a);
	cout << endl;
	return;
}


// main function
int main()
{
	char again = '1';
	do
	{
		system("cls");

		// This command is used to set different colors in the game
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

		char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
		char user1 = ' ', user2 = ' ';
		SetConsoleTextAttribute(screen, 3);

		introduction(user1, user2, a);

		cout << "Enter Player1's choice X or O : ";

		userschoice(user1, user2);
		cout << endl;
		system("cls");

		SetConsoleTextAttribute(screen, 6);
		introduction(user1, user2, a);

		int x = 9;
		while (x > 0)
		{
			x--;
			int l;
			SetConsoleTextAttribute(screen, 6);
			Sleep(300);

			cout << "Enter the number where you want to insert " << user1 << " : ";
			cin >> l;
			if (placemark(a, l))
			{
				cout << "Enter the number where you want to insert " << user1 << " : ";
				cin >> l;
			}
			a[l - 1] = user1;
			system("cls");
			SetConsoleTextAttribute(screen, 6);
			introduction(user1, user2, a);
			if (checktowin(a, user1) == true)
			{
				cout << endl;
				SetConsoleTextAttribute(screen, 14);
				cout << "\t\t\t\t\t\t\t--------------------------" << endl;
				cout << "\t\t\t\t\t\t\t| Player1 won the Game!! |" << endl;
				cout << "\t\t\t\t\t\t\t--------------------------" << endl;
				break;
			}
			if (x <= 0)
			{
				cout << endl;
				SetConsoleTextAttribute(screen, 14);
				cout << "\t\t\t\t\t\t\t------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t| Oops!! Nobody could win the Game |" << endl;
				cout << "\t\t\t\t\t\t\t------------------------------------" << endl;
				break;
			}
			x--;
			Sleep(300);
			SetConsoleTextAttribute(screen, 6);
			cout << "Enter the number where you want to insert " << user2 << " : ";
			cin >> l;
			if (placemark(a, l))
			{
				cout << "Enter the number where you want to insert " << user2 << " : ";
				cin >> l;
			}
			a[l - 1] = user2;
			system("cls");
			SetConsoleTextAttribute(screen, 6);
			introduction(user1, user2, a);
			if (checktowin(a, user2) == true)
			{
				cout << endl;
				SetConsoleTextAttribute(screen, 14);
				cout << "\t\t\t\t\t\t\t--------------------------" << endl;
				cout << "\t\t\t\t\t\t\t| Player2 won the Game!! |" << endl;
				cout << "\t\t\t\t\t\t\t--------------------------" << endl;
				break;
			}
			if (x <= 0)
			{
				cout << endl;
				SetConsoleTextAttribute(screen, 14);
				cout << "\t\t\t\t\t\t\t------------------------------------" << endl;
				cout << "\t\t\t\t\t\t\t| Oops!! Nobody could win the Game |" << endl;
				cout << "\t\t\t\t\t\t\t------------------------------------" << endl;
				break;
			}

		}
		SetConsoleTextAttribute(screen, 6);
		cout << endl << endl;
		cout << "> If you want to exit the Game Press 0" << endl;
		cout << "> If you want to play another Game Press any Alphanumeric Key" << endl;
		cout << "> ";
		cin >> again;
		cin.get();
		SetConsoleTextAttribute(screen, 7);
	} while (again != '0');

	return 0;
}