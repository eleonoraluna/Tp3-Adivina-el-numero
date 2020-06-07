#ifndef SERVER_INPUTREADER_H_
#define SERVER_INPUTREADER_H_
#include "server_GameManager.h"
#include "server_Printer.h"
#include "server_Statistics.h"
#include <string>

class Input_Reader {
public:
	Input_Reader(const std::string &port,const std::string &filename);
	void run();
	void operator()();
	virtual ~Input_Reader();
private:
	Statistics statistics;
	Game_Manager manager;
	Printer printer;
};

#endif /* SERVER_INPUTREADER_H_ */
