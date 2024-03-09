#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

// Global variables and constants
static bool headerWritten = false;
double loan_amount, yearly_interest_rate, years_of_finance, monthly_payment, monthly_interest_rate, number_of_payments;

// Function prototypes
void displayMenu();
void parameters(double& loan_amount, double& yearly_interest_rate, double& years_of_finance, string item, double min_purchase_amount);
void calculateCar(double loan_amount, double yearly_interest_rate, double years_of_finance);
void calculateAppliance(double loan_amount, double yearly_interest_rate, double years_of_finance);
void calculateHouse(double loan_amount, double yearly_interest_rate, double years_of_finance);
void fileboy(double loan_amount, double yearly_interest_rate, double years_of_finance, double monthly_payment, string item);

// Constants for minimum purchase amounts
const double CAR_MIN_PURCHASE_AMOUNT = 5000.0;
const double APPLIANCE_MIN_PURCHASE_AMOUNT = 100.0;
const double HOUSE_MIN_PURCHASE_AMOUNT = 150000.0;

int main() {

    ofstream outputFile("Full Scope.txt");

    char selection;

    do {

        displayMenu();

        cin >> selection;

        switch (toupper(selection)) {

        case 'C':
            parameters(loan_amount, yearly_interest_rate, years_of_finance, "Car", CAR_MIN_PURCHASE_AMOUNT);
            calculateCar(loan_amount, yearly_interest_rate, years_of_finance);
            fileboy(loan_amount, yearly_interest_rate, years_of_finance, monthly_payment, "Car");
            break;

        case 'A':
            parameters(loan_amount, yearly_interest_rate, years_of_finance, "Appliance", APPLIANCE_MIN_PURCHASE_AMOUNT);
            calculateAppliance(loan_amount, yearly_interest_rate, years_of_finance);
            fileboy(loan_amount, yearly_interest_rate, years_of_finance, monthly_payment, "Appliance");
            break;

        case 'H':
            parameters(loan_amount, yearly_interest_rate, years_of_finance, "House", HOUSE_MIN_PURCHASE_AMOUNT);
            calculateHouse(loan_amount, yearly_interest_rate, years_of_finance);
            fileboy(loan_amount, yearly_interest_rate, years_of_finance, monthly_payment, "House");
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;

        }

        cout << "\nDo you want to continue (Yes (Y) | No (N)): ";
        cin >> selection;

    } 
    
    while (toupper(selection) != 'N');

    outputFile.close();

    cout << "\nProgram terminated successfully. Thanks and have a nice day!!!\n";

    EXIT_SUCCESS;

}

void displayMenu() {
    cout << "\nWhat do you wish to finance today:\n";
    cout << "C. Finance a Car\n";
    cout << "A. Finance an Appliance\n";
    cout << "H. Finance a House\n";
    cout << "Enter your choice: ";
}

void parameters(double& loan_amount, double& yearly_interest_rate, double& years_of_finance, string item, double min_purchase_amount) {
    cout << "\n" << item << " Financing:\n";

    cout << "Loan Amount = ";
    cin >> loan_amount;

    // Input Validation
    while (loan_amount < min_purchase_amount) {

        cout << "\nWrong input. " << item << " purchase amount must be at least " << min_purchase_amount << ". Feel free to change your input.";
        cout << "\nLoan Amount = ";
        cin >> loan_amount;

    }

    cout << "\nYearly Interest Rate = ";
    cin >> yearly_interest_rate;

    // Input Validation
    while (yearly_interest_rate < 0) {

        cout << "\nWrong input. Yearly interest rate must be at least 0. Feel free to change your input.";
        cout << "\nYearly Interest Rate = ";
        cin >> yearly_interest_rate;

    }

    cout << "\nYears of Finance = ";
    cin >> years_of_finance;

    // Input Validation
    while (years_of_finance <= 0) {

        cout << "\nWrong input. Yearly must be greater than 0. Feel free to change your input.";
        cout << "\nYears of Finance = ";
        cin >> years_of_finance;

    }

}

void calculateCar(double loan_amount, double yearly_interest_rate, double years_of_finance) {
    
    monthly_interest_rate = (yearly_interest_rate / 12) / 100;

    number_of_payments = years_of_finance * 12;

    monthly_payment = (loan_amount * (pow((1 + monthly_interest_rate), number_of_payments)) * monthly_interest_rate) / (pow((1 + monthly_interest_rate), number_of_payments) - 1);

    cout << "\nMonthly Payment for Car = " << monthly_payment << "\n";
}

void calculateAppliance(double loan_amount, double yearly_interest_rate, double years_of_finance) {

    monthly_interest_rate = (yearly_interest_rate / 12) / 100;

    number_of_payments = years_of_finance * 12;

    monthly_payment = (loan_amount * (pow((1 + monthly_interest_rate), number_of_payments)) * monthly_interest_rate) / (pow((1 + monthly_interest_rate), number_of_payments) - 1);

    cout << "\nMonthly Payment for Appliance = " << monthly_payment << "\n";
}

void calculateHouse(double loan_amount, double yearly_interest_rate, double years_of_finance) {

    monthly_interest_rate = (yearly_interest_rate / 12) / 100;

    number_of_payments = years_of_finance * 12;

    monthly_payment = (loan_amount * (pow((1 + monthly_interest_rate), number_of_payments)) * monthly_interest_rate) / (pow((1 + monthly_interest_rate), number_of_payments) - 1);

    cout << "\nMonthly Payment for House = " << monthly_payment << "\n";
}

void fileboy(double loan_amount, double yearly_interest_rate, double years_of_finance, double monthly_payment, string item) {

    ofstream outputFile("Full Scope.txt", ios::app);

    outputFile << fixed << setprecision(2);

    if (!headerWritten) {

        outputFile << "Item Type |\t" << "Loan Amount |\t" << "Yearly Interest Rate |\t" << "Years of Finance |\t" << "Monthly Payment \n";
        outputFile << "=======================================================================================\n";
        headerWritten = true;

    }

    if (item == "Car") {

        outputFile << item << "\t\t\t\t" << loan_amount << "\t\t\t\t" << yearly_interest_rate << "\t\t\t\t" << years_of_finance << "\t\t\t\t" << monthly_payment << "\n";

    }

    else if (item == "House") {

        outputFile << item << "\t\t\t" << loan_amount << "\t\t\t" << yearly_interest_rate << "\t\t\t\t" << years_of_finance << "\t\t\t\t" << monthly_payment << "\n";
    }

    else {

        outputFile << item << "\t\t" << loan_amount << "\t\t\t\t" << yearly_interest_rate << "\t\t\t\t" << years_of_finance << "\t\t\t\t" << monthly_payment << "\n";
    }

    outputFile.close();
}