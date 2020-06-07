#ifndef CLIENT_ENCODER_H_
#define CLIENT_ENCODER_H_
#include "common_SocketTCP.h"
#include <string>

class Encoder {
public:
	explicit Encoder(const std::string &name, const std::string &port);
	void send_type(char type) const;
	void send_number(int number) const;
	bool recv() const;
	virtual ~Encoder();
private:
	Socket_TCP socket;
};

#endif /* CLIENT_ENCODER_H_ */
