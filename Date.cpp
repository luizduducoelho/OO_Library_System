#include "Date.h"
#include <time.h>
#include <string>

Date::Date(){
	time_t now = time(0);
	char str_buffer[26];
	std::string timestamp(ctime(&now));
	time_string = timestamp;
}

std::string Date::get_date(){
	return time_string;
}


