#include "client_numberCommand.h"

numberCommand::numberCommand(int number,Encoder &e):Command(e),
command_type('n'),number(number){}

int numberCommand::encode() const{
	this->myencoder.send_type(this->command_type);
	this->myencoder.send_number(this->number);
	bool keep_playing=this->myencoder.recv();
	if (!keep_playing){
		return 1;
	}
	return 0;
}

numberCommand::~numberCommand() {}

