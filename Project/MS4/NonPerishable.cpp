#include "NonPerishable.h"

using namespace std;

namespace sict
{
	//Protected
	void NonPerishable::name(const char* in)
	{
		if(m_name != nullptr) //delete old stuff if there is any
		{
			delete[] m_name;
			m_name = nullptr;
		}
		if(in != nullptr) 
		{
			int size = strlen(in) + 1;
			m_name = new char[size];
			strcpy(m_name, in);
		}
	}
	const char* NonPerishable::name() const
	{
		return m_name;
	}
	double NonPerishable::cost() const
	{
		return (m_taxable) ? ((m_price * taxRate) + m_price) : m_price;
	}
	void NonPerishable::message(const char *in)
	{
		m_errorState.message(in);
	}
	bool NonPerishable::isClear() const
	{
		return m_errorState.isClear();
	}

	//Constructors
	NonPerishable::NonPerishable()
	{
		m_type = 'N';
		strcpy(m_sku, "0");
		strcpy(m_unit, "0");
		m_name = nullptr;
		m_qty = 0;
		m_qtyNeeded = 0;
		m_price = 0;
		m_taxable = true;
		ErrorMessage ErrorState(" ");
	}
	NonPerishable::NonPerishable(const char* sku, const char* name, const char* unit, int qty, bool tax, double price, int qty_needed)
	{
		if (sku != nullptr && name != nullptr && unit != nullptr)
		{
			strcpy(m_sku, sku);
			strcpy(m_unit, unit);
			m_name = nullptr;
			this->name(name);
			m_qty = qty;
			m_taxable = tax;
			m_price = price;
			m_qtyNeeded = qty_needed;
			ErrorMessage ErrorState(" ");
		}
		else
		{
			*this = NonPerishable();
		}
	}
	NonPerishable::NonPerishable(const NonPerishable &in)
	{
		m_name = nullptr;
		*this = in;
	}
	NonPerishable& NonPerishable::operator=(const NonPerishable &in)
	{
		if (this != &in)
		{
			strcpy(this->m_sku, in.m_sku);
			strcpy(this->m_unit, in.m_unit);
			this->name(in.m_name);
			this->m_qty = in.m_qty;
			this->m_taxable = in.m_taxable;
			this->m_price = in.m_price;
			this->m_qtyNeeded = in.m_qtyNeeded;
			this->m_errorState.message(in.m_errorState.message());
		}
		return *this;
	}
	NonPerishable::~NonPerishable()
	{
		delete[] m_name;
	}

	//IO
	std::fstream& NonPerishable::store(std::fstream& file, bool newLine) const
	{
		file << m_type << "," << m_sku << "," << m_name << "," << m_unit << "," << m_qty << "," << m_qtyNeeded << "," << m_price << "," << m_taxable << ",";

		if (newLine)
		{
			file << endl;
		}

		return file;
	}
	std::fstream& NonPerishable::load(std::fstream& file)
	{
		NonPerishable temp;
		if (file.is_open() && !file.eof())
		{
			file.get(m_type);
			file.ignore();
			file.getline(m_name, max_sku_length, ',');
			file.getline(m_name, max_name_length, ',');
			file.getline(m_unit, max_unit_length, ',');
			file >> m_qty >> m_qtyNeeded >> m_taxable;
		}
		*this = temp;
		return file;
	}
	std::ostream& NonPerishable::write(std::ostream& os, bool linear) const
	{
		if (linear)
		{
			os << setw(max_sku_length) << m_sku << "|";
			os << setw(20) << m_name << "|";
			os << setw(7) << cost() << "|";
			os << setw(4) << m_qty << "|";
			os << setw(10) << m_unit << "|";
			os << setw(4) << m_qtyNeeded << "|" << endl;
		}
		else
		{
			os << "Sku: " << m_sku << endl;
			os << "Name: " << m_name << endl;
			os << "Price: " << m_price << endl;
			if (m_taxable)
			{
				os << "Price after tax: " << cost() << endl;
			}
			else
			{
				os << "N/A" << endl;
			}
			os << "Quantity On Hand: " << m_qty << endl;
			os << "Quantity Needed: " << m_qtyNeeded << endl;
		}

		return os;
	}
	std::istream& NonPerishable::read(std::istream& is)
	{
		NonPerishable temp;
		char t;
		cout << "Sku: ";
		cin >> temp.m_sku;
		cout << "Name: ";
		cin >> temp.m_name;
		cout << "Unit: ";
		cin >> temp.m_unit;

		cout << "Taxed?(y/n): ";
		cin >> t;
		if (t == 'y' || t == 'Y')
		{
			temp.m_taxable = true;
		}
		else if (t == 'n' || t == 'N')
		{
			temp.m_taxable = false;
		}
		else
		{
			this->message("Only(Y)es or (N)o are acceptable");
			is.setstate(ios::failbit);
		}

		cout << "Price: ";
		cin >> temp.m_price;
		if (temp.m_price < 0.00)
		{
			this->message("Invalid Price Entry");
			is.setstate(ios::failbit);
		}

		cout << "Quantity on hand: ";
		cin >> temp.m_qty;
		if (temp.m_qty < 0)
		{
			this->message("Invalid Quantity Entry");
			is.setstate(ios::failbit);
		}

		cout << "Quantity Needed: ";
		cin >> temp.m_qtyNeeded;
		if (temp.m_qtyNeeded)
		{
			this->message("Invalid Quantity Needed Entry");
			is.setstate(ios::failbit);
		}

		if (!is.fail())
		{
			*this = temp;
		}

		return is;
	}

	//Other
	bool NonPerishable::operator==(const char* in) const
	{
		return strcmp(m_sku, in) == 0;
	}
	double NonPerishable::total_cost() const
	{
		return m_qty * cost();
	}
	void NonPerishable::quantity(int qty)
	{
		if (qty > 0)
		{
			m_qty = qty;
		}
	}
	bool NonPerishable::isEmpty() const
	{
		return strcmp(m_sku, "0") == 0;
	}
	int NonPerishable::qtyNeeded() const
	{
		return m_qtyNeeded;
	}
	int NonPerishable::quantity() const
	{
		return m_qty;
	}
	bool NonPerishable::operator>(const char* in) const
	{
		return strcmp(m_sku, in) > 0;
	}
	int NonPerishable::operator+=(int qty)
	{
		if (qty > 0)
		{
			m_qty += qty;
		}
		return m_qty;
	}
	bool NonPerishable::operator>(const Product &in) const
	{
		return strcmp(this->m_name, in.name()) > 0;
	}

	//Helper
	std::ostream& operator<<(std::ostream& os, const Product &in)
	{
		return in.write(os, true);
	}	
	std::istream& operator>>(std::istream& is, Product &in)
	{
		return in.read(is);
	}
	double operator+=(double& cost, const Product &in)
	{
		return cost = cost + in.total_cost();
	}
	Product* CreateProduct()
	{
		Product* newProduct;
		newProduct = new NonPerishable;
		return newProduct;
	}

}