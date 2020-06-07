#ifndef CLIENT_SURRENDER_H_
#define CLIENT_SURRENDER_H_
#include "client_Command.h"

class Surrender: public Command {
public:
	explicit Surrender(Encoder &e);
	int encode() const override;
	virtual ~Surrender();
private:
	char command_type;
};

#endif /* CLIENT_SURRENDER_H_ */
