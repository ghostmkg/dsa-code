// Simple Number Guessing Game for Node.js

const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const secret = Math.floor(Math.random() * 100) + 1;
let attempts = 0;

console.log("🎯 Welcome to the Number Guessing Game!");
console.log("Guess a number between 1 and 100.");

function ask() {
  rl.question("Enter your guess: ", (input) => {
    const guess = Number(input);
    attempts++;

    if (isNaN(guess)) {
      console.log("Please enter a valid number!");
      return ask();
    }

    if (guess > secret) {
      console.log("Too high! Try again.");
      ask();
    } else if (guess < secret) {
      console.log("Too low! Try again.");
      ask();
    } else {
      console.log(`🎉 Correct! The number was ${secret}.`);
      console.log(`You guessed it in ${attempts} tries.`);
      rl.close();
    }
  });
}

ask();
