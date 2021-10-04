#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<array>

void printArray(std::array<int, 251> &vector, int sizecount){
    for(int i = 0; i<sizecount ; i++){
        std::cout<<vector[i]<<"\t";
    }
    std::cout<<"\n";
}

void playGame(){
    std::array <int,251> guessArray;
    int count = 0;
    std::cout<<"Game is being played"<<std::endl;
    int random = rand() % 251;
    std::cout<<random<<std::endl;

    while (true)
    {
        int guess;
        
        std::cout<<"Guess a number";
        std::cin>>guess;
        guessArray[count++] = guess;
        if( guess == random){
            std::cout<<"You Win"<<"\n";
            break;
        }
        else if (guess > random)
        {
            std::cout<<"guess is greater"<<"\n";
        }
        else{
            std::cout<<"guess is low"<<"\n";
        }
        
    }
    printArray(guessArray, count);
}

int main(){
    srand(time(NULL));
    int choice;

    do{
        std::cout<<"1. Quit"<< std::endl <<"2. Play"<< std::endl;
        std::cin>> choice;

        switch(choice){
            case 1:
            std::cout<<"Thanks for playing"<< std::endl;
            return 0;

            case 2:
            std::cout<<"Let's Play"<< std::endl;
            playGame();
            break;
        }
    }
    while(choice != 1);
}
