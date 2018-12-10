#include "Date.h"
#include <time.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <sstream> 
#include <cstring>
#include <cstdlib>

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

bool Date::operator==(Date t){
	if(time_string == t.time_string)
		return true;
	else
		return false;
}

void Date::set_date(std::string time_string){
	std::cout << "Inside" << std::endl;
	struct tm * timeinfo_struct;
	time_t rawtime;
	timeinfo_struct = localtime ( &rawtime );
	std::vector<std::string> result;
	std::vector<int> result_int;
	std::istringstream iss(time_string);
    for(std::string time_string ; iss >> time_string; ){
        result.push_back(time_string);
    }

    for (int i=0; i<result.size(); i++){
    	std::cout << result[i] << std::endl;
	}
	for (int i=0; i<result.size(); i++){
    	result_int.push_back(std::atoi(result[i].c_str()));
	}
	std::cout << "tm struct atribution" << std::endl;
	//std::cout << timeinfo_struct->tm_sec << std::endl;
	//timeinfo_struct->tm_sec = 47; //result_int[0];
	/*timeinfo_struct->tm_min = result_int[1];
	timeinfo_struct->tm_hour = result_int[2];
	timeinfo_struct->tm_mday = result_int[3];
	timeinfo_struct->tm_mon = result_int[4];
	timeinfo_struct->tm_year = result_int[5];
	timeinfo_struct->tm_wday = result_int[6];
	timeinfo_struct->tm_yday = result_int[7];
	timeinfo_struct->tm_isdst = result_int[8];*/
    std::cout << "Before mktime" << std::endl;
    date_stored = mktime(timeinfo_struct);
    std::cout << "End" << std::endl;
}

struct tm * Date::get_structtm() const{
	struct tm * timeinfo_struct;
	timeinfo_struct = localtime(&date_stored); 
	return timeinfo_struct;
}
