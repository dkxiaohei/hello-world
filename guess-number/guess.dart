import "dart:core";
import "dart:io";
import "dart:math";

void main() {
    var n = 100;
    guess(n);
}

void guess(int n) {
    var random = Random(DateTime.now().millisecondsSinceEpoch);
    var number = random.nextInt(n) + 1;
    var guess;
    var attempt = 0;

    print('Guess a number between 1 and $n');

    while (attempt < 10) {
        attempt++;

        stdout.write('Please type in your guess: ');
        guess = int.tryParse(stdin.readLineSync().toString());
        if (guess == null) {
            continue;
        }

        if (guess.compareTo(number) < 0) {
            print('Higher number please');
        } else if (guess.compareTo(number) > 0) {
            print('Lower number please');
        } else {
            print('Bingo! You guessed the number in $attempt attempts');
            return;
        }
    }

    print('Oops! You lose after $attempt attempts');
}
