/*
	This is the Console Executable, that makes use of the BullCow Class.
	This acts as the view ion a MVC pattern, and is responsible for all user interaction.

	For Game logic - see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //Instantiate a new game

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

//Introduction to the Game
void PrintIntro()
{	
	std::cout << "\nWelcome to Bulls and Cows - A basic word game :)\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " Letter isogram I'm thinking of?\n\n";
	return;
}

//Start the Game
void PlayGame()
{
	BCGame.Reset();
	int32 maxTries = BCGame.GetMaxTries();

	//Loop for amount of guesses while game is NOT won and while there are tries remaining
	while(!BCGame.isGameWon() && BCGame.GetCurrentTry() <= maxTries)
	{
		FText guess = GetValidGuess(); 

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(guess); //submit valid guess to the game, and recieve Counts
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	//TODO add a game summary
}


//Loop until player provides a valid guess
FText GetValidGuess()
{
	FText guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do {
		//Get guess from a player
		int32 currentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << currentTry << ". Please enter your guess: \n";
		std::getline(std::cin, guess);

		//Check Status and produce feedback
		Status = BCGame.CheckGuessValidity(guess);
		switch (Status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters";
			break;
		default:
			//assume the guess is valid
			break;
		}

		std::cout << std::endl;

	} while (Status != EGuessStatus::OK); //Keep looping until no errors are produced
	return guess;
}

//Ask to play the game again
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (Y/N)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'Y') || (Response[0] == 'y');
}
