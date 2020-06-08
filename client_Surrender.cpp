#include "client_Surrender.h"

Surrender::Surrender(Encoder &e):Command(e),command_type('s'){}

int Surrender::encode() const{
	this->myencoder.send_type(this->command_type);
	return (this->myencoder.recv());
}

Surrender::~Surrender() {}

