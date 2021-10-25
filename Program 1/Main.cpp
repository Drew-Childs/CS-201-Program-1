//Drew Childs, Program 1
#include <iostream>
#include <iomanip>
using namespace std;

double calculateInterestRate(int credit_score) {		//function determines interest rate based off of credit score
	if (credit_score < 500) {
		return 0.05;
	}
	else if (credit_score >= 501 && credit_score <= 700) {
		return 0.02;
	}
	else {
		return 0.01;
	}
}

int main() {
	int price, down_payment = 0, credit_score;		//declaring variables
	char down_payment_initial;
	double interest_rate, monthly_payment, total_interest;

	cout << "Hello and welcome to the Interest Calculator" << endl << endl;

	cout << "-Please enter the price of your dream home: $";		//user enters price of home
	cin >> price;

	cout << endl << "-Are you making any down payments? [Y: Yes | N: No] ";		//collects if user is putting down a down payment
	cin >> down_payment_initial;
	down_payment_initial = toupper(down_payment_initial);

	if (down_payment_initial == 'Y') {		//if the user wants put down a down payment
		cout << endl << "-How much is your down payment? $";
		cin >> down_payment;

		while (down_payment >= price) {		//if down payment is larger than house price
			cout << "Please note that your down payment is bigger than the house price!" << endl;
			cout << "Enter a new down payment: $";
			cin >> down_payment;
		}
	}

	cout << endl << "-Please enter your credit score: ";		//determines credit_score
	cin >> credit_score;
	interest_rate = calculateInterestRate(credit_score);
	cout << "Based on your Credit Score, your interest rate is: " << interest_rate << endl << endl;

	for (int i = 10; i < 26; i++) {		//calculates and prints monthly payment and total interest
		monthly_payment = (((price - down_payment) * pow((1 + interest_rate), i)) / (12 * i));
		total_interest = (monthly_payment * i * 12) - (price - down_payment);
		cout << fixed << setprecision(2) << "Pay in " << i << "years, monthly payment is $" << monthly_payment << ".\tTotal interest $" << total_interest << endl;
	}

	cout << "Thank you for using our application!" << endl;

	return 0;
}