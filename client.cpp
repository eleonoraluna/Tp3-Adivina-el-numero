#include <iostream>
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
			//devuelve siempre 0 como es requerido
			return 0;
		}
	}
	return 0;
}

