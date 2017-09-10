#include <iostream>
#include "Transaction.h"

using namespace std;

void enter(Transaction * tr)
{
	cout << "Enter  the account number: ";
	cin >> tr->acct;
	cout << "Enter the account type (d - debit, c - credit): ";
	cin >> tr->type;
	cout << "Enter the account amount: ";
	cin >> tr->amount;
}

void display(const Transaction * tr)
{
	cout << "Account " << tr->acct;
	cout << ((tr->type == 'd') ? " Debit $" : " Credit $") << tr->amount;
	cout << endl;
}
