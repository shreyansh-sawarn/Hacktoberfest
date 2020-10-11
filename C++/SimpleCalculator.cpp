// Used to calculate two numbers
// Select addition, subtraction, multiplication, or division

#include <iostream>
using namespace std;

int main() {
	int selection;
	double num1, num2;
	string continuing;
	
	do {
		cout << "Please input the first number: " << endl;
		cin >> num1;

		cout << "Please input the second number: " << endl;
		cin >> num2;

		cout << "Please input the # to make your selection: " << endl;
		cout << "-- 1. Adding " << num1 << " and " << num2 << endl;
		cout << "-- 2. Subtracting " << num1 << " and " << num2 << endl;
		cout << "-- 3. Multiplying " << num1 << " and " << num2 << endl;
		cout << "-- 4. Dividing " << num1 << " and " << num2 << endl;
		cin >> selection;

		switch (selection) {
		case 1:
			cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
			break;
		case 2:
			cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
			break;
		case 3:
			cout << num1 << " x " << num2 << " = " << num1 * num2 << endl;
			break;
		case 4:
			cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
			break;
		default:
			cout << "Invalid input. Try again." << endl;
		}

		cout << "Would you like to compute another pair of numbers?" << endl;
		cout << "Input 'yes' or 'no'" << endl;
		cin >> continuing;

	} while (continuing != "no");

	cout << "Thank you for using the simple calculator.";

	return 0;
}