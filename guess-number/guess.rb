#!/usr/bin/env ruby

def guess(n)
  number = rand(n) + 1
  attempt = 0

  puts "Guess a number between 1 and #{n}"

  while attempt < 10
    attempt += 1

    print "Please type in your guess: "
    guessStr = gets
    if guessStr == "\n"
      next
    end
    guess = guessStr.to_i

    if guess < number
      puts "Higher number please"
    elsif guess > number
      puts "Lower number please"
    else
      puts "Bingo! You guessed the number in #{attempt} attempts"
      return
    end
  end

  puts "Oops! You lose after #{attempt} attempts"
end

n = 100
guess(n)
