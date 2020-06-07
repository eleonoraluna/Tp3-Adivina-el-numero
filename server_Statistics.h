#ifndef SERVER_STATISTICS_H_
#define SERVER_STATISTICS_H_
#include <mutex>

class Statistics {
public:
	Statistics();
	void add_winner();
	void add_loser();
	int get_winners() const;
	int get_losers() const;
	virtual ~Statistics();
private:
	int winners;
	int losers;
	std::mutex m;
};

#endif /* SERVER_STATISTICS_H_ */
