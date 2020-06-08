#ifndef CLIENT_SURRENDER_H_
#define CLIENT_SURRENDER_H_
#include "client_Command.h"

class Encoder;

class Surrender: public Command {
public:
	explicit Surrender(Encoder &e);

	//retorna 1 ya que siempre se pierde con este comando
	int encode() const override;

	virtual ~Surrender();
private:
	char command_type;
};

#endif /* CLIENT_SURRENDER_H_ */
