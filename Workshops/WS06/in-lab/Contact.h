#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict
{
	class Contact
	{
	public: //Constructors - Destructors

		Contact();
		Contact(const char* name, const long long *phoneNumbers, int size);
		~Contact();

	private: // Private Members

		char m_name[20];
		long long* m_pPhoneNumbers;
		int m_size;

		void phoneNumberAllocation(const long long *phoneNumbers, int size);

	public: //public Members
		bool isEmpty() const;
		void display() const;
	};
}
#endif // !SICT_CONTACT_H
