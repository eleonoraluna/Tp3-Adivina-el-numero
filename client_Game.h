#ifndef CLIENT_GAME_H_
#define CLIENT_GAME_H_
#include <string>
#include "client_Command.h"
#include "client_Encoder.h"

class Game {
public:
	Game(const std::string &name, const std::string &port);
	void run();
	virtual ~Game();
private:
	std::string input;
	Encoder encoder;
	bool surrender;
	bool is_playing;
	void check_input();
	void is_number();
	void check_number();
	int resolve_command();
	void encode(Command &c);
};

#endif /* CLIENT_GAME_H_ */
