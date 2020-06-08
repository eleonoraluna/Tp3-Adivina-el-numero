#ifndef SERVER_GAMEMANAGER_H_
#define SERVER_GAMEMANAGER_H_
#include <string>
#include <vector>
#include <atomic>
#include "server_Reader.h"
#include "server_Statistics.h"
#include "common_SocketTCP.h"
#include "server_Player.h"
#include "server_Thread.h"

class Game_Manager: public Thread {
public:
	Game_Manager(const std::string &port,const std::string &filename,
			     Statistics &statistics);
	void run();

	//cierra el socket aceptador y pone a isclosed en true
	void stop();

	virtual ~Game_Manager();

private:
	Reader reader;
	Statistics &statistics;
	Socket_TCP socket;
	std::vector<Player*> players;
	std::atomic<bool> isclosed;

	//hace uso del Reader para leer el archivo de números
	void read_numbers();

	//hace accept de clientes
	//si recibe una excepcion de socket sale de la funcion
	//devuelve 1 si recibe una excepcion indicando que cerraron
	//el socket forzosamente o 0 en otro caso
	int accept_player();

	//va chequeando si los jugadores terminaron o no
	//si terminaron los elimina
	//se ejecuta únicamente si accep_player devuelve 0
	void is_player_finished();
};

#endif /* SERVER_GAMEMANAGER_H_ */
