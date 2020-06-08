#ifndef SERVER_DECODER_H_
#define SERVER_DECODER_H_
#include <string>
#include "common_SocketTCP.h"

class Decoder {
public:
	explicit Decoder(Socket_TCP socket);

	//recibe el tipo de comando
	char rcv_type() const;

	//recibe el numero que ingreso el jugador
	int rcv_number() const;

	//envía los comandos de ayuda
	void send_help() const;

	//comunica al jugador que ganó
	void send_win() const;

	//comunica al jugador que perdió
	void send_lose() const;

	//envia mensaje de número inválido
	void send_error() const;

	//arma la respuesta correspondiente dependiendo cuantos aciertos tenga
	//y envia el mensaje
	void send_next_attempt(int good,int regular,int bad) const;

	virtual ~Decoder();

private:
	void send_string(const std::string &buffer,int length) const;
	Socket_TCP socket;
};

#endif /* SERVER_DECODER_H_ */
