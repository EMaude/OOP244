#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict
{
	class Contact
	{
	public: //Constructors - Destructors

		Contact();
		Contact(const char* name, const long long *phoneNumbers, int size);
		Contact(Contact&);
		~Contact();

	private: // Private Members

		char m_name[20];
		long long* m_pPhoneNumbers;
		int m_size;

		void phoneNumberAllocation(const long long *phoneNumbers, int size);

	public: //public Members
		bool isEmpty() const;
		void display() const;

		Contact& operator=(Contact&);
		Contact& operator+=(long long nPhoneNumber);

	};
}
#endif // !SICT_CONTACT_H
