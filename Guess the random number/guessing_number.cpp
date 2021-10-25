#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<array>

using namespace std;

void printArray(std::array<int, 251> &vector, int sizecount){
    for(int i = 0; i<sizecount ; i++){
        std::cout<<vector[i]<<"\t";
    }
    cout<<"\n";
}

void playGame(){
    std::array <int,251> guessArray;
    int count = 0;
    cout<<"Game is being played"<<endl;
    int random = rand() % 251;
    cout<<random<<endl;

    while (true)
    {
        int guess;
        
        cout<<"Guess a number";
        cin>>guess;
        guessArray[count++] = guess;
        if( guess == random){
            cout<<"You Win"<<"\n";
            break;
        }
        else if (guess > random)
        {
            cout<<"guess is greater"<<"\n";
        }
        else{
            cout<<"guess is low"<<"\n";
        }
        
    }
    printArray(guessArray, count);
}

int main(){
    srand(time(NULL));
    int choice;

    do{
        scout<<"1. Quit"<< endl <<"2. Play"<<endl;
        cin>> choice;

        switch(choice){
            case 1:
            cout<<"Thanks for playing"<<endl;
            return 0;

            case 2:
            cout<<"Let's Play"<<endl;
            playGame();
            break;
        }
    }
    while(choice != 1);
}
