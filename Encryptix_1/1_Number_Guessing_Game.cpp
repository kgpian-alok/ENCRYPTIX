/*
TASK 1
NUMBER GUESSING GAME
Create a program that generates a random number and asks the user to guess it. Provide
feedback on whether the guess is too high or too low until the user guesses the correct number
*/
#include <iostream>
#include <cstdlib> //header file for rand()
#include <time.h> //header file for time(0) inside srand to avoid same random number generation
using namespace std;
//Below function for number guessing
void numberGuessingGame(double randNumber)
{
    double number;//number variable for input taken by user
    int trial=0;//to count number of trial
    while (true)
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
            cout<<"Number guessed is larger. Hence, Guess lower number\n\n";
        }
        else
        {
            cout<<"Number guessed is smaller. Hence, Guess higher number\n\n";
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
        double randNumber = rand();//random number generator
        numberGuessingGame(randNumber);
        cout << "\n\nDo you want to play the GAME again?\nEnter 1: YES\nEnter 0: NO\n";
        cin >> check;
    }
    return 0;
}
