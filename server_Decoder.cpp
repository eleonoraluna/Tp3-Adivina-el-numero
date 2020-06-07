#include <arpa/inet.h>
#include <utility>
#include <string>
#include "server_Decoder.h"

const int SIZE_INVALID_NUM=52;
const int SIZE_YOU_LOSE=8;
const int SIZE_YOU_WIN=7;
const int SIZE_ALL_BAD=5;
const int SIZE_ONLY_GOOD=6;
const int SIZE_ONLY_REGULAR=9;
const int SIZE_REGULAR_AND_GOOD=17;

Decoder::Decoder(Socket_TCP socket):socket(std::move(socket)) {}

char Decoder::rcv_type() const{
	//hago un rcv de 1 para ver que tipo de mensaje es
	char buffer[1];
	this->socket.recieve(buffer,sizeof(buffer));
	return buffer[0];
}

int Decoder::rcv_number() const{
	//recibo el numero que me mandan para adivinar
	std::uint16_t num=0;
	this->socket.recieve((char*)&num,2);
	num=ntohs(num);
	return num;
}

void Decoder::send_help() const{
	std::string buffer="Comandos válidos:\n\tAYUDA: despliega la lista de "
	"comandos válidos\n\tRENDIRSE: pierde el juego automáticamente\n\t"
	"XXX: Número de 3 cifras a ser enviado al servidor para adivinar el "
	"número secreto";
	this->send_string(buffer,buffer.size());
}

void Decoder::send_win() const{
	std::string buffer="Ganaste";
	this->send_string(buffer,SIZE_YOU_WIN);
}

void Decoder::send_lose() const{
	std::string buffer="Perdiste";
	this->send_string(buffer,SIZE_YOU_LOSE);
}

void Decoder::send_error() const{
	std::string buffer="Número inválido. Debe ser de 3 cifras no repetidas";
	this->send_string(buffer,SIZE_INVALID_NUM);
}

void Decoder::send_string(const std::string &buffer,int length) const{
	std::uint32_t len=htonl(length);
	this->socket.send((char*)&len,sizeof(len));
	this->socket.send(buffer.data(),buffer.size());
}

void Decoder::send_next_attempt(int good,int regular,int bad) const{
	std::string buff;
	if(bad!=0){
		std::string buffer="3 mal";
		this->send_string(buffer,SIZE_ALL_BAD);
	}else if (good!=0 && regular!=0){
		buff=std::to_string(good)+" bien, "+std::to_string(regular)+" regular";
		this->send_string(buff,SIZE_REGULAR_AND_GOOD);
	}else if (good!=0){
		buff=std::to_string(good)+" bien";
		this->send_string(buff,SIZE_ONLY_GOOD);
	}else {
		buff=std::to_string(regular)+" regular";
		this->send_string(buff,SIZE_ONLY_REGULAR);
	}
}

Decoder::~Decoder() {}

