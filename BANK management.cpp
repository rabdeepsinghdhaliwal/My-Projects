#include<iostream>
#include<string>       //Features to be added as the transaction history using file handling
#include<thread>       //thre are certain other features that I can add 
#include<chrono>
using namespace std;
class customer
{
private:
	int account_number;
	string name;
	int balance;

public:
	//constructor for the details by default.
	customer(int account_number=00000, const string& str = "Invalid name", int balance = 0)
	{
		this->balance = balance;
		this->name = str;
		this->account_number = account_number;
	}
	//following are the mutator functions for accessing and storing the class data variables
	void set_acc_number(int a)
	{
		account_number = a;
	}
	int get_acc_number()
	{
		return account_number;
	}
	void set_name(const std::string& str)
	{
		name = str;     //copying the string named str in the private data type name.
	}
	string get_name()
	{
		return name;
	}
	void set_balance(int d)
	{
		balance = d;
	}
	int get_balance()
	{
		return balance;
	}
	friend string loan_eligibility_criteria(int income);
};
//creating a friend function
string loan_eligibility_criteria(int income)
{
	if (income < 15000)
		return "\nINCOME TOO LESS: You are not eligible for a loan";
	else if (income >= 15000 && income <= 50000)
	{
		return "\nEligible for the loans @6% p.a. interest";
	}
	else if (income >= 50000 && income <= 200000)
	{
		return "\nEligible for the loans @7.5% p.a. interest";
	}
	else if (income >= 200000 && income <= 1000000)
	{
		return "\nEligible for the loans @8.7%p.a. interest";
	}
	else
		return "\nEligible for the loans @15.2% p.a. interest";
}

