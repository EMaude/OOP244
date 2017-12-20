//Elliot Maude
//032830127

#ifndef SICT_ERRORMESSAGE_H
#define SICT_ERRORMESSAGE_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

namespace sict
{
	class ErrorMessage
	{
	private:
		char* m_message;

	public:
		explicit ErrorMessage(const char* errorMessage = nullptr); //If nullptr puts obj in safte empty state
		ErrorMessage(const ErrorMessage& em) = delete; 
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		virtual ~ErrorMessage();

		void clear(); //clears any stored message
		bool isClear() const; //reports true if object is empty
		void message(const char* str); // sets message
		const char* message() const; //gets message
	};

	ostream& operator<<(ostream& os, const ErrorMessage& message); //sends message to ostream

}
#endif // !SICT_ERRORMESSAGE_H
