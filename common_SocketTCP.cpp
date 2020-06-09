#define _POSIX_C_SOURCE 200112L
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <string>
#include "common_SocketTCP.h"
#include "common_SocketTCPException.h"

#define MAX_CONNECTIONS 10

Socket_TCP::Socket_TCP(){
	this->fd=-1;
}

Socket_TCP::Socket_TCP(int fd){
	this->fd=fd;
}

Socket_TCP::Socket_TCP(const std::string &port){
	this->bind(port);
	this->listen();
}

void Socket_TCP::bind(const std::string &port){
	struct addrinfo hints;
	struct addrinfo *ai,*ai_list;
	bool connected=false;
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family=AF_INET; //IPv4
	hints.ai_socktype=SOCK_STREAM; //TCP
	hints.ai_flags=AI_PASSIVE; // AI_PASSIVE for server

	if (getaddrinfo(0,port.c_str(),&hints,&ai_list)!=0){
		throw Socket_TCPException();
	}
	for (ai=ai_list; ai!=NULL && connected==false; ai=ai->ai_next){
	 if ((this->fd=socket(ai->ai_family,ai->ai_socktype,ai->ai_protocol))==-1){
		 this->freeAddrinfo(ai_list);
	 }else if (::bind(this->fd,ai->ai_addr,ai->ai_addrlen)==-1){
		 this->freeAddrinfo(ai_list);
	 }
		connected=true;
	}
	freeaddrinfo(ai_list);
}

void Socket_TCP::listen() const{
	 if (::listen(this->fd,MAX_CONNECTIONS)==-1){
		throw Socket_TCPException();
	 }
}

Socket_TCP Socket_TCP::accept() const{
	int fd=::accept(this->fd,NULL,NULL);
	if(fd==-1){
		throw Socket_TCPException();
	}
	return Socket_TCP(fd);
}

void Socket_TCP::freeAddrinfo(struct addrinfo *ai){
	freeaddrinfo(ai);
	throw Socket_TCPException();
}

void Socket_TCP::connect(const std::string &name,const std::string &port){
	struct addrinfo hints;
	struct addrinfo *ai,*ai_list;
	bool connected=false;
	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family=AF_INET; //IPv4
	hints.ai_socktype=SOCK_STREAM; //TCP
	hints.ai_flags=0;

	if (getaddrinfo(name.c_str(),port.c_str(),&hints,&ai_list) !=0){
		throw Socket_TCPException();
	}
	for (ai=ai_list; ai!=NULL && connected==false; ai=ai->ai_next){
	 if ((this->fd=socket(ai->ai_family,ai->ai_socktype,ai->ai_protocol))==-1){
		 this->freeAddrinfo(ai_list);
	 }else if (::connect(this->fd,ai->ai_addr,ai->ai_addrlen)<0){
		    this->freeAddrinfo(ai_list);
	 }
	connected=true;
	}
	freeaddrinfo(ai_list);
}

void Socket_TCP::recieve(char *buffer, int length) const{
	int pos=0;
	int recieved=0;
	while(pos<length){
		recieved=::recv(this->fd,&buffer[pos],length-pos,0);
		//sigo recibiendo hasta recibir todos los bytes
		if (recieved>0){
			pos=pos+recieved;
		//recibo 0 bytes. Hicieron un shutdown o llego al EOF
		} else if (recieved==0){
			//tengo que cerrar socket
			throw Socket_TCPException();
		} else {
			throw Socket_TCPException();
		}
	}
}

void Socket_TCP::send(const char *buffer, int length) const{
	 int pos=0;
	 int sent=0;
	 while (pos<length){
		sent=::send(this->fd,&buffer[pos],length-pos,MSG_NOSIGNAL);
		if (sent==0){
			throw Socket_TCPException();
		} else if (sent<0){//error en el send
			throw Socket_TCPException();
		} else {//sigo mandando hasta que se envien todos los bytes
			pos=pos+sent;
		}
	 }
}

Socket_TCP& Socket_TCP::operator =(Socket_TCP &&other){
	if (this ==&other){
		return *this;
	}
	if (this->fd!=-1){
		this->fd=other.fd;
		other.fd=-1;
	}
	return *this;
}

Socket_TCP::Socket_TCP(Socket_TCP&& other){
	this->fd=other.fd;
	other.fd=-1;
}

void Socket_TCP::stop(){
	 shutdown(this->fd,SHUT_RDWR);
	 close(this->fd);
	 this->fd=-1;
}

Socket_TCP::~Socket_TCP() {
	if(this->fd!=-1){
		shutdown(this->fd,SHUT_RDWR);
		close(this->fd);
		this->fd=-1;
	}
}