int main()
{
	cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
	cout << "\n\n\n\t\t\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout << "\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
	this_thread::sleep_for(chrono::seconds(5));
	system("clear");
	//DO NOT FORGET THE PIN GENERATOR FOR THE TRANSACTION PROCESS 
	cout << "This is a menu driven program to provide various functions of a bank:";
	cout << "\nPlease enter your name: ";
	customer c1;
	string name;
	getline(cin, name);
	c1.set_name(name);
	//get the name displayed via the get_name() later on oin the details part of the menu mate.
	cout << "\nPlease enter your account number: ";
	int account_num;
	cin >> account_num;
	c1.set_acc_number(account_num);
	cout << "\nPlease enter the initial amount present at the time of the FIRST DEPOSIT: ";
	int balances;
	cin >> balances;
	c1.set_balance(balances);
	//PIN GENERATOR
	/*cout << "\nThis is the ssegment of the system which will help you develop a PIN for your transactions part to be carried out";
	string* pin = new string;
	cout << "\nPlease enter a password/PIN for using the transfer option: ";
	cin >> *pin; //Its a pointer Do Not use the   .   while calling the function.
	for (int i = 0; i < pin->length(); i++)
	{
		if()
	}*/
    cout << "\nThe options are:-\n1.> Bank details\n2.> Money withdrawl\n3.> Money deposit\n4.> Loan\n5.>Transactions\n6.>Fixed Deposit";
	cout << "\nPlease enter the menu index of the functions from the following menu options mate:- ";
	int option;
	cin >> option;
	switch (option)
	{
	case 1:
	{   cout << "\nPlease enter your account number: ";
		int acc;
		cin >> acc;
		if (acc == account_num)
		{
			cout << "\nName = " << c1.get_name();
			cout << "\nAccount number = " << c1.get_acc_number();
			cout << "\nBalance: " << c1.get_balance();
		}
		else { cout << "\nINVALID ACCOUNT NUMMBER -> does not match the account number that was previously entered"; }
		break;
	}

	case 2:
	{	cout << "\nThis is for the withdrawl of the money mate";
	    cout << "\nPlease enter the amount of money you wish to withdraw from your account: ";
	    int withdrawl_amt;
	    cin >> withdrawl_amt;
	    if (withdrawl_amt < 0 && withdrawl_amt>balances)
	    {
		   cout << "\nINVALID WITHDRAWL AMOUNT: The amount to be withdrawn cannot be less than 0  ";
	    }
	    else
	    {
		   int s = c1.get_balance();
		   int* amt = new int;
	 	   *amt = withdrawl_amt;
		   cout << "\nWithdrawn amount = " << withdrawl_amt;
		   balances = balances - *amt;
		   c1.set_balance(balances);
		   cout << "\namount left: " << c1.get_balance();
		   delete amt;
	}
	break;
	}
	case 3:
	{	 cout << "\nThis is the place/part where we deposit the money mate: ";
	     cout << "\nPlease enter the amount that you wish to deposit in your account: ";
	     int* n = new int;
	     cin >> *n;
	     balances += *n;
	     c1.set_balance(balances);
	     cout << "\nThe new balance will be: " << c1.get_balance();
	     delete n;
	     break;
	}
	case 4: 
	{
		cout << "\nThis is the place where you can get loans mate: ";
		if (c1.get_balance() >= 0 && c1.get_balance() <= 2000)
		{
			cout << "\nThe balance in your account is too less for loan eligibility";
		}
		else
		{
			cout << "\nPlease enter your monthly income for the loan eligibility criteria evaluation: ";
			float* income = new float;
			cin >> *income;
			//I CAN USE THE TRY AND THROW ALSO HERE BUT THEY ARE GENERALLY USED FOR THE DISCREPENCIES THAT ARISE DURING THE FUNCTIONS EXECUTION IN A PROGRAM
			string* str = new string;
			*str = loan_eligibility_criteria(*income);
			cout << loan_eligibility_criteria(*income);  //BROO YOU HAVE TO GET THE RESULTS FROM A RETURN STATEMENT OF A FUNCTIONS PRINTED, PLEASE TAKE A SIMPLE EXAMPLE IF YOU CANT REMEMBER THIS SHIT.
			if (*str == "\nINCOME TOO LESS: You are not eligible for a loan")
			{
				cout << "\n" << *str;
			}
			else if (*str == "\nEligible for the loans @6% p.a. interest")
			{
				cout << "\nEnter the loan amount: ";
				float* loan_amt = new float;
				cin >> *loan_amt;
				cout << "\nThe interest that you will have to pay along with the loan amount after a year will be: ";
				float* interest = new float;
				*interest = ((6.0f) / 100) * (*loan_amt);
					cout << *interest;
					delete interest;
					delete loan_amt;
			}
			else if (*str == "\nEligible for the loans @7.5% p.a. interest")
			{
				cout << "\nEnter the loan amount: ";
				float* loan_amt = new float;
				cin >> *loan_amt;
				cout << "\nThe interest that you will have to pay along with the loan amount after a year will be: ";
				float* interest = new float;
				*interest = ((7.5f) / 100) * (*loan_amt);
				cout << *interest;
				delete interest;
				delete loan_amt;
			}
			else if (*str == "\nEligible for the loans @8.7%p.a. interest")
			{
				cout << "\nEnter the loan amount: ";
				float* loan_amt = new float;
				cin >> *loan_amt;
				cout << "\nThe interest that you will have to pay along with the loan amount after a year will be: ";
				float* interest = new float;
				*interest = ((8.7f) / 100) * (*loan_amt);
				cout << *interest;
				delete interest;
				delete loan_amt;
			}
			else if (*str == "\nEligible for the loans @15.2% p.a. interest")
			{
				cout << "\nEnter the loan amount: ";
				float* loan_amt = new float;
				cin >> *loan_amt;
				cout << "\nThe interest that you will have to pay along with the loan amount after a year will be: ";
				float* interest = new float;
				*interest = ((15.2f) / 100) * (*loan_amt);
				cout << *interest;
				delete interest;
				delete loan_amt;
			}
			delete str;
		} 
		break;
	}
	case 5:
	{
		cout << "\nThis is where the transactions will be taken care of mate: ";
		if (balances <= 0 || balances <= 500)
		{
			cout << "\nThe minimum balance required for the transaction process to be executed is 500 ";
		}
		else
		{
			cout << "\nEnter your account number: ";
			int* acc = new int;
			cin >> *acc;

			if (*acc != c1.get_acc_number())
			{
				system("clear");
				cout << "\nYour account number that you have entered is INVALID";
				for (int i = 1; i <= 10; i++)
				{
					cout << "\n\nProcess terminated" << flush;
					this_thread::sleep_for(chrono::seconds(1));  //pauses the execution of the program for 10 seconds.
					cout << "\r                        " << flush;
					this_thread::sleep_for(chrono::seconds(1));
				}
				delete acc;
				return 0;
			}
			else
			{
				int* acc2 = new int;
				*acc2 = *acc;
				delete acc;
				acc = nullptr;

				cout << "\nPlease enter the account number of the depositor: ";
				int depositorAcc;  // New variable to store depositor's account number
				cin >> depositorAcc;

				cout << "\nEnter the amount to be transferred: ";
				int* ptr = new int;
				cin >> *ptr;

				// PIN from the pin generator
				cout << "\nThe amount will be transferred to the account number " << depositorAcc << " from the account number " << *acc2 << " within the next working 24 hours";

				delete acc2;
				delete ptr;
			}
		}
		break;
	}
	case 6:
	{
		cout << "\nThis is the interest calculator for the fixed deposit that the customer can make inside the acccount so created";
		int* fd_amount = new int;
		cout << "\nPlease enter the amount that you want to create/submit in the fixed deposit: ";
		cin >> *fd_amount;
		cout << "\nThe rate of interest that you will get is about 5% per annum of the principle amount that you have entered.";
		cout << "\nThe interest can be generated in a span of 10 years i.e. an f.d. will be created for 10 years will be :  ";
		float* net_interest = new float;
		*net_interest = (5.0f / 100) * (*fd_amount);
		*net_interest *= 10;
		cout << *net_interest;
		delete net_interest;
		delete fd_amount;
        break;
	}


    }
	return 0;
}

