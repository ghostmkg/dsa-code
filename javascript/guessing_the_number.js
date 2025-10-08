const gameNum = 90;
let attempts = 0;
let userNum = Number(prompt("Guess a number: "));
attempts++;

while (userNum !== gameNum) {
    if (userNum > gameNum) {
        userNum = Number(prompt("Too high! Try again: "));
    } else if (userNum < gameNum) {
        userNum = Number(prompt("Too low! Try again: "));
    }
    attempts++;
}
console.log("Correct number! You guessed it in " + attempts + " attempts.");