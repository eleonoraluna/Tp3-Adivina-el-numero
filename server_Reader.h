#ifndef SERVER_READER_H_
#define SERVER_READER_H_
#include <fstream>
#include <vector>
#include <string>

class Reader {
public:
	explicit Reader(const std::string &file);
	void openFile() const;
	bool is_eof();
	int readNumbers();
	int nextNumber();
	virtual ~Reader();
private:
	std::ifstream file;
	std::vector <int> numbers;
	int index_number;
	void separate_digits(int n, std::vector<int> &v) const;
	bool no_repeated_digits(int n) const;
	bool is_number_valid(int n) const;
};

#endif /* SERVER_READER_H_ */
