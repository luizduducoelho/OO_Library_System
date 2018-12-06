#ifndef DATE_H
#define DATE_H

#include <string.h>
#include <time.h>
#include <string>

class Date
{		time_t now;
		std::string time_string;
	public:
		Date();
		Date(time_t some_date);
		std::string get_date();
};

#endif
