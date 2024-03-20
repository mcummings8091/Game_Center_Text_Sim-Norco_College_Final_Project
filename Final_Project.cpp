// Matthew Cummings

// CIS - 5 Online

// 02/07/2024

// Final Project

#include <iostream>
#include <iomanip> // formatting 
#include <cstdlib> // for rand() and srand()
#include <ctime>  // for time()
#include <string> // for array of strings 

using namespace std;

// General prototypes
bool isValid(int min, int max, int input);
int mainMenu();
int generateRandomNumber(int min, int max);

// Math tutor prototypes
void mathTutor();
int tutorMenu();
void displayProblem(int topNumber, int bottomNumber, int choice);
void attemptProblem(int solution, int& correctGuesses, int& incorrectGuesses);
void displayGuesses(int correctGuesses, int incorrectGuesses);
// Math operations
int addition(int choice);
int subtraction(int choice);
int multiplication(int choice);
int division(int choice);


// Rock, Paper, Scissors prototypes
void rockPaperScissors();
int gameMenu();
void decideGame(int userChoice, int comChoice, int& draws, int& wins, int& losses);
void displayGameStats(int draws, int wins, int losses);
void displayChoices(int userChoice, int comChoice);



int main()
{
	// Seed generator
	srand(static_cast<unsigned int>(time(NULL)));

	int choice;
	bool continueGame = true;

	do {
		choice = mainMenu();

		switch (choice) {
			case  1: {
				mathTutor(); // Run math tutor program
				break; 
			}
			case  2: {
				rockPaperScissors(); // Run Rock, Paper, Scissors program
				break;
			}
			case  3: {
				cout << "\nLeaving Game Center...\n";
				cout << "Come Back Soon!";
				continueGame = false;
				break;
			}
		}
	} while (continueGame);

	return  0;
}

  

// General Functions

// Input validation
bool isValid(int min, int max, int input) {
	if (input >= min && input <= max) {
		return true;
	}
	else {
		return false;
	}
}


int generateRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}


int mainMenu() {
	int choice;

	do {
		cout << "Welcome to CIS5 Game Center! \n\n";
		cout << "1.) Math Tutor \n";
		cout << "2.) Rock Paper Scissors \n";
		cout << "3.) Quit \n\n";

		cout << "Enter selection: ";
		cin >> choice;

		if (!isValid(1, 3, choice)) {
			cout << "\nInvalid input. Please enter an option between  1 and  3.\n\n";
		}
	} while (!isValid(1, 3, choice));

	return choice;
}



// Math Tutor Functions

void mathTutor() {
	int solution;
	int choice = 0;
	int correctGuesses = 0, incorrectGuesses = 0;

	cout << "Welcome to the Math Tutor! \n\n";

	do {
		choice = tutorMenu();

		switch (choice) {
			// Addition logic
		case 1: {
			solution = addition(choice);

			attemptProblem(solution, correctGuesses, incorrectGuesses);
			displayGuesses(correctGuesses, incorrectGuesses);

			break;
		}
			  // Subtraction logic
		case 2: {
			solution = subtraction(choice);

			attemptProblem(solution, correctGuesses, incorrectGuesses);
			displayGuesses(correctGuesses, incorrectGuesses);

			break;
		}
			  // Multiplication logic
		case 3: {
			solution = multiplication(choice);

			attemptProblem(solution, correctGuesses, incorrectGuesses);
			displayGuesses(correctGuesses, incorrectGuesses);

			break;
		}
			  // Division logic to be added...
		case 4: {
			solution = division(choice);

			attemptProblem(solution, correctGuesses, incorrectGuesses);
			displayGuesses(correctGuesses, incorrectGuesses);

			break;
		}
		case 5: {
			cout << "\nQuitting Program...\n\n";
			break;
		}
		}
	} while (choice != 5);
}


// Display main menu 
int tutorMenu() {
	int choice;
	do {
		cout << "1.) Addition \n";
		cout << "2.) Subtraction \n";
		cout << "3.) Multiplication \n";
		cout << "4.) Division \n";
		cout << "5.) Quit \n";
		cout << "\nPlease select an option. ( 1 - 5 ): ";
		cin >> choice;
		if (!isValid(1, 5, choice)) {
			cout << "\nInvalid input. Please enter a number between 1 and 5.\n\n";
		}
	} while (!isValid(1, 5, choice));
	return choice;
}


// function to format the generated questions and display them to the user
void displayProblem(int topNumber, int bottomNumber, int choice) {
	string operators[4] = { "+", "-", "*", "/" };

	cout << endl;
	cout << left << setw(2) << " " << right << setw(3) << topNumber << endl;

	// "operators[choice - 1]" Is used to pick the symbol to be used for the problem formatting. 
	// For example, user picks 2 -> operators[choice - 1] -> operators[1] -> "-"
	cout << left << setw(2) << operators[choice - 1] << right << setw(3) << bottomNumber << endl;
	cout << "_____\n\n";

}


// Prompt the user for an answer to given question and providing the correct answer should the user be wrong
void attemptProblem(int solution, int& correctGuesses, int& incorrectGuesses) {
	int answer;
	int attempts = 3;

	while (attempts > 0) {
		cout << "Please attemmpt the problem: ";
		cin >> answer;

		if (answer == solution) {
			cout << "Correct!\n\n";
			correctGuesses += 1;
			break;
		}
		else {
			cout << "Incorrect. Try again!\n";
			incorrectGuesses += 1;
			attempts -= 1;
			cout << "Attempts remaining: " << attempts << endl;
		}
	}

	if (attempts == 0) {
		cout << "Good try! The solution is " << solution << endl << endl;
	}
}


