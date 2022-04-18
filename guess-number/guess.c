#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE_MAX 80

void guess(int);

int main(void)
{
    int n = 100;
    guess(n);
    return 0;
}

void guess(int n)
{
    srand(time(NULL));
    int number = rand() % n;
    char guessStr[LINE_MAX];
    int guess;
    int attempt = 0;

    printf("Guess a number betweed 1 and %d\n", n);

    while (attempt < 10) {
        attempt++;
        printf("Please type in your guess: ");
        if ((fgets(guessStr, LINE_MAX, stdin) == NULL) || guessStr[0] == '\n')
            continue;
        guess = atoi(guessStr);

        if (guess < number)
            printf("Higher number please\n");
        else if (guess > number)
            printf("Lower number please\n");
        else {
            printf("Bingo! You guessed the number in %d attempts\n", attempt);
            return;
        }
    }

    printf("Oops! You lose after %d attempts\n", attempt);
}
