#ifndef DATE_H
#define DATE_H

#include <string.h>
#include <time.h>
#include <string>

class Date
{		time_t date_stored;
		std::string time_string;
	public:
		Date();
		Date(time_t some_date);
		std::string get_date() const;
		void adiciona_dias(int d);
		void set_date(std::string time){std::string time_string = time;}
};

#endif
