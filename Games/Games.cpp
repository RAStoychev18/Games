#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

int menu(char, string, string&); //function

int main()//main function
{
	string name;
	char letter;
	int num = 0;
	string word;
	string words[] =
	{
	"garden",
	"sunflower",
	"floor",
	"item",
	"strawberry",
	"chicken",
	"pointer",
	"paper",
	"butterfly",
	"dictionary"
	}; //the list of the words

	srand(time(NULL));
	int n = rand() % 10;//choose random word from "string words"
	word = words[n]; //"word" appropriates the value of the chosen word
	int tries = n;
	string hidden(word.length(), '?');//the word will appear with ?s


	// welcome the user
	cout << endl << endl << "\t\t\t\t\t\t    HANGMAN FOR KIDS!!!";
	cout << endl << endl << "\t\t\t\t\t\t\tR U L E S";
	cout << endl << endl << "\t\t\t\t\tEach letter is represented by a question mark (?)";
	cout << endl << endl << "\t\t\t\t\tYou have to type only one letter for one try\t";
	cout << endl << endl << "\t\t\t\t\tYou have " << tries << " tries to try and guess the word.\t" << endl;


	while (num < tries) //loop
	{
		cout << endl << endl << hidden;
		cout << endl << endl << "Guess a letter: ";
		cin >> letter;

		if (menu(letter, word, hidden) == 0)
		{
			cout << endl << "Incorrect letter!" << endl;
			num++;
		}
		else
		{
			cout << endl << "You guessed a letter!" << endl;
		}

		cout << "You have " << tries - num << " guesses left." << endl;


		if (word == hidden) // Check if user guessed the word
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if (num == tries) //Check if there are no more tries
	{
		cout << endl << "You lose! You've been hanged" << endl;
		cout << "The word was : " << word << endl;
	}

	return 0;//returning 0
}

int menu(char guess, string secretword, string& guessword)//function
{
	int i;
	int match = 0;
	int length = secretword.length();//"length" appropriates the length of the secret word
	for (i = 0; i < length; i++)//"for" loop
	{

		if (guess == guessword[i]) // did we already match this letter in a previous guess
		{
			return 0;//returning 0
		}
		if (guess == secretword[i])// is the guess in the secret word
		{
			guessword[i] = guess;
			match++;//"match" increases
		}
	}

	return match;//returning match
}