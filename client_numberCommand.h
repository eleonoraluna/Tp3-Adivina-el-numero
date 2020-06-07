#ifndef CLIENT_NUMBERCOMMAND_H_
#define CLIENT_NUMBERCOMMAND_H_
#include "client_Command.h"

class numberCommand: public Command {
public:
	numberCommand(int number,Encoder &e);
	int encode() const override;
	virtual ~numberCommand();
private:
	char command_type;
	int number;
};

#endif /* CLIENT_NUMBERCOMMAND_H_ */
