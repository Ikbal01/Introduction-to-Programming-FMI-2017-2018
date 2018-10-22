/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ikbal Ramadanov Rasimov
* @idnumber 62168
* @task 6
* @compiler VC
*
*/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int getUserInput(int lowerBound, int upperBound);



int main()
{
	char symbol; // The symbol used for the ASCII art.
	cout << "Enter symbol: ";
	cin >> symbol;

	int height = getUserInput(1, 25);

	cout << setw(height + 2) << symbol << endl; // Put the top character.
	for (int i = 0; i < height - 1; ++i)
	{
		cout << setw(height + 1 - i); // Set padding before first character.
		cout << symbol;
		for (int j = 0; j < i; ++j)
		{
			cout << " " << symbol; // Set padding between characters.
		}

		cout << " " << symbol << endl;
	}
}

/**
* Gets an integer from the user in the specified range
* @param lowerBound lowest possible value of integer
* @param upperBound highest possible value of integer
* @return user input
*/
int getUserInput(int lowerBound, int upperBound)
{
	int number = 0;
	while (true)
	{
		cout << "Enter a positive integer in the range " << lowerBound << " - " << upperBound << "." << endl;

		if (cin >> number && number >= lowerBound && number <= upperBound)
		{
			break;
		}
		else
		{
			cout << "Not a valid input. Try again, please!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return number;
}