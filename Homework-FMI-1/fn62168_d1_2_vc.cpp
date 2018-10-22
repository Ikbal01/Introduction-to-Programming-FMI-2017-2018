/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ikbal Ramadanov Rasimov
* @idnumber 62168
* @task 2
* @compiler VC
*
*/


#include <iostream>
#include <limits>

using namespace std;

int reverseInteger(int number);
int getUserInput();

int main()
{
	cout << hex << uppercase << reverseInteger(getUserInput()) << endl;
}

/**
 * Gets a positive integer from user input.
 */
int getUserInput()
{
	int number = 0;
	while (true)
	{
		cout << "Enter a positive integer: ";
		if (cin >> number && number > 0)
		{
			break;
		}
		else
		{
			cout << "Not a valid positive integer!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return number;
}

/**
 * Gets the number in reverse.
 * @param number the given number
 * @return the reversed number
 */
int reverseInteger(int number)
{
	int reversed = 0;
	while (number != 0)
	{
		reversed *= 10;
		reversed += number % 10;
		number /= 10;
	}
	return reversed;
}
