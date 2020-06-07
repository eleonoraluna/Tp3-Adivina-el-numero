#ifndef COMMON_SOCKETTCPEXCEPTION_H_
#define COMMON_SOCKETTCPEXCEPTION_H_
#include <exception>

class Socket_TCPException: public std::exception{
public:
	Socket_TCPException();
	virtual const char *what() const throw();
	~Socket_TCPException();
};

#endif /* COMMON_SOCKETTCPEXCEPTION_H_ */
