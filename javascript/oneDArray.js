// 1D Array Operations in JavaScript

// Initial Array
let arr = [10, 20, 30, 40, 50];
console.log("Original Array:", arr);

// 1. Traversal
function traverseArray(arr) {
  console.log("Traversed Array:");
  for (let i = 0; i < arr.length; i++) {
    console.log(`Index ${i} => ${arr[i]}`);
  }
}
traverseArray(arr);

// 2. Insertion at specific position
function insertElement(arr, element, position) {
  if (position < 0 || position > arr.length) {
    console.log("Invalid Position!");
    return arr;
  }
  arr.splice(position, 0, element); // insert at position
  return arr;
}
arr = insertElement(arr, 25, 2);
console.log("After Insertion (25 at index 2):", arr);

// 3. Deletion from specific position
function deleteElement(arr, position) {
  if (position < 0 || position >= arr.length) {
    console.log("Invalid Position!");
    return arr;
  }
  arr.splice(position, 1); // remove 1 element at index
  return arr;
}
arr = deleteElement(arr, 4);
console.log("After Deletion (index 4):", arr);

// 4. Searching an element
function searchElement(arr, key) {
  let index = arr.indexOf(key);
  if (index !== -1) {
    console.log(`${key} found at index ${index}`);
  } else {
    console.log(`${key} not found in array`);
  }
}
searchElement(arr, 30);
searchElement(arr, 99);

// 5. Updating an element
function updateElement(arr, position, newValue) {
  if (position < 0 || position >= arr.length) {
    console.log("Invalid Position!");
    return arr;
  }
  arr[position] = newValue;
  return arr;
}
arr = updateElement(arr, 1, 200);
console.log("After Updating (index 1 → 200):", arr);
