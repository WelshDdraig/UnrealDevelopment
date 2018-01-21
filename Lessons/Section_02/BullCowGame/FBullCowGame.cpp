#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const 
{ 
	if (false) //if guess is not isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) //if guess != lowercase
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (guess.length() != GetHiddenWordLength()) //if guess length = wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}	

void FBullCowGame::Reset()
{
	constexpr int maxGuesses = 8;
	const FString hiddenWord = "planet";

	MyMaxTries = maxGuesses;
	MyHiddenWord = hiddenWord;
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

//recieves a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assuming the same length as guess

	//loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{	
		//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			//if they match
			if (guess[GChar] == MyHiddenWord[MHWChar])
			{					
				if (MHWChar == GChar) //Increment if they're in the same place
				{
					BullCowCount.Bulls++; //increment Bulls
				}
				else
				{
					BullCowCount.Cows++; //Increment Cows
				}
			}
		}
	}

	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}

	else
	{
		false;
	}

	return BullCowCount;

}
