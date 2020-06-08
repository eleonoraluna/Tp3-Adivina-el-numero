#ifndef CLIENT_HELP_H_
#define CLIENT_HELP_H_
#include "client_Command.h"

class Encoder;

class Help: public Command {
public:
	explicit Help(Encoder &e);

	//retorna siempre 0 ya que no puede ganar ni perder con este comando
	int encode() const override;

	virtual ~Help();
private:
	char command_type;
};

#endif /* CLIENT_HELP_H_ */
