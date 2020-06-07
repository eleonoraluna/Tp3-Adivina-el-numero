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
	void stop();
	virtual ~Game_Manager();
private:
	Reader reader;
	Statistics &statistics;
	Socket_TCP socket;
	std::vector<Player*> players;
	std::atomic<bool> isclosed;
	void read_numbers();
	int accept_player();
	void is_player_finished();
};

#endif /* SERVER_GAMEMANAGER_H_ */
