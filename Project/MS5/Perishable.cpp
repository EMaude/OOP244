#include "Perishable.h"

namespace sict
{
	//Constructers

	Perishable::Perishable() : NonPerishable('P')
	{
		m_expiry = Date();
	}
	Perishable::~Perishable()
	{
	}

	//IO

	std::fstream & Perishable::store(std::fstream& file, bool newline) const
	{
		NonPerishable::store(file, false);
		file << ",";
		m_expiry.write(file);
		if (newline)
		{
			file << endl;
		}
		return file;
	}
	std::fstream & Perishable::load(std::fstream & file)
	{
		NonPerishable::load(file);
		m_expiry.read(file);
		file.ignore();
		return file;
	}
	std::ostream & Perishable::write(std::ostream &os, bool linear) const
	{
		NonPerishable::write(os, linear);
		if (!m_expiry.isEmpty() || !m_expiry.bad())
		{
			if (linear)
			{
				os << m_expiry;
			}
			else
			{
				os << "Expiry date : ";
				os << m_expiry;
			}
		}
		return os;
	}
	std::istream& Perishable::read(std::istream &is)
	{
		NonPerishable::read(is);
		if (NonPerishable::isClear())
		{
			Date temp;
			cout << "Expiry date (YYYY/MM/DD): ";
			temp.read(is);

			if (!temp.bad())
			{
				m_expiry = temp;
			}
			else
			{
				is.setstate(ios::failbit);
				switch (temp.errCode())
				{
				case 1:
					NonPerishable::message("Invalid Date Entry");
					break;
				case 2:
					NonPerishable::message("Invalid Year in Date Entry");
					break;
				case 3:
					NonPerishable::message("Invalid Month in Date Entry");
					break;
				case 4:
					NonPerishable::message("Invalid Day in Date Entry");
					break;
				default:
					NonPerishable::message("Unknown Error");
					break;
				}
			}
		}
		return is;
	}

	//Other

	const Date& Perishable::expiry() const
	{
		return m_expiry;
	}
	
	//Helper

	Product* CreatePerishable()
	{
		Product* newProduct;
		newProduct = new Perishable;
		return newProduct;
	}
}