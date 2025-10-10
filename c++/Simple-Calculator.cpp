//C++ program to implement a simple calculator
//This program performs basic arithmetic operations like addition, subtraction, multiplication, and division based on user input.
// Time complexity: O(1)
//Space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
int a,b;
char op; //operator

//Taking input from user
cout<<"Enter the operation you want to perform (+,-,*,/): ";
cin>>op;

//Taking two numbers as input
cout<<"Enter two numbers: ";
cin>>a>>b;

//Performing operation based on user input
switch(op){
	case '+':
		cout<<"Result:"<<a+b; // Addition
		break;
	case '-':
		cout<<"Result:"<<a-b; // Subtraction
		break;
	case '*':
		cout<<"Result:"<<a*b; // Multiplication
		break;
	case '/':
		if(b!=0)   // Checking for division by zero
		cout<<"Result:"<<a/b; // Division
		else
		cout<<"Division by zero is not allowed.";    //If the denominator is zero division cannot be performed
		break;
	default:
		cout<<"Invalid operation.";  //If the operator is not one of +,-,*,/ then it is invalid
	}

}


