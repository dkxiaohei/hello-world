package main

import(
    "bufio"
    "fmt"
    "math/rand"
    "os"
    "strconv"
    "time"
)

func main() {
    n := 100
    guess(n);
}

func guess(n int) {
    rand.Seed(time.Now().Local().UnixNano())
    number := rand.Intn(n) + 1
    attempt := 0

    fmt.Printf("Guess a number between 1 and %d\n", n)

    scanner := bufio.NewScanner(os.Stdin)
    for attempt < 10 {
        attempt += 1

        fmt.Print("Please type in your guess: ")
        scanner.Scan()
        guess, err := strconv.Atoi(scanner.Text())
        if err != nil {
            continue
        }

        if guess < number {
            fmt.Println("Higher number please")
        } else if guess > number {
            fmt.Println("Lower number please")
        } else {
            fmt.Printf("Bingo! You guessed the number in %d attempts\n", attempt)
            return
        }
    }

    fmt.Printf("Oops! You lose after %d attempts\n", attempt)
}
