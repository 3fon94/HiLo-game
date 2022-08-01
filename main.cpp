#include <iostream>
#include <random>													//for random number generator
#include <string>													//for string usage
#include <cstring>
#include <sstream>													//for string to int conversation
#include <cctype>													//for isdigit
using namespace std;

bool checkIfNumber(string enteredNumber)							//check if number entered is number 
{
	for (int i = 0; i <= enteredNumber.length(); i++)
	{
		if (isdigit(enteredNumber[i]))
			return true;
	}
	return false;
}

void main()
{
	system("CLS");											//clears the screen when starting the program again
	random_device rd;												//random number generator
	seed_seq seq{ 1 };												//seed sequence
	mt19937 mt{ rd() };												//merlene twister randomizer
	uniform_int_distribution<> randomNumber(1, 100);				//randomNumber from 1 to 100
	int randomedNumber = static_cast<int>(randomNumber(mt));		//generate and memorize the randomed number
	cout << randomedNumber << endl;									//test purpose

	cout << "Ill think of a number and you have 7 attempts to guess it." << endl;
	int i{};
	for (i = 1; i <= 7; i++)										//7 attempts
	{
		
		input:
		string enteredNumber{};										//entereing the number
		cout << "Attempt #" << i << ":";
		std::cin >> enteredNumber;


		if (!checkIfNumber(enteredNumber))							//checking if input is not a number
		{
			wronginput:
			cout << "Wrong input. Enter a number 1 to 100." << endl;
			goto input;
		}

		if (checkIfNumber(enteredNumber))							//checkinf if the input is a number and continuing
		{
			stringstream ss;										//convertingi entered number from string enteredNumber to
			int enteredNumberInt{};									//integral enteredNumberInt
			ss << enteredNumber;									//
			ss >> enteredNumberInt;									//

			if (enteredNumberInt < 1 || enteredNumberInt > 100)		//if number is less than 1 and more than 100 go to wrong input
			{
				goto wronginput;
			}

			if (enteredNumberInt == randomedNumber)					//right guessing the answer leads you to the youWin: label
			{
				cout << "Congratulations, you win!" << endl;
				goto youWin;
			}

			if (enteredNumberInt < randomedNumber)					//low answer prints "too low"
			{
				cout << "Too low." << endl;
			}

			if (enteredNumberInt > randomedNumber)					//high answer prints "too high"
			{
				cout << "Too high." << endl;
			}
		}

	}

	goto youLose;											//if 7 attempts are wrong and the for loop ents, goes to the youLose: label

youWin:
	cout << "Do you want ot play again? (y/n)";
	char playAgain;
	std::cin >> playAgain;
	
	if (playAgain == 'y')									//if y is entered recurse the whole program
	{
		cout << endl;
		main();
	}
	
	else if (playAgain == 'n' )								//if n is entered exit the program
	{
		exit(EXIT_SUCCESS);
	}

	else													//if anything else is entered print wrong input and ask again if you want to play
	{
		cout << "Wrong input.";
		goto youWin;
	}

youLose:
	cout << "Sorry, you lose! " << endl;
	goto youWin;											//goes to ask you if you want to play again
}
