#include <iostream>
#include "server_Printer.h"

Printer::Printer(Statistics &statistics):statistics(statistics) {}

void Printer::print(){
	 std::cout<<"Estadísticas:"<<std::endl;
	 std::cout<<"	Ganadores:  "<<this->statistics.get_winners()<<std::endl;
	 std::cout<<"	Perdedores: "<<this->statistics.get_losers()<<std::endl;
}

Printer::~Printer() {}

