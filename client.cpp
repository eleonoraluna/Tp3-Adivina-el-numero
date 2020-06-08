#include <iostream>
#include <exception>
#include "common_SocketTCPException.h"
#include "client_Game.h"

const int ARGSCLIENT=3;

int main(int argc,char* argv[]){
	if(argc==ARGSCLIENT){
		try{
			Game game(argv[1],argv[2]);
			game.run();
		}catch(const Socket_TCPException &e){
			std::cout<<e.what()<<std::endl;
		}catch(const std::exception &e){
			std::cout<<e.what()<<std::endl;
		}
	}
	//retorna siempre 0 como es pedido
	return 0;
}

