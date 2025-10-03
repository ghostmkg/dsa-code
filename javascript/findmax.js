function findMax(arr) {
  let max = arr[0];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

const nums = [12, 45, 2, 67, 34];
console.log("Maximum number:", findMax(nums));
