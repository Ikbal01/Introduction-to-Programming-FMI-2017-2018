/**
*
* Solution to second homework task
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
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(vector<char> text);
int getElementIndex(vector<char> searchedVector, vector<vector<char>> element);
bool contains(vector<vector<char>> vec, vector<char> elem);
void printResult(vector<vector<char>> palindromes, vector<int> palindromeCounts);
int getLength(char *arr);
vector<char> convert(char *text);

int main()
{
	char text[50];
	cin.get(text, 50);

	vector<char> input = convert(text);

	vector<vector<char>> palindromes;
	vector<int> palindromeCounts; // Occurrences of all found palindromes.

	for (int i = 0; i < input.size(); i++)
	{
		vector<char> currentWord;
		for (int j = i; j < input.size(); j++)
		{
			currentWord.push_back(input[j]);

			// If word is a palindrome
			if (currentWord.size() > 1 && isPalindrome(currentWord))
			{
				// If palindrome has not been previously encountered, add it
				if (!contains(palindromes, currentWord))
				{
					palindromes.push_back(currentWord);
					palindromeCounts.push_back(1);
				}
				else // If already there, increment counter.
				{
					int pos = getElementIndex(currentWord, palindromes);
					palindromeCounts[pos]++;
				}
			}
		}
	}

	printResult(palindromes, palindromeCounts);

	return 0;
}

/**
* Converts a plain char array to a STL Vector.
* @param text the array to be converted
* @return the converted array
*/
vector<char> convert(char *text)
{
	vector<char> textVector;

	for (int i = 0; i < getLength(text); i++)
	{
		textVector.push_back(text[i]);
	}
	return textVector;
}

/**
* Checks if a text is a palindrome.
* @param text the text to be checked.
* @return true if the text is a palindrome, false otherwise.
*/
bool isPalindrome(vector<char> text)
{
	for (int i = 0; i < text.size() / 2; i++)
	{
		if (text[i] != text[text.size() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

/**
* Checks if a char vector contains a specified element.
* @param vec the vector to be searched
* @param elem the element to be checked
* @return true if the element exists, false otherwise
*/
bool contains(vector<vector<char>> vec, vector<char> elem)
{
	return find(vec.begin(), vec.end(), elem) != vec.end();
}

/**
* Gets the index of an element in a char vector.
* @param searchedVector the vector to be searched
* @param element the element to be checked.
* @return the index of the first occurrence of the element, -1 otherwise.
*/
int getElementIndex(vector<char> searchedVector, vector<vector<char>> element)
{
	int pos = find(element.begin(), element.end(), searchedVector) - element.begin();
	return pos;
}

/**
* Prints the result in the format specified in the coursework spec.
* @param palindromes the array of palindromes.
* @param palindromeCounts the palindrome counts
*/
void printResult(vector<vector<char>> palindromes, vector<int> palindromeCounts)
{
	for (int i = 0; i < palindromes.size(); i++)
	{
		for (char j : palindromes[i])
		{
			cout << j;
		}
		cout << " - " << palindromeCounts[i] << endl;
	}
}

/**
* Gets the length of the null-terminated char array.
* @param arr the null-terminated char array.
* @return the length of the array
*/
int getLength(char *arr)
{
	char *s;
	for (s = arr; *s; ++s) {}
	return (int)(s - arr);
}
