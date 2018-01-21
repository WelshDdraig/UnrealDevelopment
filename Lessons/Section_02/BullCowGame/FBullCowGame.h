#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset(); //TODO - Make a more rich return Value
	int GetMaxTries();
	int GetCurrentTry();
	bool isGameWon();
	bool CheckGuessValidity(std::string); //TODO - Make a more rich return Value
	

private:
	int MyCurrentTry;
	int MyMaxTries;
};