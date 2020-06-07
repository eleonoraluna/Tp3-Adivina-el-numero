#include <iostream>
#include <exception>
#include "server_FileErrorException.h"
#include "common_SocketTCPException.h"
#include "server_InputReader.h"

const int ARGSSERVER=3;

int main(int argc,char* argv[]){
	if(argc==ARGSSERVER){
		try{
			Input_Reader reader(argv[1],argv[2]);
			reader();
		}catch(const FileErrorException &e){
			std::cout<<e.what()<<std::endl;
			return 1;
		}catch(const Socket_TCPException &e){
			std::cout<<e.what()<<std::endl;
			return 1;
		}
	}else{
		std::cout<<"modo no soportado"<<std::endl;
		return 1;
	}
	return 0;
}




