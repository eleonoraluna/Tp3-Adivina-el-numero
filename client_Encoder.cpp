#include <iostream>
#include <cstdint>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "client_Encoder.h"

const int SIZE_TYPE=1;

Encoder::Encoder(const std::string &name, const std::string &port) {
	this->socket.connect(name,port);
}

void Encoder::send_number(int number) const{
	 std::uint16_t buffer=number;
	 buffer=htons(buffer);
	 this->socket.send((char*)&buffer,sizeof(buffer));
}

void Encoder::send_type(char type) const{
	 std::uint8_t buffer=type;
	 this->socket.send((char*)&buffer,SIZE_TYPE);
}

int Encoder::recv() const{
	 std::uint32_t length=0;
	 int keep_playing=0;
	 this->socket.recieve((char*)&length,sizeof(length));
	 length=ntohl(length);
	 char* buffer=(char*)calloc(length+1,1);
	 this->socket.recieve(buffer,length);
	 std::cout<<buffer<<std::endl;
	 if (strcmp(buffer,"Perdiste")==0||strcmp(buffer,"Ganaste")==0){
		keep_playing=1;
	 }
	 free(buffer);
	 return keep_playing;
}

Encoder::~Encoder() {}

