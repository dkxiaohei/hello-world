#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int guess;
    int attempt = 0;

    printf("Guess a number betweed 1 and %d\n", n);

    while (attempt++ < 10) {
        printf("Please type your guess: ");
        scanf("%d", &guess);

        if (guess < number)
            printf("Higher number please\n");
        else if (guess > number)
            printf("Lower number please\n");
        else {
            printf("Bingo! You guessd the number in %d attempts\n", attempt);
            return;
        }
    }

    printf("Oops! You lose\n");
}
