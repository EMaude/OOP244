#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include <iostream>
//Abstract Base Class
namespace sict
{
	class Product {
		virtual std::fstream& store(std::fstream file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& load(std::istream& is) = 0;
		virtual bool operator==(const char*) const = 0;
		virtual double total_Cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual void quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const Product&) const = 0;
	};

	//Helper Functions
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();
	Product* CreatePerishable();
}
#endif // !SICT_PRODUCT_H