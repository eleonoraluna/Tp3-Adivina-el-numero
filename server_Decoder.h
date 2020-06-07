#ifndef SERVER_DECODER_H_
#define SERVER_DECODER_H_
#include <string>
#include "common_SocketTCP.h"

class Decoder {
public:
	explicit Decoder(Socket_TCP socket);
	char rcv_type() const;
	int rcv_number() const;
	void send_help() const;
	void send_win() const;
	void send_lose() const;
	void send_error() const;
	void send_next_attempt(int good,int regular,int bad) const;
	virtual ~Decoder();
private:
	void send_string(const std::string &buffer,int length) const;
	Socket_TCP socket;
};

#endif /* SERVER_DECODER_H_ */
