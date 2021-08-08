// TIC-TAC-TOE (Mini Project)
#include<bits/stdc++.h>
// this library is added due to use of different colors and transitions in the game.
#include<windows.h>
using namespace std;

// Function to choose the choice of the user either 'X' or 'O'
void userschoice(char &user1,char &user2)
{
	cin>>user1;
	if(user1=='X')
	{
		user2 = 'O';
	}
	else
	{
		user2 = 'X';
	}
}

// This function displays the choice of the users before the start of the game
void printchoice(char user1,char user2)
{
	cout<<"Player 1 chose: "<<user1<<endl;
	cout<<"Player 2 chose: "<<user2<<endl;
}

// Function to show the tic-tac-toe table
void showtable(char a[])
{
	cout<<"\t\t\t"<<" "<<a[0]<<" | "<<a[1]<<" | "<<a[2]<<endl;
	cout<<"\t\t\t"<<"___|___|___ "<<endl;
	cout<<"\t\t\t"<<"   |   |    "<<endl;
	cout<<"\t\t\t"<<" "<<a[3]<<" | "<<a[4]<<" | "<<a[5]<<endl;
	cout<<"\t\t\t"<<"___|___|___ "<<endl;
	cout<<"\t\t\t"<<"   |   |    "<<endl;
	cout<<"\t\t\t"<<" "<<a[6]<<" | "<<a[7]<<" | "<<a[8]<<endl;
}

// This function determines if either any user has won or the game is set drawn
bool checktowin(char a[],char user)
{
	if(a[0]==a[1] && a[1]==a[2] && a[1]==user)
	{
		return true;
	}
	else if(a[0]==a[3]&& a[3]==a[6] && a[3]==user)
	{
		return true;
	}
	else if(a[0]==a[4] && a[4]==a[8] && a[4]==user)
	{
		return true;
	}
	else if(a[2]==a[4] && a[4]==a[6] && a[4]==user)
	{
		return true;
	}
	else if(a[2]==a[5] && a[5]==a[8] && a[5]==user)
	{
		return true;
	}
	else if(a[1]==a[4] && a[4]==a[7] && a[4]==user)
	{
		return true;
	}
	else if(a[3]==a[4] && a[4]==a[5] && a[4]==user)
	{
		return true;
	}
	else if(a[6]==a[7] && a[7]==a[8] && a[7]==user)
	{
		return true;
	}
	return false;
}

// This shows the basic information at the start of the game
void introduction(char user1,char user2,char a[])
{
	cout<<"\t\t\t\t\t\t\tWelcome to TIC-TAC-TOE"<<endl<<endl<<endl;
	cout<<endl;
	Sleep(400);
	printchoice(user1,user2);
	cout<<endl;
	Sleep(400);
	showtable(a);
	cout<<endl;
}

// main function
int main()
{
	system("cls");
	// This command is used to set different colors in the game
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	char a[9] = {'1','2','3','4','5','6','7','8','9'};
	char user1=' ',user2=' ';
	SetConsoleTextAttribute(screen,4);

	introduction(user1,user2,a);

	cout<<"Enter player1's choice X or O : ";

	userschoice(user1,user2);
	cout<<endl;
	system("cls");

	SetConsoleTextAttribute(screen,6);
	introduction(user1,user2,a);

	int x=9;
	while(x>0)
	{
		x--;
		int l;
		SetConsoleTextAttribute(screen,10);
		Sleep(500);

		cout<<"Enter the number where you want to insert "<<user1<<" : ";
		cin>>l;
		a[l-1]=user1;
		system("cls");
		SetConsoleTextAttribute(screen,6);
		introduction(user1,user2,a);
		if(checktowin(a,user1)==true)
		{
			cout<<endl;
			SetConsoleTextAttribute(screen,14);
			cout<<"\t\t\t\t\t\t\tPlayer1 won the game!!"<<endl;
			break;
		}
		if(x<=0)
		{
			cout<<endl;
			SetConsoleTextAttribute(screen,14);
			cout<<"\t\t\t\t\t\t\tOops!! Nobody could win the game"<<endl;
			break;
		}
		x--;
		Sleep(500);
		SetConsoleTextAttribute(screen,10);
		cout<<"Enter the number where you want to insert "<<user2<<" : ";
		cin>>l;
		a[l-1]=user2;
		system("cls");
		SetConsoleTextAttribute(screen,6);
		introduction(user1,user2,a);
		if(checktowin(a,user2)==true)
		{
			cout<<endl;
			SetConsoleTextAttribute(screen,14);
			cout<<"\t\t\t\t\t\t\tPlayer2 won the game!!"<<endl;
			break;
		}
		if(x<=0)
		{
			cout<<endl;
			SetConsoleTextAttribute(screen,14);
			cout<<"Oops!! Nobody could win the game"<<endl;
			break;
		}
		
	}
	// cin.get() is added here as after the above loop ends the program will close automatically. 
	// So, cin.get() prevents the direct shutdown of the program.
	cin.get();
	cin.get();
	SetConsoleTextAttribute(screen,7);
	return 0;
}