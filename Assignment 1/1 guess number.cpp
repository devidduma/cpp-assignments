#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

bool playGame() {

    srand(time(0));
    int randNumber = 1 + rand()%1000;
    
    cout<<"I have a number between 1 and 1000.\n"
        <<"Can you guess my number?\n"
        <<"Please type your fist guess. ";
    
    int guess;
    cin>>guess;

    while(guess != randNumber) {
        if(guess > randNumber)
            cout<<"Too high. Try again. ";
        else
            cout<<"Too low. Try again. ";
        cin>>guess;
    }
    cout<<"Excellent! You guessed the number!\n";

    cout<<"Would you like to play again (y or n)? ";
    char choice = char(0);  //important to initialize it, otherwise undefined bevahiour occurs
    while(!(choice == 'n' || choice == 'y')) {
        cin>>choice;
    }
    
    cout<<endl;
    
    if(choice == 'y')
        return true;
    else
        return false;
}

int main() {
    bool play = true;

    while(play){
        play = playGame();
    }
    
    return 0;
}
