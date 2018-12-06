#include "Date.h"
#include <time.h>
#include <string>

Date::Date(){
	now = time(0);
	char str_buffer[26];
	std::string timestamp(ctime(&now));
	time_string = timestamp;
}

Date::Date(time_t some_date){
	now = some_date;
	char str_buffer[26];
	std::string timestamp(ctime(&now));
	time_string = timestamp;
}

std::string Date::get_date(){
	return time_string;
}


