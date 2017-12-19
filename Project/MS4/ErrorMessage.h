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
		explicit ErrorMessage(const char* errorMessage = nullptr);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		virtual ~ErrorMessage();

		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};

	ostream& operator<<(ostream& os, const ErrorMessage& message);

}
#endif // !SICT_ERRORMESSAGE_H
