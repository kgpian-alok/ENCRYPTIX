/*
TASK 2
CALCULATOR
Develop a calculator program that performs basic arithmetic operations such as addition, subtraction,
multiplication, and division. Allow the user to input two numbers and choose an operation to perform.
*/
#include <iostream>
using namespace std;
void calculator()
{
    double x, y, value;
    bool flag = true;
    char operation;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    cout << "Enter the operation: ";
    cin >> operation;
    switch (operation)
    {
    case '+':
        value = x + y;
        break;
    case '-':
        value = x - y;
        break;
    case '*':
        value = x * y;
        break;
    case '/':
        value = x / y;
        break;
    default:
        flag = false;
        break;
    }
    if (flag)
        cout << "\nHence, (" << x << ") " << operation << " (" << y << ") = " << value;
    else
        cout << "----------INVALID OPERATION----------";
}
int main()
{
    int check = 1;
    cout<<"\n--------------------WELCOME TO YOUR CALCULATOR--------------------\n\n";
    do
    {
        calculator();
        cout << "\n\nDo you want to use calculator again?\nEnter 1: YES\nEnter 2: NO\n";
        cin >> check;
    } while (check==1);
    cout << "--------------------THANKS FOR USING CALCULATOR--------------------";
    return 0;
}