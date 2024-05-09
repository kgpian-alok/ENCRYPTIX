/*
TASK 1
NUMBER GUESSING GAME
Create a program that generates a random number and asks the user to guess it. Provide
feedback on whether the guess is too high or too low until the user guesses the correct number
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
void numberGuessingGame(double randNumber = 0)
{
    double number;
    int trial=0;
    while (1)
    {
        cout << "Enter the number to guess: ";
        cin >> number;
        trial++;
        if(number==randNumber)
        {
            cout<<"\nYou Won after "<<trial<<" trials !!\n";
            break;
        }
        else if (number>randNumber)
        {
            cout<<"\nNumber guessed is larger. Hence, Guess lower number\n";
        }
        else
        {
            cout<<"\nNumber guessed is smaller. Hence, Guess higher number\n";
        }
    }
    cout<<"\nThanks for playing the game\n";
}
int main()
{
    cout << "\n----------WELCOME TO THE NUMBER GUESSING GAME----------\n";
    srand(time(0));
    int check = 1;
    while (check)
    {
        double randNumber = rand();
        numberGuessingGame(randNumber);
        cout << "\n\nDo you want to play the GAME again?\nEnter 1: YES\nEnter 0: NO\n";
        cin >> check;
    }
    return 0;
}
