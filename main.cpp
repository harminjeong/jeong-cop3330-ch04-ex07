#include "std_lib_facilities.h"
vector<string> numbers;

void initialize_numbers()
{
	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");
	numbers.push_back("five");
	numbers.push_back("six");
	numbers.push_back("seven");
	numbers.push_back("eight");
	numbers.push_back("nine");
}

int get_number()
{
	const int not_a_symbol = numbers.size();
	int val = not_a_symbol;
	if (cin>>val) return val;
	cin.clear();
    string s;
	cin>>s;
	for (int i=0; i<numbers.size(); ++i)
		if (numbers[i]==s) val = i;
	if (val==not_a_symbol) error("unexpected number string: ",s);
	return val;
}

int main()
{
	initialize_numbers();

	cout<< "Enter two values separated by an operator: ";
	
	while (true) {
		int val1 = get_number();

		char op = 0;
		cin>>op;		
		int val2 = get_number();

		string oper;
		double result;

		switch (op) {
		case '+':
			oper = "The sum of ";
			result = val1+val2; 
			break;
		case '-':
			oper = "The difference between ";
			result = val1-val2; 
			break;
		case '*':
			oper = "The product of ";
			result = val1*val2; 
			break;
		case '/':
			oper = "The division of ";
			if (val2==0) error("Cannot divide by zero.");
			result = val1/val2; 
			break;

		default:
				error("bad operator");
		}
		cout << oper << val1 << " and " << val2 << " is " << result << '\n';
		cout << "Enter two values separated by an operator: ";
	}
}
