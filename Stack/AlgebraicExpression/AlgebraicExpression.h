#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

	bool isDigit(char c);
	bool isOperators(char c);
	int priority(char c);
	double evaluate(char c, double a, double b);
	// It converts an infix expression exp to its equivalent postfix form.
	string infix2postfix( const string exp );
	//It evaluates a postfix expression.
	double evaluatePostfix( const string exp );
