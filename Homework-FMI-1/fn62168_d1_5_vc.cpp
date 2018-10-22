/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ikbal Ramadanov Rasimov
* @idnumber 62168
* @task 5
* @compiler VC
*
*/

#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

unsigned int SwapFirstAndLastDigits(unsigned int inputNumber);

int main()
{
	unsigned int inputNumber;

	cout << "Enter the number to be swapped: ";
	if (!(cin >> inputNumber)) // Checks for correct input
	{
		cout << "Not a valid input. Program terminated." << endl;
		return 0;
	}

	cout << "Swapped number is: " << SwapFirstAndLastDigits(inputNumber) << endl;

	return 0;
}
/**
 * Swaps first and last digit of a number.
 *@param inputNumber the number that is to be swapped
 *@return the swapped number
 */
unsigned int SwapFirstAndLastDigits(unsigned int inputNumber)
{
	int digitsCount = (int)log10(inputNumber) + 1; // Count of digits of the input number.

	int firstDigit = inputNumber % 10;

	int lastDigit = inputNumber / (int)pow(10, digitsCount - 1); // Get the last digit.

	unsigned int numberBody = (inputNumber - (lastDigit * (int)pow(10, digitsCount - 1))) / 10; // numberBody is the number without the first and last digit.

	unsigned int swappedNumber = firstDigit * (int)pow(10, digitsCount - 1) + (numberBody * 10 + lastDigit);

	return swappedNumber;
}