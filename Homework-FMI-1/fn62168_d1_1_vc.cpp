/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ikbal Ramadanov Rasimov
* @idnumber 62168
* @task 1
* @compiler VC
*
*/

#include <iostream>

using namespace std;

void increasing(int previousNumber, int currentNumber);
void decreasing(int previousNumber, int currentNumber);
int getUserInput();

int main()
{
	int previousNumber = getUserInput();
	if (previousNumber <= 0) // If first number is smaller than 0, then the sequence is neither growing, nor decreasing - it's undefined. 
	{
		cout << "The sequence is undefined." << endl;
		return 0;
	}
	int currentNumber = getUserInput();
	if (currentNumber <= 0) // If second number is smaller than 0, then the sequence has only one element, that makes it undefined.
	{
		cout << "The sequence is undefined." << endl;
		return 0;
	}

	if (previousNumber < currentNumber) 
	{
		increasing(previousNumber, currentNumber); // Checks if the sequence is growing or undefined.
	}
	else if (previousNumber > currentNumber)
	{
		decreasing(previousNumber, currentNumber); // Checks if the sequence is decreasing or undefined.
	}
	else
	{
		cout << "The sequence is undefined." << endl; // If the first two numbers are equal, the sequence is undefined.
	}

	return 0;
}

/**
* Accepts input for an increasing row.
* @param previousNumber the first user input
* @param currentNumber the second user input
*/
void increasing(int previousNumber, int currentNumber)
{
	while (previousNumber < currentNumber)
	{
		previousNumber = currentNumber;
		currentNumber = getUserInput();

		if (currentNumber <= 0)
		{
			cout << "The sequence is increasing." << endl;
			return;
		}
	}
	cout << "The sequence is undefined." << endl;
}

/**
* Accepts user input for a decreasing row.
* @param previousNumber first user input
* @param currentNumber second user input
*/
void decreasing(int previousNumber, int currentNumber)
{
	while (previousNumber > currentNumber)
	{
		previousNumber = currentNumber;
		currentNumber = getUserInput();

		if (currentNumber <= 0)
		{
			cout << "The sequence is decreasing." << endl;
			return;
		}
	}

	cout << "The sequence is undefined." << endl;
}

/**
* Checks for integer overflow.
*/
int getUserInput()
{
	int number = 0;
	while (true)
	{
		cout << "Enter an integer: ";
		if (cin >> number)
		{
			break;
		}
		else
		{
			cout << "Not a valid integer!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return number;
}
