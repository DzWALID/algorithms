#include <iostream>
#include <string>
#include "AlgebraicExpression.h"
using namespace std;

// control whether character is digit or not
bool isDigit(char c)
{
	if(c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
		return true;
	else
		return false;
}

// control whether character is operator or not
bool isOperators(char c)
{
	if(c=='+' || c=='-' || c=='/' || c=='*')
		return true;
	else
		return false;
}

// Determine operators priority
int priority(char c)
{
	if(c=='*' || c=='/')
		return 2;
	if(c=='+' || c=='-')
		return 1;
	if(c=='(')
		return 0;
}

// evaluate 2 double
double evaluate(char c, double a, double b)
{
	if(c == '+')
		return a+b;
	if(c == '-')
		return a-b;
	if(c == '*')
		return a*b;
	if(c == '/')
		return a/b;
	
}
// Converts an infix expression exp to its equivalent postfix form.
string infix2postfix( const string exp )
{
	Stack s;
	char c;
	string postfixExp = "";
	for(int i=0; i<exp.length(); i++)
	{
		c = exp.at(i);
		if(isDigit(c))
			postfixExp += c;
		if(isOperators(c))
		{
			if(s.isEmpty())
				s.push(c);
			else
			{
				if(priority(c)>priority(s.getTop()))
				{
					s.push(c);
				}
				else if(priority(c)<=priority(s.getTop()))
				{
					while(!s.isEmpty() && priority(c)<=priority(s.getTop()))
					{
						postfixExp += s.getTop();
						s.pop();
					}
					s.push(c);
				}
			}
		}
		if(c=='(')
		{
			s.push(c);
		}
		if(c==')')
		{
			while(s.getTop() != '(')
			{
				postfixExp += s.getTop();
				s.pop();
			}
			s.pop();
		}
	}
	while(!s.isEmpty())
	{
		postfixExp += s.getTop();
		s.pop();
	}
	return postfixExp;
}

// Evaluates a postfix expression.
double evaluatePostfix( const string exp )
{
	Stack s;
	double n1,n2,result,newItem,postfixResult;
	char c;
	for(int i=0; i<exp.length(); i++)
	{
		c= exp.at(i);
		if(isDigit(c))
		{
			newItem = c-'0';
			s.push(newItem);
		}
		if(isOperators(c))
		{
			n1 = s.getTop();
			s.pop();
			n2 = s.getTop();
			s.pop();
			result = evaluate(c,n2,n1);
			s.push(result);
		}
	}
	postfixResult=s.getTop();
	s.pop();
	return postfixResult;
}
