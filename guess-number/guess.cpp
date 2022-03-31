#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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
    int guess;
    int attempt = 0;

    cout << "Guess a number betweed 1 and " << n << endl;

    while (attempt < 10) {
        attempt++;
        cout << "Please type in your guess: ";
        cin >> guess;

        if (guess < number)
            cout << "Higher number please" << endl;
        else if (guess > number)
            cout << "Lower number please" << endl;
        else {
            cout << "Bingo! You guessed the number in " << attempt << " attempts" << endl;
            return;
        }
    }

    cout << "Oops! You lose after " << attempt << " attempts" << endl;
}
