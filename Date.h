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
		void set_date(Date data_sistema){date_stored = data_sistema.date_stored;}
		void reset_date();
		bool operator==(Date d);
		void calcula_data_penalizacao(Date data_prevista);
		bool verifica_penalizacao();
};

#endif
