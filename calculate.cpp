#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function declarations
void runMenuSystem();
void estimateDriver();
double estimateEarnings(int, int, int, double, double, double);
void paymentDriver();
int paymentMonths(double, double, double);

int main() {
    runMenuSystem();
    return 0;
}

void runMenuSystem() {
    char menuChoice;

    while (true) {
        cout << "\n******* Welcome to Clementine Financial *******\n\n";
        cout << "Menu:\n";
        cout << "\t[E] Estimate how much money at retirement\n";
        cout << "\t[L] Loan payoff calculator\n";
        cout << "\t[Q] Quit program\n\n";

        cout << "Enter your choice and press enter: ";
        cin >> menuChoice;

        menuChoice = tolower(menuChoice);

        switch (menuChoice) {
            case 'e':
                estimateDriver();
                break;
            case 'l':
                paymentDriver();
                break;
            case 'q':
                cout << "Thank you for using Clementine Financial. Goodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void estimateDriver() {
    int firstAge, secondAge, retirementAge;
    double currSavings, monthlyPay, annualReturnPercentage;

    cout << "\nEstimate Savings at Retirement\n";
    cout << "Disclaimer: This is only a rough estimate!\n\n";

    do {
        cout << "\tEnter the first starting age in years: ";
        cin >> firstAge;
    } while (firstAge <= 0);

    do {
        cout << "\tEnter the second starting age in years: ";
        cin >> secondAge;
    } while (secondAge <= 0);

    do {
        cout << "\tEnter your target retirement age: ";
        cin >> retirementAge;
    } while (retirementAge <= firstAge || retirementAge <= secondAge);

    do {
        cout << "\tHow much have you saved already?: $";
        cin >> currSavings;
    } while (currSavings < 0);

    do {
        cout << "\tEnter your monthly contribution: $";
        cin >> monthlyPay;
    } while (monthlyPay <= 0);

    do {
        cout << "\tEnter the estimated annual return (in %): ";
        cin >> annualReturnPercentage;
    } while (annualReturnPercentage < 0);

    cout << "\nCalculating...\n\n";
    estimateEarnings(firstAge, secondAge, retirementAge, currSavings, monthlyPay, annualReturnPercentage);
}

double estimateEarnings(int firstAge, int secondAge, int retirementAge, double currSavings, double monthlyPay, double annualReturnPercentage) {
    cout << fixed << setprecision(2);
    int months1 = (retirementAge - firstAge) * 12;
    int months2 = (retirementAge - secondAge) * 12;
    double rate = annualReturnPercentage / 1200;

    auto calcSavings = [&](int months, double balance) {
        double growth = 0.0;
        for (int i = 0; i < months; ++i) {
            growth += balance * rate;
            balance += (balance * rate + monthlyPay);
        }
        return pair<double, double>{balance, growth};
    };

    auto [savings1, growth1] = calcSavings(months1, currSavings);
    cout << "Starting at age " << firstAge << ":\n";
    cout << "Estimated Retirement Savings: $" << savings1 << "\n";
    cout << "Estimated Retirement Growth: $" << growth1 << "\n\n";

    auto [savings2, growth2] = calcSavings(months2, currSavings);
    cout << "Starting at age " << secondAge << ":\n";
    cout << "Estimated Retirement Savings: $" << savings2 << "\n";
    cout << "Estimated Retirement Growth: $" << growth2 << "\n";

    double potential = abs(savings1 - savings2);
    int diffYears = abs(firstAge - secondAge);

    cout << "\n\nBy waiting " << diffYears << " years to start investing,\n";
    cout << "you may miss out on approximately $" << potential << "\n";

    char repeat;
    cout << "\nWould you like to calculate another estimate? (y/n): ";
    cin >> repeat;

    if (tolower(repeat) == 'y') estimateDriver();
    return savings1;
}

void paymentDriver() {
    double principal, rate, monthlyPayment;

    cout << "\nLoan Payment Calculator\n\n";
    cout << "Enter the principal amount: $";
    cin >> principal;

    cout << "Enter the annual interest rate (in %): ";
    cin >> rate;

    cout << "Enter your monthly payment: $";
    cin >> monthlyPayment;

    cout << "\nCalculating...\n\n";
    paymentMonths(principal, rate, monthlyPayment);
}

int paymentMonths(double principal, double rate, double monthlyPayment) {
    rate /= 1200;
    double months = log(monthlyPayment / (monthlyPayment - rate * principal)) / log(1 + rate);
    months = round(months);
    double years = months / 12;

    cout << fixed << setprecision(2);
    cout << months << " months (" << years << " years) are needed to pay off the loan.\n";

    double bonusPayment = monthlyPayment + 15;
    double bonusMonths = log(bonusPayment / (bonusPayment - rate * principal)) / log(1 + rate);
    bonusMonths = round(bonusMonths);

    cout << "By paying $15 more per month, you can pay off the loan " << (months - bonusMonths) << " months earlier.\n";

    char repeat;
    cout << "\nWould you like to calculate another loan payoff? (y/n): ";
    cin >> repeat;

    if (tolower(repeat) == 'y') paymentDriver();
    return static_cast<int>(months);
}
