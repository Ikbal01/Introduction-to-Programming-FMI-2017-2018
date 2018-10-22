/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ikbal Ramadanov Rasimov
* @idnumber 62168
* @task 4
* @compiler VC
*
*/

#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int minNumber = INT_MAX;

	int number;
	cin >> number;

	while (number > 0) // While the number is bigger than 0, keep getting input.
	{
		minNumber = (number < minNumber) ? number : minNumber; // Store the minimum number.
		cin >> number; // Get the next number.
	}

	cout << minNumber << endl;

	return 0;
}