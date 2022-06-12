function guess(n) {
    const number = Math.floor(Math.random() * n) + 1;
    let attempt = 0, guess;

    console.log(`Guess a number between 1 and ${n}`);

    const rl = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout,
        prompt: 'Please type in your guess: '
    });

    rl.prompt();

    rl.on('line', (line) => {
        attempt++;

        guess = parseInt(line);
        if (guess < number && attempt < 10) {
            console.log('Higher number please');
        } else if (guess > number && attempt < 10) {
            console.log('Lower number please');
        } else if (guess === number) {
            console.log(`Bingo! You guessed the number in ${attempt} attempts`);
            rl.close();
            return;
        }

        if (attempt === 10) {
            console.log(`Oops! You lose after ${attempt} attempts`);
            rl.close();
            return;
        }
        rl.prompt();
    });
}

const n = 100;
guess(n);
