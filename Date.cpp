#include "Date.h"
#include <time.h>
#include <string>

Date::Date(){
	date_stored = time(0);
	char str_buffer[26];
}

Date::Date(time_t some_date){
	date_stored = some_date;
}

std::string Date::get_date() const {
	std::string timestamp(ctime(&date_stored));
	return timestamp;
}

void Date::adiciona_dias(int d){
	struct tm * timeinfo_struct;
	timeinfo_struct = localtime(&date_stored);   // Convert time to struct
	timeinfo_struct->tm_mday += d;
	date_stored = mktime (timeinfo_struct);		 // Convert struct back to time
}

