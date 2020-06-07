#ifndef SERVER_FILEERROREXCEPTION_H_
#define SERVER_FILEERROREXCEPTION_H_

class FileErrorException {
public:
	FileErrorException();
	virtual const char *what() const throw();
	virtual ~FileErrorException();
};

#endif /* SERVER_FILEERROREXCEPTION_H_ */
