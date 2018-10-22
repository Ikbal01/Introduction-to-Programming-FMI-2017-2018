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

/**
* Executes the following 3 steps:
* 1. Fill the M jug if it's empty.
* 2. Pour from M to N jug until one of them is empty or full.
* 3. Empty the N jug if it's full.
*
* @param mCurrent current amount of water in the M jug
* @param nCurrent current amount of water in the N jug
* @param mCapacity maximum water capacity of the M jug
* @param nCapacity maximum water capacity of the N jug
* @param requiredAmount the goal amount of water to be present in one of the jugs.
* @param numSteps the current number of steps taken
* @return the total number of steps taken to reach the goal amount of water.
*/
int repeat(int mCurrent, int nCurrent, int mCapacity, int nCapacity, int requiredAmount, int numSteps)
{

	// Step 1: Fill the M jug if it's empty.
	if (mCurrent == 0)
	{
		mCurrent = mCapacity;
		numSteps++; // Increase the number of steps taken.
	}

	// Step 2: Pour from the M jug into the N jug until one of them is either full or empty.
	int mPrev = mCurrent;
	mCurrent -= nCapacity - nCurrent;
	if (mCurrent < 0) { mCurrent = 0; }
	nCurrent += mPrev;
	if (nCurrent > nCapacity) { nCurrent = nCapacity; }
	numSteps++; // Increase the number of steps taken.

	// Breaks out of recursion when the goal capacity is reached.
	if (mCurrent == requiredAmount || nCurrent == requiredAmount) { return numSteps; }

	// Breaks if it detects an infinite loop.
	if (numSteps > mCapacity*nCapacity*requiredAmount) { return -1; }

	// Step 3: Empty the N jug if it's full.
	if (nCurrent == nCapacity)
	{
		nCurrent = 0;
		numSteps++; // Increase the number of steps taken.
	}

	// Recursively repeat the same algorithm while passing as arguments all the values that need to be remembered.
	repeat(mCurrent, nCurrent, mCapacity, nCapacity, requiredAmount, numSteps);

}

/**
* Solves the water jug problem (task 2), as described in the spec.
* @param mCapacity the maximum capacity of the M jug
* @param nCapacity the maximum capacity of the N jug
* @param requiredAmount the goal amount of water to be reached
* @return the steps taken for the goal to be reached
*/
int solve(int mCapacity, int nCapacity, int requiredAmount)
{
	// Handle corner cases.
	if (requiredAmount == mCapacity || requiredAmount == nCapacity || requiredAmount == 0) { return 1; }

	// Solve.
	repeat(0, 0, mCapacity, nCapacity, requiredAmount, 0);
}

/**
* Gets an integer from the user in the specified range
* @param lowerBound lowest possible value of integer
* @param upperBound highest possible value of integer
* @return user input
*/
int getUserInput(int lowerBound, int upperBound, char sym)
{
	int number = 0;
	while (true)
	{
		cout << "Enter the maximum capacity of the " << sym << " jug in the range " << lowerBound << " - " << upperBound << "." << endl;

		if (cin >> number && number >= lowerBound && number <= upperBound) { break; }
		else
		{
			cout << "Not a valid input. Try again, please!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return number;
}

int main()
{
	int mCapacity = 0;
	int nCapacity = 0;
	int requiredWaterAmount = 0;

	mCapacity = getUserInput(1, 20, 'M');
	nCapacity = getUserInput(1, 20, 'N');
	cout << "Enter the goal capacity." << endl;
	cin >> requiredWaterAmount;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "The number of steps taken is " << solve(mCapacity, nCapacity, requiredWaterAmount) << endl;

	return 0;
}
