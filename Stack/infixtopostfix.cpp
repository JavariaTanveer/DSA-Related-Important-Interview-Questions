int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
Stack<int> evaluating(string infix)
{
	Stack<int> ss(10);
	int operand1;
	int operand2;
	for (int i = 0; infix[i] != '\0'; i++)
	{
		if (infix[i] >= '0'&&infix[i] <= '9')
		{
			int n = infix[i];
			n = n - 48;
			ss.push(n);
		}
		else
		{
			operand2 = ss.pop();
			operand1 = ss.pop();
			if (infix[i] == '+')
			{
				ss.push(operand1 + operand2);
			}
			else if (infix[i] == '-')
			{
				ss.push(operand1 - operand2);
			}
			else if (infix[i] == '*')
			{
				ss.push(operand1 * operand2);
			}
			else if (infix[i] == '/')
			{
				ss.push(operand1 / operand2);
			}

		}
	}
	return ss;
}

void infixToPostfix(string s)
{

	Stack<char> st; // For stack operations, we are using
					// C++ built in stack
	string result;

	for (int i = 0; i < s.length(); i++) {
		//char c = s[i];

		// If the scanned character is
		// an operand, add it to output string.
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
			|| (s[i] >= '0' && s[i] <= '9'))
			result =result+ s[i];

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (s[i] == '(')
			st.push('(');

		// If the scanned character is an ‘)’,
		// pop and to output string from the stack
		// until an ‘(‘ is encountered.
		else if (s[i] == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		// If an operator is scanned
		else {
			while (!st.isEmpty()
				&& prec(s[i]) <= prec(st.top())) {
				if (s[i] == '^' && st.top() == '^')
				{	
					result += st.top();
					st.pop();
				}
				else {
					result += st.top();
					st.pop();
				}
			}
			st.push(s[i]);
		}
	}

	// Pop all the remaining elements from the stack
	while (!st.isEmpty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}
