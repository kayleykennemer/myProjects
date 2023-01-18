//This program calculates the balance of a savings account at the end of a month period.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int accountNumber;
	double currentBalance;
	double newBalance;
	int accountType;
	double interestRate;
	double interestPaid;

	ifstream inputFile;
	inputFile.open("C:\\Users\\Michael\\Desktop\\Patrick's CMPS HW\\bank.dat");
	ofstream outputFile;
	outputFile.open("report.txt");
	
	cout << "Now writing the information to the file." << endl;

	if (inputFile.fail())
	{
		cout << "Error opening input file.\n";

	}

	else if (outputFile.fail())
	{
		cout << "Error opening file.\n";
	}

	else
	{	inputFile >> accountNumber >> currentBalance >> accountType;
		
		outputFile << "          Bank  Ruptcy- Account Balances           " << endl;
		outputFile << "Account number  Current  Interest Paid  New Balance" << endl;
		outputFile << "---------------------------------------------------" << endl;

		while (!inputFile.eof())
		{
			if (accountType == 1)
			{
				interestRate = .06 / 12;
				interestPaid = interestRate * currentBalance;
				newBalance = interestPaid + currentBalance;
				outputFile << setw(15) << accountNumber;
				outputFile << setw(9) << currentBalance;
				outputFile << fixed << showpoint << setprecision(2) << setw(15) << interestPaid;
				outputFile << setw(12) << newBalance << endl;
			}
				
			else if (accountType == 2)
			{
				interestRate = .04 / 12;
				interestPaid = interestRate * currentBalance;
				newBalance = interestPaid + currentBalance;
				outputFile << setw(15) << accountNumber;
				outputFile << setw(9) << currentBalance;
				outputFile << fixed << showpoint << setprecision(2) << setw(15) << interestPaid;
				outputFile << setw(12) << newBalance << endl;
			}

			else if (accountType == 3)
			{
				interestRate = .025 / 12;
				interestPaid = interestRate * currentBalance;
				newBalance = interestPaid + currentBalance;
				outputFile << setw(15) << accountNumber;
				outputFile << setw(9) << currentBalance;
				outputFile << fixed << showpoint << setprecision(2) << setw(15) << interestPaid;
				outputFile << setw(12) << newBalance << endl;
			}

			else if (accountType == 4)
			{
				interestRate = .012 / 12;
				interestPaid = interestRate * currentBalance;
				newBalance = interestPaid + currentBalance;
				outputFile << setw(15) << accountNumber;
				outputFile << setw(9) << currentBalance;
				outputFile << fixed << showpoint << setprecision(2) << setw(15) << interestPaid;
				outputFile << setw(12) << newBalance << endl;
			}
			
			inputFile >> accountNumber >> currentBalance >> accountType;

		}
	}

	inputFile.close();
	outputFile.close();
	cout << "Done." << endl;
	cin >> accountNumber;

}