/**
 * Comprehensive Stack Data Structure Implementation
 * 
 * A stack is a linear data structure that follows the Last In First Out (LIFO) principle.
 * The last element inserted is the first one to be removed.
 * 
 * Time Complexity:
 * - Push: O(1)
 * - Pop: O(1)
 * - Peek/Top: O(1)
 * - Search: O(n)
 * 
 * Space Complexity: O(n) where n is the number of elements
 * 
 * Author: Hacktoberfest Contributor
 * Date: October 2024
 */

class Stack {
    constructor() {
        this.items = [];
        this.count = 0;
    }

    /**
     * Add an element to the top of the stack
     * @param {*} element - Element to push
     * @return {number} New size of stack
     */
    push(element) {
        this.items[this.count] = element;
        this.count++;
        return this.count;
    }

    /**
     * Remove and return the top element
     * @return {*} The removed element, or undefined if empty
     */
    pop() {
        if (this.isEmpty()) {
            return undefined;
        }
        this.count--;
        const result = this.items[this.count];
        delete this.items[this.count];
        return result;
    }

    /**
     * Return the top element without removing it
     * @return {*} Top element, or undefined if empty
     */
    peek() {
        if (this.isEmpty()) {
            return undefined;
        }
        return this.items[this.count - 1];
    }

    /**
     * Check if the stack is empty
     * @return {boolean} True if empty, false otherwise
     */
    isEmpty() {
        return this.count === 0;
    }

    /**
     * Get the size of the stack
     * @return {number} Number of elements
     */
    size() {
        return this.count;
    }

    /**
     * Clear all elements from the stack
     */
    clear() {
        this.items = [];
        this.count = 0;
    }

    /**
     * Convert stack to array (bottom to top)
     * @return {Array} Array representation of stack
     */
    toArray() {
        return this.items.slice(0, this.count);
    }

    /**
     * Display stack contents
     * @return {string} String representation
     */
    toString() {
        if (this.isEmpty()) {
            return 'Stack: []';
        }
        return `Stack: [${this.toArray().join(', ')}] <- top`;
    }

    /**
     * Search for an element (returns position from top, 1-indexed)
     * @param {*} element - Element to search for
     * @return {number} Position from top (1-indexed), or -1 if not found
     */
    search(element) {
        for (let i = this.count - 1; i >= 0; i--) {
            if (this.items[i] === element) {
                return this.count - i; // Position from top
            }
        }
        return -1;
    }
}

/**
 * Stack applications and utility functions
 */
class StackApplications {
    
    /**
     * Check if parentheses are balanced
     * @param {string} str - String containing parentheses
     * @return {boolean} True if balanced, false otherwise
     */
    static isBalancedParentheses(str) {
        const stack = new Stack();
        const pairs = {
            '(': ')',
            '[': ']',
            '{': '}'
        };

        for (let char of str) {
            if (char in pairs) {
                // Opening bracket
                stack.push(char);
            } else if (Object.values(pairs).includes(char)) {
                // Closing bracket
                if (stack.isEmpty()) return false;
                const top = stack.pop();
                if (pairs[top] !== char) return false;
            }
        }

        return stack.isEmpty();
    }

    /**
     * Convert infix expression to postfix (Reverse Polish Notation)
     * @param {string} infix - Infix expression
     * @return {string} Postfix expression
     */
    static infixToPostfix(infix) {
        const stack = new Stack();
        let postfix = '';
        
        const precedence = {
            '+': 1, '-': 1,
            '*': 2, '/': 2,
            '^': 3
        };
        
        const isOperator = (char) => char in precedence;
        const isOperand = (char) => /[a-zA-Z0-9]/.test(char);

        for (let char of infix) {
            if (isOperand(char)) {
                postfix += char;
            } else if (char === '(') {
                stack.push(char);
            } else if (char === ')') {
                while (!stack.isEmpty() && stack.peek() !== '(') {
                    postfix += stack.pop();
                }
                stack.pop(); // Remove '('
            } else if (isOperator(char)) {
                while (!stack.isEmpty() && 
                       stack.peek() !== '(' && 
                       precedence[stack.peek()] >= precedence[char]) {
                    postfix += stack.pop();
                }
                stack.push(char);
            }
        }

        while (!stack.isEmpty()) {
            postfix += stack.pop();
        }

        return postfix;
    }

