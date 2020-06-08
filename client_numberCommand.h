#ifndef CLIENT_NUMBERCOMMAND_H_
#define CLIENT_NUMBERCOMMAND_H_
#include "client_Command.h"

class Encoder;

class numberCommand: public Command {
public:
	numberCommand(int number,Encoder &e);

	//retorna 1 si el encoder recibe un "Ganaste" o "Perdiste"
	//sino devuelve 0
	int encode() const override;

	virtual ~numberCommand();
private:
	char command_type;
	int number;
};

#endif /* CLIENT_NUMBERCOMMAND_H_ */
