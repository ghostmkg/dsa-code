// Simple Calculator in JavaScript
class Calculator {
  constructor() {
    this.result = 0;
  }

  // Addition
  add(a, b) {
    return a + b;
  }

  // Subtraction
  subtract(a, b) {
    return a - b;
  }

  // Multiplication
  multiply(a, b) {
    return a * b;
  }

  // Division
  divide(a, b) {
    if (b === 0) {
      throw new Error("Division by zero is not allowed");
    }
    return a / b;
  }

  // Power
  power(a, b) {
    return Math.pow(a, b);
  }

  // Square root
  sqrt(a) {
    if (a < 0) {
      throw new Error("Square root of negative number is not allowed");
    }
    return Math.sqrt(a);
  }

  // Percentage
  percentage(a, b) {
    return (a * b) / 100;
  }

  // Calculate expression (simple parser for basic operations)
  calculate(expression) {
    try {
      // Remove whitespace and validate expression
      expression = expression.replace(/\s/g, "");

      // Basic validation to prevent code injection
      if (!/^[0-9+\-*/.()]+$/.test(expression)) {
        throw new Error("Invalid characters in expression");
      }

      // Use eval for simple expressions (Note: In production, use a proper parser)
      return eval(expression);
    } catch (error) {
      throw new Error("Invalid expression: " + error.message);
    }
  }
}

// Function-based calculator (alternative approach)
function simpleCalculator() {
  const operations = {
    "+": (a, b) => a + b,
    "-": (a, b) => a - b,
    "*": (a, b) => a * b,
    "/": (a, b) => {
      if (b === 0) throw new Error("Division by zero");
      return a / b;
    },
  };

  return {
    calculate: (a, operator, b) => {
      if (!operations[operator]) {
        throw new Error("Unsupported operator");
      }
      return operations[operator](a, b);
    },
  };
}

// Interactive calculator function for console usage
function interactiveCalculator() {
  const calc = new Calculator();

  console.log("=== Simple Calculator ===");
  console.log("Available operations:");
  console.log("1. Basic arithmetic: add, subtract, multiply, divide");
  console.log("2. Advanced: power, sqrt, percentage");
  console.log("3. Expression evaluation");
  console.log("Examples:");
  console.log("calc.add(5, 3) = " + calc.add(5, 3));
  console.log("calc.subtract(10, 4) = " + calc.subtract(10, 4));
  console.log("calc.multiply(6, 7) = " + calc.multiply(6, 7));
  console.log("calc.divide(15, 3) = " + calc.divide(15, 3));
  console.log("calc.power(2, 3) = " + calc.power(2, 3));
  console.log("calc.sqrt(16) = " + calc.sqrt(16));
  console.log("calc.percentage(20, 15) = " + calc.percentage(20, 15));
  console.log(
    "calc.calculate('(5 + 3) * 2') = " + calc.calculate("(5 + 3) * 2"),
  );

  return calc;
}

// Usage examples
if (typeof window === "undefined") {
  // Running in Node.js environment
  const calc = interactiveCalculator();

  // Additional examples
  console.log("\n=== More Examples ===");
  try {
    console.log("20 + 15 =", calc.add(20, 15));
    console.log("100 - 25 =", calc.subtract(100, 25));
    console.log("12 * 8 =", calc.multiply(12, 8));
    console.log("144 / 12 =", calc.divide(144, 12));
    console.log("3^4 =", calc.power(3, 4));
    console.log("√64 =", calc.sqrt(64));
    console.log("15% of 200 =", calc.percentage(200, 15));
    console.log(
      "Complex: (10 + 5) * 3 - 8 =",
      calc.calculate("(10 + 5) * 3 - 8"),
    );
  } catch (error) {
    console.error("Error:", error.message);
  }
} else {
  // Running in browser environment
  console.log(
    "Calculator loaded! Create an instance: const calc = new Calculator();",
  );
}

// Export for module usage
if (typeof module !== "undefined" && module.exports) {
  module.exports = { Calculator, simpleCalculator };
}
