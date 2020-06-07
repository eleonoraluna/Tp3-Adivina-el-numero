#ifndef SERVER_PRINTER_H_
#define SERVER_PRINTER_H_
#include "server_Statistics.h"

class Printer {
public:
	explicit Printer(Statistics &statistics);
	void print();
	virtual ~Printer();
private:
	Statistics &statistics;
};

#endif /* SERVER_PRINTER_H_ */
