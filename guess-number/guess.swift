let n = 100
guess(n: n)

func guess(n: Int) {
    let number = Int.random(in: 1...n)
    var guessStr: String?
    var attempt = 0

    print("Guess a number between 1 and \(n)")

    while attempt < 10 {
        attempt += 1

        print("Please type in your guess:", terminator: " ")
        guessStr = readLine()
        let guess = Int(guessStr!)!

        if guess < number {
            print("Higher number please")
        } else if guess > number {
            print("Lower number please")
        } else {
            print("Bingo! You guessed the number in \(attempt) attempts")
            return
        }
    }

    print("Oops! You lose after \(attempt) attempts")
}
