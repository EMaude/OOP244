#ifndef SICT_PERISHABLE_H
#define SICT_PERISHABLE_H

#include <iostream>
#include <iomanip>
#include <cstring>

#include "NonPerishable.h"
#include "Date.h"
#include "Product.h"

namespace sict
{
	class Perishable : public NonPerishable
	{
	private:
		Date m_expiry;

	public:
		//Constructors
		Perishable();
		~Perishable();

		//IO
		std::fstream& store(std::fstream& file, bool newline = true) const; //stores data to file
		std::fstream& load(std::fstream& file); //loads data from fstream
		std::ostream& write(std::ostream& os, bool linear) const; //outputs data to ostream
		std::istream& read(std::istream& is); //reads data from ostream

		//Other
		const Date& expiry() const;
	};

	//Helper
	Product* CreatePerishable();

}
#endif // !SICT_PERISHABLE_H

