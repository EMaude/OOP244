//Modular Example
//Transaction.h
#pragma once

struct Transaction
{
	int acct; //account number
	char type; // c - credit, d - debit
	double amount; //transaction amount
};

void enter(struct Transaction* tr);
void display(const struct Transaction* tr);