    /**
     * Evaluate postfix expression
     * @param {string} postfix - Postfix expression
     * @return {number} Result of evaluation
     */
    static evaluatePostfix(postfix) {
        const stack = new Stack();

        for (let char of postfix) {
            if (/\d/.test(char)) {
                stack.push(parseInt(char));
            } else {
                const b = stack.pop();
                const a = stack.pop();
                
                switch (char) {
                    case '+': stack.push(a + b); break;
                    case '-': stack.push(a - b); break;
                    case '*': stack.push(a * b); break;
                    case '/': stack.push(Math.floor(a / b)); break;
                    case '^': stack.push(Math.pow(a, b)); break;
                }
            }
        }

        return stack.pop();
    }

    /**
     * Find next greater element for each element in array
     * @param {number[]} arr - Input array
     * @return {number[]} Array with next greater elements (-1 if none)
     */
    static nextGreaterElement(arr) {
        const stack = new Stack();
        const result = new Array(arr.length).fill(-1);

        for (let i = arr.length - 1; i >= 0; i--) {
            // Pop elements smaller than current
            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }
            
            // If stack not empty, top is the next greater element
            if (!stack.isEmpty()) {
                result[i] = stack.peek();
            }
            
            // Push current element
            stack.push(arr[i]);
        }

        return result;
    }

    /**
     * Calculate maximum area in histogram
     * @param {number[]} heights - Array of histogram heights
     * @return {number} Maximum rectangular area
     */
    static largestRectangleArea(heights) {
        const stack = new Stack();
        let maxArea = 0;
        let index = 0;

        while (index < heights.length) {
            if (stack.isEmpty() || heights[index] >= heights[stack.peek()]) {
                stack.push(index++);
            } else {
                const top = stack.pop();
                const area = heights[top] * (stack.isEmpty() ? index : index - stack.peek() - 1);
                maxArea = Math.max(maxArea, area);
            }
        }

        while (!stack.isEmpty()) {
            const top = stack.pop();
            const area = heights[top] * (stack.isEmpty() ? index : index - stack.peek() - 1);
            maxArea = Math.max(maxArea, area);
        }

        return maxArea;
    }
}

/**
 * Demonstration and testing functions
 */
