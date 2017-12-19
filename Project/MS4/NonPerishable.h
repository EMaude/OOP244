#ifndef SICT_NONPERISHABLE_H
#define SICT_NONPERISHABLE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "ErrorMessage.h"
#include "Product.h"


namespace sict
{
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double taxRate = 0.13;

	class NonPerishable : public Product
	{
	private:
		char m_type;
		char m_sku[max_sku_length + 1];
		char m_unit[max_unit_length + 1];
		char* m_name;
		int m_qty;
		int m_qtyNeeded;
		double m_price;
		bool m_taxable;
		ErrorMessage m_errorState;

	protected:
		//Protected Functions
		void name(const char*); //sets product name
		const char* name() const; //gets product name
		double cost() const; // returns price + tax;
		void message(const char *); //Sets the error message
		bool isClear() const; // returns the state of the error message
	
	public:
		
		//CONSTRUCTORS
		
		NonPerishable();
		NonPerishable(const char* sku, const char* name, const char* unit, int qty = 0, bool tax = true, double price = 0.0, int qty_needed = 0);
		NonPerishable(const NonPerishable&);
		NonPerishable& operator=(const NonPerishable&);
		~NonPerishable();

		//IO
		
		std::fstream& store(std::fstream& file, bool newLine=true) const; //put current object data to fstream
		std::fstream& load(std::fstream& file); //extracts record from fstream
		std::ostream& write(std::ostream& os, bool linear) const; // writes data of object out to ostream
		std::istream& read(std::istream& is); //gets data from istream

		//OTHER

		bool operator==(const char*) const; //check if the string matched the sku
		double total_cost() const; //total cost of the current stock of item
		void quantity(int qty); //set current quntity
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const; //returns if the sku is greater than the string or not
		int operator+=(int qty); //add qty to m_qty and returns updated result;
		bool operator>(const Product&) const; //returns if the name of the current product is greater than that of the recived product
	};

	//Helper Functions
	std::ostream& operator<<(std::ostream&, const Product&); //helper for the write function
	std::istream& operator>>(std::istream&, const Product&); //helper for the read function
	double operator+=(double&, const Product&); //add totalcost of product to the double recived
	Product* CreateProduct(); //creates a new object in dynamic memory
}

#endif