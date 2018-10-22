/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ikbal Ramadanov Rasimov
* @idnumber 62168
* @task 3
* @compiler VC
*
*/

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int getNumberOfReps(int digit, long long number);
int findMaxRepeatedDigit(long long inputNumber);
void printResult(int maxRepeatCount, long long inputNumber);

int main()
{
	long long inputNumber;
	cin >> inputNumber;

	// Checks if input is in the specified range.
	if (inputNumber > pow(2, 32) || inputNumber < -pow(2, 32))
	{
		cout << -1 << endl;
		return 0;
	}
	else if (inputNumber < 0)
	{
		inputNumber *= (-1);
	}

	int maxRepDigitCount = findMaxRepeatedDigit(inputNumber);
	printResult(maxRepDigitCount, inputNumber);

	return 0;
}

/**
* Finds the number of repetitions of the most repeated digit in a number.
* @param inputNumber the number to be tested.
* @return the number of repetitions of the most repeated digit in a number
*/
int findMaxRepeatedDigit(long long inputNumber)
{
	int maxRepeatedDigitCount = 0;

	for (int i = 0; inputNumber > 0; i++)
	{
		int digit = inputNumber % 10;
		int numberOfDigitReps = getNumberOfReps(digit, inputNumber);
		if (numberOfDigitReps > maxRepeatedDigitCount)
		{
			maxRepeatedDigitCount = numberOfDigitReps;
		}
		inputNumber /= 10;
	}
	return maxRepeatedDigitCount;
}

/**
* Prints the result in the format specified in the coursework spec.
* @param maxRepeatedDigitCount the most repeated digit
* @param inputNumber the number
*/
void printResult(int maxRepeatedDigitCount, long long inputNumber)
{
	for (int i = 0; inputNumber > 0; i++)
	{
		int digit = inputNumber % 10;
		int numberOfDigitReps = getNumberOfReps(digit, inputNumber);
		if (numberOfDigitReps == maxRepeatedDigitCount)
		{
			cout << digit << " -> " << numberOfDigitReps << endl;
		}
		inputNumber /= 10;
	}
}

/**
* Gets the number of repetitions of a digit in a given number.
* @param digit the digit that is going to be counted for occurrences.
* @param number the number
* @return the number of repetitions of a given digit
*/
int getNumberOfReps(int digit, long long number)
{
	int count = 0;

	for (int i = 0; number > 0; i++)
	{
		int remainder = number % 10;
		if (remainder == digit)
		{
			count++;
		}
		number /= 10;
	}
	return count;
}