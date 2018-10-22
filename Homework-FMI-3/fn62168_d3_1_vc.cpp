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
#include <string>

using namespace std;

/**
* Checks if parentheses within a string are balanced.
* @param str the string to be checked.
* @param i the index of the char currently being checked.
* @param counter this works as a stack that keeps track of brackets that are to be closed.
* @return true if balanced, false otherwise.
*/
bool isBalanced(string str, int i, int counter)
{
	if (counter == -1) { return false; } // Slight optimisation in order to break out of function earlier.
	if (i == str.size()) // If the whole string is processed
	{
		if (counter == 0) { return true; } // Return true if balanced, false otherwise.
		else return false;
	}

	// Modify the counter and increment the index, then pass the new values as arguments and call function recursively.
	return isBalanced(str, i + 1, str.at(i) == '(' ? counter + 1 : counter - 1);

}

/**
* Removes non-bracket characters from a string.
* @param str the string to be parsed
* @return the string after parsing
*/
string removeNonBracketChars(string str)
{
	string bracketsOnlyStr = "";

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '(' || str.at(i) == ')')
		{
			bracketsOnlyStr.insert(bracketsOnlyStr.end(), str.at(i));
		}
	}
	return bracketsOnlyStr;
}

/**
* Solves task 1 from the homework.
* @param str the string to be solved
* @return true if parentheses are balanced, false otherwise
*/
bool solve(string str)
{
	return isBalanced(removeNonBracketChars(str), 0, 0);
}


int main()
{
	string str;
	cout << "Enter a string to be checked for balanced parentheses." << endl;
	getline(cin, str);
	std::cout << (solve(str) ? "correct" : "incorrect") << std::endl;
	return 0;
}
