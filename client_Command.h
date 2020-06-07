#ifndef CLIENT_COMMAND_H_
#define CLIENT_COMMAND_H_
#include "client_Encoder.h"

class Command {
public:
	explicit Command(Encoder &e);
	virtual int encode()const=0;
	virtual ~Command();
protected:
	Encoder &myencoder;
};

#endif /* CLIENT_COMMAND_H_ */
