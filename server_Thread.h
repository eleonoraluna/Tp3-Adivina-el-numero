#ifndef SERVER_THREAD_H_
#define SERVER_THREAD_H_
#include <thread>

class Thread {
public:
	Thread();
	void start();
	void join();
	virtual void run()=0;
	Thread(const Thread&)=delete;
	Thread& operator=(const Thread&) = delete;
	Thread(Thread&& other);
	Thread& operator=(Thread&& other);
	virtual ~Thread();
private:
	std::thread thread;
};

#endif /* SERVER_THREAD_H_ */
