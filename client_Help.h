#ifndef CLIENT_HELP_H_
#define CLIENT_HELP_H_
#include "client_Command.h"
#include "client_Encoder.h"

class Help: public Command {
public:
	explicit Help(Encoder &e);
	int encode() const override;
	virtual ~Help();
private:
	char command_type;
};

#endif /* CLIENT_HELP_H_ */
