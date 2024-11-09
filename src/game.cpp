#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

namespace game
{

const std::string high_scores_filename = "high_scores.txt";

std::string enter_your_name()
{
    std::string name;
    std::cout << "Hi! Enter your name: ";
    std::cin >> name;

    return name;
}

int get_max_value()
{
    const int max_value = 100;
    return max_value;
}

int random_value(int max_value)
{

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max_value;

	return random_value;
}


int check_value(int target_value)
{
    int your_value = 0;
    bool win = false;
    int attemps = 0;

    std::cout << "Enter your value: ";


    while (!win)
    {
        ++attemps;
        std::cin >> your_value;
        if(your_value > target_value)
            std::cout << "Less than " << your_value << "\n";
        else if(your_value < target_value)
            std::cout << "Grater than " << your_value << "\n";
        else if(your_value == target_value) {
            std::cout << "You win!" << " attemps: " << attemps << "\n";
            win = true;    
        }
    }    

    return attemps;
}

static void high_scores(const std::string& name, int user_attemps)
{
    // const std::string high_scores_filename = "high_scores.txt";

    std::ofstream out_file{high_scores_filename, std::ios_base::app};
    if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
	}

    out_file << name << ' ';
	out_file << user_attemps;
	out_file << std::endl;
}

void print_high_score()
{
    std::ifstream in_file{high_scores_filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

			// Print the information to the screen
		std::cout << username << '\t' << high_score << std::endl;
	}
}



void run()
{
    int max_value = get_max_value();
    int target_value = random_value(max_value);
    std::string name = enter_your_name();
    int user_attemps = check_value(target_value);
    high_scores(name, user_attemps);
    print_high_score();
}


}