void displayGuesses(int correctGuesses, int incorrectGuesses) {
	cout << endl;
	cout << "Correct Guesses: " << correctGuesses << endl;
	cout << "Incorrect Guesses: " << incorrectGuesses << endl << endl;
}


int addition(int choice) {
	//return topNumber + bottomNumber;
	int topNumber = generateRandomNumber(2, 500);
	int bottomNumber = generateRandomNumber(1, 99);
	while (bottomNumber > topNumber) {
		bottomNumber = generateRandomNumber(1, 99);
	}
	int solution = topNumber + bottomNumber;

	displayProblem(topNumber, bottomNumber, choice);

	return solution;
}


int subtraction(int choice) {
	//return topNumber - bottomNumber;
	int topNumber = generateRandomNumber(2, 500);
	int bottomNumber = generateRandomNumber(1, 500);
	while (bottomNumber > topNumber) {
		bottomNumber = generateRandomNumber(1, 500);
	}
	int solution = topNumber - bottomNumber;

	displayProblem(topNumber, bottomNumber, choice);

	return solution;
}


int multiplication(int choice) {
	//return topNumber * bottomNumber;
	int topNumber = generateRandomNumber(1, 12);
	int bottomNumber = generateRandomNumber(1, 12);

	int solution = topNumber * bottomNumber;

	displayProblem(topNumber, bottomNumber, choice);

	return solution;
}


int division(int choice) {
	//return topNumber / bottomNumber;
	int topNumber = generateRandomNumber(10, 999);
	int bottomNumber;
	do {
		bottomNumber = generateRandomNumber(1, 9);
	} while (bottomNumber == 0);

	int solution = topNumber / bottomNumber;

	displayProblem(topNumber, bottomNumber, choice);

	return solution;
}




// Rock paper scissors functions

void rockPaperScissors() {
	int comChoice;
	int userChoice;
	int draws = 0, wins = 0, losses = 0; // Variables to track player stats
	char continueGame; // Variable to track if the player will play again

	cout << "\nWelcome to Rock, Paper, Scissors! Battle the Com and try to come out on top! \n";
	
	do {
		// Com picks a random number 1 - 3
		comChoice = generateRandomNumber(1, 3);
		userChoice = gameMenu();

		// Output Com & Player choices
		displayChoices(userChoice, comChoice);
		
		// Determine the outcome of the game and add the outcome to the stat tracker
		decideGame(userChoice, comChoice, draws, wins, losses);

		// Display game stats
		displayGameStats(draws, wins, losses);
		
		// Propmt user if they would like to play again
		cout << "\nWould you like to play again? (y/n) ";
		cin >> continueGame;


	} while (continueGame != 'n' && continueGame != 'N');

	cout << "\nQuitting Program...\n\n";


}


// Handle displaying the menu and validating the user input
int gameMenu() {
	int userChoice;
	do {
		cout << "\nMake your choice\n";
		cout << "1.) Rock \n";
		cout << "2.) Paper \n";
		cout << "3.) Scissors \n";

		cout << "Select: ";
		cin >> userChoice;

		if (!isValid(1, 3, userChoice)) {
			cout << "\nInvalid input. Try again.";
		}

	} while (!isValid(1, 3, userChoice));

	return userChoice;
}


// Determine the outcome of the game and add the outcome to the stat tracker
void decideGame(int userChoice, int comChoice, int& draws, int& wins, int& losses) {
	if (userChoice == comChoice) {
		cout << "\nIt's a draw!" << endl;
		draws += 1;
	}
	// User wins
	else if (userChoice == 1 && comChoice == 3) {
		cout << "\nRock smashes Scissors!\n";
		cout << "You win!\n";
		wins += 1;
	}
	else if (userChoice == 3 && comChoice == 2) {
		cout << "\nScissors cuts Paper!\n";
		cout << "You win!\n";
		wins += 1;
	}
	else if (userChoice == 2 && comChoice == 1) {
		cout << "\nPaper covers Rock!\n";
		cout << "You win!\n";
		wins += 1;
	}
	// Com wins
	else if (comChoice == 1 && userChoice == 3) {
		cout << "\nRock smashes Scissors!\n";
		cout << "You lose!\n";
		losses += 1;
	}
	else if (comChoice == 3 && userChoice == 2) {
		cout << "\nScissors cuts Paper!\n";
		cout << "You lose!\n";
		losses += 1;
	}
	else if (comChoice == 2 && userChoice == 1) {
		cout << "\nPaper covers Rock!\n";
		cout << "You lose!\n";
		losses += 1; 
	}
}


// Dsplay Com and user choices
void displayChoices(int userChoice, int comChoice) {
	string choices[3] = { "Rock", "Paper", "Scissors" };

	cout << "\nUser Choice: " << choices[userChoice - 1] << endl;
	cout << "Computer Choice: " << choices[comChoice - 1] << endl;
}


// Display Player stats
void displayGameStats(int draws, int wins, int losses) {
	cout << endl;
	cout << "Draws: " << draws << endl;
	cout << "Wins: " << wins << endl;
	cout << "Losses: " << losses << endl;
}
