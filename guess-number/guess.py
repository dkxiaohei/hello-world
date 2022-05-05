#!/usr/bin/env python3

from random import randint

def guess(n):
    number = randint(1, n)
    attempt = 0

    print(f'Guess a number between 1 and {n}')

    while attempt < 10:
        attempt += 1

        guessStr = input("Please type in your guess: ")
        try:
            guess = int(guessStr)
        except ValueError:
            continue

        if guess < number:
            print("Higher number please")
        elif guess > number:
            print("Lower number please")
        else:
            print(f'Bingo! You guessed the number in {attempt} attempts')
            return

    print(f'Oops! You lose after {attempt} attempts')

if __name__ == '__main__':
    n = 100
    guess(n)
