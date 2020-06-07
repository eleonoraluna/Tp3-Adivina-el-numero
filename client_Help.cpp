#include "client_Help.h"

Help::Help(Encoder &e):Command(e),command_type('h'){}

int Help::encode() const{
	this->myencoder.send_type(this->command_type);
	this->myencoder.recv();
	return 0;
}

Help::~Help() {}