function demonstrateStack() {
    console.log('📚 STACK DATA STRUCTURE DEMONSTRATION');
    console.log('=====================================\n');

    // Basic operations
    console.log('1. Basic Stack Operations:');
    const stack = new Stack();
    
    console.log(stack.toString()); // Empty stack
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    console.log(stack.toString()); // [10, 20, 30]
    
    console.log(`Peek: ${stack.peek()}`); // 30
    console.log(`Pop: ${stack.pop()}`);   // 30
    console.log(stack.toString());        // [10, 20]
    
    console.log(`Size: ${stack.size()}`); // 2
    console.log(`Search 20: ${stack.search(20)}`); // 1 (position from top)
    console.log(`Search 10: ${stack.search(10)}`); // 2
    console.log(`Search 99: ${stack.search(99)}`); // -1

    console.log('\n' + '='.repeat(50) + '\n');

    // Applications
    console.log('2. Stack Applications:');
    
    // Balanced parentheses
    const expressions = [
        '()',
        '()[]{}',
        '([{}])',
        '(((',
        '({[}])',
        '{[()()]}'
    ];
    
    console.log('Balanced Parentheses Check:');
    expressions.forEach(expr => {
        const balanced = StackApplications.isBalancedParentheses(expr);
        console.log(`${expr.padEnd(10)} -> ${balanced ? '✓' : '✗'}`);
    });

    console.log('\nInfix to Postfix Conversion:');
    const infixExpressions = ['A+B*C', '(A+B)*C', 'A+B*C-D'];
    infixExpressions.forEach(expr => {
        const postfix = StackApplications.infixToPostfix(expr);
        console.log(`${expr.padEnd(10)} -> ${postfix}`);
    });

    console.log('\nPostfix Evaluation:');
    const postfixExpressions = ['23+', '23*45*+', '532*+'];
    postfixExpressions.forEach(expr => {
        const result = StackApplications.evaluatePostfix(expr);
        console.log(`${expr.padEnd(10)} -> ${result}`);
    });

    console.log('\nNext Greater Element:');
    const arrays = [[4, 5, 2, 25], [13, 7, 6, 12], [1, 2, 3, 4, 5]];
    arrays.forEach(arr => {
        const nge = StackApplications.nextGreaterElement(arr);
        console.log(`${JSON.stringify(arr)} -> ${JSON.stringify(nge)}`);
    });

    console.log('\nLargest Rectangle in Histogram:');
    const histograms = [[2, 1, 5, 6, 2, 3], [6, 2, 5, 4, 5, 1, 6]];
    histograms.forEach(heights => {
        const area = StackApplications.largestRectangleArea(heights);
        console.log(`${JSON.stringify(heights)} -> Max area: ${area}`);
    });
}

/**
 * Performance testing
 */
function performanceTest() {
    console.log('\n' + '='.repeat(50));
    console.log('3. Performance Testing:');
    console.log('='.repeat(50));

    const stack = new Stack();
    const n = 100000;

    // Push performance
    console.time('Push 100k elements');
    for (let i = 0; i < n; i++) {
        stack.push(i);
    }
    console.timeEnd('Push 100k elements');

    // Pop performance
    console.time('Pop 100k elements');
    for (let i = 0; i < n; i++) {
        stack.pop();
    }
    console.timeEnd('Pop 100k elements');

    console.log(`Final stack size: ${stack.size()}`);
}

/**
 * Interactive demo (for Node.js environment with readline)
 */
function interactiveDemo() {
    console.log('\n🎮 INTERACTIVE STACK DEMO');
    console.log('==========================');
    console.log('Commands: push <value>, pop, peek, size, clear, search <value>, quit');
    
    const stack = new Stack();
    
    // This would work in a Node.js environment with readline
    console.log('Note: Interactive demo requires Node.js readline module');
    console.log('Example usage:');
    console.log('> push 10');
    console.log('> push 20');
    console.log('> peek');
    console.log('> pop');
    console.log(stack.toString());
}

// Main execution
if (typeof module !== 'undefined' && module.exports) {
    // Node.js environment
    module.exports = { Stack, StackApplications };
    
    if (require.main === module) {
        demonstrateStack();
        performanceTest();
        interactiveDemo();
    }
} else {
    // Browser environment
    window.Stack = Stack;
    window.StackApplications = StackApplications;
    
    // Auto-run demonstration
    demonstrateStack();
    performanceTest();
}

/*
 * Usage Examples:
 * 
 * // Create a new stack
 * const myStack = new Stack();
 * 
 * // Basic operations
 * myStack.push(10);
 * myStack.push(20);
 * console.log(myStack.peek()); // 20
 * console.log(myStack.pop());  // 20
 * console.log(myStack.size()); // 1
 * 
 * // Check balanced parentheses
 * console.log(StackApplications.isBalancedParentheses('([{}])')); // true
 * 
 * // Convert infix to postfix
 * console.log(StackApplications.infixToPostfix('A+B*C')); // "ABC*+"
 * 
 * // Next greater element
 * console.log(StackApplications.nextGreaterElement([4, 5, 2, 25])); // [5, 25, 25, -1]
 */