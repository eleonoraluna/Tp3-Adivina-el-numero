#include "common_SocketTCPException.h"

Socket_TCPException::Socket_TCPException() {}

const char* Socket_TCPException:: what() const throw(){
	  return "TCP Socket error";
}

Socket_TCPException::~Socket_TCPException() {}

