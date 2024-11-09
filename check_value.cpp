#include <iostream>


int main()
{
    const int target_value = 0;
    int your_value = 0;
    bool win = false;

    std::cout << "Enter your value: ";

    while (!win)
    {
        std::cin >> your_value;
        if(your_value > target_value)
            std::cout << "Less than" << your_value << "\n";
        else if(your_value < target_value)
            std::cout << "Grater than" << your_value << "\n";
        else if(your_value == target_value) {
            std::cout << "You win!";
            win = true;    
        }
    }

    return 0;    
}