#include <utility>
#include <string>
#include <vector>
#include "common_SocketTCPException.h"
#include "server_GameManager.h"

Game_Manager::Game_Manager(const std::string &port,const std::string &filename,
Statistics &statistics):
reader(filename),statistics(statistics),socket(port),isclosed(false){
}

void Game_Manager::read_numbers(){
	 this->reader.openFile();
	 this->reader.readNumbers();
}

int Game_Manager::accept_player(){
	 try{
	 Socket_TCP socket_player=this->socket.accept();
	 Player* p=new Player(this->reader.nextNumber(),this->statistics
			              ,std::move(socket_player));
	 this->players.push_back(p);
	 p->start();
	 }catch(const Socket_TCPException &e){
		 return 1;
	 }
	 return 0;
}

void Game_Manager::is_player_finished(){
	 std::vector<Player*> aux;
	 for (Player* p:this->players){
		  if (!p->is_playing()){
			  p->join();
			  delete(p);
		  }else{
			  aux.push_back(p);
		  }
	 }
	 this->players.swap(aux);
}

void Game_Manager::stop(){
	 this->isclosed=true;
	 this->socket.stop();
}

void Game_Manager::run(){
	 while (!this->isclosed){
		 if (this->accept_player()!=1){
		    this->is_player_finished();
		 }
	 }
}

Game_Manager::~Game_Manager() {
	for (Player* p:this->players){
		 p->join();
		 delete(p);
	}
}

