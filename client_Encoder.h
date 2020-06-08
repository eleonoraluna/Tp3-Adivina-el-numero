#ifndef CLIENT_ENCODER_H_
#define CLIENT_ENCODER_H_
#include "common_SocketTCP.h"
#include <string>

class Encoder {
public:
	explicit Encoder(const std::string &name, const std::string &port);

	//envía el tipo de comando
	void send_type(char type) const;

	//envía el numero a adivinar en un unsigned de 2 bytes en big endian
	void send_number(int number) const;

	//recibe los mensajes del servidor
	//si recibe un "Ganaste" o "Perdiste" retorna 1
	//sino 0
	int recv() const;
	virtual ~Encoder();
private:
	Socket_TCP socket;
};

#endif /* CLIENT_ENCODER_H_ */
