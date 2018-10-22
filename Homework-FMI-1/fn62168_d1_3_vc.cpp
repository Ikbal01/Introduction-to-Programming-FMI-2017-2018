/**
*
* Solution to homework task
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
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
	int seconds;
	cout << "Enter seconds: ";
	if (!(cin >> seconds && seconds >= 0 && seconds < 24 * 3600))  // For 24 hours ( 1 hour has 3600 seconds )
	{
		cout << "Not a valid input. Program terminated." << endl;
		return 0;
	}

	int hours = seconds / 3600; // 3600 seconds == 1 hour.
	int minutes = (seconds % 3600) / 60; // The minutes are the remainder divided by 60 seconds.

	cout << "HH:MM from the beginning of the day is: ";
	cout << setw(2);
	cout << setfill('0');
	cout << hours << ':';

	cout << setw(2);
	cout << setfill('0');
	cout << minutes << endl;

	return 0;
}