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
	enum Commands{HELP,SURRENDER,OTHER};
	Encoder encoder;
	bool surrender;
	bool is_playing;

	//dependiendo del comando se ejecutan las acciones correspondientes
	void check_input();

	//Chequea si realmente es un número o una mezcla de caracteres
	void is_number();

	//Chequea que el numero pueda ser representado en un unsigned de 2 bytes
	void check_number();

	//mapea el comando ingresado a alguna de las opciones del enum
	enum Commands resolve_command();

	//una vez que el comando pasa los chequeos se lo codifica para enviarlo
	void encode(Command &c);
};

#endif /* CLIENT_GAME_H_ */
