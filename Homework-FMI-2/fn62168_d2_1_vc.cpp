/**
*
* Solution to second homework task
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
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

char* baseOfWords[] = { "student", "refrigerator", "flower", "neighbourhood", "negative", "telephone", "upwards", "declare", "criminal", "teenager", "supermarket", "speaker", "statement", "crocodile", "crossroads", "communication", "dominoes", "interpretation", "overflow", "sentence", "stomach", "celebration", "intelligence", "interpretation", "sightseeing", "strawberry", "uncomfortable", "experience", "geography", "housekeeper" };

vector<char> getRandomWord();
vector<char> underscoreToLetter(vector<char> randomWord, vector<char> guessWord, char letter);
vector<char> wordToUnknown(vector<char> word);
bool contains(vector<char> word, char symbol);
int getTotalAttempts();
void printElements(vector<char> vec);
int getLength(char *arr);


int main()
{
	int attemptsCount = getTotalAttempts();
	vector<char> randomWord = getRandomWord();
	vector<char> guessWord = wordToUnknown(randomWord);

	printElements(guessWord);
	cout << endl << "You have " << attemptsCount << " attempts." << endl;

	while (attemptsCount > 0)
	{
		// Get user input.
		char guessLetter;
		cin >> guessLetter;
		guessLetter = (char)(tolower(guessLetter));

		if (contains(randomWord, guessLetter))
		{
			// If letter is already found.
			if (contains(guessWord, guessLetter))
			{
				cout << "The letter is already found!" << endl;
				printElements(guessWord);
				cout << endl << "Attempts left: " << attemptsCount << endl << endl;
				continue;
			}
			guessWord = underscoreToLetter(randomWord, guessWord, guessLetter);

			// If the word is found.
			if (randomWord == guessWord)
			{
				cout << "Congratulations, you win! The word is \"";
				printElements(guessWord);
				cout << "\"." << endl;
				return 0;
			}
			cout << "Success!" << endl;
			printElements(guessWord);
			cout << endl << "Attempts left: " << attemptsCount << endl << endl;
		}
		else // If letter is wrong.
		{
			cout << "Error!" << endl;
			printElements(guessWord);
			cout << endl;
			if (attemptsCount == 1)
			{
				cout << "Attempts left: 0\n" << "You Lost!" << endl;
				return 0;
			}
			cout << "Attempts left: " << --attemptsCount << endl << endl;
		}
	}
	return 0;
}

/**
* Gets a random word
* @return the random word
*/
vector<char> getRandomWord()
{
	srand((unsigned int)time(0));
	int randomNumber = (rand() % 30);

	vector<char> randomWord;
	for (int i = 0; i < getLength(baseOfWords[randomNumber]); i++)
	{
		randomWord.push_back(baseOfWords[randomNumber][i]);
	}
	return randomWord;
}

/**
* Reveals a letter from a given word.
* @param randomWord the given word
* @param guessWord the word with hidden letters
* @param letter the letter to reveal
* @return returns the new word
*/
vector<char> underscoreToLetter(vector<char> randomWord, vector<char> guessWord, char letter)
{
	for (int i = 1; i < guessWord.size(); i++)
	{
		if (randomWord[i] == letter)
		{
			guessWord[i] = letter;
		}
	}
	return guessWord;
}

/**
* Adds underscores to unknown letters in a word.
* @param word the word to transform
* @return the transformed word
*/
vector<char> wordToUnknown(vector<char> word)
{
	char underscore = '_';

	for (int i = 1; i < word.size() - 1; i++)
	{
		if (word[i] != word[0] && word[i] != word[word.size() - 1])
		{
			word[i] = underscore;
		}
	}
	return word;
}

/**
* Checks if a word contains a symbol.
* @param word the word to be checked
* @param symbol the contained symbol
* @return true if the symbol exists, false otherwise
*/
bool contains(vector<char> word, char symbol)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == symbol)
		{
			return true;
		}
	}
	return false;
}

/**
* Gets user input and returns the total attempts.
* @return the total attempts the user has based on the chosen difficulty.
*/
int getTotalAttempts()
{
	cout << "Difficulty modes: (0)easy = 15 attempts, (1)normal = 10 attempts, (2)hard = 6 attempts, (3)very hard = 3 attempts" << endl;
	cout << "Please type the difficulty : (0-3)" << endl;

	int difficulty;
	cin >> difficulty;
	int attempts;

	if (difficulty == 0) { attempts = 15; }
	else if (difficulty == 1) { attempts = 10; }
	else if (difficulty == 2) { attempts = 6; }
	else if (difficulty == 3) { attempts = 3; }
	else
	{
		cout << "There is no such difficulty!" << endl;
		attempts = 0;
	}
	return attempts;
}

/**
* Prints all elements of a word.
* @param vec the word as a vector of characters.
*/
void printElements(vector<char> vec)
{
	for (char i : vec)
	{
		cout << i;
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