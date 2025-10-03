let numbers = [20, 90, 10, 324, 9, 73];
let smallest = numbers[0];

for (let i = 1; i < numbers.length; i++) {
  if (numbers[i] < smallest) {
    smallest = numbers[i];
  }
}
console.log(smallest);
