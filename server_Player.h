#ifndef SERVER_PLAYER_H_
#define SERVER_PLAYER_H_
#include <vector>
#include <atomic>
#include "server_Decoder.h"
#include "server_Statistics.h"
#include "server_Thread.h"

class Player: public Thread{
public:
	Player(int number,Statistics &statistics,Socket_TCP socket);
	void run();
	bool is_playing() const;
	virtual ~Player();

private:
	int number;
	std::vector<int> mynumber;
	int attempts;
	std::atomic<bool> isplaying;
	Statistics &statistics;
	Decoder decoder;

	//dependiendo el comando ejecuta las acciones correspondientes
	void run_command(char type);

	void run_help() const;

	//suma 1 ganador a las estadísticas y le dice al decoder que mande
	//el mensaje correspondiente
	//marca la partida como terminada
	void win();

	//suma 1 perdedor a las estadísticas y le dice al decoder que mande
	//el mensaje correspondiente
	//marca la partida como terminada
	void lose();

	//compara el numero a adivinar con el que ingreso el jugador
	//y cuenta cuantos digitos tiene bien regular y mal
	void keep_trying(int n) const;

	//chequea si el numero esta dentro del rango establecido
	void check_number();

	//devuelve true si el número esta dentro del rango y no tiene
	//dígitos repetidos
	bool is_number_valid(int n) const;

	//chequea si el número tiene digitos repetidos
	bool no_repeated_digits(int n) const;

	//chequea si adivinó, perdió o puede seguir intentando
	void guess_number(int n);

	//separa los dígitos de un número y los coloca en un vector
	void separate_digits(int n, std::vector<int> &v) const;
};

#endif /* SERVER_PLAYER_H_ */
