import java.util.*

fun main(args: Array<String>) {
    val n = 100
    guess(n)
}

fun guess(n: Int) {
    val random = SplittableRandom()
    val number = random.nextInt(1, n + 1)
    var guess: Int
    var attempt = 0

    println("Guess a number between 1 and $n")
    val scanner = Scanner(System.`in`)

    while (attempt < 10) {
        attempt++;
        print("Please type in your guess: ")
        guess = scanner.nextInt()

        when {
            guess < number -> println("Higher number please")
            guess > number -> println("Lower number please")
            else -> {
                println("Bingo! You guessed the number in $attempt attempts")
                scanner.close()
                return
            }
        }
    }

    println("Oops! You lose after $attempt attempts")
    scanner.close()
}
