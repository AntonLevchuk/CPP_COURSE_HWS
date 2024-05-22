#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

int generateRandomValue(int maxValue);
std::string isUserWon(char pcSymbol, char userSymbol, std::map<int, int>& roundStats);
void outputStats(std::map<int, int> roundStats);

enum RoundStats {
	WIN,
	LOOSE,
	DRAW,
	roundsAmountForStats,
};

int main()
{
	int continueCondition = true;
	std::vector<char> possibleSymbols = { 'r', 'p', 's' };
	std::vector<std::string> outputVariants = { "r - rock", "p - paper", "s - scissors" };

	std::cout << "Hello! Welcome to the 'Rock paper scissors' game for 2 players." << std::endl;
	while (continueCondition) {
		std::map<int, int> roundStats = { {RoundStats::WIN, 0}, {RoundStats::LOOSE, 0}, {RoundStats::DRAW, 0}, {RoundStats::roundsAmountForStats, 0}};

		int roundsAmount;

		std::cout << "How many rounds would you like to play(Enter -1 to quit)? ";
		std::cin >> roundsAmount;
		roundStats[RoundStats::roundsAmountForStats] = roundsAmount;

		switch (roundsAmount)
		{
		case 0:
			std::cout << "Rounds amount could not be 0.\nIf you want to continue enter number that is grater than 0, if you want to stop enter -1." << std::endl;
			continue;
		case -1:
			std::cout << "BYE-BYE" << std::endl;
			continueCondition = false;
			break;
		default:
			if (roundsAmount < -1) {
				std::cout << "Rounds amount could not be less than -1.\nIf you want to continue enter number that is grater than 0, if you want to stop enter -1." << std::endl;
				continue;
			}
		}

		while (roundsAmount > 0) {
			char userSymbol;
			char randomSymbol;
			std::string result = "";

			std::cout << "\nTo make your turn enter one of possible symbols:" << std::endl;
			for (std::string elem:outputVariants) {
				std::cout << std::setw(5 + elem.size()) << elem;
			}

			std::cout << "\nYour choose is: ";
			std::cin >> userSymbol;
			userSymbol = std::tolower(userSymbol);
			
			if (std::find(possibleSymbols.begin(), possibleSymbols.end(), userSymbol) == possibleSymbols.end()) {
				std::cout << "Icorrect value! Try again." << std::endl;
				continue;
			}

			randomSymbol = possibleSymbols[generateRandomValue(possibleSymbols.size() - 1)];

			result = isUserWon(randomSymbol, userSymbol, roundStats);
			//roundStats[result] += 1;
			std::cout << "Result: " << result << std::endl;
			std::cout << "PC symbol: " << randomSymbol << std::endl;

			roundsAmount--;
		}

		outputStats(roundStats);

	}
}

int generateRandomValue(int maxValue) {
	std::srand(std::time(nullptr));
	return std::rand() % (maxValue + 1);
}

std::string isUserWon(char pcSymbol, char userSymbol, std::map<int, int> &roundStats) {
	std::string result = "";

	if (pcSymbol == userSymbol) {
		roundStats[RoundStats::DRAW]++;
		return "DRAW";
	}
 	else if (userSymbol == 'r') {
		if (pcSymbol == 's') {
			roundStats[RoundStats::WIN]++;
			result = "WIN";
		}
		else if (pcSymbol == 'p') {
			roundStats[RoundStats::LOOSE]++;
			result = "LOOSE";
		}
	}
	else if (userSymbol == 'p') {
		if (pcSymbol == 'r') {
			roundStats[RoundStats::WIN]++;
			result = "WIN";
		}
		else if (pcSymbol == 's') {
			roundStats[RoundStats::LOOSE]++;
			result = "LOOSE";
		}
	}
	else if (userSymbol == 's') {
		if (pcSymbol == 'p') {
			roundStats[RoundStats::WIN]++;
			result = "WIN";
		}
		else if (pcSymbol == 'r') {
			roundStats[RoundStats::LOOSE]++;
			result = "LOOSE";
		}
	}

	return result;
}

void outputStats(std::map<int, int> roundStats) {
	std::cout << std::string(40, '-') << std::endl;
	std::cout << "Thanks for playing. Your final stats:" << std::endl;
	std::cout << std::setw(25) << "Number of rounds - " << roundStats[RoundStats::roundsAmountForStats] << std::endl;
	std::cout << std::setw(25) << "Number of wins - " << roundStats[RoundStats::WIN] << std::endl;
	std::cout << std::setw(25) << "Number of looses - " << roundStats[RoundStats::LOOSE] << std::endl;
	std::cout << std::setw(25) << "Number of draws - " << roundStats[RoundStats::DRAW] << std::endl;

	if (roundStats[RoundStats::WIN] > roundStats[RoundStats::LOOSE]) {
		std::cout << "Greate! You're smarter than my PC!" << std::endl;
	}
	else if (roundStats[RoundStats::WIN] < roundStats[RoundStats::LOOSE]) {
		std::cout << "Bad luck! My PC won! Try again!" << std::endl;
	}
	else {
		std::cout << "WOW! It's draw. Try again and maybe you'll win!" << std::endl;
	}
	std::cout << std::string(40, '-') << std::endl;
}
