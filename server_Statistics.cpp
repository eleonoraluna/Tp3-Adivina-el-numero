#include "server_Statistics.h"

Statistics::Statistics():winners(0),losers(0){}

void Statistics::add_winner(){
	 std::unique_lock<std::mutex> lock(this->m);
	 this->winners++;
}

void Statistics::add_loser(){
	 std::unique_lock<std::mutex> lock(this->m);
	 this->losers++;
}

int Statistics::get_winners() const{
	return(this->winners);
}

int Statistics::get_losers() const{
	return(this->losers);
}

Statistics::~Statistics() {}

