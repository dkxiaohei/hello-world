use rand::Rng;
use std::io;
use std::cmp::Ordering;

fn main() {
    let n = 100;
    guess(n);
}

fn guess(n: u32) {
    println!("Guess a number between 1 and {}", n);

    let number = rand::thread_rng().gen_range(1..n + 1);
    let mut attempt = 0;

    loop {
        attempt += 1;
        if attempt > 10 {
            break;
        }

        let mut guess = String::new();
        println!("Please type in your guess");
        io::stdin().read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        match guess.cmp(&number) {
            Ordering::Less => println!("Higher number please"),
            Ordering::Greater => println!("Lower number please"),
            Ordering::Equal => {
                println!("Bingo! You guessed the number in {} attempts", attempt);
                return;
            }
        }

    }

    println!("Oops! You lose");
}
