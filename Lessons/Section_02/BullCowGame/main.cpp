#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

//Main Application Code
int main()
{
	bool bPlayAgain = false;

	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0; // Quit Application

}

///Introduction to the Game
void PrintIntro()
{	
	constexpr int wordLength = 9;

	std::cout << "Welcome to Bulls and Cows - A basic word game :)\n";
	std::cout << "Can you guess the " << wordLength << " Letter isogram I'm thinking of?\n\n";
	return;
}

///Start the Game
void PlayGame()
{
	//Loop for amount of guesses
	constexpr int turnLimit = 5;
	for (int count = 1; count <= turnLimit; count++)
	{
		std::string guess = GetGuess();
		std::cout << "Your guess was: " << guess << std::endl;
		std::cout << std::endl;
	}
}

///Get guess from a player
std::string GetGuess()
{	
	std::cout << "Please enter your guess:\n";
	std::string guess = "";
	std::getline(std::cin, guess);
	return guess;
}

///Ask to play the game again
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (Y/N)";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'Y') || (Response[0] == 'y');
}
