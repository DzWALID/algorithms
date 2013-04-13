#include <iostream>
#include "AlgebraicExpression.h"
using namespace std;
int main()
{
	//cout <<infix2postfix("(5-8/9*6-6)+5-7/6*(3*8-4/5+6)")<< endl;
	//cout <<infix2postfix("(4+5)-2*4") << endl;
	cout << evaluatePostfix("589/6*-6-5+76/38*45/-6+*-") << endl;
	return 0;
}
