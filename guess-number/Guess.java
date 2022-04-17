import java.util.concurrent.ThreadLocalRandom;
import java.util.Scanner;

public class Guess {

    public static void main(String[] args) {
        int n = 100;
        guess(n);
    }

    private static void guess(int n) {
        int number = ThreadLocalRandom.current().nextInt(1, n + 1);
        int guess;
        int attempt = 0;

        System.out.printf("Guess a number between 1 and %d\n", n);
        Scanner scanner = new Scanner(System.in);

        while (attempt < 10) {
            attempt++;
            System.out.printf("Please type in your guess: ");
            try {
                guess = Integer.parseInt(scanner.nextLine());
            } catch (Exception e) {
                continue;
            }

            if (guess < number)
                System.out.printf("Higher number please\n");
            else if (guess > number)
                System.out.printf("Lower number please\n");
            else {
                System.out.printf("Bingo! You guessed the number in %d attempts\n", attempt);
                scanner.close();
                return;
            }
        }

        System.out.printf("Oops! You lose after %d attempts\n", attempt);
        scanner.close();
    }
}
