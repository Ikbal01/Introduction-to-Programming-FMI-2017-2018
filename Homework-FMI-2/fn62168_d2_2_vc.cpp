/**
*
* Solution to second homework task
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
#include <vector>
#include <iomanip>

using namespace std;

char punctuationChars[] = { '.', ',', '!', '?', ':', ';', '\'', '\"', '(', ')', '-' };

void printWord(vector<char> word);
void printDashes(int dashesCount);
int getLongestSize(vector<vector<char>> wordList);
vector<vector<char>> splitToWords(char *text);
void solve(char *inputText);
bool IsPunctuationChar(char token);
int getLength(char *arr);


int main()
{
	char inputText[100];
	cin.get(inputText, 100);

	solve(inputText);

	return 0;
}

/**
* Solves the given homework task.
* @param inputText the inputted text
*/
void solve(char *inputText)
{
	vector<vector<char>> words = splitToWords(inputText);

	printDashes(getLongestSize(words) + 2);

	// Prints the result in the specified format.
	for (int i = 0; i < words.size(); i++)
	{
		cout << '|';
		printWord(words[i]);
		cout << setfill(' ') << setw((getLongestSize(words) + 1) - words[i].size()) << '|' << endl;
	}
	printDashes(getLongestSize(words) + 2);
}

/**
* Checks if a character is a punctuation char.
* @param token character to be tested
* @return true if it's a punctuation character, false otherwise.
*/
bool IsPunctuationChar(char token)
{
	for (int i = 0; i < sizeof(punctuationChars); i++)
	{
		if (token == punctuationChars[i])
		{
			return true;
		}
	}
	return false;
}

/**
* Splits a text to an array of words.
* @param text the text to be splitted
* @return the array of all words in the text
*/
vector<vector<char>> splitToWords(char *text)
{
	vector<vector<char>> words;
	vector<char> word;

	for (int i = 0; i < getLength(text); i++)
	{
		if (text[i] != ' ' && text[i] != '\t' && !IsPunctuationChar(text[i]))
		{
			word.push_back(text[i]);
			if (i == getLength(text) - 1)
			{
				words.push_back(word);
			}
		}
		else if (!word.empty())
		{
			words.push_back(word);
			word.clear();
		}
	}
	return words;
}

/**
* Gets the length of the longest word from an array of words.
* @param wordList the vector (array) of words to be searched.
* @return the length of the longest word
*/
int getLongestSize(vector<vector<char>> wordList)
{
	int LongestWordsSize = 0;
	for (int i = 0; i < wordList.size(); i++)
	{
		if (LongestWordsSize < wordList[i].size())
		{
			LongestWordsSize = wordList[i].size();
		}
	}
	return LongestWordsSize;
}

/**
* Prints a given number of dashes.
* @param dashesCount The number of dashes to be printed.
*/
void printDashes(int dashesCount)
{
	cout << setfill('-') << setw(dashesCount) << '-' << endl;
}

/**
* Prints a word on the screen.
* @param word
*/
void printWord(vector<char> word)
{
	for (int i = 0; i < word.size(); i++)
	{
		cout << word[i];
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
