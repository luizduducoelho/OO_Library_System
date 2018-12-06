#ifndef DATE_H
#define DATE_H

#include <string.h>
#include <time.h>
#include <string>

class Date
{
		std::string time_string;
	public:
		Date();
		std::string get_date();
};

#endif
