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
	void run_command(char type);
	void run_help() const;
	void win();
	void lose();
	void keep_trying(int n) const;
	void check_number();
	bool is_number_valid(int n) const;
	bool no_repeated_digits(int n) const;
	void guess_number(int n);
	void separate_digits(int n, std::vector<int> &v) const;
};

#endif /* SERVER_PLAYER_H_ */
