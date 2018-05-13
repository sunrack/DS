#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool IsOperator(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '^':
			return true;

		default:
			return false;
	}
}

int precedence(char ch)
{
	switch(ch)
	{
		case '(':
			return 0;

		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
			return 2;

		case '^':
			return 3;

		case ')':
			return 10;

		default:
			return -1;
	}
}

// scan all char
// 		if operhand, directly output
// 		if operator:
// 				if (, stack
// 				if ), unstack and output operator until meet )  *( and ) don't need to output*
// 				if others, unstack and output operator until get a **lower** precedence one in stack, 
//         then stack current operator
//	unstack and output remaininng perators

// ** ( has the lowest precedence 
// ** ) has the greatest precedence

string ST_InfixToPostfix(string strInfix)
{
	string strPostfix;
	stack<char> st;

	for(unsigned int i=0; i<strInfix.size(); i++)
	{
		char ch = strInfix[i];

		if(!IsOperator(ch))
		{
			// if operhand, just output
			strPostfix += ch;
		}
		else
		{
			if(ch == '(')
			{
				st.push(ch);				
			}
			else if(ch == ')')
			{
				while(!st.empty() && st.top() != '(')
				{
					strPostfix += st.top();
					st.pop();
				}

				st.pop();			
			}
			else
			{
				// unstack operator until get a lower one
				while(!st.empty() && (precedence(st.top()) >= precedence(ch)))
				{
					if(st.top() != '(')
					{
						strPostfix += st.top();
					}
					
					st.pop();
				}

				// stack current operator
				st.push(ch);
			}
		}
	}

	// unstack all remaining operator
	while(!st.empty())
	{
		strPostfix += st.top();
		st.pop();
	}

	return strPostfix;
}

int main()
{
	string strInfix = "";
	string strPostfix = "";

	strInfix = "a+b-c*d+e";
	strPostfix = ST_InfixToPostfix(strInfix);

	cout<<strInfix<<endl;
	cout<<strPostfix<<endl<<endl;

		//------------------------------------------------------

	strInfix = "a+b*(c^d-e)^(f+g*h)-i";
	strPostfix = ST_InfixToPostfix(strInfix);

	cout<<strInfix<<endl;
	cout<<strPostfix<<endl<<endl;

	//------------------------------------------------------

	strInfix = "a+b*c+(d*e+f)*g";
	strPostfix = ST_InfixToPostfix(strInfix);

	cout<<strInfix<<endl;
	cout<<strPostfix<<endl<<endl;

}