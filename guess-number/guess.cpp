#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

void guess(int);

int main()
{
    int n = 100;
    guess(n);
    return 0;
}

void guess(int n)
{
    srand(time(nullptr));
    int number = rand() % n;
    std::string guessStr;
    int guess;
    int attempt = 0;

    std::cout << "Guess a number betweed 1 and " << n << std::endl;

    while (attempt < 10) {
        attempt++;
        std::cout << "Please type in your guess: ";
        getline(std::cin, guessStr);
        try {
            guess = std::stoi(guessStr);
        } catch (std::invalid_argument const& e) {
            continue;
        }

        if (guess < number)
            std::cout << "Higher number please" << std::endl;
        else if (guess > number)
            std::cout << "Lower number please" << std::endl;
        else {
            std::cout << "Bingo! You guessed the number in " << attempt << " attempts" << std::endl;
            return;
        }
    }

    std::cout << "Oops! You lose after " << attempt << " attempts" << std::endl;
}
