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
	if (date_stored == (long long int)NULL){
		return "";
	}
	std::string timestamp(ctime(&date_stored));
	return timestamp;
}

void Date::adiciona_dias(int d){
	struct tm * timeinfo_struct;
	timeinfo_struct = localtime(&date_stored);   // Convert time to struct
	timeinfo_struct->tm_mday += d;
	date_stored = mktime (timeinfo_struct);		 // Convert struct back to time
}

void Date::reset_date(){
	long long int  ptr = NULL;
	date_stored = ptr;
}

bool Date::operator==(Date t){
	if(time_string == t.time_string)
		return true;
	else
		return false;
}

void Date::calcula_data_penalizacao(Date data_prevista){
	double seconds;
	int dias_de_penalizacao;
	seconds = difftime(date_stored, data_prevista.date_stored);
	if (seconds > 0){
		dias_de_penalizacao = seconds/86400;
		adiciona_dias(dias_de_penalizacao*3);
	}
}

bool Date::verifica_penalizacao(){
	time_t now = time(0);
	double seconds;
	seconds = difftime(date_stored, now);
	if (seconds > 0){
		// Esta penalizado
		return false;
	}
	else{
		return true;
	}
}
